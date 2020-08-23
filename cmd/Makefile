SHELL = /bin/sh
CC=	gcc
AR=ar -rcs

SOURCE=	$(wildcard *.c)
#OBJ=	$(SOURCE:%.c=%.o) 
LIB_TARGET=	libcmd.a
LIB_DIR=	../lib	

$(shell mkdir -p ${LIB_DIR})

	
all:
	gcc -c *.c -I ../include
	$(AR) $(LIB_TARGET) *.o
	mv $(LIB_TARGET) $(LIB_DIR)
	rm -f *.o

.PHONY:	clean

clean:
	rm -rf $(LIB_DIR) 
