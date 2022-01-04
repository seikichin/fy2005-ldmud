inherit __DIR__"ann_residence.c";
void save_t();
mixed test;
mapping test1=([
"910" : __DIR__"userroom/wps1614516448",
"909" : __DIR__"userroom/cff1613416307",
"908" : __DIR__"userroom/cee1613415775",
"907" : __DIR__"userroom/cgg1613414353",
"906" : __DIR__"userroom/cbb1595159707",
"905" : __DIR__"userroom/tanghulu1590924560",
"904" : __DIR__"userroom/heng1589142762",
"903" : __DIR__"userroom/cjb1588857324",
"902" : __DIR__"userroom/shaolin1588084801",
"901" : __DIR__"userroom/mrsunys1587366760",]);
void create ()
{
  set("floor",1);

  set ("short", "新月楼底层");
  set ("long", "\n"
"  \n"
"    星沉月落夜闻香 素手出锋芒 前缘再续新曲 \n"
"    \n"
"    心有意 爱无伤 江湖远 碧空长 路茫茫 \n"
"    \n"
"    闲愁滋味 多感情怀 无恨思量 \n\n"
"");

        set("coor/x",-15);
        set("coor/y",-35);
        set("coor/z",query("floor")*40);
        save_t();
        test=restore_value(read_file(__DIR__"o_bag"+query("floor")+".o"));
        printf("%O",test);
                set("exits", ([
  "up" : __DIR__"moon"+(query("floor")+1), 
  "southwest" : __DIR__"enterance",
])+test);
        setup();
}
void save_t(){
	string str=save_value(test1);
write_file(__DIR__"o_bag"+query("floor")+".o",str,1);

}



/*
*/
