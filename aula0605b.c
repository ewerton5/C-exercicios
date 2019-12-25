/*
 * Universidade Federal do Rio de Janeiro 
 * Escola Politecnica 
 * Departamento de Eletronica e de Computacao 
 * EEL270 - Computacao II - Turma 2019/2
 * Prof. Marcelo Luiz Drumond Lanza 
 * Autor: Ewerton Vieira de Silles
 * Descricao: programa de testes para a funcao GerarDigitoVerificadorPisPasep passando 1 argumento

 * $Author: ewerton.silles $ 
 * $Date: 2019/09/27 02:33:19 $ 
 * $Log: aula0605b.c,v $
 * Revision 1.2  2019/09/27 02:33:19  ewerton.silles
 * *** empty log message ***
 *
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
	char pisPasep [COMPRIMENTO_PIS_PASEP + 1];
	tipoErros codigoRetorno;
	if (argc != NUMERO_ARGUMENTOS) {
		printf ("Uso: %s <10_primeiros_digitos_pis/pasep>\n", argv [0]);
		exit (NUMERO_ARGUMENTOS_INVALIDO);
	}
	codigoRetorno = GerarDigitoVerificadorPisPasep(argv [1], pisPasep);
	if (codigoRetorno) {
		printf("Erro Executando a funcao GerarDigitoVerificadorPisPasep\n");
		printf("Erro #%i\n", codigoRetorno);
		exit(OK);
	}
	printf("Pis/Pasep: %s\n", pisPasep);
	return OK;
}
