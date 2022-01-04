inherit F_CLEAN_UP;
int main(object me, string arg)
{
  mapping help_m=([
  "初入风云指南":({"newbie"}),
  "风云所有指令汇编":({"cmds"}),
  "详尽介绍游戏内容":({"game"}),
  "风云中的武功门派":({"menpai"}),
  "风云游戏规则":({"rules"}),
  "风云地图汇总":({"maps"}),
  "风云任务帮助":({"quest"}),
  ]);
  this_player()->process_gmcp(help_m,"Char.Help","List");

	return 1;
}
