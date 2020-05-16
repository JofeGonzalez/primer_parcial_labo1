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

/** \brief To indicate that all positions in the array are empty,
 *		   this function put the flag (isEmpty) in TRUE in all
 *		   positions of the array.
 *	\param Client* list Pointer to array of Clients.
 *	\param int len length of the array.
 *	\return -1 if Error, 0 if OK.
 */
int initClient(Client *list, int len);

/** \brief Search next isEmpty = 1 in the array.
 *	\param Client* list Pointer to array of Clients.
 *	\param int len length of the array.
 *	return int.
 */
int findFreeSpaceClient(Client *list, int len);

/** \brief add in a existing list of Clients the values received as parameters
 * in the first empty position
 * \param list Client*
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param cuil[] char
 * \return Client
 */
Client addClient(Client *list, int id, char name[], char lastName[],
		char cuil[]);

/** \brief Charges an Client data
 * \param list Client*
 * \param len int
 * \return (-1) if Error, 0 if OK.
 */
int chargeClientData(Client *list, int len);

/** \brief modify an existing Client data
 * \param list Client*
 * \param len int
 * \param id int
 * \return (-1) if Error, 0 if OK.
 */
int changeClientData(Client *list, int len, int id);

/** \brief Remove a Client by Id (put isEmpty Flag in 1)
 *
 * \param list Client*
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
 find a Client] - (0) if Ok
 *
 */
int removeClient(Client *list, int id);
