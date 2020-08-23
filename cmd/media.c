#include "process.h" 

int set_viewfield(int ac,char* av[]);
int get_viewfield(int ac,char* av[]);
int set_audioencode(int ac,char* av[]);
int get_audioencode(int ac,char* av[]);
int set_videonorm(int ac,char* av[]);
int get_videonorm(int ac,char* av[]);
int set_timeosd(int ac,char* av[]);
int get_timeosd(int ac,char* av[]);
int set_flip(int ac,char* av[]);
int get_flip(int ac,char* av[]);
int set_burstinfo(int ac,char* av[]);
int get_burstinfo(int ac,char* av[]);
int set_mainvideoformat(int ac,char* av[]);
int get_mainvideoformat(int ac,char* av[]);
int photo(int ac,char* av[]);
int set_timelapseinfo(int ac,char* av[]);
int get_timelapseinfo(int ac,char* av[]);
int get_recordtimelapse(int ac,char* av[]);
int set_recordtimelapse(int ac,char* av[]);


SUB_PROCESS_ARRAY sub_proc_media[]={
    {"setviewfield",set_viewfield,"media setviewfield [fov]:set viewfield.\n\
                                \t--fov:  120/150/170\n\
                                \texample: media setviewfield 170\n"
    },
    {"getviewfield",get_viewfield,"media getviewfield:get current video format(120/150/170)\n\
                                \texample:  media getviewfield\n"
    },
    {"setaudioencode",set_audioencode,"media setaudioencode [enable]:set audioencode.\n\
                                \t--enable:     enable=1,\n\
                                                disable=0\n\
                                \texample: media setaudioencode 0\n"
    },
    {"getaudioencode",get_audioencode,"media getaudioencode:check if audioencode is enabled.\n\
                                \texample: media getaudioencode\n"
    },
    {"setvideonorm",set_videonorm,"media setvideonorm [videonorm]:set videonorm.\n\
                                \t--videonorm:     PAL/NTSC,\n\
                                \texample: media setvideonorm PAL\n"
    },
    {"getvideonorm",get_videonorm,"media getvideonorm:check if videonorm is enabled.\n\
                                \texample: media getvideonorm\n"
    },
    {"settimeosd",set_timeosd,"media settimeosd <enable>:set time on-screen-display.\n\
                                \t--enable:     enable=1,\n\
                                                disable=0\n\
                                \texample: media settimeosd 0\n"
    },
    {"gettimeosd",get_timeosd,"media gettimeosd:get time on-screen-display state\n\
                                \texample:  media gettimeosd\n"
    },
    {"setflip",set_flip,"media setflip [enable]:set flip.\n\
                        \t--enable:     enable=1,\n\
                                        disable=0\n\
                        \texample: media setflip 0\n"
    },
    {"getflip",get_flip,"media getflip:check if flip is enabled.\n\
                           \texample: media getflip\n"
    },
    {"setburstinfo",set_burstinfo,"media setburstinfo [time] [count]:set burstinfo, take [count] pictures in [time] seconds.\n\
                                \tHowever, the value of [time] and [count] have limitaions: you can only choose form following pairs:\n\
                                \t--time\t--count\n\
                                \t1\t3\n\
                                \t1\t5\n\
                                \t1\t10\n\
                                \t1\t15\n\
                                \t1\t30\n\
                                \t2\t20\n\
                                \t2\t30\n\
                                \t3\t30\n\
                                \texample:media setburstinfo 1 3\n"
    },
    {"getburstinfo",get_burstinfo,"media getburstinfo:check if burstinfo is enabled.\n\
                           \texample: media getburstinfo\n"
    },
    {"setmainvideoformat",set_mainvideoformat,"media setmainvideoformat [format]:set mainvideoformat.\n\
                              \t--format:   H265/H264\n\
                              \texample: media setmainvideoformat H264\n"
    },
    {"getmainvideoformat",get_mainvideoformat,"media getmainvideoformat:get current video format(H264 or H265)\n\
                              \texample: media getmainvideoformat\n"
    },
    {"photo",photo,"media photo [type] [cmd]:I do not know its usage.\n\
                        \t--type:         \n\
                        \t--cmd:          \n\
                        \texample: media photo 1 2\n"
    },
    {"settimelapseinfo",set_timelapseinfo,"media settimelapseinfo [time] :set timelapseinfo.\n\
                        \texample: media settimelapseinfo 1\n"
    },
    {"gettimelapseinfo",get_timelapseinfo,"media gettimelapseinfo:check if timelapseinfo is enabled.\n\
                           \texample: media gettimelapseinfotimelapseinfo\n"
    },
    {"setrecordtimelapse",set_recordtimelapse,"media setrecordtimelapse [time] :set recordtimelapse.\
                                [time] has to be greater than u32min and less than u32max.\
                                Both u32max and u32min are in g_pstPDTCfg->stWorkModeParam.stRecModeCfg.stLapseAttr.stIntervalRange\n\
                                \texample: media setrecordtimelapse 0\n"
    },
    {"getrecordtimelapse",get_recordtimelapse,"media getrecordtimelapse : get recordtimelapse\n"}    
};

int media(int ac,char* av[]){
    Call_Sub(ac,av);
}

int set_recordtimelapse(int ac,char* av[]){
    if(ac-4){
        printf("Wrong Format:setrecordtimelapse\n");
        printf("\t%10s\t: %s\n", sub_proc_recordtimelapse[0].Name, sub_proc_recordtimelapse[0].Func);
        return WRONG;
    }

    char work_mode[3];
    strncpy(work_mode,av[3],1);
    strncpy(work_mode+1,av[4],1);
    work_mode[2]='\0';

    strcat(request,"setrecordtimelapse.cgi?");
    strcat(request,"-time=");
    strcat(request,work_mode);

    return OK;
}

