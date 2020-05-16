/*
 ============================================================================
 Name        : PrimerParcialLabo1.c
 Author      : Jose Gonzalez
 Version     : 1.0
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "optionsMenu.h"
#define MAX 50
int main(void) {
	setbuf(stdout,NULL);
	Client aClient[MAX];
	Loan aLoan[MAX];
	int firstOption;
	char answer = 'n';
	int countClient = 0;
	initClient(aClient, MAX);
	initLoan(aLoan, MAX);
	do {
		system("cls");
		printMenu();
		printf("Que desea hacer?\n");
		scanf("%d", &firstOption);
		setbuf(stdin, NULL);
		countClient = optionMenu(firstOption, aClient, aLoan, MAX, countClient);
		printf("Desea continuar? (s or n)");
		scanf("%c", &answer);
		setbuf(stdin, NULL);
	} while (answer == 's');
}
