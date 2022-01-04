#pragma save_types

/* obj/simul_efun.c
 *
 * The simul-efun object provides functions which can be accessed as
 * if they were true efuns. This is most useful to protect sensitive
 * efuns from clumsy fingers, but is also used to simulate functions
 * which formerly were implemented by the driver.
 */

#define MAX_LOG_SIZE 50000
#define BACKBONE_WIZINFO_SIZE 8
#define GLOBAL_INFO 2
#define LIVING_NAME 3
#define NAME_LIVING 4
#define MEMORY_BUFF 5
#define NETDEAD_MAP 6
#define IP_NAMES    7
mixed *info;
mapping living_name_m, name_living_m, netdead,global_info;
#include <ansi.h>
#include "/sys/wizlist.h"
#include "/sys/erq.h"
#include "/sys/files.h"
#include "/sys/configuration.h"
#include "/sys/interactive_info.h"
#include "/sys/object_info.h"
#include "/sys/driver_info.h"
#include "/secure/simul_efun/sefuns.c"
#include "/secure/simul_efun/xlpc.c"
#include "/secure/simul_efun/seteuid.c"
#include "/secure/simul_efun/gender.c"
#include "/secure/simul_efun/file.c"
#include "/secure/simul_efun/chinese.c"
#include "/secure/simul_efun/util.c"
#include "/secure/simul_efun/message.c"
#include "/secure/simul_efun/path.c"
#include "/secure/simul_efun/query_editing.c"
#include "/secure/simul_efun/query_input_pending.c"
#include "/secure/simul_efun/clone_object.c"
#include "/secure/simul_efun/process_mxp.c"
private void CleanLivingData();
  /* Living -> Name and Name -> Living mappings.
   */
protected void reset()
{
    set_next_reset(60);

   CleanLivingData();
    clone_object_reset();
}
//---------------------------------------------------------------------------
void start_simul_efun()
{
    
   
    if ( !(info = get_extra_wizinfo(0)) )
	set_extra_wizinfo(0, info = allocate(BACKBONE_WIZINFO_SIZE));
    if (!(global_info = info[GLOBAL_INFO]))
    	global_info = info[GLOBAL_INFO] = m_allocate(0, 1);
    if (!(living_name_m = info[LIVING_NAME]))
	living_name_m = info[LIVING_NAME] = m_allocate(0, 1);
    if (!(name_living_m = info[NAME_LIVING]))
	name_living_m = info[NAME_LIVING] = m_allocate(0, 1);
   if (!(netdead = info[NETDEAD_MAP]))
    netdead = info[NETDEAD_MAP] =m_allocate(0, 1);
   clone_object_create();
}

//---------------------------------------------------------------------------
void ls (string path)
/* Print the directory listing of <path>, like the unix command. */
{
    int max, i, len, tmp;
    status trunc_flag;
    mixed *dir;
    set_this_object(previous_object());
    dir = get_dir (path, GETDIR_NAMES|GETDIR_SIZES);
    if (path != "/")
	path += "/";
    if (!dir) {
        write("No such directory.\n");
        return;
    }
    if (sizeof(dir) > 999)
    {
        dir = dir[0..998];
        trunc_flag = 1;
    }
    for(i = sizeof(dir); i--; ) {
        if(dir[i--] == -2)
            dir[i]+="/";
        len = sizeof(dir[i]);
        if (len > max)
            max = len;
    }
    ++max;
    if (max > 79)
        max = 79;
    for (i=0; i < sizeof(dir); i+=2) {
	string name;
            name = dir[i];
	tmp = sizeof(name);
	if (len + tmp > 79) {
	    len = 0;
	    write("\n");
	}
	write(name);
        if (len + max > 79) {
            write("\n");
            len = 0;
        } else {
            write("                                                                                "[80-max+tmp..]);
            len += max;
        }
    }
    write("\n");
    if (trunc_flag) write("***TRUNCATED***\n");
}

//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
void localcmd()
{
    string *verbs;
    int i,j;

    verbs = query_actions(this_player());
    for (i=0, j = sizeof(verbs); --j >= 0; i++) {
	write(verbs[i]+" ");
    }
    write("\n");
}

