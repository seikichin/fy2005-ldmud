#include <ansi.h>
inherit "/std/room/vrm_server3.c";

#define ENTER_ROOM_X  0
#define ENTER_ROOM_Y  0
#define ENTER_ROOM_Z  0

void create() 
{ 
	"*"::create();
        set_lonely_create(1);
        set_normal_room(1);
        
        //迷宫房间所继承的物件的档案名称。 
        set_inherit_room( __DIR__"maze_room" ); 
        
        //迷宫的单边长 
        set_maze_long(3); 
        
        set_maze_boxs(1);
        
        //set_maze_traps(2);
                        
        //入口方向(出口在对面) 
        set_entry_dir("east"); 
                        
        //出口与区域的连接方向 
        set_link_exit_dir("west"); 
                        
        //出口与区域的连接档案名 
      //  set_link_exit_room(__DIR__"leave"); 

        //以下是入口坐标 
        set_link_entry_room_x(ENTER_ROOM_X); 
        set_link_entry_room_y(ENTER_ROOM_Y); 
        set_link_entry_room_z(ENTER_ROOM_Z); 
                        
        //普通房间描述
        set_maze_room_short("迷宫");
                        
        set_maze_room_desc("这是一间宽敞的石屋，四周巨石垒就的墙壁泛出幽幽的青色光芒，两盏青铜\n"
"灯吐出一尺高的火焰，飘忽闪烁，偶然有灯花爆裂的轻响，更令人感到窒息般的\n"
"寂静。地上是丈许见方的青石板铺就，房间中央一块白色石板格外醒目，上面雕\n"
"刻着细密的图纹，让人不由自主的想上前查看（mazemap）一番。\n"
); 

        //入口房间短描述 
        set_entry_short("漆黑入口"); 
                        
        //入口房间描述 
        set_entry_desc("黑漆漆的一个密窟，虽然一眼看去空荡荡的，但似乎随时随地会跳出伏兵，若是\n"
"你不想丧命于此，可用（ｏｕｔ）命令退出\n"
);
                        
        //出口房间短描述 
        set_exit_short("总坛"); 
        
                        
        //出口房间描述 
        set_exit_desc("终于到了密窟深处，这里胡乱地堆着些柴草，想到一路上的血战，你恨不得把这\n"
"个鬼地方一把火烧了（ｂｕｒｎ）。\n"
);
 
        // 迷宫限制最高进入等级
        set_remove_time(3600); 
} 


