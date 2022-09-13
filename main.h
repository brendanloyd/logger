#ifndef MAIN_H
#define MAIN_H
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <getopt.h>
#include <unistd.h>
#include <random>
#include <string.h>
#include <errno.h>
#include "log.h"
using namespace std;

extern int errno;

int randomNumber(int);
int optionHandler(int, char **, char *);
void menu(int, char *);
int validateInputs();
#endif
