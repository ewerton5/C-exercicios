/*
 * Uversidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2019/2
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Ewerton Vieira de Silles
 * Descricao: funcao que calcula a serie harmonica alternada ate um determinado limite com o laco for

 * $Author: ewerton.silles $
 * $Date: 2019/09/12 12:37:40 $
 * $Log: aula0501c.c,v $
 * Revision 1.1  2019/09/12 12:37:40  ewerton.silles
 * Initial revision
 *
*/

#include "aula0401.h"
#include "aula0501.h"

float
CalcularSerieHarmonicaAlternada (unsigned long int limite) {
	float resultado = 0;
	unsigned long contador;
	for (contador = 1; contador <= limite ; contador++)
		if (!(contador % 2))
			resultado -= 1/CalcularExponencial(contador, contador); 
		else
			resultado += 1/CalcularExponencial(contador, contador);
	return resultado;
}
