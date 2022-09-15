#ifndef LOG_C
#define LOG_C 

#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <fstream>
#include "log.h"

typedef struct list_struct {
	data_t item;
 	struct list_struct *next;
} list_t;

static list_t *headptr = NULL;
static list_t *tailptr = NULL;

int addmsg(char type, char * msg) {
	list_t *newnode;
	int nodesize;
	nodesize = sizeof(list_t) + (sizeof(type) + (strlen(msg)) + 2);
	
	if ((newnode = (list_t *)(malloc(nodesize))) == NULL) {
		perror("Error: addmsg ");
		return -1;
	}
	
	newnode->item.time = time(NULL);
	newnode->item.type = type;	
	newnode->item.string = (char *)newnode + sizeof(list_t);
	strcpy(newnode->item.string, msg);
	newnode->next = NULL;

	if (headptr == NULL)
	headptr = newnode;
	else
	tailptr->next = newnode;
	tailptr = newnode;

	return 0;
}

char * getlog() {
	int stringOffset = 0, sum = 0;
	list_t * ptr = headptr;
	char * finalString = NULL;
	size_t stringlen;
	
	while (ptr != NULL) {
		stringlen = strlen(ptr->item.string);
		sum += stringlen;

		finalString = (char*) realloc(finalString, (sum + stringOffset));
		strncat(finalString, ptr->item.string, stringlen);
		ptr = ptr->next;
		stringOffset += sum;
		
		finalString = (char *) realloc(finalString, (sum + 1));
		finalString[sum + 1] = 0x00;

	}
	return finalString;
}



int savelog(char *filename) {
	FILE *out_file = fopen(filename, "a");	

	if(out_file == NULL){
		perror("Error: savelog ");
		return -1;
	} else {
		fprintf(out_file, "%s", getlog());
	} 

	return 0;
}

void clearlog(void) {
	list_t * nextNode = headptr;
	
	while (headptr != NULL) {
		nextNode = headptr->next;
		free(headptr);
		headptr = nextNode;
	}
}

#endif
