inherit ROOM;

void create()
{
    set("short", "莽林边缘");
    set("long","无意中道路越来越窄，两旁的树枝越来越密，树缝中洒下来的阳光也变得斑斑\n"
"点点。茅草渐厚，灌木丛生，路径漫灭。吹来的风也越发的阴冷潮湿。远方密林的\n"
"天空上有几只盘旋的秃鹰，发出撕心裂肺的叫声，令人毛骨耸然。路边歪歪扭扭贴\n"
"着张告示：[33m『猛兽出没，有去无回』[32m\n"
);
    set("exits", ([ /* sizeof() == 4 */
	"south" : __DIR__"groupn2",
	"north" : AREA_FYCYCLE"fyroad0",
      ]));
    set("outdoors", "manglin");
    set("NONPC",1);
    set("coor/x",50);
    set("coor/y",-40);
    set("coor/z",20);
    setup();

}
