/*
 * Universidade Federal do Rio de Janeiro 
 * Escola Politecnica 
 * Departamento de Eletronica e de Computacao 
 * EEL270 - Computacao II - Turma 2019/2
 * Prof. Marcelo Luiz Drumond Lanza 
 * Autor: Ewerton Vieira de Silles
 * Descricao: programa de testes para a funcao CalcularMaximoDivisorComum

 * $Author: ewerton.silles $ 
 * $Date: 2019/08/21 01:41:23 $ 
 * $Log: aula0202.c,v $
 * Revision 1.1  2019/08/21 01:41:23  ewerton.silles
 * Initial revision
 *
 *
*/

#include <stdio.h>
#include <stdlib.h>

#include "aula0201.h"

#define OK				0
#define NUMERO_ARGUMENTOS_INVALIDO	1
#define ARGUMENTO_INVALIDO		2

#define NUMERO_ARGUMENTOS 		3

#define EOS				'\0'

int main (int argc, char *argv [ ]) {
	unsigned indice;
	unsigned argcont;
	if (argc != NUMERO_ARGUMENTOS) {
		printf ("Uso: %s <inteiro-nao-negativo> <inteiro-nao-negativo>\n", argv [0]);
		exit (NUMERO_ARGUMENTOS_INVALIDO);
	}
	for (argcont = 1; argcont < argc; argcont++)
		for (indice = 0; argv [argcont][indice] != EOS; indice++)
			if (argv [argcont][indice] < '0' || argv [argcont][indice] > '9') {
				printf ("Argumento invalido.\n");
				printf ("Primeiro caractere invalido: \"%c\"\n", argv [argcont][indice]);
				exit (ARGUMENTO_INVALIDO);
			}
	printf("O MDC entre %s e %s vale %llu\n", argv[1], argv[2], 
		CalcularMaximoDivisorComum((ull) atoi (argv[1]), (ull) atoi (argv[2])));
	return OK;
}

/* $RCSfile: aula0202.c,v $ */
