/*
 * Uversidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2019/2
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Ewerton Vieira de Silles
 * Descricao: funcao que calcula um termo da serie de Fibonacci com recursividade

 * $Author: ewerton.silles $
 * $Date: 2019/08/28 22:04:12 $
 * $Log: aula0301a.c,v $
 * Revision 1.1  2019/08/28 22:04:12  ewerton.silles
 * Initial revision
 *
*/

#include "aula0301.h"

unsigned long long
CalcularTermoSerieFibonacci (unsigned short termo) {
	if (termo <= 1)
		return (unsigned long long) termo;
	return CalcularTermoSerieFibonacci(termo - 1) + CalcularTermoSerieFibonacci(termo - 2);
}
