#include "remo.h"

//help page
static int Remo_Test_Help( int ac, char *av[])
{
     printf("Try ./remo [OPTION] for more information.\n");
     return 0;
}

static REMO_TEST_LIST_s RemoTestCmdListHead = {
    .Name       = "help",
    .Handler    = Remo_Test_Help,
    .Func       = "Show man page",
    .pNext      = NULL
};


int Remo_Test_RegisterCommand(const char *CmdName, REMO_TEST_COMMAND_HANDLER_f CmdHandler,const char *CmdFunc){
    REMO_TEST_LIST_s *pNewCommand = NULL;
    REMO_TEST_LIST_s *pCommand = &RemoTestCmdListHead;

    if (CmdHandler == NULL || CmdName == NULL || strlen(CmdName) > (REMO_TEST_MAX_NAME_LENGTH - 1)|| CmdFunc == NULL || strlen(CmdFunc) > (REMO_TEST_MAX_FUNC_LENGTH - 1))
        return WRONG;           
    else{       //in case that we alloc a NULL space
        if((pNewCommand=(REMO_TEST_LIST_s *)calloc(1,sizeof(REMO_TEST_LIST_s)))==NULL)
            return WRONG;
        if((pNewCommand->Name=(char *)calloc(1,strlen(CmdName) + 1))==NULL)
            return WRONG;
        if((pNewCommand->Func=(char *)calloc(1,strlen(CmdFunc) + 1))==NULL)
            return WRONG;

    strncpy(pNewCommand->Name, CmdName, strlen(CmdName) + 1);
    strncpy(pNewCommand->Func, CmdFunc, strlen(CmdFunc) + 1);

    pNewCommand->Handler = CmdHandler;
    pNewCommand->pNext = NULL;

    while (pCommand->pNext != NULL) {
        pCommand = pCommand->pNext;
    }
    pCommand->pNext = pNewCommand;

    return OK;
    }
}

int Remo_Test_UnRegisterCommand(const char *CmdName, REMO_TEST_COMMAND_HANDLER_f CmdHandler,const char *CmdFunc){
    REMO_TEST_LIST_s *pCommand = &RemoTestCmdListHead;
    REMO_TEST_LIST_s *pLastCommand = NULL;

    while (pCommand != NULL) {
        if (strncmp(pCommand->Name, CmdName, REMO_TEST_MAX_NAME_LENGTH) == 0 || strncmp(pCommand->Func, CmdFunc, REMO_TEST_MAX_FUNC_LENGTH) == 0)
            break;

        pLastCommand = pCommand;
        pCommand = pCommand->pNext;
    }

    if (pCommand->Handler == CmdHandler) {
        if (pLastCommand == NULL) {
            //should never happen 
        } else {
            pLastCommand->pNext = pCommand->pNext;
           free((void*) pCommand->Name);
           free((void*) pCommand->Func);
           free((void*) pCommand);
        }
    }

    return OK;
}

//get the commandlist header link
REMO_TEST_LIST_s *Remo_Test_GetCommandList(void)
{
    return &RemoTestCmdListHead;
};

//command query and action
int really_process(int ac,char *av[]){
    REMO_TEST_LIST_s *pCmd = Remo_Test_GetCommandList();

    if (ac == 1) {
        pCmd->Handler(ac, av); // Show help page 
        printf("supported test commands:\n");
        while (pCmd) {
            printf("\t%-32s\t%s\n", pCmd->Name,pCmd->Func);
            pCmd = pCmd->pNext;
        }
    } else {
        while (pCmd) {
            if (strcmp(av[1], pCmd->Name) == 0) {
            	return cmd_process(pCmd,ac,av);
            }
            pCmd = pCmd->pNext;
        }

        printf("%s: test command not found!\n", av[1]);
    }

    return 0;
}

int send_http_request( REMO_TEST_LIST_s *pCmd,int ac,char* av[]){
    int bufflen,res,fd;
    char text[BUFFSIZE],waste[BUFFSIZE];
    char* io;
    int flag=1;

    memset(request,0,BUFFSIZE);
    
    strcat(request,"GET http://192.168.1.10/cgi-bin/hi3510/");   

    res=pCmd->Handler(ac, av);
    if(res!=OK) return OK;

    strcat(request," HTTP/1.1\n\r");
    strcat(request,"Content-Length: 0\n");
    strcat(request,"User-Agent: Zexal\n");
    strcat(request,"Host: 192.168.1.30\n\n");

    //establish a socket
    fd=connect_to_server();
    res=send(fd,request,strlen(request),0);
    if(res==SOCKET_ERROR)
    	return printf("Error in sending http request!\n");

    while(flag){
        memset(text,0,BUFFSIZE);
        memset(waste,0,BUFFSIZE);
        bufflen=recv(fd,text,BUFFSIZE,0);
        if(bufflen<0){
            printf("error in receive\n");
            close(fd);
            exit(1);
        }
        if(bufflen>0){
            io=2+strstr(text,"\n\r\n");
            strncpy(waste,io,bufflen);
            printf("%s",waste);
        }
        else 
            flag=0;
        }

    //close the socket
    close(fd);
}

int cmd_process(REMO_TEST_LIST_s *pCmd,int ac,char* av[]){
    return send_http_request(pCmd,ac,av);
}

int connect_to_server(){
        int sock_id;
        struct sockaddr_in servadd;
        struct hostent *hp;

        sock_id = socket(AF_INET,SOCK_STREAM,0);
        if(sock_id == -1)
                oops("socket");
        bzero(&servadd,sizeof(servadd));
        inet_pton(AF_INET,"192.168.1.10",&(servadd.sin_addr));
        servadd.sin_port= htons(PORTNUM);
        servadd.sin_family=AF_INET;

        if(connect(sock_id,(struct sockaddr *)&servadd, sizeof(servadd))!=0)
                oops("connect");

        return sock_id;
}
