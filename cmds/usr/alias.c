// alias.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	int i;
	mapping alias;
	string verb, replace, *vrbs;

	if( !arg ) {
		alias = me->query_all_alias();
		if( !sizeof(alias) ) {
			write("你目前并没有设定任何 alias。\n");
			return 1;
		} else  {
			write("你目前设定的 alias 有：\n");
			vrbs = keys(alias);
			for(i=0; i<sizeof(vrbs); i++)
				printf("%-15s = %s\n", vrbs[i], alias[vrbs[i]]);
			return 1;
		}
	}

	if( sscanf(arg, "%s %s", verb, replace)!=2 )
		me->set_alias(arg, 0);
	else if( verb=="alias" )
		return notify_fail("你不能将 \"alias\" 指令设定其他用途。\n");
	else if( verb=="" )
		return notify_fail("你要设什麽 alias？\n");
	else
		return me->set_alias(verb, replace);
		
//	write("Ok.\n");
	return 1;
}

int help (object me)
{
	write("[0;1;37m────────────────────────────────[0m\n"
"[0;1;36m指令格式 : 	alias <欲设定之指令> <系统提供之指令>[0m\n"
"[0;1;37m────────────────────────────────[0m   \n"
" \n"
"有时系统所提供之指令需要输入很长的字串, 在使用时(尤其是经常用到的)\n"
"或许会感觉不方便, 此时你(玩家)即可用此一指令设定并替代原有之指令。\n"
" \n"
"□例:\n"
"	'alias sc score' 会以 sc 取代 score 指令。\n"
"	'alias' 後不加参数则列出你所有的替代指令。\n"
"	'alias sc' 会消除 sc 这个替代指令。 (如果你有设的话)\n"
" \n"
"其中可以用 $1, $2, $3 .... 来取代第一、第二、第三个参数，\n"
"或是 $* 取代所有的参数，如：\n"
"	'alias pb put $1 in $2'\n"
"\n"
"则每当你(玩家)打：\n"
"	pb bandage bag\n"
"\n"
"就会取代成：\n"
"	put bandage in bag\n"
"\n"
"[0;1;37m────────────────────────────────[0m   \n"
"	\n"
""
);
        return 1;
}
