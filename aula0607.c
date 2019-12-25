/*
 * Universidade Federal do Rio de Janeiro 
 * Escola Politecnica 
 * Departamento de Eletronica e de Computacao 
 * EEL270 - Computacao II - Turma 2019/2
 * Prof. Marcelo Luiz Drumond Lanza 
 * Autor: Ewerton Vieira de Silles
 * Descricao: programa de testes para a funcao GerarPisPasep

 * $Author: ewerton.silles $ 
 * $Date: 2019/09/27 23:06:24 $ 
 * $Log: aula0607.c,v $
 * Revision 1.1  2019/09/27 23:06:24  ewerton.silles
 * Initial revision
 *
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "aula0601.h"

#define OK										0
#define NUMERO_ARGUMENTOS_INVALIDO		1

#define NUMERO_ARGUMENTOS 					1

int main (int argc, char *argv [ ]) {
	unsigned short indice;
	byte pisPasep [COMPRIMENTO_PIS_PASEP];
	tipoErros codigoRetorno;
	if (argc != NUMERO_ARGUMENTOS) {
		printf ("Uso: %s\n", argv [0]);
		exit (NUMERO_ARGUMENTOS_INVALIDO);
	}
	codigoRetorno = GerarPisPasep(pisPasep);
	if (codigoRetorno) {
		printf("Erro Executando a funcao GerarPisPasep\n");
		printf("Erro #%i\n", codigoRetorno);
		exit(OK);
	}
	printf("Pis/Pasep: ");
	for (indice = 0; indice < COMPRIMENTO_PIS_PASEP; indice++)
		printf("%u", pisPasep[indice]);
	printf("\n");
	return OK;
}
