/*
 * Uversidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2019/2
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Ewerton Vieira de Silles
 * Descricao: funcao que calcula o maximo divisor comum entre dois numeros com o laco for

 * $Author: ewerton.silles $
 * $Date: 2019/08/26 20:59:18 $
 * $Log: aula0201c.c,v $
 * Revision 1.2  2019/08/26 20:59:18  ewerton.silles
 * *** empty log message ***
 *
 * Revision 1.1  2019/08/22 18:47:40  ewerton.silles
 * Initial revision
 * 
*/

#include "aula0201.h"

#define OK			1
#define ERRO			0

ull CalcularMaximoDivisorComum (ull numero1 , ull numero2) {
	ull menor;
	if (numero1 == 0 && numero2 == 0)
		return ERRO;
	if (numero1 == 0)
		return numero2;
	if (numero2 == 0)
		return numero1;
	for (menor = (numero1 < numero2) ? numero1 : numero2; menor > 0 ;menor-- ) {
		if (numero1 % menor == 0 && numero2 % menor == 0)
			return menor;
	}
	return OK;
}
