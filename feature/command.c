// command.c

#include <command.h>
#include <dbase.h>
#include "/secure/simul_efun/set_is_wizard.c"

protected string *path;
nosave int hook_flag = 0;

nomask int  query_wiz_level(){
return wiz_level(this_player());
}
string find_command(string verb)
{
	return ({string})COMMAND_D->find_command(verb, path);
}


nomask int command_hook(string arg)
{
    string verb, file;

    verb = query_verb();

    // going to an exit
    if( !arg 
        &&(environment() && stringp(environment()->query("exits/" + verb)))
	&&stringp(file = find_command("go"))
	&&call_other(file, "main", this_object(), verb))
        ;
    //execute a command
    else if( stringp(file = find_command(verb)) 
             && call_other(file, "main", this_object(), arg));
    //issue a emote
    //else if( EMOTE_D->do_emote( this_object(), verb, arg ) )
    //    ;
    //do channel.
    else if( CHANNEL_D->do_channel( this_object(), verb, arg ) );

    else return 0;


    return 1;
}

nomask void set_path(string *p)
{
//	if( origin() != ORIGIN_LOCAL
//	&&	geteuid(previous_object()) != ROOT_UID )
//		return;
	path = p;
}

string *query_path() { return path; }
mixed *query_commands() { 
 return transpose_array(({
 	 query_actions(this_player(),1),
 	 query_actions(this_player(),2),
 	 query_actions(this_player(),8),
 	 query_actions(this_player(),16)}));
}


int force_me(string cmd)
{
        int ret;

        if( !is_root(previous_object()) )
                return 0;

        ret = efun::command(this_object()->process_input(cmd));
        return ret;
}
nomask void enable_player()
{
	if(query_temp("disable_inputs")){
		 delete_temp("disable_inputs");}
	else
	{
	   
		if( stringp(query("id")) ) set_living_name(query("id"));
		else set_living_name(query("name"));
		enable_commands();
		// fix the double add from those enable_player() in other codes.	
		if (hook_flag==0) {
			hook_flag = 1;
			add_action("command_hook", "", 1);
			
		}
		if( !userp(this_object()) )
			set_path(NPC_PATH);
		else
		switch( wizhood(this_object()) ) {
		  		case "(admin)":
				set_path(ADM_PATH);
				 set_is_wizard(this_object(),1);
				break;
			case "(arch)":
				set_path(ARC_PATH);
				set_is_wizard(this_object(),1);
				break;
			case "(wizard)":
				set_path(WIZ_PATH);
				set_is_wizard(this_object(),1);
				break;
			case "(apprentice)":
				set_path(APR_PATH);
				set_is_wizard(this_object(),1);
				break;
			case "(immortal)":
				set_path(IMM_PATH);
				break;
			default:
				set_path(PLR_PATH);
		}
	}
}

nomask void disable_player(string type)
{
        if( geteuid(previous_object())!=ROOT_UID
        &&      previous_object()!=this_object()) return;

        set("disable_type", type);
//      I hate to do this, but to fix the call crash bug
        if(!userp(this_object()))
        	disable_commands();
        else
        	set_temp("disable_inputs",1);
}


