/*
 * Uversidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2019/2
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Ewerton Vieira de Silles
 * Descricao: funcao que calcula o maximo divisor comum entre dois numeros com recursividade

 * $Author: ewerton.silles $
 * $Date: 2019/08/21 01:41:08 $
 * $Log: aula0201a.c,v $
 * Revision 1.1  2019/08/21 01:41:08  ewerton.silles
 * Initial revision
 * 
*/

#include "aula0201.h"

#define ERRO			0

ull CalcularMaximoDivisorComum (ull numero1 , ull numero2) {
	if (numero1 == 0 && numero2 == 0)
		return ERRO;
	if (numero1 == 0)
		return numero2;
	if (numero2 == 0)
		return numero1;
	if (numero1 % numero2 == 0)
		return numero2;
	return CalcularMaximoDivisorComum(numero2, numero1 % numero2);
}
