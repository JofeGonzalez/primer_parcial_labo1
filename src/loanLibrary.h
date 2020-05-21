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

/** \brief To indicate that all positions in the array are empty,
 *		   this function put the flag (isEmpty) in TRUE in all
 *		   positions of the array.
 *	\param Loan* list Pointer to array of Loan.
 *	\param int len length of the array.
 *	\return -1 if Error, 0 if OK.
 */
int initLoan(Loan *list, int len);

/** \brief Search next isEmpty = 1 in the array.
 *	\param Loan* list Pointer to array of Loan.
 *	\param int len length of the array.
 *	return int.
 */
int findFreeSpaceLoan(Loan *list, int len);

/** \brief add in a existing list of Loan the values received as parameters
 * in the first empty position
 * \param list Loan*
 * \param len int
 * \param id int
 * \param clientID int
 * \param amount float
 * \param feesAmount int
 * \return Loan
 */
Loan addLoan(Loan *list, int id, int clientID, float amount, int feesAmount);

/** \brief charges a Loan data
 * \param list Loan*
 * \param len int
 * \param id int
 * \return (-1) if Error, 0 if OK.
 */
int chargeLoanData(Loan *list, int len);

/** \brief change the status of the loan
 * \param list Loan*
 * \param id int
 * \return (-1) if Error, 0 if OK.
 */
int payOffLoan(Loan *list, int id);

/** \brief change the status of the loan
 * \param list Loan*
 * \param id int
 * \return (-1) if Error, 0 if OK.
 */
int resumeLoan(Loan *list, int id);

/** \brief print the loans that are equal to the amount entered
 *
 * \param list Loan*
 * \param len int
 * \param amount float
 * \return int
 */
int printEspecificAmountLoans(Loan *list, int len, float amount);

int print12LoansFees(Loan *list, int len);

int printEspecificFeesLoan(Loan *list, int len, int fees);
