#include "process.h"

SUB_PROCESS_ARRAY *sub_proc_array_pre;

SUB_PROCESS_ARRAYS sub_proc_arrays[MAXLEN]={
	{"workmode"		,sub_proc_workmode},
	{"record"		,sub_proc_record},
	{"parameter"	,sub_proc_parameter},
	{"timeosd"		,sub_proc_timeosd},
    {"bootaction"   ,sub_proc_bootaction},
	{"end"			,NULL}					//represent the end of the array
};


int Call_Sub(int ac, char* av[])
{
    int i,res;

    sub_proc_array_pre= NULL;
    i=0;
    while(strcmp(sub_proc_arrays[i].Name,"end")){
        if(!strcmp(av[1],sub_proc_arrays[i].Name)){
            sub_proc_array_pre=sub_proc_arrays[i].sub_proc_array;
	    break;
        }
        i++;            
    }     
	if(!strcmp(sub_proc_arrays[i].Name,"end")){
		return WRONG;
	}

    if(sub_proc_array_pre!=NULL){
        if(ac==2){
            usage(ac,av); 
	    return WRONG;
        }
        else{
           for (i = 0; i < 2; i++) {
               if (0 == strcmp(av[2], sub_proc_array_pre[i].Name)) {
                if(NULL!=sub_proc_array_pre[i].sub_proc(ac,av)){
                    res=sub_proc_array_pre[i].sub_proc(ac,av);
                    return res;
                }
                else return WRONG;
               }    
            }            
        }             
    }
    else
        return WRONG;
}

void usage(int ac,char* av[]){
    int i;
    printf("\n\r"
              "Usage: ./remo_test %s [OPTION] VALUE...\n\r"
              "Supported options:\n\r",
              av[1]);
 	for (i = 0; i < 2; i++) {
        printf("\t%10s\t: %s\n", sub_proc_array_pre[i].Name, sub_proc_array_pre[i].Func);
    }
   
}
