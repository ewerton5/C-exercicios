/*
 * Uversidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2019/2
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Ewerton Vieira de Silles
 * Descricao: funcao que calcula a serie harmonica alternada ate um determinado limite com o laco do while

 * $Author: ewerton.silles $
 * $Date: 2019/09/12 12:23:13 $
 * $Log: aula0501b.c,v $
 * Revision 1.2  2019/09/12 12:23:13  ewerton.silles
 * *** empty log message ***
 *
 * Revision 1.1  2019/09/12 12:16:51  ewerton.silles
 * Initial revision
 *
*/

#include "aula0401.h"
#include "aula0501.h"

float
CalcularSerieHarmonicaAlternada (unsigned long int limite) {
	float resultado = 0;
	unsigned long contador = 1;
	if (limite == 0)
		return 0;
	do {
		if (!(contador % 2))
			resultado -= 1/CalcularExponencial(contador, contador); 
		else
			resultado += 1/CalcularExponencial(contador, contador);
		contador++;
	} while (contador <= limite);
	return resultado;
}
