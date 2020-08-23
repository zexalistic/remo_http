//This is the function file, the record function
#include "process.h" 

int record_stop(int ac,char* av[]);
int record_start(int ac,char* av[]);

SUB_PROCESS_ARRAY sub_proc_record[]={
    {"start",record_start,"record start: start record function, the specific process is up to workmode.\n"},
    {"stop",record_stop,"record stop: stop record function."}
};

int record(int ac,char* av[]){
	Call_Sub(ac,av);
}

//./remo_test record start
int record_start(int ac,char* av[]){

	if(ac-3){
		printf("Wrong Format:record\n");
        usage(ac,av);
		return WRONG;
	}

    strcat(request,"record.cgi?");
    strcat(request,"-cmd=");
    strcat(request,av[2]);

    return OK;
} 

int record_stop(int ac,char* av[]){

	if(ac-3){
		printf("Wrong Format:record\n");
        usage(ac,av);
        return WRONG;
	}

    strcat(request,"record.cgi?");
    strcat(request,"-cmd=");
    strcat(request,av[2]);

    return OK;
} 