int get_recordtimelapse(int ac,char* av[]){
    if(ac-3){
        printf("Wrong Format:getrecordtimelapse\n");
        printf("\t%10s\t: %s\n", sub_proc_recordtimelapse[1].Name, sub_proc_recordtimelapse[1].Func);
        return WRONG;
    }
    strcat(request,"getrecordtimelapse.cgi?");
    return OK;
}


int set_timelapseinfo(int ac,char* av[]){

    if(ac-4){
        printf("Wrong Format:timelapseinfo\n");
        usage(ac,av);
        return WRONG;
    }

    strcat(request,"settimelapseinfo.cgi?");
    strcat(request,"-time=");
    strcat(request,av[3]);

    return OK;
} 

int get_timelapseinfo(int ac,char* av[]){
    if(ac-3){
        printf("Wrong Format:timelapseinfo\n");
        usage(ac,av);
        return WRONG;
    }

    strcat(request,"gettimelapseinfo.cgi?");

    return OK;
} 

int photo(int ac,char* av[]){

    if(ac-5){
        printf("Wrong Format:photo\n");
        usage(ac,av);
        return WRONG;
    }

    strcat(request,"photo.cgi?");
    strcat(request,"-type=");
    strcat(request,av[3]);
    strcat(request,"&-cmd=");
    strcat(request,av[4]);

    return OK;
} 


int set_mainvideoformat(int ac,char* av[]){

    if(ac-4){
        printf("Wrong Format:mainvideoformat\n");
        usage(ac,av);
        return WRONG;
    }

    strcat(request,"setmainvideoformat.cgi?");
    strcat(request,"-format=");
    strcat(request,av[3]);

    return OK;
} 

int get_mainvideoformat(int ac,char* av[]){

    if(ac-3){
        printf("Wrong Format:mainvideoformat\n");
        usage(ac,av);
        return WRONG;
    }

    strcat(request,"getmainvideoformat.cgi?");

    return OK;
} 

int set_burstinfo(int ac,char* av[]){

    if(ac-5){
        printf("Wrong Format:burstinfo\n");
        usage(ac,av);
        return WRONG;
    }

    strcat(request,"setburstinfo.cgi?");
    strcat(request,"-time=");
    strcat(request,av[3]);
    strcat(request,"-count=");
    strcat(request,av[4]);

    return OK;
} 

int get_burstinfo(int ac,char* av[]){
    if(ac-3){
        printf("Wrong Format:burstinfo\n");
        usage(ac,av);
        return WRONG;
    }

    strcat(request,"getburstinfo.cgi?");

    return OK;
} 

int set_flip(int ac,char* av[]){

    if(ac-4){
        printf("Wrong Format:flip\n");
        usage(ac,av);
        return WRONG;
    }

    strcat(request,"setflip.cgi?");
    strcat(request,"-enable=");
    strcat(request,av[3]);

    return OK;
} 

int get_flip(int ac,char* av[]){
    if(ac-3){
        printf("Wrong Format:flip\n");
        usage(ac,av);
        return WRONG;
    }

    strcat(request,"getflip.cgi?");

    return OK;
} 

int set_timeosd(int ac,char* av[]){

    if(ac-4){
        printf("Wrong Format:timeosd\n");
        usage(ac,av);
        return WRONG;
    }

    strcat(request,"settimeosd.cgi?");
    strcat(request,"-enable=");
    strcat(request,av[3]);

    return OK;
} 

int get_timeosd(int ac,char* av[]){

    if(ac-3){
        printf("Wrong Format:timeosd\n");
        usage(ac,av);
        return WRONG;
    }

    strcat(request,"gettimeosd.cgi?");

    return OK;
} 

//./remo_test viewfield set 1
int set_viewfield(int ac,char* av[]){

    if(ac-4){
        printf("Wrong Format:viewfield\n");
        usage(ac,av);
        return WRONG;
    }

    strcat(request,"setviewfield.cgi?");
    strcat(request,"-fov=");
    strcat(request,av[3]);

    return OK;
} 

int get_viewfield(int ac,char* av[]){

    if(ac-3){
        printf("Wrong Format:viewfield\n");
        usage(ac,av);
        return WRONG;
    }

    strcat(request,"getviewfield.cgi?");

    return OK;
} 

int set_audioencode(int ac,char* av[]){

    if(ac-4){
        printf("Wrong Format:audioencode\n");
        usage(ac,av);
        return WRONG;
    }

    strcat(request,"setaudioencode.cgi?");
    strcat(request,"-enable=");
    strcat(request,av[3]);

    return OK;
} 

int get_audioencode(int ac,char* av[]){
    if(ac-3){
        printf("Wrong Format:audioencode\n");
        usage(ac,av);
        return WRONG;
    }

    strcat(request,"getaudioencode.cgi?");

    return OK;
} 


int set_videonorm(int ac,char* av[]){

    if(ac-4){
        printf("Wrong Format:videonorm\n");
        usage(ac,av);
        return WRONG;
    }

    strcat(request,"setvideonorm.cgi?");
    strcat(request,"-videonorm=");
    strcat(request,av[3]);

    return OK;
} 

int get_videonorm(int ac,char* av[]){
    if(ac-3){
        printf("Wrong Format:videonorm\n");
        usage(ac,av);
        return WRONG;
    }

    strcat(request,"getvideonorm.cgi?");

    return OK;
} 
