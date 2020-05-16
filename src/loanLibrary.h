/*
 ============================================================================
 Name        : loanLibrary.h
 Author      : Jose Gonzalez
 Version     : 1.0
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

typedef struct{
	int ID;
	int clientID;
	float amount;
	int feesAmount;
	int state;
	int isEmpty;
}Loan;

int initLoan(Loan *list, int len);
int findFreeSpaceLoan(Loan *list, int len);
Loan addLoan(Loan *list, int id, int clientID, float amount, int feesAmount);
int chargeLoanData(Loan *list, int len);
int payOffLoan(Loan *list, int id);
int resumeLoan(Loan *list, int id);
int printEspecificAmountLoans(Loan *list, int len, float amount);
