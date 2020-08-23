//This is the function file, the setwifichannel function

#include "process.h" 

int set_wifichannel(int ac,char* av[]);
int get_wifichannel(int ac,char* av[]);
int wifisleep(int ac,char* av[]);
int set_wifi(int ac,char* av[]);
int get_wifi(int ac,char* av[]);

SUB_PROCESS_ARRAY sub_proc_wifi[]={
    {"setchannel",set_wifichannel,"wifi setchannel [wifichannel]:set wifichannel.\n\
						          \t--wifichannel: channel number\n\
						          \texample: wifichannel set 0\n"
    },
    {"getchannel",get_wifichannel,"wifi getchannel: get the number of wifichannel\n\
                                  \texample:  wifichannel get\n"
    },
    {"sleep",wifisleep,"example: wifi sleep\n"
    },
    {"setproperty",set_wifi,"wifi setproperty [enablewifi] [secretmode] [whichkey] [linkstatus] [wifissid] [wifikey]:set wifi property.\n\
                    \t--enablewifi:     \ton=1,off=0;\n\
                    \t--secretmode:     \tWEP=1,WPA2=2;\n\
                    \t--whichkey:       \tUsing which key in WEP mode(4 in all).Default 0 in WPA2 mode.\n\
                    \t--linkstatus:     \twifi link status. Connect=1, disconnect=0.\n\
                    \t--wifissid:       \twifissid,input a string.
                    \t--wifikey:        \tyour wifi password.
                    \texample: wifi setproperty 1 1 1 1 lalala remo123\n"
    },
    {"getproperty",get_wifi,"wifi getproperty:get wifi property.\n\
                    \texample: wifi getproperty\n"
    }
};

int wifi(int ac,char* av[]){
	Call_Sub(ac,av);
}

int wifisleep(int ac,char* av[]){
    if(ac-2){
        printf("Wrong Format:wifisleep\n");
        usage(ac,av);
        return WRONG;
    }
    strcat(request,"wifisleep.cgi?");
    
    return OK;
} 

//./remo_test wifichannel set 1
int set_wifichannel(int ac,char* av[]){

	if(ac-4){
		printf("Wrong Format:wifichannel\n");
        usage(ac,av);
        return WRONG;
    }

    strcat(request,"setwifichannel.cgi?");
    strcat(request,"-wifichannel=");
    strcat(request,av[3]);

    return OK;
} 

int get_wifichannel(int ac,char* av[]){

	if(ac-3){
		printf("Wrong Format:wifichannel\n");
        usage(ac,av);
        return WRONG;
    }

    strcat(request,"getwifichannel.cgi?");

    return OK;
} 

int set_wifi(int ac,char* av[]){

    if(ac-9){
        printf("Wrong Format:wifi\n");
        usage(ac,av);
        return WRONG;
    }

    strcat(request,"setwifi.cgi?");
    strcat(request,"-enablewifi=");
    strcat(request,av[3]);
    strcat(request,"-secretmode=");
    strcat(request,av[4]);
    strcat(request,"-whichkey=");
    strcat(request,av[5]);
    strcat(request,"-linkstatus=");
    strcat(request,av[6]);
    strcat(request,"-wifissid=");
    strcat(request,av[7]);
    strcat(request,"-wifikey=");
    strcat(request,av[8]);

    return OK;
} 

int get_wifi(int ac,char* av[]){
    if(ac-3){
        printf("Wrong Format:wifi\n");
        usage(ac,av);
        return WRONG;
    }

    strcat(request,"getwifi.cgi?");

    return OK;
} 