/*
 * Universidade Federal do Rio de Janeiro 
 * Escola Politecnica 
 * Departamento de Eletronica e de Computacao 
 * EEL270 - Computacao II - Turma 2019/2
 * Prof. Marcelo Luiz Drumond Lanza 
 * Autor: Ewerton Vieira de Silles
 * Descricao: programa de testes para a funcao ValidarPisPasep passando 11 argumentos

 * $Author: ewerton.silles $ 
 * $Date: 2019/09/27 02:33:19 $ 
 * $Log: aula0606a.c,v $
 * Revision 1.2  2019/09/27 02:33:19  ewerton.silles
 * *** empty log message ***
 *
 * Revision 1.1  2019/09/24 04:37:30  ewerton.silles
 * Initial revision
 *
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "aula0604.h"

#define OK										0
#define NUMERO_ARGUMENTOS_INVALIDO		1

#define NUMERO_ARGUMENTOS 					12

int main (int argc, char *argv [ ]) {
	unsigned short indice;
	char pisPasep [COMPRIMENTO_PIS_PASEP + 2] = "";
	tipoErros codigoRetorno;
	if (argc != NUMERO_ARGUMENTOS) {
		printf ("Uso: %s <d1> <d2> <d3> <d4> <d5> <d6> <d7> <d8> <d9> <d10> <d11>\n", argv [0]);
		exit (NUMERO_ARGUMENTOS_INVALIDO);
	}
	for (indice = 1; indice < argc; indice++)
		strcat(pisPasep, argv [indice]);
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
