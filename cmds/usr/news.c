//BBB 09/25/1999
//让玩家不会漏过任何重要新闻，也不要长途跋涉去看巫师公告版。
// Modify by snowman@SJ for new_list when login.
// Modified By Numa@SJ 2000.3.31 For write all to player
// Modified By bbb@SJ 2000.11.03 For Mysql
// Modified by snowman@SJ 19/12/2000 for faster speed.

// Modified for fy game... credits go to above authors.

#include <ansi.h>
#include <mudlib.h>

#define NEWS_DIR       "/data/"
#define NEWS_FILENAME  "news"

#define NEWS_TITLE  "\n================================= "HIC"风云公告系统"NOR" =====================================\n"
#define NEWS_END  "====================================================================================\n"

#define NEWS_P HIY"风云公告系统："NOR

inherit F_SAVE;

nosave object ob = 0;
nosave int statuss=0;
nosave string msg,subject;

mapping *notes;

string query_save_file()
{
	return NEWS_DIR + NEWS_FILENAME ;
}

void tell_me(string msg)
{
	if (objectp(ob)) tell_object(ob, msg);
}

void done_post(object me,mapping note, string text)
{
	int i;
	note["msg"] = text;
	i = sizeof(notes);
	if( !pointerp(notes) || !sizeof(notes) )
		notes = ({ note });
	else
		notes += ({ note });
	note["time"] = time();
	tell_object(me, NEWS_P + HIM "新闻发布完毕。\n"NOR);
	save();
	return;
}

void list_news(object me, int login)
{
	int i = 0, ulogin, j = 0;
	string str;

	if (sizeof(notes) < 1)
		write("公告栏为空。\n");
	else {
		ulogin = me->query("last_news");
		str = NEWS_END;
		foreach (mapping item in notes) {
			i++;
			if (ulogin < item["time"]) {
				if (j++ < 15)
					str = sprintf("%3d) %-=40s %18s (%s)\n%s",
						i, item["title"],
						wizardp(me)?item["poster"]+"("+capitalize(item["author"])+")":"",
						ctime(item["time"])[0..9], str
					);
			}
		}
		if (!j)
			write("目前没有新的公告。\n");
		else {
			if (login && j > 5)
				;
			else
				write(NEWS_TITLE + str);
			write("\n");
			write(YEL"当前共有 "WHT+ i +YEL" 条公告、"HIR+ j +NOR+YEL" 条未读。\n");
			write("请用 fynews 阅读标题，或者 fynews new|next|编号 阅读具体内容。\n"
"详细指令请参阅 help fynews \n\n"NOR);
		}
	}
}

void list_allnews(object me)
{
	int i;
	string str;

	i = sizeof(notes);
	if ( i < 1) {
		write(NEWS_P +"没有任何公告。\n");
		return;
	}
	str = NEWS_TITLE;
	while( i-- )
		str += sprintf("%3d) %-=40s %18s (%s) \n",
			i+1, notes[i]["title"], wizardp(me)?notes[i]["poster"]+"("+capitalize(notes[i]["author"])+")":"",
			ctime(notes[i]["time"])[0..9] );
	str += NEWS_END;
	me->start_more("",str,0);
}

void create()
{
	seteuid(getuid());
	restore();
	call_out("create", 900);
}

