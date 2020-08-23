//This file contains all process
#ifndef PROCESS_H
#define PROCESS_H

#include "workmode_define.h"

	#ifndef STD_H
	#define STD_H

	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <strings.h>

	#define OK					0 
	#define WRONG				-1

	#endif

#define BUFFSIZE 		1024
#define REMO_TEST_MAX_NAME_LENGTH 32
#define REMO_TEST_MAX_FUNC_LENGTH 4096
#define MAXLEN 			128

char request[BUFFSIZE];		//global variable

typedef struct _SUB_PROCESS_ARRAY_ {
    char                        			Name[REMO_TEST_MAX_NAME_LENGTH];
    int 						(*sub_proc)(int ac,char* av[]); 
    char 						Func[REMO_TEST_MAX_FUNC_LENGTH];
} SUB_PROCESS_ARRAY;

typedef struct _SUB_PROCESS_ARRAYS_{
	char 					Name[REMO_TEST_MAX_NAME_LENGTH];
	SUB_PROCESS_ARRAY*  		sub_proc_array;		
} SUB_PROCESS_ARRAYS;

extern int getfilelist(int ac,char* av[]);
extern int getfileinfo(int ac,char* av[]);
extern int parameter(int ac,char* av[]);
extern int workmode(int ac,char* av[]); 
extern int timeosd(int ac,char* av[]);
extern int photo(int ac,char* av[]);
extern int record(int ac,char* av[]);
extern int bootaction(int ac,char* av[]); 
extern int getdevcapabilities(int ac,char* av[]); 

extern int  Call_Sub(int ac,char *av[]);
extern void usage(int ac,char *av[]);

extern SUB_PROCESS_ARRAY sub_proc_workmode[];
extern SUB_PROCESS_ARRAY sub_proc_record[];
extern SUB_PROCESS_ARRAY sub_proc_parameter[];
extern SUB_PROCESS_ARRAY sub_proc_timeosd[];
extern SUB_PROCESS_ARRAY sub_proc_bootaction[];

#endif

