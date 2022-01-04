#pragma no_range_check

#include <telnet.h>
#include <time.h>

#define GMCP_LOG        50


static int dump_gmcp_log();
static int update_points_display();
public mixed QueryGMCP();

#ifdef GMCP_LOG
nosave string* gmcp_log = ({});
#endif
private nosave string last_hpsp_str = "";
private nosave string lstats = "";

private void log_gmcp(string msg)
{
#ifdef GMCP_LOG
  gmcp_log = gmcp_log[>-GMCP_LOG..<1] + ({ msg });
#endif
}

private void send_gmcp(string package, string message, varargs mixed* data)
{
#if __EFUN_DEFINED__(json_serialize)
  string pkg = lower_case(package);
  efun::binary_message( ({ IAC, SB, TELOPT_GMCP }), 1 );
  string msg = package + "." + message;
  if (sizeof(data))
    catch(msg += " " + json_serialize(data[0]));
#if __VERSION__ > "3.5.2"
  efun::binary_message(to_bytes(msg, "gbk"), 1);
#else
  efun::binary_message(msg, 1);
#endif
  log_gmcp("Sending: " + msg);
  efun::binary_message( ({ IAC, SE }), 1 );
#endif
}

static void receive_gmcp(string data)
{
  log_gmcp("Received: " + data);

#if __EFUN_DEFINED__(json_parse)
  string* words = explode(data, " ");
  mixed args, temp;

  if (sizeof(words) > 1)
    args = json_parse(implode(words[1..], " "));

  switch(lower_case(words[0]))
  {
    // Modul Core
    case "core.hello":
      break;
     case "char.training.list":
     "/cmds/gmcp/skills.c"->main();
      break; 
      case "char.help.list":
     "/cmds/gmcp/help1.c"->main();
      break;         
    default:
      log_gmcp("Received (unhandled): " + data);
      break;
  }
#endif
}

static void init_gmcp()
{
  if (!QueryGMCP())
    return;
  send_gmcp("Core", "Hello", ([ "name": MUD_NAME ]));
  add_action("dump_gmcp_log", "gmcp");
  add_action("update_points_display", "updgmcp");
}

void transfer_gmcp(string *messages)
{
  if (!previous_object() || program_name(previous_object()) != LOGIN_D".c")
    return 0;
  log_gmcp("Reset due to transfer from " + program_name(previous_object()));

  foreach (string msg: messages)
    receive_gmcp(msg);
}

#ifdef GMCP_LOG
static int dump_gmcp_log()
{
  write(implode(gmcp_log, "\n") + "\n");
  return 1;
}
#endif

varargs void process_gmcp(mapping attributes,string package, string message)
{
  mapping data,header,detail;
  int ix;
  if (!QueryGMCP())
    return;
  if (!package || !message) {
    log_gmcp("Returning: "+package+"."+message);
    return;
  }
  log_gmcp("Process: "+package+"."+message);
  switch (lower_case(package+"."+message))
  {
    // Module core:------------------------------------------
    case "room.info":
      if (mappingp(attributes))
        send_gmcp(package, message, attributes);
      return;
       case "comm.channel.text":
      if (mappingp(attributes))
        send_gmcp(package, message, attributes);
      return;
         case "char.training.list":
         send_gmcp(package, message, attributes);
      return;
        case "char.help.list":
         send_gmcp(package, message, attributes);
      return;
    case "move.info":
      if (mappingp(attributes))
        send_gmcp(package, message, attributes);
      return;
     default:
      return;
  }
}
#define PRINT_STAT(x) to_string(x)
static int update_points_display()
{
  mapping my;
  if (!interactive() || !QueryGMCP() )
    return 0;
 my = this_object()->query_entire_dbase();
  int kee=this_object()->query("kee");
  int max_kee=this_object()->query("max_kee");
  int gin=this_object()->query("gin");
  int max_gin=this_object()->query("max_gin");
  int sen=this_object()->query("sen");
  int max_sen=this_object()->query("max_sen");
  
  string hpsp_str = kee+" kee("+max_kee+") and "+gin+" gin("+max_gin+
                    ") and "+sen+" sen("+max_sen+")";
  if (last_hpsp_str!=hpsp_str)
  {
    last_hpsp_str=hpsp_str;
    process_gmcp(
      ([
        "kee":kee,
        "max_kee":max_kee,
        "gin":gin,
        "max_gin":max_gin,
        "sen":sen,
        "max_sen":max_sen,
      ]),
      "Char","Vitals");
  }
  string lstr = PRINT_STAT(({int})this_object()->query("str"));
  string lagi = PRINT_STAT(({int})this_object()->query("agi"));
  string lint = PRINT_STAT(({int})this_object()->query("int"));
  string lcon = PRINT_STAT(({int})this_object()->query("con"));
  string lcps = PRINT_STAT(({int})this_object()->query("cps"));
  string lneu = lstr+"/"+lagi+"/"+lint+"/"+lcon+"/"+lcps;
  if (lneu != lstats)
  {
    lstats = lneu;
    process_gmcp(
      ([
        "str": lstr,
        "agi": lagi,
        "wis": lint,
        "con": lcon,
        "cps": lcps,
        ]),
    "Char","Stats");
  }
  return 1;
}