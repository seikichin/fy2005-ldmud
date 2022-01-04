#include <mudlib.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object *allobjects,*players;
	object ob;
	string *aObPro, *filteredObPro = ({});
	mapping objectlist = ([]);
	string obPro;
	int obCount;
	int filteredlistCount = 0;
	//default count
	int object_count = 40;

	if (arg && to_int(arg))
	{
		object_count = to_int(arg);
	}
	allobjects = objects();
	players = filter(objects(), (: userp($1) && !wizardp($1) :));
	for(int i=0;i<sizeof(allobjects);i++)
	{
		
		ob = allobjects[i];
		obPro = base_name(ob);
		obCount =({int})objectlist[obPro];

		if(obCount){
			objectlist[obPro] = obCount + 1;
			
		}else{
			//object isn't in the list
			objectlist += ([obPro : 1 ]);
		}
	}
	printf("Total objects in current mud: %d \n",sizeof(allobjects));
	printf("Total different objects in current mud: %d \n",sizeof(objectlist));
	printf("Total players in current mud: %d \n",sizeof(players));
	printf("--- Objects over count %d --- \n",object_count);
	aObPro = keys(objectlist);
	for(int i=0;i<sizeof(objectlist);i++){
		obPro = aObPro[i];
		if(objectlist[obPro] > object_count){
			//filteredlistCount++;
			filteredObPro += ({obPro});
			
		}
	}
	
	for(int i=0;i<sizeof(filteredObPro);i++)
	{
		obPro = filteredObPro[i];
		printf("* %s : %d \n",obPro,objectlist[obPro]);
	}
	return 1;
}

int help(object me)
{
write(funcall(#'read_file,"/help/cmds/wiz/objectwatch"));
   return 1;
}
