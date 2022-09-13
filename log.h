#ifndef LOG_H
#define LOG_H 


#include <time.h>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>

typedef struct data_struct
{
	time_t time; // Time stamp
	char type; // Message type (I/W/E/F)
	char * string; // Message string
} data_t;

int addmsg(char, char*);
void clearlog(void);
char * getlog(void);
int savelog ( char * filename );

#endif
