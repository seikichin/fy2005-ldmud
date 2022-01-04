#include <configuration.h>
#include <object_info.h>
#include "/sys/break_string.h"
#include "/sys/strings.h"

int file_size(string file){
if(strstr(file," ")!=-1) return -1;
return efun::file_size(file);
}

int uptime( void ){
return time()-__BOOT_TIME__;
}
object *children(string|object obj)
{
return clones(obj);
}
string wizhood(mixed ob)
{
	return SECURITY_D->get_status(ob);
}
int wiz_level(mixed ob)
{
	return SECURITY_D->get_wiz_level(ob);
}
int is_root(mixed ob)
{
        if( stringp(ob) )
                return (SECURITY_D->get_status(ob) == "(arch)" ||
                        SECURITY_D->get_status(ob) == "(admin)");

        if( objectp(ob) ) {
                if( geteuid(ob) == ROOT_UID )
                        // Root object want to execute
                        return 1;

                return (SECURITY_D->get_status(geteuid(ob)) == "(arch)" ||
                        SECURITY_D->get_status(geteuid(ob)) == "(admin)");
        }

        return 1;
}

varargs void message( mixed class, string message, mixed target,mixed exclude )
{
object *receivers = allocate(0);

if( !target ) return;
      if( stringp(target) )
		target = load_object(target);
	if( objectp(target) )
	{
	   
	     if(!living(target)){  /*start room*/
	        receivers = filter(all_inventory(target),(:living($1):));
	      	if( exclude )
	       {
		if( pointerp(exclude) )
			receivers -= exclude;
		else if( objectp(exclude) )
			receivers -= ({ exclude });
	       }
	     filter_objects(receivers,"receive_message",message,class);
	     return ;
	     } /*end room*/
	
		receivers += ({ target});
	}
	if( pointerp(target) )
	{
	receivers += target;
	}
	      	     if( exclude )
	       {
		if( pointerp(exclude) )
			receivers -= exclude;
		else if( objectp(exclude) )
			receivers -= ({ exclude });
	       }
     filter_objects(receivers,"receive_message",message,class);

}


#if ! __EFUN_DEFINED__(query_once_interactive)

int query_once_interactive(object ob)
{
    return efun::object_info(ob, OI_ONCE_INTERACTIVE);
}
int userp(object ob)
{
    return efun::object_info(ob, OI_ONCE_INTERACTIVE)|| strstr(object_name(ob), "/obj/user#")== 0;
}
#endif



#if ! __EFUN_DEFINED__(file_name)
string file_name(object ob){
return object_name(ob);
}
#endif

#if !__EFUN_DEFINED__(keys)    //mixed * m_indices(mapping map)
mixed * keys( mapping map ) {
	if(!mappingp(map)) return 0;
    return(m_indices(map));
    }
#endif    //keys

#if !__EFUN_DEFINED__(values)    //mixed * m_values(mapping map)
mixed * values( mapping map ) {
	if(!mappingp(map)) return 0;
    return(m_values(map));
    }
#endif    //values

#if ! __EFUN_DEFINED__(disable_commands)

void disable_commands()
{
    object ob = efun::previous_object();

    efun::configure_object(ob, OC_COMMANDS_ENABLED, 0);
    efun::set_this_player(0);
}
#endif  //disable_commands

#if ! __EFUN_DEFINED__(mapp)

int mapp(mixed arg)
{
  return mappingp(arg);
}

#endif  //mapp

#if !__EFUN_DEFINED__(member_array)
 int member_array(mixed item, mixed arraystring) {

  if (pointerp(arraystring)) {
    return(efun::member(arraystring,item));
  }
  else if (stringp(arraystring)) {
    return(efun::member(arraystring,to_int(item)));
  }
  else {
    set_this_object(previous_object());
    raise_error(sprintf("Bad argument 1 to member_array(): %O",arraystring));
  }
}
#endif // !__EFUN_DEFINED__(member_array)


#if ! __EFUN_DEFINED__(strsrch)

int strsrch( string str, string|int substr)
{
   if(typeof(substr)==0x3){
   return strstr(str,substr);
   }
   else if(typeof(substr)==0x2) { return member(str,substr);
   }
   return strstr(str,substr);
}

