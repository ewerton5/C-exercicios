/*
 * Uversidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2019/2
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Ewerton Vieira de Silles
 * Descricao: funcao que calcula a serie harmonica alternada ate um determinado limite com o laco while

 * $Author: ewerton.silles $
 * $Date: 2019/09/12 12:51:13 $
 * $Log: aula0501d.c,v $
 * Revision 1.1  2019/09/12 12:51:13  ewerton.silles
 * Initial revision
 *
*/

#include "aula0401.h"
#include "aula0501.h"

float
CalcularSerieHarmonicaAlternada (unsigned long int limite) {
	float resultado = 0;
	unsigned long contador = 1;
	while (contador <= limite) {
		if (!(contador % 2))
			resultado -= 1/CalcularExponencial(contador, contador); 
		else
			resultado += 1/CalcularExponencial(contador, contador);
		contador++;
	}
	return resultado;
}
