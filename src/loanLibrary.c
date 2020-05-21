/*
 ============================================================================
 Name        : loanLibrary.c
 Author      : Jose Gonzalez
 Version     : 1.0
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "loanLibrary.h"

int initLoan(Loan *list, int len) {
	int i;
	int r = -1;
	if (len > 0) {
		for (i = 0; i < len; i++) {
			list[i].isEmpty = 1;
			r = 0;
		}
	}
	return r;
}

int findFreeSpaceLoan(Loan *list, int len) {
	int ID = -1;
	int i;
	for (i = 0; i < len; i++) {
		if (list[i].isEmpty == 1) {
			ID = i;
			break;
		}
	}
	return ID;
}

Loan addLoan(Loan *list, int id, int clientID, float amount, int feesAmount) {
	Loan newLoan;
	newLoan.ID = id;
	newLoan.clientID = clientID - 1;
	newLoan.amount = amount;
	newLoan.feesAmount = feesAmount;
	newLoan.isEmpty = 0;
	newLoan.state = 1;
	return newLoan;
}

int chargeLoanData(Loan *list, int len) {
	int ID;
	char idClient[20];
	int idClientAuxiliar;
	char amount[51];
	float amountAuxiliar;
	char feesAmount[51];
	int feesAmountAuxiliar;
	ID = findFreeSpaceLoan(list, len);
	if (ID == -1) {
		printf("No hay espacios libres");
	} else {
		fflush(stdin);
		if (!getStringNumeros("Ingrese el ID del cliente: \n", idClient)) {
			printf("El ID debe ser numerico\n");
			ID = -1;
		}
		idClientAuxiliar = atoi(idClient);
		fflush(stdin);
		if (!getStringNumerosFlotantes("Ingrese el monto del prestamo: \n",
				amount)) {
			printf("El monto debe ser numerico\n");
			ID = -1;
		}
		amountAuxiliar = atof(amount);
		fflush(stdin);
		if (!getStringNumeros("Ingrese el numero de cuotas del prestamo: \n",
				feesAmount)) {
			printf("El numero de cuotas debe ser numerico\n");
			ID = -1;
		}
		feesAmountAuxiliar = atoi(feesAmount);
	}
	if (ID != -1) {
		list[ID] = addLoan(list, ID, idClientAuxiliar, amountAuxiliar,
				feesAmountAuxiliar);
	}
	return ID;
}

int payOffLoan(Loan *list, int id) {
	int ID;
	ID = id - 1;
	if (list[ID].isEmpty != 1) {
		list[ID].state = 0;
		return 0;
	}
	return -1;
}

int resumeLoan(Loan *list, int id) {
	int ID;
	ID = id - 1;
	if (list[ID].isEmpty != 1) {
		list[ID].state = 1;
		return 0;
	}
	return -1;
}

int printEspecificAmountLoans(Loan *list, int len, float amount) {
	int i;
	int count = 0;
	if (amount > 999) {
		for (i = 0; i < len; i++) {
			if (list[i].isEmpty != 1 && list[i].amount == amount) {
				count++;
			}
		}
		printf("Cantidad de prestamos con ese monto: %d\n", count);
	} else {
		printf("El monto debe ser mayor a 1000\n");
	}
	return 0;
}

int print12LoansFees(Loan *list, int len) {
	int i;
	printf("ID      Monto      Cuotas\n");
	for (i = 0; i < len; i++) {
		if (list[i].isEmpty != 1 && list[i].feesAmount == 12) {
			if (list[i].state == 0) {
				printf("%d      %.2f      %d\n", list[i].ID + 1, list[i].amount,
						list[i].feesAmount);
			}
		}
	}
	return 0;
}

int printEspecificFeesLoan(Loan *list, int len, int fees) {
	int i;
	int count = 0;
	for (i = 0; i < len; i++) {
		if (list[i].isEmpty != 1 && list[i].feesAmount == fees) {
			count++;
		}
	}
	printf("Cantidad de prestamos con ese monto: %d\n", count);
	return 0;
}
