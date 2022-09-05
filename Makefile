CC = g++
CFLAGS = -g -Wall -std=c++11
OBJS = main.o log.o
TARGET = logger

logger: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o logger

main.o: main.c main.h log.h
	$(CC) $(CFLAGS) -c main.c

 
log.o: log.c log.h
	$(CC) $(CFLAGS) -c log.c
