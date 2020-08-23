//This is the function file, the getparameter function
#include "process.h" 
int set_parameter(int ac,char* av[]);
int get_parameter(int ac,char* av[]);

SUB_PROCESS_ARRAY sub_proc_parameter[]={
    {"get",get_parameter,"parameter get [workmode_master] [workmode_slave] [type]:get parameter.\n\
                        \t--[workmode_master]\t[workmode_slave]\t[type]:\n\
                        \t--0\t0\t0 \t:photo single image-mode\n\
                        \t--0\t0\t2 \t:photo single photo-scene\n\
                        \t--0\t1\t0 \t:photo delay image-mode\n\
                        \t--0\t1\t1 \t:photo delay delay-photo-time\n\
                        \t--0\t1\t2 \t:photo delay photo-scene\n\
                        \t--0\t2\t0 \t:photo raw image-mode\n\
                        \t--1\t0\t0 \t:multiphoto burst image-mode\n\
                        \t--1\t0\t1 \t:multiphoto burst burst-photo-rate-mode\n\
                        \t--1\t1\t0 \t:multiphoto lapse image-mode\n\
                        \t--1\t1\t2 \t:multiphoto lapse lapse-photo-interval\n\
                        \t--1\t2\t0 \t:multiphoto continuous image-mode\n\
                        \t--1\t2\t3 \t:multiphoto continuous continuous-photo-framerate\n\
                        \t--2\t0\t0 \t:record normal video-mode\n\
                        \t--2\t1\t0 \t:record loop video-mode\n\
                        \t--2\t1\t7 \t:record loop loop-record-type\n\
                        \t--2\t2\t0 \t:record lapse video-mode\n\
                        \t--2\t2\t1 \t:record lapse lapse-photo-interval\n\
                        \t--2\t4\t0 \t:record slow video-mode\n\
                        \texample: parameter get 0 0 0\n"
                        },
    {"set",set_parameter,"parameter set [workmode_master] [workmode_slave] [type] [value]:set parameter.\n\
                        \t--[workmode_master]\t[workmode_slave]\t[type]\t[value]:\n\
                        \t--0\t0\t0\t[0-16] \t:photo single image-mode\n\
                        \t--0\t0\t2\t[0-16] \t:photo single photo-scene\n\
                        \t--0\t1\t0\t[0-16] \t:photo delay image-mode\n\
                        \t--0\t1\t1\t[0-16] \t:photo delay delay-photo-time\n\
                        \t--0\t1\t2\t[0-16] \t:photo delay photo-scene\n\
                        \t--0\t2\t0\t[0-16] \t:photo raw image-mode\n\
                        \t--1\t0\t0\t[0-16] \t:multiphoto burst image-mode\n\
                        \t--1\t0\t1\t[0-16] \t:multiphoto burst burst-photo-rate-mode\n\
                        \t--1\t1\t0\t[0-16] \t:multiphoto lapse image-mode\n\
                        \t--1\t1\t2\t[0-16] \t:multiphoto lapse lapse-photo-interval\n\
                        \t--1\t2\t0\t[0-16] \t:multiphoto continuous image-mode\n\
                        \t--1\t2\t3\t[0-16] \t:multiphoto continuous continuous-photo-framerate\n\
                        \t--2\t0\t0\t[0-16] \t:record normal video-mode\n\
                        \t--2\t1\t0\t[0-16] \t:record loop video-mode\n\
                        \t--2\t1\t7\t[0-16] \t:record loop loop-record-type\n\
                        \t--2\t2\t0\t[0-16] \t:record lapse video-mode\n\
                        \t--2\t2\t1\t[0-16] \t:record lapse lapse-photo-interval\n\
                        \t--2\t4\t0\t[0-16] \t:record slow video-mode\n\
                        \t--value:              VIDEO_MODE_720P_120_REC = 0\n\
                                                VIDEO_MODE_720P_240_REC = 1\n\
                                                VIDEO_MODE_1080P_60_REC = 2\n\
                                                VIDEO_MODE_1080P_60_REC_SNAP = 3\n\
                                                VIDEO_MODE_1080P_120_REC = 4\n\
                                                VIDEO_MODE_1440P_60_REC = 5\n\
                                                VIDEO_MODE_1440P_60_REC_SNAP = 6\n\
                                                VIDEO_MODE_4K2K_30_REC = 7\n\
                                                VIDEO_MODE_4K2K_30_REC_SNAP = 8\n\
                                                VIDEO_MODE_4K2K_SNAP = 9\n\
                                                VIDEO_MODE_12M_SNAP = 10\n\
                                                VIDEO_MODE_16M_SNAP = 11\n\
                                                VIDEO_MODE_4K2K_MULTISNAP = 12\n\
                                                VIDEO_MODE_12M_MULTISNAP = 13\n\
                                                VIDEO_MODE_16M_MULTISNAP = 14\n\
                                                VIDEO_MODE_1440P_30_REC = 15\n\
                                                VIDEO_MODE_1440P_30_REC_SNAP = 16\n\
                                                VIDEO_MODE_BUTT\n\
                        \texample: parameter set 0 0 0 12\n"
                        },
}; 

//./remo_test parameter set 0 0 0 12
int set_parameter(int ac,char* av[]){
    char work_mode[3];

    if(ac-7){
        printf("Wrong Format:setparameter\n");
        usage(ac,av);
        return WRONG;
    }

    strncpy(work_mode,av[3],1);
    strncpy(work_mode+1,av[4],1);
    work_mode[2]='\0';

    strcat(request,"setparameter.cgi?");
    strcat(request,"-workmode=");
    strcat(request,work_mode);
    strcat(request,"&-type=");
    strcat(request,av[5]);
    strcat(request,"&-value=");
    strcat(request,av[6]);

    return OK;
} 


int get_parameter(int ac,char* av[]){
    char work_mode[3];

    if(ac-6){
        printf("Wrong Format:getparameter\n");
        usage(ac,av);
        return WRONG;
    }

    strncpy(work_mode,av[3],1);
    strncpy(work_mode+1,av[4],1);
    work_mode[2]='\0';

    strcat(request,"getparameter.cgi?");
    strcat(request,"-workmode=");
    strcat(request,work_mode);
    strcat(request,"&-type=");
    strcat(request,av[5]);

    return OK;
} 

int parameter(int ac,char* av[]){
    Call_Sub(ac,av);    
} 
