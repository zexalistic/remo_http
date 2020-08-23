#ifndef SOCKET_H
#define SOCKET_H

#define PORTNUM 		80			//based on thttp conf file
#define oops(msg)  {perror(msg);return WRONG;}
#define SOCKET_ERROR		-1

#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <sys/stat.h>


extern int connect_to_server();

#endif
