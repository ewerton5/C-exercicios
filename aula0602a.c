/*
 * Universidade Federal do Rio de Janeiro 
 * Escola Politecnica 
 * Departamento de Eletronica e de Computacao 
 * EEL270 - Computacao II - Turma 2019/2
 * Prof. Marcelo Luiz Drumond Lanza 
 * Autor: Ewerton Vieira de Silles
 * Descricao: programa de testes para a funcao GerarDigitoVerificadorPisPasep passando 10 argumentos

 * $Author: ewerton.silles $ 
 * $Date: 2019/09/23 23:58:35 $ 
 * $Log: aula0602a.c,v $
 * Revision 1.4  2019/09/23 23:58:35  ewerton.silles
 * *** empty log message ***
 *
 * Revision 1.3  2019/09/23 22:47:17  ewerton.silles
 * *** empty log message ***
 *
 * Revision 1.2  2019/09/23 22:32:57  ewerton.silles
 * *** empty log message ***
 *
 * Revision 1.1  2019/09/23 21:25:19  ewerton.silles
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

#define NUMERO_ARGUMENTOS 					11
#define ALGARISMO 							1

#define EOS										'\0'

int main (int argc, char *argv [ ]) {
	unsigned short indice;
	char *validacao;
	byte pisPasep [COMPRIMENTO_PIS_PASEP];
	tipoErros codigoRetorno;
	if (argc != NUMERO_ARGUMENTOS) {
		printf ("Uso: %s <d1> <d2> <d3> <d4> <d5> <d6> <d7> <d8> <d9> <d10>\n", argv [0]);
		exit (NUMERO_ARGUMENTOS_INVALIDO);
	}
	for (indice = 1; indice < argc; indice++)
		if (strlen(argv[indice]) > ALGARISMO) {
			printf("Argumento invalido. Entre apenas com algarismos.\n");
			exit(ARGUMENTO_INVALIDO);
		}
	for (indice = 0; indice < NUMERO_ARGUMENTOS - 1; indice++) {
		pisPasep [indice] = (byte) strtoul(argv[indice + 1], &validacao, 10);
		if (*validacao != EOS) {
			printf ("Argumento invalido.\n");
			printf ("Primeiro caractere invalido: \"%c\"\n", validacao[0]);
			exit (ARGUMENTO_INVALIDO);
		}
	}
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
