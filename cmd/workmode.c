//This is the function file, the workmode function
#include "process.h" 

int get_workmode(int ac,char* av[]);
int set_workmode(int ac,char* av[]);

SUB_PROCESS_ARRAY sub_proc_workmode[]={
    {"set",set_workmode,"workmode set [workmode_master] [workmode_slave]:set work mode.\n\
                        \t--[workmode_master]\t[workmode_slave]:\n\
                        \t--0\t0 \t:photo single\n\
                        \t--0\t1 \t:photo delay\n\
                        \t--0\t2 \t:photo raw\n\
                        \t--1\t0 \t:multiphoto burst\n\
                        \t--1\t1 \t:multiphoto lapse\n\
                        \t--1\t2 \t:multiphoto continuous\n\
                        \t--2\t0 \t:record normal\n\
                        \t--2\t1 \t:record loop\n\
                        \t--2\t2 \t:record lapse\n\
                        \t--2\t3 \t:record recsnap\n\
                        \t--2\t4 \t:record slow\n\
                        \t--3\t[0-9]\t:playback\n\
                        \texample: workmode set 0 0\n"
                        },
    {"get",get_workmode,"workmode get : get work mode\n"}
}; 

int set_workmode(int ac,char* av[]){
    if(ac-5){
        printf("Wrong Format:setparameter\n");
        printf("\t%10s\t: %s\n", sub_proc_workmode[1].Name, sub_proc_workmode[1].Func);
        return WRONG;
    }

    char work_mode[3];
    strncpy(work_mode,av[3],1);
    strncpy(work_mode+1,av[4],1);
    work_mode[2]='\0';

    strcat(request,"setworkmode.cgi?");
    strcat(request,"-workmode=");
    strcat(request,work_mode);

    return OK;
}

int get_workmode(int ac,char* av[]){
    if(ac-3){
        printf("Wrong Format:setparameter\n");
        printf("\t%10s\t: %s\n", sub_proc_workmode[0].Name, sub_proc_workmode[0].Func);
        return WRONG;
    }
	strcat(request,"getworkmode.cgi?");
    return OK;
}

int workmode(int ac,char* av[]){
	Call_Sub(ac,av);	
} 



