// edit.c
#include <input_to.h>

int edit(closure callback)
{
	write("结束离开用 '.'，取消输入用 '~q'，使用内建列编辑器用 '~e'。\n");
	write("—————————————————————————————\n");
	input_to("input_line", INPUT_PROMPT,"","", callback);
	return 1;
}

void input_line(string line, string text, closure callback)
{
	if( line=="." ) {
	    apply(callback,text);
		return;
	} else if( line=="~q" ) {
		write("输入取消。\n");
		return;
	} else if( line=="~e" ) {
	} else
		text += line + "\n";
	input_to("input_line",INPUT_PROMPT,"",text, callback);
}
