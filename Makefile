CC = g++
CFLAGS = -g -Wall -std=c++11
OBJS = main.o log.o
TARGET = logger

driver: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o driver

main.o: main.c main.h log.h
	$(CC) $(CFLAGS) -c main.c

 
log.o: log.c log.h
	$(CC) $(CFLAGS) -c log.c
