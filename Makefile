SHELL = /bin/sh
CC=	gcc
AR=ar -rcs

SOURCE=	$(wildcard *.c)
OBJ=	main.o	remo.o	remo_http.o
TARGET=	remo_test

#LIB_DIR=	lib
SUB_DIR = 	cmd	

all:$(OBJ)
	cd cmd && $(MAKE)
	cd ..
	$(CC)  *.o -o $(TARGET) -Llib -lcmd -I ./inlcude
	rm -f *.o
remo_http.o: remo_http.c 
	$(CC) -c remo_http.c -L ./lib -I ./include
remo.o:remo.c
	$(CC) -c remo.c -L ./lib -I ./include
main.o:main.c
	$(CC) -c main.c -L ./lib -I ./include

.PHONY:	clean

clean:
	rm $(TARGET) *.o
 
