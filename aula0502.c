/*
 * Universidade Federal do Rio de Janeiro 
 * Escola Politecnica 
 * Departamento de Eletronica e de Computacao 
 * EEL270 - Computacao II - Turma 2019/2
 * Prof. Marcelo Luiz Drumond Lanza 
 * Autor: Ewerton Vieira de Silles
 * Descricao: programa de testes para a funcao CalcularSerieHarmonicaAlternada

 * $Author: ewerton.silles $ 
 * $Date: 2019/10/12 01:23:00 $ 
 * $Log: aula0502.c,v $
 * Revision 1.3  2019/10/12 01:23:00  ewerton.silles
 * *** empty log message ***
 *
 * Revision 1.2  2019/10/12 01:17:13  ewerton.silles
 * *** empty log message ***
 *
 * Revision 1.1  2019/09/11 13:30:57  ewerton.silles
 * Initial revision
 *
*/

#include <stdio.h>
#include <stdlib.h>

#include "aula0501.h"

#define OK										0
#define NUMERO_ARGUMENTOS_INVALIDO		1
#define ARGUMENTO_INVALIDO					2
#define ARGUMENTO_NEGATIVO					3

#define NUMERO_ARGUMENTOS 					2

#define EOS				'\0'

int main (int argc, char *argv [ ]) {
	char *validacao;
	unsigned long limite;
	if (argc != NUMERO_ARGUMENTOS) {
		printf ("Uso: %s <inteiro-nao-negativo>\n", argv [0]);
		exit (NUMERO_ARGUMENTOS_INVALIDO);
	}
	if (argv[1][0] == '-') {
		printf ("Entre apenas com numeros positivos.\n");
		exit (ARGUMENTO_NEGATIVO);
	}	
	limite = strtoul(argv[1], &validacao, 10);
	if (*validacao != EOS) {
		printf ("Argumento invalido.\n");
		printf ("Primeiro caractere invalido: \"%c\"\n", validacao[0]);
		exit (ARGUMENTO_INVALIDO);
	}
	printf("S(%lu) = %g\n", limite, CalcularSerieHarmonicaAlternada(limite));
	return OK;
}

/* $RCSfile: aula0502.c,v $ */
