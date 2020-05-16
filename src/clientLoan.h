/*
 ============================================================================
 Name        : clientLoan.h
 Author      : Jose Gonzalez
 Version     : 1.0
 ============================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "clientLibrary.h"
#include "loanLibrary.h"

int printEspecificClientLoans(Client *list1, Loan *list2, int len, int id);
int printEspecificClient(Client *list1, Loan *list2, int len, int id);
int printClientLoans(Client *list1, Loan *list2, int len);
int printActiveLoans(Client *list1, Loan *list2, int len);
int printClientMoreActiveLoans(Client *list1, Loan *list2, int len);
int printClientMorePayOffLoans(Client *list1, Loan *list2, int len);
