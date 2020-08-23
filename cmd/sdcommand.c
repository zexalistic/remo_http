#include "process.h" 

int mount_sd(int ac,char* av[]);
int umount_sd(int ac,char* av[]);
int status_sd(int ac,char* av[]);
int getsdstate(int ac,char* av[]);

SUB_PROCESS_ARRAY sub_proc_sdcommand[]={
    {"mount",mount_sd,"sdcommand mount:mount sd.\n\
                    \texample: sdcommand mount\n"
    },
    {"umount",umount_sd,"sdcommand umount:umount sd.\n\
                    \texample: sdcommand umount\n"
    },
    {"status",umount_sd,"sdcommand status:sdcard format and partition.\n\
                    \texample: sdcommand status\n"
    },
    {"state",getsdstate,"sdcommand state:sdcard state and storage.\n\
                    \texample: sdcommand state\n"
    }
};

int sdcommand(int ac,char* av[]){
    Call_Sub(ac,av);
}

int getsdstate(int ac,char* av[]){

    if(ac-3){
        printf("Wrong Format:sdcommand\n");
        usage(ac,av);
        return WRONG;
    }

    strcat(request,"getsdstate.cgi?");

    return OK;
} 

int mount_sd(int ac,char* av[]){

    if(ac-3){
        printf("Wrong Format:sdcommand\n");
        usage(ac,av);
        return WRONG;
    }

    strcat(request,"sdcommand.cgi?");
    strcat(request,"-mount");

    return OK;
} 

int umount_sd(int ac,char* av[]){
    if(ac-3){
        printf("Wrong Format:sdcommand\n");
        usage(ac,av);
        return WRONG;
    }

    strcat(request,"sdcommand.cgi?");
    strcat(request,"-umount");

    return OK;
} 

int status_sd(int ac,char* av[]){
    if(ac-3){
        printf("Wrong Format:sdcommand\n");
        usage(ac,av);
        return WRONG;
    }

    strcat(request,"sdcommand.cgi?");
    strcat(request,"-format&-partition");

    return OK;
} 