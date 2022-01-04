/* --- Globale Variablen: --- */
mapping clones;
//mapping copies;
/* --- Initialisierung: --- */
protected void clone_object_create()
{
    clones = global_info["clones"] ||= ([:3]);
 //   copies = global_info["copies"] ||= ([:3]);
}
varargs object player_present(object room, int flags)
{
    for (object ob = first_inventory(room || previous_object()); ob;
	    ob = next_inventory(ob))
	if(interactive(ob) ||  query_once_interactive(ob))
	return ob;
  return 0;
}
#if ! __EFUN_DEFINED__(query_shadowing)

object query_shadowing(object ob)
{
    return efun::object_info(ob, OI_SHADOW_PREV);
}

object shadow(object ob, int flag)
{
    if(flag)
    {
        object shadower = efun::previous_object();
        efun::set_this_object(shadower);

        if (efun::shadow(ob))
            return efun::object_info(shadower, OI_SHADOW_PREV);
        else
            return 0;
    }
    else
        return efun::object_info(ob, OI_SHADOW_NEXT);
}

#endif
protected void clone_object_reset()
{
    /* Nicht referenzierte Objekte killen: */
    mixed type;
    mapping c = clones;

    clones = global_info["clones"] = ([:3]);

    foreach(object ob, string creator, int line, string trace : c)
    {
        // Ausnahmefall/Driverbug:
        if(!ob) continue;

        if(environment(ob) || query_shadowing(ob) || interactive(ob) ||
           !clonep(ob) || player_present(ob))
        {
            // OK.
            continue;
        }

        type = 1;
        catch(type = ({mixed})ob->query("no_clean_up") ||
                     ({mixed})ob->query("no_reset") ||
                     ({mixed})ob->query("virtual_room") ||
                     ({mixed})ob->is_room(); publish);

        if(type)
        {
            // Entweder OK oder Fehler.
            // Bleibt manueller Ueberpruefung ueberlassen.
            continue;
        }

        if(time() - object_time(ob) < 120)
        {
            // Schonzeit 120 Sekunden (Verkaeufer):
            clones[ob,0] = c[ob,0];
            clones[ob,1] = c[ob,1];
            clones[ob,2] = c[ob,2];
            continue;
        }

        
        log_file("clone_object",sprintf("\nClone had no environment and therefore was destroyed.\nTrace:\n%O \ncreator :\n%O \nobject_name:\n%O \nline:\n%O", trace,creator, object_name(ob), line));
                    
        catch(ob->remove(); publish);
        catch(destruct(ob); publish);
    }
}
private object clone_object_set_this_object(mixed ob, object po)
{
    set_this_object(po);
    return efun::clone_object(ob);
}


object clone_object(mixed toclone)
{

    object clone;

     if (objectp(toclone) || stringp(toclone) )
           clone = funcall(#'clone_object_set_this_object,toclone,previous_object());

    if(clone)
    {

        clones[clone,0] = efun::load_name(previous_object());
//        copies[clone,0] = efun::load_name(previous_object());
//#if __EFUN_DEFINED__(driver_info)
//        clones[clone,1] = efun::driver_info(DI_TRACE_CURRENT)[<2][TRACE_LOC];
//        clones[clone,2] = efun::driver_info(DI_TRACE_CURRENT_AS_STRING);
//#else
//        clones[clone,1] = efun::debug_info(DINFO_TRACE, DIT_CURRENT)[<2][TRACE_LOC];
//        clones[clone,2] = efun::debug_info(DINFO_TRACE, DIT_STR_CURRENT);
//#endif
    }
    return clone;
}
