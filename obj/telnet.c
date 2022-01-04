inherit ITEM;
#include <socket.h>

object sock;      // the socket object
object user;
string buff,log_file;       // message buffer
int connected,state;     // the connection state:
int attached;
#define T_NONE 0  // no connection
#define T_CONN 1  // trying to connect
#define T_ESTA 2  // connection established
#define T_DETA 3  // connection detached
                  // should use sock->State() instead!

#define TIMEOUT 15

void cb(int fd, int action, varargs mixed* args);
void create()
{
      //   if (!clonep()) return;

        set_name("锈铁块", ({ "telnet" }));
        set_weight(300);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "块");
                set("value", 0);
    		  set("no_clean_up",1);
		  set("no_reset",1);
                set("no_give",1);
		  set("no_drop",1);
		  set("no_steal",1);
		  set("no_get",1);

		}
    ::init_item();
}
void init()
{
	  add_action("help", "help");
        add_action("main", "telnet");
}
void tell_user(string msg)
{
    if (state == T_ESTA)
	tell_object(user, msg);
#if 0
    else
	buff=sprintf("%s%s", buff, msg);
    if (!attached && member(msg, '') != -1)
	tell_object(user, sprintf("[telnet: Beep from %s%c%s]\n",
	    host,
	    port == DEFAULT_PORT ? 0 :' ',
	    port == DEFAULT_PORT ? "":to_string(port)));
    if (log_file)
	write_file(log_file, msg);
    return;
#endif
}

int main(string str) {
  string host;
  int port;

  if (!wizardp(this_player())) return 0;

  if (!str) {
    if (!sock || state != T_DETA)
      return notify_fail("telnet: Could not find detatched session.\n");
    // reattach;
    return 1;
  }

  if (str == "-q") {
    if (!sock)
      return notify_fail("telnet: Could not find session.\n");
    sock->Close();
    sock=0;
    return 1;
  }

  if (sock) {
    switch (state) {
      default:
      case T_NONE:
        write("some bug occured!\n");
        break;
      case T_CONN:
        write("You are still trying to connect...\n");
        break;
      case T_ESTA:
        write("You are in a connection right now!\n");
        break;
      case T_DETA:
        write("You have a detatched session.\n");
        break;
    }
    return 1;
  }
      
  if (sscanf(str, "%s %d", host, port) != 2) {
    host = str;
    port = 23;
  }

  sock  = SOCKET_D->New(TCP_OPEN, host, port, #'cb, SOCKET_BINARY);
  printf("sock: %O \n",sock);
  user  = this_player();
  state = T_CONN;
  attached=1;
  write("Trying to open connection to "+host+":"+port+"...\n");
  call_out("timeout", TIMEOUT);
  input_to("input");
  return 1;
}

int help() {
  write("telnet [<address> [<port>] | -q]\n"
        "Telnet to the address given, or reactivate a dormant session.\n"
        "You may only have one session at any given time.\n"
        "Several telnet commands are available, a telnet\n"
        "command starts with the escape character (^[).\n"
        "Use \"^[?\" to get a list of available telnet commands.\n"
        "The \"-q\" option allows you to close a telnet session\n"
        "from the commandline.\n");
  return 1;
}

void timeout() {
  if (state != T_CONN) return;
  write("telnet: connection timed out.\n");
  state = T_NONE;
  if (sock) sock->Close();
  sock=0;
}

void cb(int fd, int action, varargs mixed* args) {
  int* ans, i, n, b;
  int* msg;
  if (action == SOCKET_READY) {
    if (state == T_CONN) {
      state = T_ESTA;
      while (remove_call_out("timeout") >= 0);
      tell_user("telnet: connection established.\n");
      connected=1;
    }
    return;
  }

  if (action == SOCKET_WRITTEN) return;

  if (action == SOCKET_CLOSE) {
    tell_user("telnet: connection closed.\n");
    state = 0;
    connected=0;
    return;
  }

  if (action == SOCKET_ERROR) {
    tell_object(user, "telnet: "+args[0]+"\n");
    if (sizeof(args)>2 && stringp(args[2]))
      tell_object(user, "        "+args[2]+"\n");
    state = 0;
    return;
  }

  if (action == SOCKET_READ) {
    // simulate telnet negotation - deny all
    msg = to_array(args[0]);
    ans = ({});
    n = sizeof(msg);
    for (i = 0; i < n; i++) {
      if (msg[i] != 255 || i > n-2) continue;
      b = 0;
      i++;
      if (msg[i] == 251 || msg[i] == 252) b = 254;
      else if (msg[i] == 253 || msg[i] == 254) b = 252;
      if (b) {
        ans += ({ 255, b, msg[++i] });
        msg[i] = msg[i-1] = msg[i-2] = 0;
      }
    }
    if (sizeof(ans)) {
      sock->Write(ans);
    }

    msg -= ({ 0 });
    tell_user(to_text(msg,"utf-8"));
    return;
  }

  tell_user("telnet: unrecognized action "+action+"\n");
}

void input(string str) {
  if (!sock || state < T_ESTA) return;

//#if 0
  if (str[0]=='') {
      switch(str[1]) {
	case 'c': {
	  if (!log_file)
	      write("telnet: Not logging session.\n");
	  else {
	      printf("telnet: Stopped logging session to: %s.\n", log_file);
	      log_file=0;
          }
	  input_to("input");
	  return;
	}
	case 'd': {
	  tell_object(user, "Detached.  Type 'telnet' to resume.\n");
	  attached=0;
	  return;
	}
	case 'l': {
	  if (!str[2]) {
	      if (log_file)
		  printf("telnet: Logging session to: %s.\n", log_file);
	      else
		  write("telnet: Not logging session.\n");
	  } else {
	      // str=eval_path(trimstr(str[2..]));
	       str=(str[2..]);
	      if (file_size(str) == -2)
		  str=sprintf("%s/telnet_log", str);
	      printf("telnet: Logging session to: %s.\n", str);
	      log_file=str;
	  }
	  input_to("input");
	  return;
	}
	case 'q': {
	  SOCKET_D->socket_close(sock);
	  tell_user("telnet: connection closed.\n");
	  if (!attached)
	      tell_object(user, buff);
	  user=0;
	  sock=0;
	  destruct(this_object());
	  return;
	}
	case 's': {
	  // str=eval_path(trimstr(str[2..]));
	  if (file_size(str) < 0)
	      printf("telnet: Could not find file: %s.\n", str);
	  else if (connected) {
	      string *lines;
	      lines=explode(read_file(str), "\n");
	      tell_user(sprintf("telnet: Sending file: %s.\n", str));
	      for(; sizeof(lines); lines=lines[1..])
	          SOCKET_D->socket_write(sock, sprintf("%s\n", lines[0]));
	      tell_user("telnet: File sent.\n");
	  }
	  input_to("input");
	  return;
	}
	case '!': {
	  str=str[1..];
	}
	case '?': {
	  write("telnet: Escape commands:\n"
		"All commands are preceeded by the escape (^[) character.\n"
		"\n"
		"c          Close session log.\n"
		"d          Detach telnet session.\n"
		"l<file>    Open session log into <file>.\n"
		"q          Forcefully close telnet session.\n"
		"s<file>    Send a file to telnet session.\n"
		"!<arg>     Send '!<arg>' to remote host.\n"
		"?          This help page.\n");
	  input_to("input");
	  return;
	}
      }
    }
//#endif
  if (state >= T_ESTA) {
  sock->Write(str+"\n");
#if 0
	if (log_file)
	    write_file(log_file, str);
#endif
    }
  input_to("input");
  return;
}