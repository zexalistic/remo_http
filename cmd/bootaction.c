//This is the function file, the getbootaction function
#include "process.h"           

int set_bootaction(int ac,char* av[]);
int get_bootaction(int ac,char* av[]);

SUB_PROCESS_ARRAY sub_proc_bootaction[]={
    {"set",set_bootaction,"bootaction set [enable]:set bootaction.\n\
    						\t--action: 	HISNET_WORKMODE_RECORD = 0 //video-recording\n\
    										HISNET_WORKMODE_RECORDLOOP = 1\n\
    										HISNET_WORKMODE_RECORDSLOW = 2\n\
    										HISNET_WORKMODE_RECORDLAPSE= 3\n\
    										HISNET_WORKMODE_RECORDSNAP = 4\n\
   		 									HISNET_WORKMODE_LAPSE = 5 /*定时抓拍*/\n\
    										HISNET_WORKMODE_TIMER = 6 /*延时抓拍*/\n\
    										HISNET_WORKMODE_IDLE = 7  /*空闲*/\n\
						\texample: bootaction set 0\n"
    					},
    {"get",get_bootaction,"bootaction get:\texample: bootaction get\n"}
};

int bootaction(int ac,char* av[]){
	Call_Sub(ac,av);
}

//./remo_test bootaction set 1
int set_bootaction(int ac,char* av[]){

	if(ac-4){
		printf("Wrong Format:bootaction\n");
        usage(ac,av);
        return WRONG;
    }

    strcat(request,"setbootaction.cgi?");
    strcat(request,"-action=");
    strcat(request,av[3]);

    return OK;
} 

int get_bootaction(int ac,char* av[]){

	if(ac-3){
		printf("Wrong Format:bootaction\n");
        usage(ac,av);
        return WRONG;
    }

    strcat(request,"getbootaction.cgi?");

    return OK;
} 