#endif  //strsrch

#if ! __EFUN_DEFINED__(error)

void error( string arg)
{
   raise_error(arg);
}

#endif  //error

#if ! __EFUN_DEFINED__(map_delete)

void map_delete( mapping m, mixed element )
{
     m_delete( m, element);
}
#endif  //map_delete

#if ! __EFUN_DEFINED__(functionp)
int functionp(mixed arg )
{
    return closurep(arg);
}
#endif  //functionp

#if ! __EFUN_DEFINED__(old_explode)
string *old_explode(string str, string del) {
  int s, t;
  string *strs;

  if (!stringp(str)) {
      set_this_object(previous_object());
      raise_error(sprintf(
         "Invalid argument 1 to old_explode()! Expected <string>, got: "
         "%.30O\n",str));
  }
  if (!stringp(del)) {
      set_this_object(previous_object());
      raise_error(sprintf(
         "Invalid argument 2 to old_explode()! Expected <string>, got: "
         "%.30O\n",del));
  }
  if(del == "")
    return ({str});
  strs=efun::explode(str, del);
  t=sizeof(strs)-1;
  while(s<=t && strs[s++] == "");s--;
  while(t>=0 && strs[t--] == "");t++;
  if(s<=t)
    return strs[s..t];
  return ({});
}
#endif  //old_explode

#if ! __EFUN_DEFINED__(evaluate)

mixed evaluate(mixed f, varargs mixed arg )
{
   return apply(f,arg);
}
#endif  //evaluate

#if ! __EFUN_DEFINED__(strlen)
int strlen(string str)
{
    return sizeof(str);
}
#endif

#if ! __EFUN_DEFINED__(replace_string)
string replace_string(string x,string y,string z )
{
    return implode(explode((x),(y)),(z));
}
#endif

int wizardp(object ob)
{
    return (wiz_level(ob)>=2);
}

// * break_string
// stretch() -- stretch a line to fill a given width 
private string stretch(string s, int width) {
  int len=sizeof(s);
  if (len==width) return s;
  string trimmed=trim(s,TRIM_LEFT," ");
  if (trimmed=="") return s; 
  int start_spaces = len - sizeof(trimmed);
  string* words = explode(trimmed, " ");
  int word_count=sizeof(words) - 1;

  if (!word_count)
    return " "*start_spaces + words[0];

  int space_count = width - len;

  int space_per_word=(word_count+space_count) / word_count;

  int rest=(word_count+space_count) % word_count; 

  foreach (int pos : rest) words[pos]+=" ";
  return (" "*start_spaces) + implode( words, " "*space_per_word );
}

