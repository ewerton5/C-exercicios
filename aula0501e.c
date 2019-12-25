/*
 * Uversidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2019/2
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Ewerton Vieira de Silles
 * Descricao: funcao que calcula a serie harmonica alternada ate um determinado limite com recursividade e a funcao pow

 * $Author: ewerton.silles $
 * $Date: 2019/09/15 00:24:03 $
 * $Log: aula0501e.c,v $
 * Revision 1.1  2019/09/15 00:24:03  ewerton.silles
 * Initial revision
 *
*/

#include <math.h>
#include "aula0501.h"

float
CalcularSerieHarmonicaAlternada (unsigned long int limite) {
	if (limite == 0)
		return 0;
	if (!(limite % 2))
		return - 1/pow(limite, limite) + CalcularSerieHarmonicaAlternada(limite - 1); 
	return 1/pow(limite, limite) + CalcularSerieHarmonicaAlternada(limite - 1);
}
