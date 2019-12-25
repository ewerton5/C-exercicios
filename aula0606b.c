/*
 * Universidade Federal do Rio de Janeiro 
 * Escola Politecnica 
 * Departamento de Eletronica e de Computacao 
 * EEL270 - Computacao II - Turma 2019/2
 * Prof. Marcelo Luiz Drumond Lanza 
 * Autor: Ewerton Vieira de Silles
 * Descricao: programa de testes para a funcao ValidarPisPasep passando 1 argumento

 * $Author: ewerton.silles $ 
 * $Date: 2019/09/24 04:37:30 $ 
 * $Log: aula0606b.c,v $
 * Revision 1.1  2019/09/24 04:37:30  ewerton.silles
 * Initial revision
 *
*/

#include <stdio.h>
#include <stdlib.h>

#include "aula0604.h"

#define OK										0
#define NUMERO_ARGUMENTOS_INVALIDO		1

#define NUMERO_ARGUMENTOS 					2

int main (int argc, char *argv [ ]) {
	tipoErros codigoRetorno;
	if (argc != NUMERO_ARGUMENTOS) {
		printf ("Uso: %s <pis/pasep>\n", argv [0]);
		exit (NUMERO_ARGUMENTOS_INVALIDO);
	}
	codigoRetorno = ValidarPisPasep(argv [1]);
	if (codigoRetorno && codigoRetorno != digitoInvalido) {
		printf("Erro Executando a funcao ValidarPisPasep\n");
		printf("Erro #%i\n", codigoRetorno);
		exit(OK);
	}
	if (!codigoRetorno)
		printf("Pis/Pasep valido.\n");
	else
		printf("Pis/Pasep invalido.\n");
	return OK;
}