private varargs string block_string(string s, int width, int flags) {

  if ( (flags & BS_LEAVE_MY_LFS)
      && !(flags & BS_NO_PARINDENT))
  {
      s = " "+regreplace(s,"\n","\n ",1);
  }


  s = sprintf( "%-*=s", width, s);

  string *tmp=explode(s, "\n");

  if (sizeof(tmp) > 1)
    return implode( map( tmp[0..<2], #'stretch/*'*/, width ), "\n" ) 
      + "\n" + tmp[<1];

  return s;
}

public varargs string break_string(string s, int w, mixed indent, int flags)
{
    if ( !s || s == "" ) return "";

    if ( !w ) w=78;

    if( intp(indent) )
       indent = indent ? " "*indent : "";

    int indentlen=stringp(indent) ? sizeof(indent) : 0;

    if (indentlen>w) {
      set_this_object(previous_object());
      raise_error(sprintf("break_string: indent longer %d than width %d\n",
                  indentlen,w));
      // w=((indentlen/w)+1)*w;
    }

    if (!(flags & BS_LEAVE_MY_LFS)) 
      s=regreplace( s, "\n", " ", 1 );

    if ( flags & BS_SINGLE_SPACE )
       s = regreplace( s, "(^|\n| )  *", "\\1", 1 );
 
    string prefix="";
    if (indentlen && flags & BS_PREPEND_INDENT) {
      if (indentlen+sizeof(s) > w || 
         (flags & BS_LEAVE_MY_LFS) && strstr(s,"\n")>-1) {
       prefix=indent+"\n";
       indent=(flags & BS_NO_PARINDENT) ? "" : " ";
       indentlen=sizeof(indent);
      }
    }

    if ( flags & BS_BLOCK ) {
      /*
           s = implode( map( explode( s, "\n" ),
                               #'block_string, w, indentlen, flags),
                      "" );
      */
      s = block_string( s , w - indentlen, flags );
    }
    else {
      s = sprintf("%-1.*=s",w-indentlen,s);
    }
    if ( s[<1] != '\n' ) s += "\n";

    if ( !indentlen ) return prefix + s;
    
    string indent2 = ( flags & BS_INDENT_ONCE ) ? (" "*indentlen) :indent;
      
    return prefix + indent + 
      regreplace( s[0..<2], "\n", "\n"+indent2, 1 ) + "\n";
      /*
       string *buf;

       buf = explode( s, "\n" );
       return prefix + indent + implode( buf[0..<2], "\n"+indent2 ) + buf[<1] + "\n";
      */
}

string domain_file(string file)
{
	string domain,temp;

	if( sscanf(file, "/d/%s/%*s", domain,temp) )
		return domain;

	return ROOT_UID;
}

int arrayp(mixed* ranks){  return pointerp(ranks);  }

closure bind(closure f, object ob) {  return bind_lambda(f,ob);  }

int atoi(string str)
{
	int v;

	if( !stringp(str) || !sscanf(str, "%d", v) ) return 0;
	return v;
}

nomask int undefinedp(mixed what)
{
  if (what == 0)
    return 1;
  return 0;
}

nomask object *users()
{
   return filter(efun::users(),
       (:
           string on = object_name($1);

           return strstr(on, "/obj/user#") == 0;
       :));
}
nomask closure do_bind_with_args(closure c, varargs mixed* args)
{
    closure cl = bind_lambda(c);
    return function mixed (varargs mixed* vargs)
               { return funcall(cl, args..., vargs...); };
}
varargs string center(mixed text, int len, string pad)
{
    int b;

    if (len<=0)
	return "";
    text = ""+text;
    if ((b=text_width(text))>=len) {
	b=(b-len)/2;
	return text[b..b+len-1];
	}
    b = (len-b) % 2;
    if (pad)
	return sprintf("%|*'"+pad+"'s",len+b,text)[b..len];
    return sprintf("%|*s",len+b,text)[b..len];
}
varargs string left(mixed text, int len, string pad)
{
    if (len<=0)
	return "";
    if (pad)
	return sprintf("%'"+pad+"':-*s",len,""+text);
    return sprintf("%:-*s",len,""+text);
}
varargs string right(mixed text, int len, string pad)
{
    if (len<=0)
	return "";
    text = ""+text; /* um eventuelle integerzahlen in string zu verwandeln */
    if (len<=text_width(text))
	return text[<len..];
    if (pad)
	return sprintf("%'"+pad+"':*s",len,text);
    return sprintf("%:*s",len,text);
}
varargs string wrap(string str, int len, int left)
{
    if(!sizeof(str))
	return str;

    if (len < 1) len = 75;
    if ((left >= len) || (left < 0)) left = 0;
    str = sprintf("%*s%-=*s\n",left,"",len-left,str);
    if (str[<2..] == "\n\n")
        return str [0..<2];
    else
        return str;
}

void destruct(object ob) {
	if(objectp(ob)) {
		ob->remove_all_call_out();
		ob->remove_all_killer();
		//use base_name(obj) to record item number
		if(objectp(environment(ob))) {
			all_inventory(environment(ob))->remove_killer(ob);
		}
		ob->dismiss_team();
              ob->remove();
	}
	efun::destruct(ob);
}
public void msg_write( string cl, string msg ) {
  /* sends the 'msg' with class 'class' to this_player()
   */

  if ( ! this_player() )
    raise_error( "Invalid call to msg_write: this_player() is 0.\n" );

  this_player()->receive_message( msg,cl);
}
