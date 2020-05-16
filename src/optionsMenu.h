/*
 ============================================================================
 Name        : optionsMenu.h
 Author      : Jose Gonzalez
 Version     : 1.0
 ============================================================================
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "clientLoan.h"
/*
 * \brief Print the menu
 */
void printMenu(void);
/*
 * \brief Receive a number as a parameter and choose the option corresponding to this
 * \param Client *clientList
 * \param Loan *loanList
 * \param len
 * \param option is the number entered by the user
 * \return (-1) if invalid option. (0) if OK.
 *
 */
int optionMenu(int option, Client *clientList, Loan *loanList, int len, int count) ;
