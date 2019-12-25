/*
 * Universidade Federal do Rio de Janeiro 
 * Escola Politecnica 
 * Departamento de Eletronica e de Computacao 
 * EEL270 - Computacao II - Turma 2019/2
 * Prof. Marcelo Luiz Drumond Lanza 
 * Autor: Ewerton Vieira de Silles
 * Descricao: programa de testes para a funcao ValidarPisPasep passando 1 argumento

 * $Author: ewerton.silles $ 
 * $Date: 2019/09/24 03:01:05 $ 
 * $Log: aula0603b.c,v $
 * Revision 1.2  2019/09/24 03:01:05  ewerton.silles
 * *** empty log message ***
 *
 * Revision 1.1  2019/09/24 02:20:25  ewerton.silles
 * Initial revision
 *
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "aula0601.h"

#define OK										0
#define NUMERO_ARGUMENTOS_INVALIDO		1
#define ARGUMENTO_INVALIDO					2
#define ARGUMENTO_NEGATIVO					3

#define NUMERO_ARGUMENTOS 					2
#define NUMERO_DIGITOS						11

#define EOS										'\0'

int main (int argc, char *argv [ ]) {
	unsigned short indice;
	char *validacao;
	byte pisPasep [COMPRIMENTO_PIS_PASEP];
	tipoErros codigoRetorno;
	if (argc != NUMERO_ARGUMENTOS) {
		printf ("Uso: %s <pis/pasep>\n", argv [0]);
		exit (NUMERO_ARGUMENTOS_INVALIDO);
	}
	if (strlen(argv[1]) != NUMERO_DIGITOS) {
		printf("Argumento invalido. Entre com 11 algarismos.\n");
		exit(ARGUMENTO_INVALIDO);
	}
	if (argv[1][0] == '-') {
		printf("Argumento invalido. O Pis/Pasep nao pode ser um numero negativo.\n");
		exit(ARGUMENTO_NEGATIVO);
	}
	strtoul(argv[1], &validacao, 10);
	if (*validacao != EOS) {
		printf ("Argumento invalido.\n");
		printf ("Primeiro caractere invalido: \"%c\"\n", validacao[0]);
		exit (ARGUMENTO_INVALIDO);
	}
	for (indice = 0; indice < NUMERO_DIGITOS; indice++)
		pisPasep [indice] = (byte) (argv[1][indice] - '0');
	codigoRetorno = ValidarPisPasep(pisPasep);
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
