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

/** \brief print all the customer loans from which the id was entered
 * \param list1 Client*
 * \param list2 Loan*
 * \param len int
 * \param id int
 * \return int
 */
int printEspecificClientLoans(Client *list1, Loan *list2, int len, int id);

/** \brief print the information of the client to which the loan belongs
 * \param lis1 Client*
 * \param list2 Loan*
 * \param len int
 * \param id int
 * \return int
 */
int printEspecificClient(Client *list1, Loan *list2, int len, int id);

/** \brief print the list of clients next to the loans that belong to them
 * \param list1 Client*
 * \param list2 Loan*
 * \param len int
 */
int printClientLoans(Client *list1, Loan *list2, int len);

/** \brief print the list of active loans
 * \param list1 Client*
 * \param list2 Loan*
 * \param len int
 * \return int
 */
int printActiveLoans(Client *list1, Loan *list2, int len);

/** \brief print the client with the most active loans
 * \param list1 Client*
 * \param list2 Loan*
 * \param len int
 * \return int
 */
int printClientMoreActiveLoans(Client *list1, Loan *list2, int len);

/** \brief print the client with more loans paid
 * \param list1 Client*
 * \param list2 Loan*
 * \param len int
 * \return int
 */
int printClientMorePayOffLoans(Client *list1, Loan *list2, int len);
