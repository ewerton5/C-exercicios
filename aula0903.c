/*
 * Universidade Federal do Rio de Janeiro 
 * Escola Politecnica 
 * Departamento de Eletronica e de Computacao 
 * EEL270 - Computacao II - Turma 2019/2
 * Prof. Marcelo Luiz Drumond Lanza 
 * Autor: Ewerton Vieira de Silles
 * Descricao: programa de testes para a funcao DecodificarBase64

 * $Author: ewerton.silles $ 
 * $Date: 2019/10/22 04:26:31 $ 
 * $Log: aula0903.c,v $
 * Revision 1.1  2019/10/22 04:26:31  ewerton.silles
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

#define NUMERO_ARGUMENTOS				2
#define NUMERO_MAXIMO_BYTES			1024

int main (int argc, char *argv [ ]) {
	unsigned short indice;
	unsigned numeroBytes;
	byte saida [NUMERO_MAXIMO_BYTES];
	tipoErros codigoRetorno;
	if (argc != NUMERO_ARGUMENTOS) {
		printf ("Uso: %s <codigo_64>\n", argv [0]);
		exit (NUMERO_ARGUMENTOS_INVALIDO);
	}
	codigoRetorno = DecodificarBase64(argv[1], saida, &numeroBytes);
	if (codigoRetorno) {
		printf("Erro executando a funcao DecodificarBase64.\n");
		printf("Erro: #%u\n", codigoRetorno);
		exit(OK);
	}
	printf("Hexadecimal decoded: %02X", saida[0]);
	for (indice = 1; indice < numeroBytes; indice++)
		printf(" %02X", saida[indice]);
	printf("\n");
	return OK;
}
