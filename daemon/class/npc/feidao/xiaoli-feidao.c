// counterattack.c

#include <ansi.h>

inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("[31må°æé£å[37måªè½å¯¹ææä¸­çå¯¹æä½¿ç¨ã\n");
	if(({int}) me->query_skill("feidao",1) <= 300)
		return notify_fail("ä½ çé£åç»æè¿ä¸å¤ç²¾çº¯ï¼ä¸è½ååºå°æé£åã\n");

	message_vision(RED"$Nç®ä¸è½¬çå°ç¯ç$nï¼åå¤ååºè´å½ä¸å»ã\n"NOR,me,target);
        me->start_call_out( (: call_other( __FILE__, "kill_him", me, target) :), random(5)+5);
	me->start_busy(5);
	return 1;
}
void kill_him(object me, object target)
{
	string msg;
	if(me->is_fighting() && target->is_fighting() &&
	environment(me) == environment(target))
	{
msg = HIY "$Nä½¿åºé£åç»æä¸­ä¾æ èåç" + HIR "å°æé£å" +HIY "ï¼$nåªè§å¾ç¼åä¸è±ï¼å½åå·²è¢«å¯¹ç©¿èè¿ï¼ï¼ï¼" ;
msg +=  "\nä¸è¡è¡ç®­å·æ¶èåºï¼ï¼$nçç¼çæ­»é±¼è¬ççªäºåºæ¥ï¼ï¼\n" NOR;

	message_vision(msg, me, target);
		target->die();
	}
	return ;
}
