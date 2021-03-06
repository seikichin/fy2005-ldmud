inherit ROOM;

void create()
{
    set("short", "洞道");
	set("long","石壁上已经爬满了青苔，但还是明显看得出斧凿的痕迹，洞道曲折晦暗，而地\n"
"势却愈来愈开阔平坦，人行其中，一开始还得匍匐爬行，到得后来，却已是方圆数\n"
"丈距离。然而嶙峋的怪石，和曲折的洞道让道路更加难辨。\n");
	set("exits", ([ 
  		"west" : __DIR__"chiyoudao2",
  		"north" : __DIR__"chiyoudao6",
  		"south" : __DIR__"chiyoudao7",
  	]));

	set("indoors","wolfmount");
	setup();
}

void init(){
	int i;
    string *rooms = ({"chiyoudao0", "chiyoudao1", "chiyoudao2", "chiyoudao3",
    "chiyoudao6", "chiyoudao7", "chiyoudao8"});
	i = random(7);
    set("exits/east", __DIR__ + rooms[i]);
}