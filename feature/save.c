int save() {
	string file;
	
	if(stringp(file = this_object()->query_save_file())) {
		assure_file(file);
		this_object()->set("actions",0);
		this_object()->set("default_actions", 0);
		if(save_object(file)==0) return 1;
	}
	return 0;
}

int restore() {
	string file;
	
	if(stringp(file = this_object()->query_save_file())) {
		return restore_object(file);
	}
	return 0;
}
