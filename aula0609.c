/*
 * Universidade Federal do Rio de Janeiro 
 * Escola Politecnica 
 * Departamento de Eletronica e de Computacao 
 * EEL270 - Computacao II - Turma 2019/2
 * Prof. Marcelo Luiz Drumond Lanza 
 * Autor: Ewerton Vieira de Silles
 * Descricao: programa de testes para a funcao GerarDigitoVerificadorPisPasep

 * $Author: ewerton.silles $ 
 * $Date: 2019/09/28 00:20:20 $ 
 * $Log: aula0609.c,v $
 * Revision 1.1  2019/09/28 00:20:20  ewerton.silles
 * Initial revision
 *
*/

#include <stdio.h>
#include <stdlib.h>

#include "aula0608.h"

#define OK										0
#define NUMERO_ARGUMENTOS_INVALIDO		1

#define NUMERO_ARGUMENTOS 					2

int main (int argc, char *argv [ ]) {
	unsigned short indice;
	char pisPasep [COMPRIMENTO_PIS_PASEP + 1];
	tipoErros codigoRetorno;
	if (argc != NUMERO_ARGUMENTOS) {
		printf ("Uso: %s <10_primeiros_digitos_pis/pasep>\n", argv [0]);
		exit (NUMERO_ARGUMENTOS_INVALIDO);
	}
	for (indice = 0; indice < COMPRIMENTO_PIS_PASEP; indice++)
		pisPasep [indice] = argv [1][indice];
	codigoRetorno = GerarDigitoVerificadorPisPasep(pisPasep);
	if (codigoRetorno) {
		printf("Erro Executando a funcao GerarDigitoVerificadorPisPasep\n");
		printf("Erro #%i\n", codigoRetorno);
		exit(OK);
	}
	printf("Pis/Pasep: %s\n", pisPasep);
	return OK;
}
