/*
 * Uversidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2019/2
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Ewerton Vieira de Silles
 * Descricao: funcao que calcula o exponencial de um numero com o laco while

 * $Author: ewerton.silles $
 * $Date: 2019/09/05 17:54:23 $
 * $Log: aula0401d.c,v $
 * Revision 1.1  2019/09/05 17:54:23  ewerton.silles
 * Initial revision
 *
*/

#include <math.h>
#include "aula0401.h"

long double
CalcularExponencial (double base, int expoente) {
	long double resultado = 1;
	if (base == 0 && expoente < 0)
		return INFINITY;
	if (expoente < 0) {
		expoente *= -1;
		base = 1/base;
	}
	if (expoente == 0)
		return 1;
	while (expoente > 0) {
		resultado *= base;
		expoente--;
	}
	return resultado;
}
