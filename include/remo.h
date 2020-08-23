/******************************************************************************
  File Name     : remo.h
  Version       : 4.0
  Last Modified :
  Description   : Argument parser
  History       :
  1.Date        : 8/25/2017
    Author      : Liu Yihao
******************************************************************************/

#ifndef REMO_H
#define REMO_H

	#ifndef STD_H
	#define STD_H

	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <strings.h>

	#define OK					0 
	#define WRONG				-1

	#endif

#include "socket.h"
#include "process.h"

typedef int (*REMO_TEST_COMMAND_HANDLER_f)(int, char **);


typedef struct _REMO_TEST_LIST_s_ {
    char                        *Name;
    REMO_TEST_COMMAND_HANDLER_f Handler;
    char 						*Func;
    struct _REMO_TEST_LIST_s_   *pNext;
} REMO_TEST_LIST_s;

extern void Remo_init();
extern void Remo_finish();
extern REMO_TEST_LIST_s *Remo_Test_GetCommandList(void);
extern int Remo_Test_RegisterCommand(const char *, REMO_TEST_COMMAND_HANDLER_f,const char *CmdFunc);			//Register the linked list
extern int Remo_Test_UnRegisterCommand(const char *, REMO_TEST_COMMAND_HANDLER_f,const char *CmdFunc);		//unregister the linked list

extern int send_http_request( REMO_TEST_LIST_s *pCmd,int ac,char* av[]);
extern int cmd_process( REMO_TEST_LIST_s *pCmd,int ac,char* av[]);
extern int really_process(int ac,char *av[]);


#endif
