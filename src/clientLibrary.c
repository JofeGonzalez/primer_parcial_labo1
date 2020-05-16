/*
 ============================================================================
 Name        : clientLibrery.c
 Author      : Jose Gonzalez
 Version     : 1.0
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "clientLibrary.h"

int initClient(Client *list, int len) {
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

int findFreeSpaceClient(Client *list, int len) {
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

Client addClient(Client *list, int id, char name[], char lastName[],
		char cuil[]) {
	Client newClient;
	strcpy(newClient.name, name);
	strcpy(newClient.lastName, lastName);
	strcpy(newClient.cuil, cuil);
	newClient.ID = id;
	newClient.isEmpty = 0;
	return newClient;
}

int chargeClientData(Client *list, int len) {
	int ID;
	char name[51];
	char lastName[51];
	char cuil[20];
	ID = findFreeSpaceClient(list, len);
	if (ID == -1) {
		printf("No hay espacios libres");
	} else {
		fflush(stdin);
		if (!getStringLetras("Ingrese el nombre del cliente: \n", name)) {
			printf("El nombre debe contener solo letras\n");
			ID = -1;
		}
		fflush(stdin);
		if (!getStringLetras("Ingrese el apellido del cliente: \n", lastName)) {
			printf("El apellido debe contener solo letras\n");
			ID = -1;
		}
		fflush(stdin);
		if (!getCUIL("Ingrese el CUIL del cliente: \n", cuil)) {
			printf("El cuil debe contener solo numeros y 2 guiones\n");
			ID = -1;
		}
	}
	if (ID != -1) {
		list[ID] = addClient(list, ID, name, lastName, cuil);
	}
	return ID;
}

int changeClientData(Client *list, int len, int id) {
	char name[51];
	char lastName[51];
	char cuil[20];
	int ID;
	ID = id - 1;
	fflush(stdin);
	if (!getStringLetras("Ingrese el nombre del cliente: \n", name)) {
		printf("El nombre debe contener solo letras\n");
		ID = -1;
	}
	fflush(stdin);
	if (!getStringLetras("Ingrese el apellido del cliente: \n", lastName)) {
		printf("El apellido debe contener solo letras\n");
		ID = -1;
	}
	fflush(stdin);
	if (!getCUIL("Ingrese el CUIL del cliente: \n", cuil)) {
		printf("El cuil debe contener solo numeros y 2 guiones\n");
		ID = -1;
	}
	if (ID != -1) {
		list[ID] = addClient(list, ID, name, lastName, cuil);
	}
	return ID;
}

int removeClient(Client *list, int id) {
	int ID;
	ID = id - 1;
	list[ID].isEmpty = 1;
	if (list[ID].isEmpty == 1) {
		return 0;
	} else {
		return -1;
	}
}