int main(object me, string arg)
{
	mapping note;
	string s,arg1;
	int num = -1;

	if (!arg) {
		list_news(me, 0);
		return 1;
	}

	if (sscanf(arg, "%s", s) == 1) {
		if ( s == "all" ) {
			list_allnews(me);
			return 1;
		}
		if ( s == "post" ){
			if( wiz_level(me)<3 ){
				 notify_fail(NEWS_P +"只有巫师才可以发布消息。 \n");return 0;}
			else{ notify_fail("使用方法： fynews post 主题 \n");return 0;}
		}
		if ( s == "delete" ){
			if( wiz_level(me)<3 ){
				 notify_fail(NEWS_P +"只有巫师才可以删除消息。 \n");return 0;}
			else{	 notify_fail("使用方法： fynews delete 编号 \n");return 0;}
		}
		
		if (s == "announce") {
			if (wiz_level(me)<3){
				notify_fail(NEWS_P +"只有巫师才可以公告游戏。\n");return 0;}
			CHANNEL_D->do_sys_channel("info","风云游戏发布新的公告，请及时用fynews指令查询，谢谢。");
			return 1;
		}
	}

	if (sscanf(arg, "post %s", arg1) == 1) {
		if ( wiz_level(me)<3 ){
			notify_fail(NEWS_P +"只有巫师才可以发布消息。 \n");return 0;}
		if ( strlen(arg1)< 4 || strlen(arg1)>20 ){
			notify_fail(NEWS_P +"请简明扼要地说明主题，主题字数必须在4-20之间。 \n");return 0;}
		else note = m_allocate(5);
		note["title"] = arg1;
		note["author"] = getuid(me);
		note["poster"] = me->query("name");
		me->edit( (:done_post(me, note,$1):));
		return 1;
	}

	if (sscanf(arg, "delete %d", num)== 1) {
		if ( wiz_level(me)<3 ){
			notify_fail(NEWS_P +"只有巫师才可以删除消息。 \n");
			return 0;
			}
		if( !pointerp(notes) || num < 1 || num > sizeof(notes) ){
			notify_fail(NEWS_P +"没有这个编号的公告。\n");
			return 0;
			}
		else num--;
		notes = notes[0..num-1] + notes[num+1..<1];
		save();
		write(NEWS_P +"删除第 " + (num+1) + " 号公告....Ok。\n");
		return 1;
	}

	if (arg == "new" || arg == "next") {
		int ulogin = me->query("last_news");

		num = sizeof(notes);
		while (num--)
			if (ulogin >= notes[num]["time"])
				break;
		num+=2;
	}

	if (num+1 || sscanf(arg, "%d", num) == 1) {
		int size = sizeof(notes);

		if (!size){
			notify_fail(NEWS_P +"没有任何公告。\n");
			return 0;
			}
		if (num < 1 || num > size){
			notify_fail(NEWS_P +"没有这个编号的公告。\n");
			return 0;
			}
		num--;
		me->start_more("",sprintf("%d) %-=43s %8s(%s)(%s)\n"+NEWS_END,
			num + 1, notes[num]["title"],
			wizardp(me)?notes[num]["poster"]:"",
			wizardp(me)?notes[num]["author"]:"News",
			ctime(notes[num]["time"])[0..15]) + notes[num]["msg"],0
		);
		write(NEWS_END);
		if (me->query("last_news") < notes[num]["time"])
			me->set("last_news", notes[num]["time"]);
		return 1;
	}

	if ( arg == "write all" ) {
		if (!wizardp(me)){
			notify_fail("这是巫师命令。\n");return 0;}
		if( !pointerp(notes) || !sizeof(notes) ){
			notify_fail(NEWS_P +"没有任何公告。\n");return 0;}
		msg = NEWS_TITLE;
		for (num=0;num<sizeof(notes);num++) {
			msg += sprintf(HIW"%d"NOR") %-=43s %8s(%s)(%s)\n"+NEWS_END,num + 1, notes[num]["title"],
				wizardp(me)?notes[num]["poster"]:"",wizardp(me)?notes[num]["author"]:"",
				ctime(notes[num]["time"])[0..15]) + notes[num]["msg"] + "\n\n";
		}
		me->start_more("",msg,0);
		return 1;
	}
	
	notify_fail("请使用help fynews来查看所有的有关参数。\n");
	return 0;
}

int help(object me)
{
//	if (!wiz_level(me) )
	write(funcall(#'read_file,"/help/cmds/usr/fynews0"));
//	else
//	write(funcall(#'read_file,"/help/cmds/usr/fynews1"));
	return 1;
}