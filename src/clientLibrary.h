/*
 ============================================================================
 Name        : clientLibrary.h
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
	char name[51];
	char lastName[51];
	char cuil[20];
	int isEmpty;
}Client;

int initClient(Client *list, int len);
int findFreeSpaceClient(Client *list, int len) ;
Client addClient(Client *list, int id, char name[], char lastName[],
		char cuil[]);
int chargeClientData(Client *list, int len);
int changeClientData(Client *list, int len, int id);
int removeClient(Client *list, int id);
