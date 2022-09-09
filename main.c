#include "main.h"

int randomNumber(int num) {
	int randomNumber = (rand() % ((2 * num) - 0 + 1) + 0);

	return randomNumber;
}

void menu(int sleepValue,char* fileName) {


	int menuChoice;
	printf("(1)Add message\n");
        printf("(2)Clear log\n");
        printf("(3)Get log\n");
        printf("(4)Save log\n");
	printf("Please enter your choice between 1-4:");
	menuChoice = validateInputs();
	switch (menuChoice) {
		case 1 :
			printf("Your inside case 1\n");
			break;
                case 2 :
                        printf("Your inside case 2\n");
                        break;
                case 3 :
                        printf("Your inside case 3\n");
                        break;
                case 4 :
                        printf("Your inside case 4\n");
                        break;
	}
}

/*int optionHandler(int argc, char **argv, char *fileName) {
        int option;
        while ((option = getopt(argc, argv, "ht:")) != -1) {
                switch (option) {
                case 'h' :
                        printf("To run this program please use the following format:\n");
                        printf("./driver [-h] [-t] [filename.txt]\n");
                        return 0;
                        break;
                case 't' :
			if(strstr(argv[optind], ".txt")) {
				fileName = (char*)malloc(strlen(argv[optind]));
				strcpy(fileName*, argv[optind]);
				printf("The file is %s\n", fileName);
			} else {
				printf("perror here\n");
			} 

			return randomNumber(atoi(optarg));
                        break;
                default :
                        printf("Error processing using perror will be used here.!\n");
			return 0;
                }
        }
	return 0;
}*/


int validateInputs() {
        bool flag = true;
        int input = 0;
        while(flag) {
                scanf("%d", &input);
                while (input < 1 || input > 4) {
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
                        break;
                case 't' :
                        if(strstr(argv[optind], ".txt")) {
                                fileName = (char*)malloc(strlen(argv[optind]));
                                strcpy(fileName, argv[optind]);
                        } else {
				perror("Driver: Error");
                        }
			sleepValue = randomNumber(atoi(optarg));
			menu(sleepValue, fileName);
			return 0;
                        break;
                default :
			perror("Driver: Error");
                        return 0;
                }
        }

	return 0;
}
