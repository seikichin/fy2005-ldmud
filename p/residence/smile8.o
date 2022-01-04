

inherit __DIR__"ann_residence.c";

void create ()
{
  set("floor",8);

  set ("short", "笑浅楼"+CHINESE_D->chinese_number(query("floor"))+"层");
  set ("long", "\n\n"
"情人的话本不是说给别人听的。\n"
"有些话在别人听来一定很肉麻，\n"
"但在情人们自己听来，却温柔如春风，优美如歌曲。\n\n"
"");
        set("exits", ([
"808" : __DIR__"userroom/cnn1621347170",
"807" : __DIR__"userroom/cmm1621347041",
"806" : __DIR__"userroom/cjj1621346686",
"805" : __DIR__"userroom/cii1621345662",
"804" : __DIR__"userroom/chh1621344547",
"803" : __DIR__"userroom/ckk1621341830",
"802" : __DIR__"userroom/cll1621341520",
"801" : __DIR__"userroom/caa1621338435",

  "down" : __DIR__"smile"+(query("floor")-1),
  "up" : __DIR__"smile"+(query("floor")+1), 
]));
  	set("coor/x",-20);
	set("coor/y",-30);
	set("coor/z",query("floor")*40);
	setup();
}

/*
 
               (\~~~/)            
               ( ．．)        

               (_____)~．      
   
　　　　　　　- FengYun - 　　　
　　　　　　annie 10.2003
　　　dancing_faery@hotmail.com
*/
