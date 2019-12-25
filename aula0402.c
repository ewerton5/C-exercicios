/*
 * Universidade Federal do Rio de Janeiro 
 * Escola Politecnica 
 * Departamento de Eletronica e de Computacao 
 * EEL270 - Computacao II - Turma 2019/2
 * Prof. Marcelo Luiz Drumond Lanza 
 * Autor: Ewerton Vieira de Silles
 * Descricao: programa de testes para a funcao CalcularExponencial

 * $Author: ewerton.silles $ 
 * $Date: 2019/10/12 01:38:41 $ 
 * $Log: aula0402.c,v $
 * Revision 1.2  2019/10/12 01:38:41  ewerton.silles
 * *** empty log message ***
 *
 * Revision 1.1  2019/09/05 16:38:05  ewerton.silles
 * Initial revision
 *
*/

#include <stdio.h>
#include <stdlib.h>

#include "aula0401.h"

#define OK				0
#define NUMERO_ARGUMENTOS_INVALIDO	1
#define ARGUMENTO_INVALIDO		2

#define NUMERO_ARGUMENTOS 		3

#define EOS				'\0'

int main (int argc, char *argv [ ]) {
	char *validacao;
	double base;
	int expoente;
	if (argc != NUMERO_ARGUMENTOS) {
		printf ("Uso: %s <real> <inteiro>\n", argv [0]);
		exit (NUMERO_ARGUMENTOS_INVALIDO);
	}
	base = strtod(argv[1], &validacao);
	if (*validacao != EOS) {
		printf ("Argumento invalido.\n");
		printf ("Primeiro caractere invalido: \"%c\"\n", validacao[0]);
		exit (ARGUMENTO_INVALIDO);
	}
	expoente = (int) strtol(argv[2], &validacao, 10);
	if (*validacao != EOS) {
		printf ("Argumento invalido.\n");
		printf ("Primeiro caractere invalido: \"%c\"\n", validacao[0]);
		exit (ARGUMENTO_INVALIDO);
	}
	printf("%lg elevado a %i vale %Lg\n", base, expoente, CalcularExponencial(base, expoente));
	return OK;
}

/* $RCSfile: aula0402.c,v $ */
