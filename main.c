#include "main.h"

int main(int argc, char **argv) {
	int option;
	while ((option = getopt(argc, argv, "ht")) != -1) {
		switch (option) {
		case 'h' :
			printf("You need help don't you?");
			break;
		case 't' :
                        printf("This is the second option.");
                        break;
		default :
			printf("Error mf!");
		}
	}

}
