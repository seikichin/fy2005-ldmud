inherit F_CLEAN_UP;
int help(object me);
object *containers(object ob){
    object *ret =({});
    if(!ob) ob = previous_object();
    while(environment(ob)){
        ret += ({ environment(ob) });
        ob = environment(ob);
    }
    return ret;
}
int main(object me, string file)
{
   string err;
   object *ob;
   mapping env=([]);
   mapping con=([]);
    if (file[ < 2.. < 1] != ".c")
    return notify_fail("格式不对！\n");
    if (file[ < 2.. < 1] == ".c"){
     err = catch( call_other(file, "???") );
        if (err){
        printf( "发生错误：\n%s\n", err );
        }else{
       ob=deep_inventory(find_object(file));

       foreach(object item in ob) {
       env["file"]=base_name(item);
       env["name"]=item->name();
       env["id"]=item->get_id();
       env["short"]=item->short();
       
       for (int i=0;i<sizeof(containers(item));i++){
       con[""+i]=base_name(containers(item)[i]);
       }
       printf("con %O\n",con);
       env["env"]= con;
       printf("%O\n",json_serialize(env));
       
       }
       }       
        }
    

  return 1;
}
int help(object me)
{
    return 1;
}
