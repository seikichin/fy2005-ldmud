// virtuald.c
// Modified by Find.
/* /system/daemon/virtual.c
 * from XO Object Library II
 * compile some virtual objects. 
 * created by trill 19970920
 * last modify by akuma on 24-04-2002
 * version 1.1 for player self-found domains
 * add virtual object for MF by akuma 2003-7-9
 */


void create()
{
	seteuid(getuid());
}

// This function is called by master object to return the "virtual" object
// of <file> when dirver failed to find such a file.

object compile_object(string file)
{

	string pname ;
	object obj,oe;
        if(file[<2..]==".c") file=file[0..<3];
        pname=file;
	if ( !file )
	{
		return 0;
	}
	else if (strlen(file) > 15 && file[0..15] == "/d/phoenix/base/" && file != "/d/phoenix/base/alive")
	{

		obj = find_object("/d/phoenix/base/alive");
		if (!obj)
			obj = load_object("/d/phoenix/base/alive");
		// this object controls the whole virtual area.

		oe = obj->get_obj(file);
		if (oe)
			return oe;
		destruct(obj);
		return 0;
	}	
	else if ( strlen(file) > 15 && file[0..15] == "/d/place/player/" )
	{
		object room = clone_object ("/d/place/player/newroom");
		if (room->restore_me(file[16..]))
			return room;
		else
		{
			destruct(room);
			return 0;
		}
	}
	else if ( strlen(file) > 15 && file[0..15] == "/d/place/domain/" )
	{		
		object room = clone_object ("/std/room/vroom");                
		room->restore_me(file[16..]);
		room->set_exits(file);
		return room;
	}
	 else if( file[0..1] == "/f" )
        {
                obj = FUBEN_D->compile_object(file);
                if( objectp(obj) ) 
                {
                        obj->setup();
                        return obj;
                }
                return 0;
        }
        else if( file[0..1] == "/p" )
        {
                obj = FUBEN_D->compile_private_object(file);
                if( objectp(obj) ) 
                {
                        obj->setup();
                        return obj;
                }
                return 0;
        }
			
	while (1)
	{
		int idx = strrstr(pname, "/", -1);
			
		if(idx == -1)
			return 0;

		if( idx != 0 )
			pname = pname[0..idx-1];
		    if( file_size(pname + ".c")>= 0)       	
			 if(obj = pname->query_maze_room(file[idx + 1..]))
			{
				obj->set("virtual_room",1);
				return obj;
			}
			
		if(!idx)
			return 0;
	}

	return 0;
}
