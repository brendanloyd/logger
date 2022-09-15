#include "main.h"

int randomNumber(int num) {
	int randomNumber = (rand() % ((2 * num) - 0 + 1) + 0);
	return randomNumber;
}

void menu(int sleepValue,char * fileName) {

	char messageType;
	char message[200];
	int menuChoice;

	do {	
		printf("(1)Add message\n");
	        printf("(2)Clear log\n");
	        printf("(3)Get log\n");
	        printf("(4)Save log\n");
		printf("(5)Quit\n");
		printf("Please enter your choice between 1-5:");
		menuChoice = validateInputs();
		switch (menuChoice) {
			case 1 :
				printf("What type of message would you like to add?One char only.(I, W, E, or F): ");
				scanf(" %c", &messageType);
				printf("What is the message you would like to add to the queue? : ");
				scanf(" %[^\n]%*c", message);
				sleep(sleepValue);
				addmsg(messageType, message);
				break;

                	case 2 :
				sleep(sleepValue);
                        	clearlog();
                        	break;

                	case 3 :
				sleep(sleepValue);
                        	printf("The log in queue is: %s\n", getlog());
                        	break;

                	case 4 : {
				sleep(sleepValue);
				int exitStatus = savelog(fileName);
                        	break;
			}

			case 5 :
				printf("Exiting program.\n");
		}
	} while (menuChoice != 5);
	
}

int validateInputs() {
        bool flag = true;
        int input = 0;

        while(flag) {
                scanf("%d", &input);

                while (input < 1 || input > 5) {
                    printf("That is an invalid input. Please enter a number between 1 and 4: ");
                    scanf("%d", &input);
                }

                flag = false;
        }
        return input;
    }


int main(int argc, char **argv) {
	char *fileName;
	int sleepValue;
        int option;

        while ((option = getopt(argc, argv, "ht:")) != -1) {
                switch (option) {
                	case 'h' :
                        	printf("To run this program please use the following format:\n");
                        	printf("./driver [-h] [-t] [filename.txt]\n");
                        	return 0;

                	case 't' :
                        	if(strstr(argv[optind], ".txt")) {
                                	fileName = (char*)malloc(strlen(argv[optind]));
                                	strcpy(fileName, argv[optind]);
                        	} else {
					fileName = (char*)"messages.log";
                        	}

				sleepValue = randomNumber(atoi(optarg));
				menu(sleepValue, fileName);
				return 0;

			case '?':
                        	printf("Driver : main : Invalid option.");
                        	exit(-1);

                	default :
				printf("Driver : main : Invalid argument");
                        	return 0;
                }
        }
	if(strstr(argv[optind], ".txt")) {
		
		fileName = (char*)argv[optind];
		//fileName = (char*)malloc(strlen(argv[optind]));
                //strcpy(fileName, argv[optind]);
		menu(0, fileName);
        } else {
		fileName = (char*)"messages.log";
		menu(0, fileName);
	} 
	return 0;
}
