#include "process.h" 

int get_deviceattr(int ac,char* av[]);
int set_autoshutdown(int ac,char* av[]);
int get_autoshutdown(int ac,char* av[]);
int set_systime(int ac,char* av[]);
int get_systime(int ac,char* av[]);
int reset(int ac,char* av[])
int set_screenautosleep(int ac,char* av[]);
int get_screenautosleep(int ac,char* av[]);
int set_screenbrightness(int ac,char* av[]);
int get_screenbrightness(int ac,char* av[]);
int set_buzzer(int ac,char* av[]);
int get_buzzer(int ac,char* av[]);
int getdevcapabilities(int ac,char* av[]);
int set_ledstate(int ac,char* av[]);
int get_ledstate(int ac,char* av[]);


SUB_PROCESS_ARRAY sub_proc_system[]={
    {"getdeviceattr",get_deviceattr,"system getdeviceattr:get deviceattr details.\n\
                    \texample: system getdeviceattr\n"
    },
    {"setsystime",set_systime,"system setsystime [time]:set system time.\n\
                    \t--time:           \ttime string, year-month-day-hour-min-second;\n\
                    \texample: systime setsystime 20170631110426\n"
    },
    {"getsystime",get_systime,"systime getsystime:get system time.The function was hidden in the code. So maybe you will receive a stange thing\n\
                        \tIn the code, you can get [time] [timeformat] [timezone]. timezone is an integer.\n\
                        \t--timeformat:     \tdefault=1, e.g.20170631110426;\n\
                                            \t        2, e.g.06/31/2017;\n\
                                            \t        3, e.g.2017-06-31;\n\
                        \tThe code just defines [time]=current systime, [timeformat]=default, [timezone]=Asia Shanghai(63)\n\
                        \texample: system getsystime\n"
    },
    {"setautoshutdown",set_autoshutdown,"system setautoshutdown [time]:set autoshutdown time.\n\
                    \t--time:     \t[time] min, 0 means no autoshutdown;\n\
                    \texample: system setautoshutdown 1\n"
    },
    {"getautoshutdown",get_autoshutdown,"system getautoshutdown:get autoshutdown time.\n\
                    \texample: system getautoshutdown\n"
    },
    {"reset",reset,"system reset:reset whatever parameters.\n\
                    \texample: system reset\n"
    },
    {"setscreenautosleep",set_screenautosleep,"system setscreenautosleep [time]:set screenautosleep time.\n\
                    \t--time:     \t[time] min, 0 means no screenautosleep;\n\
                    \texample: system setscreenautosleep 1\n"
    },
    {"getscreenautosleep",get_screenautosleep,"system getscreenautosleep:get screenautosleep time.\n\
                    \texample: system getscreenautosleep\n"
    },
    {"setscreenbrightness",set_screenbrightness,"system setscreenbrightness [brightness]:set screen brightness.\n\
                    \t--brightness:     \t30/60/100;\n\
                    \texample: system setscreenbrightness 60\n"
    },
    {"getscreenbrightness",get_screenbrightness,"screenbrightness getscreenbrightness:get screen brightness.\n\
                    \texample: system getscreenbrightness\n"
    },
    {"setbuzzer",set_buzzer,"system setbuzzer [enable] [lasttime]:set buzzer.\n\
                    \t--enable:     \ton=1,off=0;\n\
                    \t--lasttime:   \tduration, unit:second;\n\
                    \texample: system setbuzzer 1 5\n"
    },
    {"getbuzzer",get_buzzer,"system getbuzzer:get buzzer state.\n\
                    \texample: system getbuzzer\n"
    },
    {"getbatterycapacity",getbatterycapacity,"system getbatterycapacity:getbatterycapacity.\n\
                    \texample: system getbatterycapacity\n"
    },
    {"getdevcapabilities",getdevcapabilities,"system getdevcapabilities:getdevcapabilities.\n\
                    \texample: system getdevcapabilities\n"
    },
    {"setledstate",set_ledstate,"system setledstate [enable] :set ledstate.\n\
                    \t--enable:     \ton=1,off=0;\n\
                    \texample: system setledstate 1 \n"
    },
    {"getledstate",get_ledstate,"system getledstate:get screen enable.\n\
                    \texample: system getledstate\n"
    }     
};

int system(int ac,char* av[]){
    Call_Sub(ac,av);
}

