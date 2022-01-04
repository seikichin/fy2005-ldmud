#include <lpctypes.h>
#include <rtlimits.h>
#define LPC_FILE           "tmp/tool.lpc"
#define NULL               (0)
#define FALSE              (0)
#define TRUE               (1)
#define ERROR              (-1)
#define PREV               previous_object()
#define TP                 efun::this_player()
#define RTP                efun::this_interactive()
#define USAGE2(x,y)  notify_fail("Usage: "+(y)+"\n");\
                     if((!(x))||((x)=="?")) return FALSE;
#define W(x)               Write(x)
#define WLN(x)             W(x+"\n")
#define WDLN(x)            W(x+".\n")
#define ENV(x)             environment(x)
#define MAX_RECURSION      (6)
#define string_replace(x,y,z) implode(explode((x),(y)),(z))
#define ME this_object()
string mixed_to_string(mixed mix, int lvl);
nosave mapping variable=([]);
static int Write(string str);
private mixed limited_eval(closure cl, int evals, varargs mixed* arg)
{
    // Sprung ueber Unlimited machen, damit die verbrauchten
    // Evals nicht fuer den normalen Ablauf mitzaehlen.
    return limited( (: apply(#'limited, $1, ({$2}), $3) :),
            ({ LIMIT_UNLIMITED }), cl, evals, arg);
}

static void Destruct(object obj)
{
  if(!obj || !this_object())
    return;
  catch(({int})obj->remove());
  if(objectp(obj) && !query_once_interactive(obj))
    destruct(obj);
}

string lit_string(string str)
{
  str=string_replace(str, "\\", "\\\\");
  str=string_replace(str, "\b", "\\b");
  str=string_replace(str, "\n", "\\n");
  str=string_replace(str, "\r", "\\r");
  str=string_replace(str, "\t", "\\t");
  return string_replace(str, "\"", "\\\"");
}

string mixed_to_string(mixed mix, int lvl)
{
  int i, j, s, t;
  string str;
  mixed *keys;

  if(lvl)
  {
    switch(typeof(mix))
    {
      default:
      case T_INVALID:
      return "<invalid>";
      case T_LVALUE:
      return "&"+mixed_to_string(mix, lvl-1);
      case T_NUMBER:
      case T_FLOAT:
      return to_string(mix);
      case T_STRING:
      return "\""+lit_string(mix)+"\"";
      case T_POINTER:
      return "({"+implode(map(mix,"mixed_to_string",ME,lvl-1),",")+"})";
      case T_OBJECT:
      return "["+object_name(mix)+"]";
      case T_MAPPING:
      s=sizeof(keys=m_indices(mix));
      t=get_type_info(mix, 1);
      str="([";
      for(i=0;i<s;i++)
      {
	str+=mixed_to_string(keys[i], lvl-1);
	if(t)
	{
	  str+=":"+mixed_to_string(mix[keys[i],0], lvl-1);
	  for(j=1;j<t;j++)
	    str+=";"+mixed_to_string(mix[keys[i],j], lvl-1);
	}
	if(i<s-1) str+=",";
      }
      return str+"])";
      case T_CLOSURE:
      case T_SYMBOL:
      return sprintf("%O", mix);
      case T_QUOTED_ARRAY:
      return "'"+mixed_to_string(funcall(lambda(0, mix)), lvl-1);
      case T_BYTES:
      case T_STRUCT:
      return sprintf("%O",mix);
    }
  }
  return "...";
}

static int Write(string str)
{
  if(!stringp(str) || str=="")
    return FALSE;
  if(!RTP && objectp(this_player()))
    write(str);
  else
    tell_object(RTP, str);
  return TRUE;
}

int Xlpc(string str)
{
  object obj;
  string file, error;
  int *ru1, *ru2, time;
  mixed res;
  
  
  USAGE2(str, "xlp(c) <lpc code>");
  file=LPC_FILE+".c";
  if(file_size(file)>0)
    rm(file);
  if(obj=find_object(LPC_FILE))
    Destruct(obj);
  write_file(file,
      "#pragma no_warn_missing_return,strong_types,warn_deprecated,rtt_checks\n#include <ansi.h>\n"
     +"mixed eval(mixed me, mixed here){"+str+";}\n");
  if(error=catch(obj=clone_object(file)))
    W("Error: "+error[1..0]);
  else
  {
    ru1=rusage();
    error=limited_eval((:catch(res=({mixed})obj->eval(RTP, ENV(RTP))):),0);
    ru2=rusage();
    if(error)
      W("Error: "+error[1..]);
    else
    {
      time=ru2[0]-ru1[0]+ru2[1]-ru1[1];
      WDLN("\nEvaluation time: "+(time<0 ? 0 : time)+" ms");
      WLN("Result: "+mixed_to_string(res, MAX_RECURSION));
      if(objectp(res))
        variable["result"] = res;
    }
  }
  rm(file);
  if(obj)
    Destruct(obj);
  return TRUE;
}