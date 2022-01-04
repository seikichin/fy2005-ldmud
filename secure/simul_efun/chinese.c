#include <ansi.h>
#include <regexp.h>
string remove_ansi(string str)
{
        string tmp = "";
        int i, j = 0, len;

        if( !stringp(str) ) return "";

        len = sizeof(str);

        for( i = 0; i < len; i++ ) {
                if( str[i] == ESC[0] ) {
                        for( j = i; j < len; j++ ) {
                                i++;
                                if( ( str[i] > 'A' && str[i] < 'Z' )
                                 || ( str[i] > 'a' && str[i] < 'z') )
                                 break;
                        }
                }
                else tmp += str[i..i];
        }
        return tmp;
}
string chinese_number(int i)
{
	return CHINESE_D->chinese_number(i);
}

string to_chinese(string str)
{
	return CHINESE_D->chinese(str);
}

int is_chinese(string name)
{
	if(!name)
		return 0;
  name=remove_ansi(name);
  return regmatch(name,"^([\\p{Han}\\p{P}])*$",RE_PCRE);

}

string time_period(int time)
{
        int t, d, h, m, s;
        string str;

        t = time;
        s = t % 60;             t /= 60;
        m = t % 60;             t /= 60;
        h = t % 24;             t /= 24;
        d = t;

        if( d ) str = chinese_number(d) + "天";
        else str = "";

        if( h ) str += chinese_number(h) + "小时";
        if( m ) str += chinese_number(m) + "分";
        str += chinese_number(s) + "秒";

        return str;
}