// eventd.c

mapping action_list = ([]);
int last_time;

void auto_update_objects();
void check_whonature();
void clean_action_list();
void add_event(int event_time, object ob,closure event_function);

void create() {
	seteuid(ROOT_UID);
	last_time = time();
//	set_heart_beat(1);

	// Start the heart_beat, after one min
//	call_out("run_heart_beat", 1);
	
	// clean up the action list, need run more often when testing.
//	call_out("clean_action_list", 3600);
}

void add_event(int event_time, object ob, closure event_function) {
	mixed* event_list;
     printf("int event_time %O, object ob %O, closure event_function %O\n",event_time, ob, event_function);
	event_list = action_list[event_time];
	if(!event_list) {
		event_list = ({ ({ob, event_function}) });
	} else {
		event_list += ({ ({ob, event_function}) });
	}
	action_list[event_time] = event_list;
}

void run_heart_beat() {
	int cur_time, i, j;
	mixed* event_list;
	write("run_heart_beat 1\n");
	
	remove_call_out("run_heart_beat");
	cur_time = time();
	i = last_time + 1;
	last_time = cur_time;
	call_out("run_heart_beat", 5);
	for(; i<=cur_time; i++) {

		event_list = action_list[i];
		printf("i %O event_list%O\n",i,event_list);
		if(!event_list) {
			continue;
		}
		map_delete(action_list, i);

		for(j=0; j<sizeof(event_list); j++) {
		  printf("objectp(event_list[j][0]) %O\n",objectp(event_list[j][0]));
			if(objectp(event_list[j][0])) {
			       write("run_heart_beat 3\n");
				apply(event_list[j][1]);	
			}
		}
	}
}

int reset_heart_beat() {
	set_heart_beat(1);
	return 1;
}

void clean_action_list() {
	mixed *event_list, *keyList;
	int i, cur_time;
	
	remove_call_out("clean_action_list");
	keyList = keys(action_list);
	cur_time = time() - 10;
	for(i=0; i<sizeof(keyList); i++) {
		if(keyList[i] < cur_time) {
			map_delete(action_list, keyList[i]);
			continue;
		}
		event_list = action_list[keyList[i]];	
		event_list = filter(event_list, (: objectp($1[0]) :));
		if(sizeof(event_list)) {
			action_list[keyList[i]] = event_list;	
		} else {
			map_delete(action_list, keyList[i]);
		}
	}
//	set_heart_beat(1);
	call_out("clean_action_list", 3600);
}

mapping query_action_list() {
	mapping debug_list = ([]);
	mixed *event_list, *keyList;
	int i, j, k, cur_time;
	string delay;
	
	clean_action_list();
	cur_time = time();
	keyList = keys(action_list);
	if(sizeof(keyList)) {
		for(i=0; i<sizeof(keyList); i++) {
			event_list = action_list[keyList[i]];	
			j = keyList[i] - cur_time;
			k = keyList[i] % 1440;
			delay = sprintf("%d hour %d min %d sec --- %d:%d", j/3600, (j%3600)/60, j%60
					, k/60, k%60); 
			debug_list[delay] = event_list;
		}
	}
	return debug_list;
}

// Following are a list of functions need to be call regularly.
// They really should be move out of here and into their own object.
// For now, I will leave it here.

void auto_update_objects() {
	int delay;
	
	delay = time() + 900 + random(900);
	add_event(delay, this_object(),  #'auto_update_objects );
}

void cl(string x,string y,string z){
printf("x %O y %O z%O\n",x,y,z);
}
closure f=(:#'cl:);
nomask closure do_bind_varargs(closure c)
{
    closure cl = bind_lambda(c);
    return function mixed (varargs mixed* vargs)
               { return funcall(cl, vargs); };
}
void test(){
funcall(funcall(do_bind_varargs(f)),"xxx","yyy","zzz");
write("end");
}
void phase(int i){
printf("call phase %O\n",i);
}

void test1(int i){
add_event(i, this_object(), (:phase(i):)); 
printf("action_list %O\n",action_list);
}
void test2(){
string *list;
string err;
int i;
list = old_explode(read_file("/tmp/fullpath"), "\n");
for(i=0; i<sizeof(list); i++) {
err = catch(load_object(list[i]));
if(err){
write("Cannot load object, reason:\n"+err+"\n");
break;
} 
write(" load object : \n"+list[i]+"\n");
}

}


