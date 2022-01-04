// message.c

#include <ansi.h>
#include <dbase.h>
#include <mxp.h>

#define MAX_MSG_BUFFER 500
#define TOMXP ({int})this_object()->QueryMXP()
nosave int editing; 
public int SetEditing(int f) { return editing=f; }
public int QueryEditing() {
  return ( editing ||
	   objectp(query_input_pending(this_object())) ||
	   objectp(query_editing(this_object())) );
}

nosave string *msg_buffer = ({});
nosave string terminal;             /* the actual terminal used by client */
void print_eor();                              /* std/player/telnet_neg  */
public mixed query_terminal();                 /* std/player/telnet_neg  */

public string SetTerminal(string str) {
  mixed term = query_terminal();
  if (pointerp(term) && sizeof(term) > 1 && sizeof(term[1]) > 0)
    terminal = term[1][0];
  else
    terminal = str;
  return terminal;
}
public string QueryTerminal() { return terminal; }

void receive_message(string msg,string msgclass)
{
	string subclass, *ch;
       
	if( !interactive(this_object()) ) {
		this_object()->relay_message(msgclass, msg);
		return;
	}
	   if (msgclass == "telnet")
        {
                efun::tell_object(this_object(),msg);
                return;
        }
 
	if( sscanf(msgclass, "%s:%s", subclass, msgclass)==2 ) {
		switch(subclass) {
			case "channel":
				if( !pointerp(ch = query("channels"))
				||	member_array(msgclass, ch)==-1 )
					return;
				break;
			case "outdoor":
				if( !environment() || !environment()->query("outdoors") )
					return;
				break;
			default:
				error("Message: Invalid Subclass " + subclass + ".\n");
		}
	}
  
	if( query_temp("block_msg/all") || query_temp("block_msg/" + msgclass) )
		return;

           if( QueryEditing() ) {
                if( sizeof(msg_buffer) > MAX_MSG_BUFFER )
                        msg_buffer = msg_buffer[1..];
                msg_buffer += ({ msg });
        } else
	efun::tell_object( this_object(), process_mxp(msg, TOMXP));

}


void print_prompt(mixed prompt)
{
	mixed value;
	if( sizeof(msg_buffer) ) {
		tell_object(this_object(),BOLD "[输入时暂存讯息]\n" NOR);
		for(int i=0; i<(sizeof(msg_buffer)>MAX_MSG_BUFFER?  MAX_MSG_BUFFER:sizeof(msg_buffer)); i++)
		      tell_object(this_object(),msg_buffer[i]);
			msg_buffer = ({});
	}
	 value = process_mxp(sprintf("%s%s%s", MXPTAG("Prompt"), ">", MXPTAG("/Prompt")), TOMXP);
	 efun::tell_object( this_object(),  value);
	//write("> ");
	print_eor(); 
	return 0;
}

void receive_snoop(string msg)
{
	tell_object(this_object(),"%" + msg);
}
