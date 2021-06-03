/*
*
*	Bachelor of Computer Science (Software Engineering)
*
*				Kyle J. Brookes | 6822794
*
*					 Assignment 3
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Urlgeneration.h"

using namespace std;

int Urlgeneration::generateNumber() {

	int randomNumber;

	srand(time(NULL));

	randomNumber = rand() % 10 + 1;

	return randomNumber;

}