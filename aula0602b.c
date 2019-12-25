/*
 * Universidade Federal do Rio de Janeiro 
 * Escola Politecnica 
 * Departamento de Eletronica e de Computacao 
 * EEL270 - Computacao II - Turma 2019/2
 * Prof. Marcelo Luiz Drumond Lanza 
 * Autor: Ewerton Vieira de Silles
 * Descricao: programa de testes para a funcao GerarDigitoVerificadorPisPasep passando 1 argumento

 * $Author: ewerton.silles $ 
 * $Date: 2019/09/23 23:58:35 $ 
 * $Log: aula0602b.c,v $
 * Revision 1.2  2019/09/23 23:58:35  ewerton.silles
 * *** empty log message ***
 *
 * Revision 1.1  2019/09/23 22:55:21  ewerton.silles
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
#define NUMERO_DIGITOS						10

#define EOS										'\0'

int main (int argc, char *argv [ ]) {
	unsigned short indice;
	char *validacao;
	byte pisPasep [COMPRIMENTO_PIS_PASEP];
	tipoErros codigoRetorno;
	if (argc != NUMERO_ARGUMENTOS) {
		printf ("Uso: %s <10_primeiros_digitos_pis/pasep>\n", argv [0]);
		exit (NUMERO_ARGUMENTOS_INVALIDO);
	}
	if (strlen(argv[1]) != NUMERO_DIGITOS) {
		printf("Argumento invalido. Entre com 10 algarismos.\n");
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
	codigoRetorno = GerarDigitoVerificadorPisPasep(pisPasep);
	if (codigoRetorno) {
		printf("Erro Executando a funcao GerarDigitoVerificadorPisPasep\n");
		printf("Erro #%i\n", codigoRetorno);
		exit(OK);
	}
	printf("Pis/Pasep: ");
	for (indice = 0; indice < COMPRIMENTO_PIS_PASEP; indice++)
		printf("%u", pisPasep[indice]);
	printf("\n");
	return OK;
}
