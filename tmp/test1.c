#include <ansi.h>
string test(){
string str=HIR"红色a"HIY"黄色bc"HIG"绿色\n"HIC"金色"HIM"紫色"NOR"正常";

write(sprintf("%#-40s",
                HIR"one\n"HIY"two\n"HIG"three\n"HIC"four\n"HIM"fiveeeeeeeeeeeeeeeeeeeeee\n"NOR"six\n"HIG"seven\n"HIY"eight\n"HIM"nine\n"HIG"ten\n\n"));
                            // returns "one     three   five    seven   nine\n"
                            //         "two     four    six     eight   ten"

return str;
}


