/*
 * Universidade Federal do Rio de Janeiro 
 * Escola Politecnica 
 * Departamento de Eletronica e de Computacao 
 * EEL270 - Computacao II - Turma 2019/2
 * Prof. Marcelo Luiz Drumond Lanza 
 * Autor: Ewerton Vieira de Silles
 * Descricao: programa de testes para a funcao CodificarBase64

 * $Author: ewerton.silles $ 
 * $Date: 2019/10/22 04:20:25 $ 
 * $Log: aula0902.c,v $
 * Revision 1.2  2019/10/22 04:20:25  ewerton.silles
 * *** empty log message ***
 *
 * Revision 1.1  2019/10/20 05:36:29  ewerton.silles
 * Initial revision
 *
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "aula0901.h"

#define OK									0
#define NUMERO_ARGUMENTOS_INVALIDO	1
#define ARGUMENTO_INVALIDO				2
#define ARGUMENTO_NEGATIVO				3

#define NUMERO_MINIMO_ARGUMENTOS		3
#define NUMERO_MAXIMO_ARGUMENTOS		1026
#define NUMERO_MAXIMO_BYTES			1024
#define NUMERO_MAXIMO_SAIDA			1366

int main (int argc, char *argv [ ]) {
	unsigned short indice;
	char *validacao;
	unsigned numeroBytes;
	byte entrada [NUMERO_MAXIMO_BYTES];
	char saida [NUMERO_MAXIMO_SAIDA];
	tipoErros codigoRetorno;
	if (argc < NUMERO_MINIMO_ARGUMENTOS || argc > NUMERO_MAXIMO_ARGUMENTOS) {
		printf ("Uso: %s <numero_de_bytes> <primeiro_byte_em_hexadecimal> ... <ultimo_byte_em_hexadecimal>(maximo=1024)\n", argv [0]);
		exit (NUMERO_ARGUMENTOS_INVALIDO);
	}
	if (argv[1][0] == '-') {
		printf("O numero de bytes deve ser positivo.\n");
		exit(ARGUMENTO_NEGATIVO);
	}
	numeroBytes = (unsigned) strtoul(argv[1], &validacao, 10);
	if (*validacao != EOS) {
		printf ("Argumento invalido.\n");
		printf ("Primeiro caractere invalido: \"%c\"\n", validacao[0]);
		exit (ARGUMENTO_INVALIDO);
	}
	if (argc - 2 != numeroBytes) {
		printf ("Uso: %s <numero_de_bytes> <primeiro_byte_em_hexadecimal> ... <ultimo_byte_em_hexadecimal>(maximo=1024)\n", argv [0]);
		exit (NUMERO_ARGUMENTOS_INVALIDO);
	}
	for (indice = 2; indice < argc; indice++) {
		if (strlen(argv[indice]) > 2) {
			printf("O argumento nao e um byte.\n");
			exit(ARGUMENTO_INVALIDO);
		}
		if (argv[indice][0] == '-') {
			printf("Os bytes devem ser positivos.\n");
			exit(ARGUMENTO_NEGATIVO);
		}
		entrada[indice - 2] = (byte) strtoul(argv[indice], &validacao, 16);
		if (*validacao != EOS) {
			printf ("Argumento invalido.\n");
			printf ("Primeiro caractere invalido: \"%c\"\n", validacao[0]);
			exit (ARGUMENTO_INVALIDO);
		}
	}
	codigoRetorno = CodificarBase64(entrada, numeroBytes, saida);
	if (codigoRetorno) {
		printf("Erro executando a funcao CodificarBase64.\n");
		printf("Erro: #%u\n", codigoRetorno);
		exit(OK);
	}
	printf("Codigo Base64: %s\n", saida);
	return OK;
}
