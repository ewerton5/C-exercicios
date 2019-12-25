/*
 * Uversidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2019/2
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Ewerton Vieira de Silles
 * Descricao: funcao que calcula o exponencial de um numero com recursividade

 * $Author: ewerton.silles $
 * $Date: 2019/09/05 17:48:23 $
 * $Log: aula0401a.c,v $
 * Revision 1.3  2019/09/05 17:48:23  ewerton.silles
 * *** empty log message ***
 *
 * Revision 1.2  2019/09/05 16:56:19  ewerton.silles
 * *** empty log message ***
 *
 * Revision 1.1  2019/09/05 16:38:10  ewerton.silles
 * Initial revision
 *
*/

#include <math.h>
#include "aula0401.h"

long double
CalcularExponencial (double base, int expoente) {
	if (base == 0 && expoente < 0)
		return INFINITY;
	if (expoente < 0) {
		expoente *= -1;
		base = 1/base;
	}
	if (expoente == 0)
		return 1;
	return base * CalcularExponencial(base, expoente - 1);	
}