//---------------------------------------------------------------------------
mixed *unique_array(mixed *arr,string func,mixed skipnum)
{
    mixed *al, last;
    mapping m;
    int i, j, k, *ordinals;

    if (sizeof(arr) < 32)
        return efun::unique_array(arr, func, skipnum);
    for (ordinals = allocate(i = sizeof(arr)); i--; )
	    ordinals[i] = i;
    m = mkmapping(map_objects(arr, func), ordinals, arr);
    al = m_indices(m);
    ordinals = m_values(m, 0);
    arr = m_values(m, 1);
    if (k = i = sizeof(al)) {
        for (last = al[j = --i]; i--; ) {
            if (al[i] != last) {
                if (last != skipnum) {
                    arr[--k] = arr[i+1..j];
                    ordinals[k] = ordinals[j];
                }
                last = al[j = i];
            }
        }
        if (last != skipnum) {
            arr[--k] = arr[0..j];
            ordinals[k] = ordinals[j];
        }
    }
    return m_values(mkmapping(ordinals[k..], arr[k..]),0);
}

//---------------------------------------------------------------------------
varargs mixed snoop(mixed snoopee)
{
    int result;

    if (snoopee && interactive(snoopee) && interactive_info(snoopee, II_SNOOP_NEXT)) {
        write("Busy.\n");
        return 0;
    }
    result = snoopee ? efun::snoop(this_player(), snoopee)
                     : efun::snoop(this_player());
    switch (result) {
	case -1:
	    write("Busy.\n");
	    break;
	case  0:
	    write("Failed.\n");
	    break;
	case  1:
	    write("Ok.\n");
	    break;
    }
    if (result > 0) return snoopee;
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
string version() {
    return __VERSION__;
}

//---------------------------------------------------------------------------
string query_host_name() {
    return __HOST_NAME__;
}

//---------------------------------------------------------------------------
nomask void set_environment() {}

nomask void set_this_player() { write("nomask void set_this_player \n"); }

//---------------------------------------------------------------------------
varargs void add_worth(int value, object ob)
{
    mixed old;
#ifdef __COMPAT_MODE__
    switch (explode(object_name(previous_object()), "/")[0]) {
#else
    switch (explode(object_name(previous_object()), "/")[1]) {
#endif
      default:
	raise_error("Illegal call of add_worth.\n");
      case "obj":
      case "std":
      case "room":
    }
    if (!ob) {
	if ( !(ob = previous_object(1)) )
	    return;
    }
    if (intp(old = get_extra_wizinfo(ob)))
        set_extra_wizinfo(ob, old + value);
}
//---------------------------------------------------------------------------
void shout(string s)
{
    filter(users(), lambda(({'u}),({#'&&,
      ({#'environment, 'u}),
      ({#'!=, 'u, ({#'this_player})}),
      ({#'tell_object, 'u, to_string(s)})
    })));
}

//---------------------------------------------------------------------------
void set_living_name(string name)
{
    string old;
    mixed a;
    int i;

    if (old = living_name_m[previous_object()]) {
	if (pointerp(a = name_living_m[old])) {
	    a[member(a, previous_object())] = 0;
	} else {
	    efun::m_delete(name_living_m, old);
	}
    }
    living_name_m[previous_object()] = name;
    if (a = name_living_m[name]) {
	if (!pointerp(a)) {
	    name_living_m[name] = ({a, previous_object()});
	    return;
	}
	/* Try to reallocate entry from destructed object */
	if ((i = member(a, 0)) >= 0) {
	    a[i] = previous_object();
	    return;
	}
	name_living_m[name] = a + ({previous_object()});
	return;
    }
    name_living_m[name] = previous_object();
}

//---------------------------------------------------------------------------
object find_living(string livname) {
  mixed *a, r;
  int i;

  if (pointerp(r = name_living_m[livname])) {
    if (member(r,0)>=0)
      r-=({0});
    if (!sizeof(r)){
      m_delete(name_living_m,livname);
      return 0;
    }
    if ( !living(r = (a = r)[0])) {
      for (i = sizeof(a); --i;) {
       if (living(a[<i])) {
         r = a[<i];
         a[<i] = a[0];
         return a[0] = r;
       }
      }
    }
    return r;
  }
  return living(r) && r;
}
object find_real_living(string livname){
 object ob,*child;
 ob=find_living(livname);
 child=children(ob);
 if(sizeof(child)) return child[0];
 return ob;
}


mixed *dump_livings()
{
  return sort_array(m_indices(name_living_m),#'>);
}
private void clean_name_living_m(string *keys, int left, int num)
{
  int i, j;
  mixed a;

  while (left && num--)
  {
    if (pointerp(a = name_living_m[keys[--left]]) && member(a, 0)>=0)
    {
      a-=({0});
      name_living_m[keys[left]] = a;
    }
    if (!a || (pointerp(a) && !sizeof(a)))
    {
       m_delete(name_living_m, keys[left]);
    } 
  }
  if (left)
    efun::call_out(#'clean_name_living_m, 1, keys, left, 80);

}

private void clean_netdead() {
  int i;
  string *s;
  object ob;

  s=m_indices(netdead);
  for (i=sizeof(s)-1;i>=0;i--)
    if (!objectp(ob=netdead[s[i]]) || interactive(ob))
      m_delete(netdead,s[i]);
}
void remove_living_name()
{
  string livname;

  if (!previous_object())
    return;
  if (livname=living_name_m[previous_object()])
  {
    m_delete(living_name_m,previous_object());
    if (objectp(name_living_m[livname]))
    {
      if (name_living_m[livname]==previous_object())
       m_delete(name_living_m,livname);
      return;
    }
    if (pointerp(name_living_m[livname]))
    {
      name_living_m[livname]-=({previous_object()});
      if (!sizeof(name_living_m[livname]))
       m_delete(name_living_m,livname);
    }
  }
}

object *livings()
{
    return m_indices(living_name_m);
}
void _set_netdead()
{
  if (query_once_interactive(previous_object()))
    netdead[geteuid(previous_object())]=previous_object();
}

void _remove_netdead()
{
  m_delete(netdead,geteuid(previous_object()));
}


object find_netdead(string uuid)
{
  int i;
  string uid;
  // Wenn sscanf() 2 liefert, ist uuid auch ne uuid.
  int is_uuid = sscanf(uuid, "%s_%d", uid, i) == 2;
  if (!is_uuid)
    uid = uuid;
 
  if (is_uuid && geteuid(netdead[uid]) != uuid)
      return 0;

  return netdead[uid];
}

string *dump_netdead()
{
  return m_indices(netdead);
}

private void CleanLivingData() {
  if (find_call_out(#'clean_name_living_m) < 0) {
    efun::call_out(#'clean_name_living_m,
                 1,
                 m_indices(name_living_m),
                 sizeof(name_living_m),
                 80
                 );
  }
}

//---------------------------------------------------------------------------
object find_player(string name)
{
    mixed *a, r;
    int i;

    if (pointerp(r = name_living_m[name])) {
	if ( !(r = (a = r)[0]) || !efun::object_info(r, OI_ONCE_INTERACTIVE)) {
	    for (i = sizeof(a); --i;) {
		if (a[<i] && efun::object_info(a[<i], OI_ONCE_INTERACTIVE)) {
		    r = a[<i];
		    a[<i] = a[0];
		    return a[0] = r;
		}
	    }
	    return 0;
	}
	return r;
    }
    return r && efun::object_info(r, OI_ONCE_INTERACTIVE) && r;
}

/*===========================================================================
 * The following functions provide the necessary compatibility of this
 * compat-mode mudlib with a plain driver.
 * Just the parse_command() efun is not simulated.
 */

#ifndef __COMPAT_MODE__
//---------------------------------------------------------------------------
string function_exists (string str, object ob)
{
    string rc;

    rc = efun::function_exists(str, ob);
    return stringp(rc) ? rc[1..] : 0;
}

//---------------------------------------------------------------------------
string object_name(object ob)
{
    string rc;

    rc = efun::object_name(ob);
    return stringp(rc) ? rc[1..] : 0;
}

//---------------------------------------------------------------------------
string program_name(object ob)
{
    string rc;

    rc = efun::program_name(ob);
    return stringp(rc) ? rc[1..] : 0;
}

//---------------------------------------------------------------------------
string* inherit_list(object ob)
{
    string *rc;
    int i;

    rc = efun::inherit_list(ob);
    for (i = sizeof(rc); i-- > 0; )
        rc[i] = rc[i][1..];
    return rc;
}

//---------------------------------------------------------------------------
string to_string(mixed arg)
{
    string rc;

    rc = efun::to_string(arg);
    return objectp(arg) ? rc[1..] : rc;
}

//---------------------------------------------------------------------------
string creator(object ob)
{
    return getuid(ob);
}

//---------------------------------------------------------------------------
varargs void add_action(string fun, string cmd, int flag)
{
    if (fun == "exit")
        raise_error("Illegal to define a command to the exit() function.\n");

    efun::set_this_object(previous_object());
    if (cmd)
        efun::add_action(fun, cmd, flag);
}

//---------------------------------------------------------------------------
object present_clone (mixed obj, object env)
{
  if (stringp(obj) && '/' != obj[0])
      obj = "/"+obj;
  return efun::present_clone(obj, env);
}

//---------------------------------------------------------------------------
#endif /* __COMPAT_MODE__ */

#if !__EFUN_DEFINED__(present)
//---------------------------------------------------------------------------
varargs object present(mixed ob, object env)
{
    int specific, num, i;
    object found;
    string str;

    if (!env)
    {
        env = previous_object();
        specific = 0;
    }
    else
        specific = 1;

    if (objectp(ob))
    {
        /* Quick check: is ob there or not? */

        if (specific)
            return environment(ob) == env ? ob : 0;
        if (environment(ob) == env
         || (environment(env) && environment(ob) == environment(env))
           )
            return ob;
        return 0;
    }

    /* Search by name. Prepare the search parameters */
    if (2 != sscanf(ob, "%s %d", str, num))
    {
        num = 1;
        str = ob;
    }

    /* First, search in env by name */
    for (found = first_inventory(env), i = 0
        ; found
        ; found = next_inventory(env))
    {
        if (found->id(str) && ++i == num)
            break;
        if (!found)  /* may happen */
            break;
    }

    if (found || specific)
        return found;

    /* If not found, search in environment(env) by name */
    env = environment(env);
    if (!env)
        return 0;
    if (env->id(ob))
        return env;
    if (!env) /* the id() may have destructed env */
        return 0;

    for (found = first_inventory(env), i = 0
        ; found
        ; found = next_inventory(env))
    {
        if (found->id(str) && ++i == num)
            break;
        if (!found)  /* may happen */
            break;
    }

    return found;
}

#endif /* !efun_defined(present) */

#if !__EFUN_DEFINED__(transfer)
//---------------------------------------------------------------------------
/*
 * Transfer an object from an object to an object.
 * Call add_weight(), drop(), get(), prevent_insert(), add_weight(),
 * and can_put_and_get() where needed.
 * Return 0 on success, and special code on failure:
 *
 * 1: To heavy for destination.
 * 2: Can't be dropped.
 * 3: Can't take it out of it's container.
 * 4: The object can't be inserted into bags etc.
 * 5: The destination doesn't allow insertions of objects.
 * 6: The object can't be picked up.
 */
int transfer(object item, object dest)
{
    int weight;
    object from;

    efun::set_this_object(previous_object());

    weight = item->query_weight();
    if (!item)
        return 3;

    from = environment(item);
    if (from)
    {
        /*
         * If the original place of the object is a living object,
         * then we must call drop() to check that the object can be dropped.
         */
        if (living(from))
        {
            if (item->drop() || !item)
                return 2;
        }
        /*
         * If 'from' is not a room and not a player, check that we may
         * remove things out of it.
         */
        else if (environment(from))
        {
            if (!from->can_put_and_get() || !from)
                return 3;
        }
    }

    /*
     * If the destination is not a room, and not a player,
     * Then we must test 'prevent_insert', and 'can_put_and_get'.
     */
    if (environment(dest) && !living(dest))
    {
        if (item->prevent_insert())
            return 4;
        if (!dest->can_put_and_get() || !dest)
            return 5;
    }

    if (living(dest))
    {
        if (!item->get() || !item)
            return 6;
    }

    /*
     * If it is not a room, correct the total weight in the destination.
     */
    if (environment(dest) && weight)
    {
        if (!dest->add_weight(weight) || !dest)
            return 1;
    }

    /*
     * If it is not a room, correct the weight in the 'from' object.
     */
    if (from && environment(from) && weight)
    {
        from->add_weight(-weight);
    }

    move_object(item, dest);

    return 0;
}

#endif /* !efun_define(transfer) */

#if !__EFUN_DEFINED__(extract)
//---------------------------------------------------------------------------
mixed extract (mixed data, varargs mixed*from_to)

{
    int from, to;

    if (!stringp(data) && !pointerp(data))
    {
        raise_error("Illegal type for extract(): must be string or array.\n");
        return 0;
    }

    switch(sizeof(from_to))
    {
    case 0: return data;
    case 1:
        if (!intp(from_to[0]))
        {
            raise_error("Illegal 'from' index for extract(): must be a number.\n");
            return 0;
        }
        from = from_to[0];
        if (from >= 0)
            return data[from..];
        return data[<-from..];
    case 2:
        if (!intp(from_to[0]) || !intp(from_to[1]))
        {
            raise_error("Illegal index for extract(): must be a number.\n");
            return 0;
        }
        from = from_to[0];
        to = from_to[1];
        if (from >= 0)
        {
            if (to >= 0)
                return data[from..to];
            return data[<from..<-to];
        }
        if (to >= 0)
            return data[<-from..to];
        return data[<from..<-to];
    }

    raise_error("Illegal number of arguments for extract().\n");
    return 0;
}

#endif /* !efun_defined(extract) */

#if ! __EFUN_DEFINED__(set_heart_beat)
//---------------------------------------------------------------------------
int set_heart_beat(int flag)
{
    object ob = efun::previous_object();
    int hb = efun::object_info(ob, OC_HEART_BEAT);

    if (!flag == !hb)
        return 0;

    efun::configure_object(ob, OC_HEART_BEAT, flag);

    return 1;
}

#endif

#if ! __EFUN_DEFINED__(enable_commands)
//---------------------------------------------------------------------------
void enable_commands()
{
    object ob = previous_object();
     efun::configure_object(ob, OC_COMMANDS_ENABLED, 1);
    efun::set_this_player(ob);

}

#endif

#if ! __EFUN_DEFINED__(query_ip_name)
//---------------------------------------------------------------------------
varargs string query_ip_name(object player)
{
    return interactive_info(player || this_player(), II_IP_NAME);
}

#endif

#if ! __EFUN_DEFINED__(query_ip_number)
//---------------------------------------------------------------------------
varargs string query_ip_number(object player)
{
  if(objectp(player) && interactive(player))
  {
    return interactive_info(player || this_player(), II_IP_NUMBER);
   }
   
   return "0.0.0.0";
}

#endif

#if ! __EFUN_DEFINED__(query_idle)
//---------------------------------------------------------------------------
int query_idle(object ob)
{
    return interactive_info(ob, II_IDLE);
}

#endif

#if ! __EFUN_DEFINED__(query_load_average)
//---------------------------------------------------------------------------
string query_load_average()
{
    return sprintf("%.2f cmds/s, %.2f comp lines/s",
        driver_info(DI_LOAD_AVERAGE_COMMANDS),
        driver_info(DI_LOAD_AVERAGE_LINES));
}

#endif

#if ! __EFUN_DEFINED__(query_snoop)
//---------------------------------------------------------------------------
object query_snoop(object ob)
{
    if(!interactive(ob))
        return 0;

    object prev = previous_object();
    set_this_object(prev);

    return interactive_info(ob, II_SNOOP_PREV);
}
#endif

#if ! __EFUN_DEFINED__(cat)
//---------------------------------------------------------------------------
#define CAT_MAX_LINES 50
varargs int cat(string file, int start, int num)
{
    set_this_object(previous_object());
    int more;

    if (num < 0 || !this_player())
        return 0;

    if (!start)
        start = 1;

    if (!num || num > CAT_MAX_LINES) {
        num = CAT_MAX_LINES;
        more = sizeof(read_file(file, start+num, 1));
    }

    string txt = read_file(file, start, num);
    if (!txt)
        return 0;

    tell_object(this_player(), txt);

    if (more)
        tell_object(this_player(), "*****TRUNCATED****\n");

    return sizeof(txt & "\n");
}
#endif

#define TAIL_MAX_BYTES 1000
varargs int tail(string file)
{
    if (extern_call())
        set_this_object(previous_object());

    if (!stringp(file) || !this_player())
        return 0;

    bytes bs = read_bytes(file, -(TAIL_MAX_BYTES + 80),
                          (TAIL_MAX_BYTES + 80));
    // read_bytes() returns 0 if the start of the section given by
    // parameter #2 lies before the beginning of the file.
    // In this case we simply try and read the entire file.
    if (!bytesp(bs) && file_size(file) < TAIL_MAX_BYTES+80)
      bs = read_bytes(file, 0, (TAIL_MAX_BYTES + 80));
    // Exit if still nothing could be read.
    if (!bytesp(bs))
      return 0;

    // convert to string
    string txt = to_text(bs, "UTF-8");

    // cut off first (incomplete) line
    int index = strstr(txt, "\n");
    if (index > -1) {
        if (index + 1 < sizeof(txt))
            txt = txt[index+1..];
        else
            txt = "";
    }

    efun::tell_object(this_player(), txt);

    return 1;
}
#undef TAIL_MAX_BYTES

/*************************************************************************/
