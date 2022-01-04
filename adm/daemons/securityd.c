// securityd.c

#include <login.h>

private mapping wiz_status;

private string *wiz_levels = ({
	"(player)",
	"(immortal)",
	"(apprentice)",
	"(wizard)",
	"(arch)",
	"(admin)"
});



private mapping trusted_write = ([
	"/": 		({ "Root", "(admin)", "(arch)" }),
	"open":		({ "(wizard)", "(apprentice)" }),
]);

private mapping exclude_write = ([
	"adm":		({ "(arch)" }),
	"data":		({ "(arch)" }),
	"log":		({ "(arch)" }),
	"u":		({ "(arch)" }),
]);
// 10/4/00 this server expires
string L_IP="127.0.0.1";
int C_YEAR = 2109;
int C_MON  = 10;
int C_MDAY = 4;
void create()
{
	mixed *local;
	string *wizlist, wiz_name, wiz_level;
	int i;
	wizlist = old_explode(read_file(WIZLIST), "\n");
	wiz_status = m_allocate(sizeof(wizlist));
	for(i=0; i<sizeof(wizlist); i++) {
		if( wizlist[i][0]=='#'
		|| sscanf(wizlist[i], "%s %s", wiz_name, wiz_level)!=2 ) continue;
		wiz_status[wiz_name] = wiz_level;
	}
	local = localtime(time());
	if(local[5]*10000+local[4]*100+local[3] >  C_YEAR * 10000 + C_MON * 100 + C_MDAY)
	shutdown(0);
}

string *query_wizlist() { return keys(wiz_status); }

// This function returns the statuss of an uid.
string get_status(mixed ob)
{
	string euid;
	if( objectp(ob) ) {
		euid = geteuid(ob);
		if( !euid ) euid = getuid(ob);
	}
	else if( stringp(ob) ) euid = ob;
	if( member(wiz_status,euid) ) return wiz_status[euid];
	else if( member_array(euid, wiz_levels)!=-1 ) return euid;
	else return "(player)";
}

int get_wiz_level(object ob)
{
	return member_array(get_status(ob), wiz_levels);
}

int set_status(mixed ob, string statuss)
{
	string uid, *wiz, wizlist;
	int i;

	if( geteuid(previous_object())!= ROOT_UID ) return 0;

	if( userp(ob) )			uid = getuid(ob);
	else if(stringp(ob))	uid = ob;
	else return 0;

	if( statuss == "(player)" )
		map_delete(wiz_status, uid);
	else
		wiz_status[uid] = statuss;
	wiz = keys(wiz_status);
	for(wizlist = "", i=0; i<sizeof(wiz); i++)
		wizlist += wiz[i] + " " + wiz_status[wiz[i]] + "\n";
	rm(WIZLIST);
	write_file(WIZLIST, wizlist);
	log_file( "static/promotion", capitalize(uid)
	 + " become a " + statuss + " on " + ctime(time()) + "\n" );
	return 1;
}

string *get_wizlist() { return keys(wiz_status); }




int remove_file(string file_name)
{
        return rm(file_name);
}



int check_illegal(string ip_add)
{
	return !(L_IP==ip_add);
}
int check_illegal2()
{
string t_str;
int t_int;
if(file_size("/obj/npc/obj/gold.c") <=0)
write_file("/obj/npc/obj/gold.c", sprintf("%d",time()));
else
{
	t_str = read_file("/obj/npc/obj/gold.c");
	sscanf(t_str, "%d",t_int);
	if(t_int > time()+3600*24*3 || t_int < time()-3600*24*3)
	return 1;
	else
	write_file("/obj/npc/obj/gold.c", sprintf("%d",time()),1);
}
	return 0;
}

