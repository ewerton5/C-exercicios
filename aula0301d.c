/*
 * Uversidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2019/2
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Ewerton Vieira de Silles
 * Descricao: funcao que calcula um termo da serie de Fibonacci com o laco  while

 * $Author: ewerton.silles $
 * $Date: 2019/08/29 15:20:49 $
 * $Log: aula0301d.c,v $
 * Revision 1.1  2019/08/29 15:20:49  ewerton.silles
 * Initial revision
 *
*/

#include "aula0301.h"

unsigned long long
CalcularTermoSerieFibonacci (unsigned short termo) {
	unsigned long long operador1 = 0; 
	unsigned long long operador2 = 1; 
	unsigned long long auxiliar;
	unsigned short contador = 0; 
	while (contador < termo) {
		auxiliar = operador2;
		operador2 = operador1 + operador2;
		operador1 = auxiliar;
		contador++;
	}
	return operador1;
}
