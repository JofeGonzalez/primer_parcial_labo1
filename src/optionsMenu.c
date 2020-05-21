/*
 ============================================================================
 Name        : optionsMenu.c
 Author      : Jose Gonzalez
 Version     : 1.0
 ============================================================================
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "utn.h"
#include "optionsMenu.h"

void printMenu(void) {
	printf("1. Alta de Cliente\n");
	printf("2. Modificar Datos de Cliente\n");
	printf("3. Baja de Cliente\n");
	printf("4. Crear Prestamo\n");
	printf("5. Saldar Prestamo\n");
	printf("6. Renaudar Prestamo\n");
	printf("7. Imprimir Clientes\n");
	printf("8. Imprimir Prestamos\n");
	printf("9. Informar Clientes\n");
	printf("	a) Cliente con mas prestamos activos\n");
	printf("	b) Cliente con mas prestamos saldados\n");
	printf("	c) Cliente con mas prestamos\n");
	printf("10. Informar Prestamos\n");
	printf("    a) Prestamos de importe mayor a 1000\n");
	printf("    b) Prestamos de 12 cuotas saldados\n");
	printf("    c) Prestamos por cuotas\n");
}

int optionMenu(int option, Client *clientList, Loan *loanList, int len,
		int count) {
	int AddClientCount = count;
	int addClientDone;
	char printClientOption;
	int changeClientDone;
	int changeClientDataID;
	int removeDataid;
	char removeClientOption;
	int removeClientDone;
	int addLoanDone;
	int payOffLoanID;
	char payOffLoanOption;
	int removePayOffLoan;
	int resumeLoanID;
	char resumeLoanOption;
	int resumeLoanDone;
	float printAmount;
	char printLoanOption;
	int printEspecificFeesLoans;
	switch (option) {
	case 1:
		addClientDone = chargeClientData(clientList, len);
		if (addClientDone != -1) {
			printf("Alta realizada, ID del cliente: %d\n", addClientDone + 1);
			AddClientCount++;
		} else {
			printf("No se pudo agregar el cliente\n");
		}
		break;
	case 2:
		if (AddClientCount != 0) {
			printf("Ingrese el ID del cliente: \n");
			scanf("%d", &changeClientDataID);
			setbuf(stdin, NULL);
			changeClientDone = changeClientData(clientList, len,
					changeClientDataID);
			if (changeClientDone != -1) {
				printf("Modificacion realizada, ID del cliente: %d\n",
						changeClientDone + 1);
			} else {
				printf("No se pudo modificar los datos del cliente\n");
			}
		} else {
			printf("No puede modificar sin antes haber ingresado un cliente\n");
		}
		break;
	case 3:
		if (AddClientCount != 0) {
			printf("Ingrese el ID del cliente: \n");
			scanf("%d", &removeDataid);
			setbuf(stdin, NULL);
			printEspecificClientLoans(clientList, loanList, len, removeDataid);
			printf("Quiere darle de baja a este cliente? (s or n)\n");
			scanf("%c", &removeClientOption);
			setbuf(stdin, NULL);
			switch (removeClientOption) {
			case 's':
				removeClientDone = removeClient(clientList, removeDataid);
				if (removeClientDone == 0) {
					printf("Baja exitosa\n");
					AddClientCount--;
				} else {
					printf("No se pudo dar de baja al cliente\n");
				}
				break;
			case 'n':
				printf("No se realizo ninguna baja\n");
				break;
			default:
				printf("La opcion ingresada no es valida\n");
				break;
			}
		} else {
			printf("No puede eliminar sin antes haber agregado un cliente\n");
		}
		break;
	case 4:
		if (AddClientCount != 0) {
			addLoanDone = chargeLoanData(loanList, len);
			if (addLoanDone != -1) {
				printf("Alta realizada, ID del prestamo: %d\n",
						addLoanDone + 1);
			} else {
				printf("No se pudo agregar el prestamo\n");
			}
		} else {
			printf(
					"No se puede crear un prestamo sin antes haber agregado un cliente\n");
		}
		break;
	case 5:
		if (AddClientCount != 0) {
			printf("Ingrese el ID del prestamo: \n");
			scanf("%d", &payOffLoanID);
			setbuf(stdin, NULL);
			printEspecificClient(clientList, loanList, len, payOffLoanID);
			printf("Quiere saldar este prestamo? (s or n)\n");
			scanf("%c", &payOffLoanOption);
			setbuf(stdin, NULL);
			switch (payOffLoanOption) {
			case 's':
				removePayOffLoan = payOffLoan(loanList, payOffLoanID);
				if (removePayOffLoan == 0) {
					printf("Prestamo saldado\n");
				} else {
					printf("No se pudo saldar el prestamo\n");
				}
				break;
			case 'n':
				printf("No se realizo ningun cambio\n");
				break;
			default:
				printf("La opcion ingresada no es valida\n");
				break;
			}
		} else {
			printf(
					"No se pueden saldar prestamos sin antes haber cargado un cliente\n");
		}
		break;
	case 6:
		if (AddClientCount != 0) {
			printf("Ingrese el ID del prestamo: \n");
			scanf("%d", &resumeLoanID);
			setbuf(stdin, NULL);
			printEspecificClient(clientList, loanList, len, resumeLoanID);
			printf("Quiere reanudar este prestamo? (s or n)\n");
			scanf("%c", &resumeLoanOption);
			setbuf(stdin, NULL);
			switch (resumeLoanOption) {
			case 's':
				resumeLoanDone = resumeLoan(loanList, resumeLoanID);
				if (resumeLoanDone == 0) {
					printf("Prestamo reanudado\n");
				} else {
					printf("No se pudo reanudar el prestamo\n");
				}
				break;
			case 'n':
				printf("No se realizo ningun cambio\n");
				break;
			default:
				printf("La opcion ingresada no es valida\n");
				break;
			}
		} else {
			printf(
					"No se pueden reanudar prestamos sin antes haber cargado un cliente");
		}
		break;
	case 7:
		if (AddClientCount != 0) {
			printClientLoans(clientList, loanList, len);
		} else {
			printf(
					"No se puede imprimir la lista de clientes ya que no ha ingresado ninguno\n");
		}
		break;
	case 8:
		if (AddClientCount != 0) {
			printActiveLoans(clientList, loanList, len);
		} else {
			printf(
					"No se pueden imprimir los prestamos sin antes haber incluido un cliente\n");
		}
		break;
	case 9:
		if (AddClientCount != 0) {
			printf("Que desea Informar?");
			scanf("%c", &printClientOption);
			setbuf(stdin, NULL);
			switch (printClientOption) {
			case 'a':
				printClientMoreActiveLoans(clientList, loanList, len);
				break;
			case 'b':
				printClientMorePayOffLoans(clientList, loanList, len);
				break;
			case 'c':
				printClientMoreLoans(clientList, loanList, len);
				break;
			default:
				printf("La opcion ingresada no es valida\n");
				break;
			}
		} else {
			printf(
					"No se puede imprimir la lista de clientes ya que no ha ingresado ninguno\n");
		}
		break;
	case 10:
		printf("Que desea Informar?");
		scanf("%c", &printLoanOption);
		setbuf(stdin, NULL);
		switch (printLoanOption) {
		case 'a':
			printf("Ingrese el monto: \n");
			scanf("%f", &printAmount);
			setbuf(stdin, NULL);
			printEspecificAmountLoans(loanList, len, printAmount);
			break;
		case 'b':
			print12LoansFees(loanList, len);
			break;
		case 'c':
			printf("Ingrese el numero de cuotas: \n");
			scanf("%d", &printEspecificFeesLoans);
			setbuf(stdin, NULL);
			printEspecificFeesLoan(loanList, len, printEspecificFeesLoans);
			break;
		default:
			printf("La opcion ingresada no es valida\n");
			break;
		}
		break;
	default:
		printf("La opcion ingresada no es valida\n");
		break;
	}
	return AddClientCount;
}
