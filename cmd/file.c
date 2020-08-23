#include "process.h" 

int getfileinfo(int ac,char* av[]);
int getfilecount(int ac,char* av[]);
int deleteallfiles(int ac,char* av[]);
int deletefile(int ac,char* av[]);
int getfilelist(int ac,char* av[]);


SUB_PROCESS_ARRAY sub_proc_file[]={
    {"getinfo",getfileinfo,"file getinfo [name] :get file information.\n\
                    \t--name:     \tfile path;\n\
                    \texample: file getinfo sd/DCIM/100HISDV/NORM0001.MP4\n"
    },
    {"getcount",getfilecount,"file getcount: get the number of files.\n\
                    \texample: file getcount\n"
    },
    {"getlist",getfilelist,"file getlist [start] [end] :list file.\n\
                    \t--start: 		\tinteger\n\
                    \t--end: 		\tinteger\n\
                    \texample: file getlist 0 20\n"
    },
    {"delete",getfileinfo,"file delete [name] :delete file.\n\
                    \t--name:     \tfile path;\n\
                    \texample: file delete sd/DCIM/100HISDV/NORM0001.MP4\n"
    }, 
    {"deleteall",getfileinfo,"file deleteall:delete all DV files.\n\
                    \texample: file deleteall\n"
    }
};

int file(int ac,char* av[]){
    Call_Sub(ac,av);
}

int deleteallfiles(int ac,char* av[]){

    if(ac-3){
        printf("Wrong Format:deleteallfiles\n");
        usage(ac,av);
        return WRONG;
    }

    strcat(request,"deleteallfiles.cgi?");

    return OK;
} 


int getfilecount(int ac,char* av[]){

	if(ac-3){
		printf("Wrong Format:getfilecount\n");
        usage(ac,av);
        return WRONG;
	}
    strcat(request,"getfilecount.cgi?");
    
    return OK;
} 

int getfileinfo(int ac,char* av[]){

	if(ac-4){
		printf("Wrong Format:getfileinfo\n");
        usage(ac,av);
        return WRONG;
	}

    strcat(request,"getfileinfo.cgi?");
    strcat(request,"-name=");
    strcat(request,av[3]);

	return OK;
} 

int getfilelist(int ac,char* av[]){

	if(ac-5){
		printf("Wrong Format:getfilelist\n");
        usage(ac,av);
        return WRONG;
	}

    strcat(request,"getfilelist.cgi?");
    strcat(request,"-start");
    strcat(request,av[3]);
    strcat(request,"&-end");
    strcat(request,av[4]);

    return OK;
} 

int deletefile(int ac,char* av[]){

	if(ac-4){
		printf("Wrong Format:deletefile\n");
        usage(ac,av);
        return WRONG;
	}

    strcat(request,"deletefile.cgi?");
    strcat(request,"-name");
    strcat(request,av[3]);

    return OK;
} 