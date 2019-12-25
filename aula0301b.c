/*
 * Uversidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2019/2
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Ewerton Vieira de Silles
 * Descricao: funcao que calcula um termo da serie de Fibonacci com o laco do while

 * $Author: ewerton.silles $
 * $Date: 2019/08/29 14:43:14 $
 * $Log: aula0301b.c,v $
 * Revision 1.2  2019/08/29 14:43:14  ewerton.silles
 * *** empty log message ***
 *
*/

#include "aula0301.h"

unsigned long long
CalcularTermoSerieFibonacci (unsigned short termo) {
	unsigned long long operador1 = 0; 
	unsigned long long operador2 = 1; 
	unsigned long long auxiliar;
	unsigned short contador = 0; 
	if (termo <= 1)
		return (unsigned long long) termo;
	do {
		auxiliar = operador2;
		operador2 = operador1 + operador2;
		operador1 = auxiliar;
		contador++;
	} while (contador < termo);
	return operador1;
}