int set_ledstate(int ac,char* av[]){

    if(ac-4){
        printf("Wrong Format:ledstate\n");
        usage(ac,av);
        return WRONG;
    }

    strcat(request,"setledstate.cgi?");
    strcat(request,"-enable=");
    strcat(request,av[3]);

    return OK;
} 

int get_ledstate(int ac,char* av[]){
    if(ac-3){
        printf("Wrong Format:ledstate\n");
        usage(ac,av);
        return WRONG;
    }

    strcat(request,"getledstate.cgi?");

    return OK;
} 

int getdevcapabilities(int ac,char* av[]){

    if(ac-2){
        printf("Wrong Format:getdevcapabilities\n");
        usage(ac,av);
        return WRONG;
    }
    strcat(request,"getdevcapabilities.cgi?");
    
    return OK;
} 

int getbatterycapacity(int ac,char* av[]){

    if(ac-2){
        printf("Wrong Format:getbatterycapacity\n");
        usage(ac,av);
        return WRONG;
    }

    strcat(request,"getbatterycapacity.cgi?");

    return OK;
} 

int get_deviceattr(int ac,char* av[]){
    if(ac-3){
        printf("Wrong Format:deviceattr\n");
        usage(ac,av);
        return WRONG;
    }

    strcat(request,"getdeviceattr.cgi?");

    return OK;
} 

int set_autoshutdown(int ac,char* av[]){

    if(ac-4){
        printf("Wrong Format:autoshutdown\n");
        usage(ac,av);
        return WRONG;
    }

    strcat(request,"setautoshutdown.cgi?");
    strcat(request,"-time=");
    strcat(request,av[3]);

    return OK;
} 

int get_autoshutdown(int ac,char* av[]){
    if(ac-3){
        printf("Wrong Format:autoshutdown\n");
        usage(ac,av);
        return WRONG;
    }

    strcat(request,"getautoshutdown.cgi?");

    return OK;
} 
 

int reset(int ac,char* av[]){

    if(ac-3){
        printf("Wrong Format:reset\n");
        usage(ac,av);
        return WRONG;
    }

    strcat(request,"reset.cgi?");

    return OK;
} 

int set_screenautosleep(int ac,char* av[]){

    if(ac-4){
        printf("Wrong Format:screenautosleep\n");
        usage(ac,av);
        return WRONG;
    }

    strcat(request,"setscreenautosleep.cgi?");
    strcat(request,"-time=");
    strcat(request,av[3]);

    return OK;
} 

int get_screenautosleep(int ac,char* av[]){
    if(ac-3){
        printf("Wrong Format:screenautosleep\n");
        usage(ac,av);
        return WRONG;
    }

    strcat(request,"getscreenautosleep.cgi?");

    return OK;
} 

int set_screenbrightness(int ac,char* av[]){

    if(ac-4){
        printf("Wrong Format:screenbrightness\n");
        usage(ac,av);
        return WRONG;
    }

    strcat(request,"setscreenbrightness.cgi?");
    strcat(request,"-brightness=");
    strcat(request,av[3]);

    return OK;
} 

int get_screenbrightness(int ac,char* av[]){
    if(ac-3){
        printf("Wrong Format:screenbrightness\n");
        usage(ac,av);
        return WRONG;
    }

    strcat(request,"getscreenbrightness.cgi?");

    return OK;
} 

int set_buzzer(int ac,char* av[]){

    if(ac-5){
        printf("Wrong Format:buzzer\n");
        usage(ac,av);
        return WRONG;
    }

    strcat(request,"setbuzzer.cgi?");
    strcat(request,"-enable=");
    strcat(request,av[3]);
    strcat(request,"-lasttime=");
    strcat(request,av[4]);

    return OK;
} 

int get_buzzer(int ac,char* av[]){
    if(ac-3){
        printf("Wrong Format:buzzer\n");
        usage(ac,av);
        return WRONG;
    }

    strcat(request,"getbuzzer.cgi?");

    return OK;
} 

int set_systime(int ac,char* av[]){

    if(ac-4){
        printf("Wrong Format:systime\n");
        usage(ac,av);
        return WRONG;
    }

    strcat(request,"setsystime.cgi?");
    strcat(request,"-time=");
    strcat(request,av[3]);;

    return OK;
} 

int get_systime(int ac,char* av[]){
    if(ac-3){
        printf("Wrong Format:systime\n");
        usage(ac,av);
        return WRONG;
    }

    printf("This function has to be open in code!!!!\n");    
    strcat(request,"getsystime.cgi?");

    return OK;
} 
