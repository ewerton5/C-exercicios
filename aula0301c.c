/*
 * Uversidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2019/2
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Ewerton Vieira de Silles
 * Descricao: funcao que calcula um termo da serie de Fibonacci com o laco for

 * $Author: ewerton.silles $
 * $Date: 2019/08/29 15:06:29 $
 * $Log: aula0301c.c,v $
 * Revision 1.1  2019/08/29 15:06:29  ewerton.silles
 * Initial revision
 *
*/

#include "aula0301.h"

unsigned long long
CalcularTermoSerieFibonacci (unsigned short termo) {
	unsigned long long operador1 = 0; 
	unsigned long long operador2 = 1; 
	unsigned long long auxiliar;
	unsigned short contador; 
	for (contador = 0; contador < termo; contador++) {
		auxiliar = operador2;
		operador2 = operador1 + operador2;
		operador1 = auxiliar;
	}
	return operador1;
}
