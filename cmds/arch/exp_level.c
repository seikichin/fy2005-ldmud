#include <ansi.h>
inherit F_CLEAN_UP;
inherit F_LEVEL;

int main(object me, string arg)
{
	int num;
	mapping data;
	
	if (!arg){
		 notify_fail("格式错误：请察看帮助文件。\n");
		 return 0;
		 }

	if (sscanf(arg, "%d/%d", num) != 1){
		notify_fail("格式错误：请察看帮助文件。\n");
		return 0;
		}

	if ( num>0 && num <= 500)
	{
		write ("等级（"+num+"）	换算经验值（"+level_to_exp(num,0)+"）\n");
		return 1;
	}
	
	if ( num > 2000 && num < 100000000)
	{
		data = exp_to_level(num);
		
		write("经验值（" + num + "）换算：\n");
		write("	当前等级 = " + data["level"] + "\n");
		write("	该等级起始经验 = " + data["level_exp"] + "\n");
		write("	已完成百分数 = " + data["sub"] /10 + "." + data["sub"]%10 + "%\n");
		write("	这一等级共需要经验值 = " + data["next_level"] + "\n");
		
		return 1;
	}	
		
	 notify_fail("格式错误：请察看帮助文件。\n");
	 return 0;
}
		
int help(object me)
{
write(funcall(#'read_file,"/help/cmds/arch/exp_level"));
	return 1;
}