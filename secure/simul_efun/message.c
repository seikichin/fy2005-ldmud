// message.c
nomask varargs void printf(varargs mixed *args)
{
    if (this_player())
	write(apply(#'sprintf,args));
}
nomask void tell_object(object ob, string str)
{
    ob->receive_message(str,"tell_object");
}
nomask void write(mixed msg)
{

   switch (typeof(msg))
  {
    case T_NUMBER:
    case T_FLOAT:
      msg = sprintf("%O", msg);
      break;
    case T_STRING:
      break;
    case T_OBJECT:
      msg = "OBJ("+object_name(msg)+")";
      break;
    case T_POINTER:
      msg = "<ARRAY>:\n"+sprintf("%O",msg);
      break;
    case T_MAPPING:
      msg = "<MAPPING>:\n"+sprintf("%O",msg);
      break;
    case T_STRUCT:
      msg = "<STRUCT>";
      break;
    case T_CLOSURE:
      msg = "<CLOSURE>";
      break;
    default:
      msg = "<UNKNOWN>";
      break;
  }
    if (this_player() && msg)
	this_player()->receive_message(msg,"write");
}
string sort_msg(string input)
{

        int i;
        int sl;
        int len;
        int esc;
        string result;
        result = "";

        len = 0;
        esc = 0;
        sl = strlen(input);
        for( i = 0; i < sl; i++ ) {
                if( len >= 64 && input[i] != '\n' ) {
                        switch (input[i..i+1])
                        {
                        case "：":
                        case "”":
                        case "。":
                        case "，":
                        case "、":
                        case "；":
                        case "）":
                        case " )":
                        case "！":
                        case "？":
                                break;
                        default:
                                len = 0;
                                result += "\n";
                                break;
                        }
                }

                if( input[i] == 27)
                        esc = 1;

                if( !esc ) {
                        if( input[i] > 160 ) {
                                result += input[i..i+1];
                                i ++;
                                len += 2;
                                continue;
                        }
                        if( input[i] == '\n' ) {
                                result += "\n";
                                len = 0;
                                continue;
                        }
                }

                result += input[i..i];
                if( !esc ) len++;

                if( esc && input[i] == 'm' )
                        esc = 0;
        }

        if( i < sl )
                result += input[i..sl-1];

        return result;

}
varargs void message_vision(string msg, object me, object you)
{
	string my_gender, your_gender, my_name, your_name;
	string str1, str2, str3;
	object room;
	string *v_room;
	int i;
	my_name= me->name();
	my_gender = me->query("gender");
		
	if (you && you == me)
	{
		str1 = replace_string(msg,"$p","$P");
		str1 = replace_string(str1,"$n","$N");
		str1 = replace_string(str1,  "$P", gender_self(my_gender));
		str1 = replace_string(str1, "$N", gender_self(my_gender));
	} else
	{	
		str1 = replace_string(msg,  "$P", gender_self(my_gender));
		str1 = replace_string(str1, "$N", gender_self(my_gender));
	}
	
	str3 = replace_string(msg,  "$P", my_name);
	str3 = replace_string(str3, "$N", my_name);
	
	if( you ) {
		your_name= you->name();
		your_gender= you->query("gender");
		str2 = replace_string(msg,  "$P", gender_pronoun(my_gender));
		str2 = replace_string(str2, "$p", gender_self(your_gender));
		str2 = replace_string(str2, "$N", my_name);
		str2 = replace_string(str2, "$n", gender_self(your_gender));
		if (you != me)
			message("vision", str2, you);
		str1 = replace_string(str1, "$p", gender_pronoun(your_gender));
		str1 = replace_string(str1, "$n", your_name);
		str3 = replace_string(str3, "$p", your_name);
		str3 = replace_string(str3, "$n", your_name);
	}
	
	message("vision", str1, me);
	if(room=environment(me))
	{
		message("vision", str3,  environment(me), ({ me, you}) );
		if(v_room=room->query("viewer"))
		for(i=0;i<sizeof(v_room);i++)
			tell_room(v_room[i],str3);
	}
}


varargs void message_sort(string msg, object me, object you)
{
        string my_gender, your_gender, my_name, your_name;
        string str1, str2, str3;

        if( !objectp(me) || !environment(me) ) return;

        my_name= me->name();
        my_gender = me->query("gender");
        str1 = replace_string(msg,  "$P", gender_self(my_gender));
        str1 = replace_string(str1, "$N", gender_self(my_gender));
        str3 = replace_string(msg,  "$P", my_name);
        str3 = replace_string(str3, "$N", my_name);
        if( you ){
                your_name= you->name();
                your_gender= you->query("gender");
                str2 = replace_string(msg,  "$P", gender_pronoun(my_gender));
                str2 = replace_string(str2, "$p", gender_self(your_gender));
                str2 = replace_string(str2, "$N", my_name);
                str2 = replace_string(str2, "$n", gender_self(your_gender));
                message("vision", sort_msg(str2), you);
                str1 = replace_string(str1, "$p", gender_pronoun(your_gender));
                str1 = replace_string(str1, "$n", your_name);
                str3 = replace_string(str3, "$p", your_name);
                str3 = replace_string(str3, "$n", your_name);
        }
        message("vision", sort_msg(str1), me);
        message("vision", sort_msg(str3),  environment(me), ({ me, you}) );
}

