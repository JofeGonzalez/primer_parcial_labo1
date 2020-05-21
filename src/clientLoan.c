/*
 ============================================================================
 Name        : clientLoan.c
 Author      : Jose Gonzalez
 Version     : 1.0
 ============================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "clientLoan.h"

int printEspecificClientLoans(Client *list1, Loan *list2, int len, int id) {
	int i;
	int ID;
	char state[20];
	char activeStateAuxiliar[] = "Activo";
	char payOffStateAuxiliar[] = "Saldado";
	ID = id - 1;
	printf("ID      Nombre      Apellido      CUIL\n");
	if (list1[ID].isEmpty != 1) {
		printf("%d      %s      %s       %s\n", list1[ID].ID + 1,
				list1[ID].name, list1[ID].lastName, list1[ID].cuil);
		printf("Prestamos\n");
		for (i = 0; i < len; i++) {
			if (list2[i].isEmpty != 1 && list2[i].clientID == list1[ID].ID) {
				if (list2[i].state == 1) {
					strcpy(state, activeStateAuxiliar);
				} else {
					strcpy(state, payOffStateAuxiliar);
				}
				printf("%d      %.2f      %d      %s\n", list2[i].ID + 1,
						list2[i].amount, list2[i].feesAmount, state);
			}
		}
	}
	return 0;
}

int printEspecificClient(Client *list1, Loan *list2, int len, int id) {
	int i;
	int ID;
	char state[20];
	char activeStateAuxiliar[] = "Activo";
	char payOffStateAuxiliar[] = "Saldado";
	ID = id - 1;
	printf("ID      Nombre      Apellido      CUIL\n");
	if (list2[ID].isEmpty != 1) {
		for (i = 0; i < len; i++) {
			if (list1[i].isEmpty != 1 && list1[i].ID == list2[ID].clientID) {
				if (list2[i].state == 1) {
					strcpy(state, activeStateAuxiliar);
				} else {
					strcpy(state, payOffStateAuxiliar);
				}
				printf("%d      %s      %s       %s      %s\n", list1[i].ID + 1,
						list1[i].name, list1[i].lastName, list1[i].cuil, state);
			}
		}
	}
	return 0;
}

int printClientLoans(Client *list1, Loan *list2, int len) {
	int i, j;
	char state[20];
	char activeStateAuxiliar[] = "Activo";
	char payOffStateAuxiliar[] = "Saldado";
	printf("ID      Nombre      Apellido      CUIL\n");
	for (i = 0; i < len; i++) {
		if (list1[i].isEmpty != 1) {
			printf("%d      %s      %s       %s\n", list1[i].ID + 1,
					list1[i].name, list1[i].lastName, list1[i].cuil);
			printf("ID      Monto      Cuotas      Estado\n");
			for (j = 0; j < len; j++) {
				if (list2[j].isEmpty != 1 && list1[i].ID == list2[j].clientID) {
					if (list2[j].state == 1) {
						strcpy(state, activeStateAuxiliar);
					} else {
						strcpy(state, payOffStateAuxiliar);
					}
					printf("%d      %.2f      %d      %s\n", list2[j].ID + 1,
							list2[j].amount, list2[j].feesAmount, state);
				}
			}
		}
	}
	return 0;
}

int printActiveLoans(Client *list1, Loan *list2, int len) {
	int i, j;
	printf("ID      Monto      Cuotas      CUIL\n");
	for (i = 0; i < len; i++) {
		if (list2[i].isEmpty != 1 && list2[i].state == 1) {
			for (j = 0; j < len; j++) {
				if (list1[j].isEmpty != 1 && list1[j].ID == list2[i].clientID) {
					printf("%d      %.2f      %d      %s\n", list2[i].ID + 1,
							list2[i].amount, list2[i].feesAmount,
							list1[j].cuil);
				}
			}
		}
	}
	return 0;
}

int printClientMoreActiveLoans(Client *list1, Loan *list2, int len) {
	int i, j;
	int count = 0;
	int max = 0;
	Client newClient;
	printf("ID      Nombre      Apellido      CUIL      Prestamos\n");
	for (i = 0; i < len; i++) {
		if (list1[i].isEmpty != 1) {
			for (j = 0; j < len; j++) {
				if (list2[j].isEmpty != 1 && list1[i].ID == list2[j].clientID) {
					if (list2[j].state == 1) {
						count++;
					}
				}
			}
			if (count > max) {
				max = count;
				newClient.ID = list1[i].ID;
				strcpy(newClient.name, list1[i].name);
				strcpy(newClient.lastName, list1[i].lastName);
				strcpy(newClient.cuil, list1[i].cuil);
				count = 0;
			}
		}
	}
	printf("%d      %s      %s      %s\n", newClient.ID + 1, newClient.name,
			newClient.lastName, newClient.cuil);
	return 0;
}

int printClientMorePayOffLoans(Client *list1, Loan *list2, int len) {
	int i, j;
	int count = 0;
	int max = 0;
	Client newClient;
	printf("ID      Nombre      Apellido      CUIL      Prestamos\n");
	for (i = 0; i < len; i++) {
		if (list1[i].isEmpty != 1) {
			for (j = 0; j < len; j++) {
				if (list2[j].isEmpty != 1 && list1[i].ID == list2[j].clientID) {
					if (list2[j].state == 0) {
						count++;
					}
				}
			}
			if (count > max) {
				max = count;
				newClient.ID = list1[i].ID;
				strcpy(newClient.name, list1[i].name);
				strcpy(newClient.lastName, list1[i].lastName);
				strcpy(newClient.cuil, list1[i].cuil);
				count = 0;
			}
		}
	}
	printf("%d      %s      %s      %s\n", newClient.ID + 1, newClient.name,
			newClient.lastName, newClient.cuil);
	return 0;
}

int printClientMoreLoans(Client *list1, Loan *list2, int len) {
	int i, j;
	int count = 0;
	int max = 0;
	Client newClient;
	printf("ID      Nombre      Apellido      CUIL      Prestamos\n");
	for (i = 0; i < len; i++) {
		if (list1[i].isEmpty != 1) {
			for (j = 0; j < len; j++) {
				if (list2[j].isEmpty != 1 && list1[i].ID == list2[j].clientID) {
					count++;
				}
			}
			if (count > max) {
				max = count;
				newClient.ID = list1[i].ID;
				strcpy(newClient.name, list1[i].name);
				strcpy(newClient.lastName, list1[i].lastName);
				strcpy(newClient.cuil, list1[i].cuil);
				count = 0;
			}
		}
	}
	printf("%d      %s      %s      %s      %d\n", newClient.ID + 1, newClient.name,
			newClient.lastName, newClient.cuil, max);
	return 0;
}
