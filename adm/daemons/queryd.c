// queryd.c

#include <ansi.h>

void create() {
    seteuid(ROOT_UID);
       if (sl_open("/adm/etc/dbase.sqlite") != 1)
    {
      raise_error("Database could not be opened.\n");
    }
    
}
string name() {return("<Query-Daemon>");}
public varargs string db_query( string quest)
{
 mixed tmp = sl_exec("SELECT * FROM quest WHERE quest.name =?1;",quest);
   if (sizeof(tmp))
    return tmp[0];
   return 0;
  
}