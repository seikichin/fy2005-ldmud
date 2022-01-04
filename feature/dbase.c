// dbase.c
inherit F_TREEMAP;
mapping dbase;
nosave mapping tmp_dbase;

//	The default_ob provides the default "value"s of the dbase. It is set to
//	be master copy of an object.
nosave mixed default_ob;

mixed query_default_object() { return default_ob; }

void set_default_object(mixed ob)
{
//	if( geteuid(previous_object()) != ROOT_UID )
//		error("dbase: Only this_object() or object with root euid can set default_ob.\n");
	if( !geteuid() ) seteuid(getuid());
	default_ob = ob;
	ob->add("no_clean_up", 1);
}

mixed set(string prop, mixed data)
{
	if( !mappingp(dbase) ) dbase = ([]);
	
	if( strsrch(prop, '/')!=-1 ){
	return _set( dbase, old_explode(prop, "/"), data );
	
	}
	return dbase[prop] = data;
}
mixed set_with_slash(string prop, mixed data)
{
        if( !mappingp(dbase) ) dbase = ([]);
        if( strsrch(prop, '.')!=-1 )
                return _set( dbase, old_explode(prop, "."), data );

        return dbase[prop] = data;
}
varargs mixed query_with_slash(string prop, int raw)
{
        mixed data;
        int m;
	mapping m2;

        if( !mappingp(dbase) ) return 0;

        if( undefinedp(dbase[prop]) && (strsrch(prop, '.')!=-1) ){
		m2 = _query(dbase, old_explode(prop, "/"));
		data=m2["value", 0];
		m=m2["value", 1];	
            }
        else{
		data = dbase[prop];
		m=member(dbase,prop);
            }

        if( undefinedp(m) && default_ob )
                data = default_ob->query(prop, 1);

        if( raw ) return data;

        return apply( data, this_object() );
}

varargs mixed query(string prop, int raw) {
	mixed data, pdata;
	int m;
	mapping m2;

	if(!mappingp(dbase)) {
	return 0;
	}	
	if(undefinedp(dbase[prop]) && (strsrch(prop, '/')!=-1)) {
		m2 = _query(dbase, old_explode(prop, "/"));
		data=m2["value", 0];
		m=m2["value", 1];		
	} else {
		data = dbase[prop];
		m=member(dbase,prop);
	}
	
	if(default_ob) {
		if(undefinedp(m)) {
			data = default_ob->query(prop, 1);
		} else if(mapp(data)) {
			pdata = default_ob->query(prop, 1);
			if(mapp(pdata)) {
				data = pdata + data;
			}
		}
	}

	if(raw) {
		return data;
	}

	return apply( data, this_object() );
}

int delete(string prop)
{
	if( !mappingp(dbase) ) return 0;

	if( strsrch(prop, '/')!=-1 )
		return _delete(dbase, old_explode(prop, "/"));
	else {
		map_delete(dbase, prop);
		return 1;
	}
}

mixed add(string prop, mixed data)
{
	mixed old;
	if( !mappingp(dbase) || !(old = query(prop, 1)) )
		return set(prop, data);

	if( closurep(old) )
		error("dbase: add() - called on a closure type property.\n");

	return set(prop, old + data);
}

mapping query_entire_dbase()
{
//	if( (previous_object() != this_object())
//	&&	(geteuid(previous_object()) != ROOT_UID) )
//		error("dbase: query_entire_dbase() - must has root euid or be this_object().\n");

	return dbase;
}

mixed set_temp(string prop, mixed data)
{
	if( !mappingp(tmp_dbase) ) tmp_dbase = ([]);
 	if( strsrch(prop, '/')!=-1 )
		return _set( tmp_dbase, old_explode(prop, "/"), data );

	return tmp_dbase[prop] = data;
}

varargs mixed query_temp(string prop, int raw)
{
	mixed data;
	mapping m2;
	if( !mappingp(tmp_dbase) ) return 0;
	if( strsrch(prop, '/')!=-1 ){
		m2 = _query(tmp_dbase, old_explode(prop, "/"));
		data=m2["value", 0];
	}
	else{
		data = tmp_dbase[prop];
	}

	if( closurep(data) && !raw )
		return apply(data, this_object());
	else 
		return data;
}

int delete_temp(string prop)
{
	if( !mappingp(tmp_dbase) ) return 0;

	if( strsrch(prop, '/')!=-1 )
		return _delete(tmp_dbase, old_explode(prop, "/"));
	else {
		map_delete(tmp_dbase, prop);
		return 1;
	}
}

mixed add_temp(string prop, mixed data)
{
	mixed old;

	if( !mappingp(tmp_dbase) || !(old = query_temp(prop, 1)) )
		return set_temp(prop, data);

	if( closurep(old) )
		error("dbase: add_temp() - called on a closure type property.\n");

	return set_temp(prop, old + data);
}

mapping query_entire_temp_dbase()
{
//	if( (previous_object() != this_object())
//	&&	(geteuid(previous_object()) != ROOT_UID) )
//		error("dbase: query_entire_temp_dbase() - must has root euid or be this_object().\n");

	return tmp_dbase;
}

