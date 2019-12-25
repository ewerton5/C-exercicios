/*
 * Universidade Federal do Rio de Janeiro 
 * Escola Politecnica 
 * Departamento de Eletronica e de Computacao 
 * EEL270 - Computacao II - Turma 2019/2
 * Prof. Marcelo Luiz Drumond Lanza 
 * Autor: Ewerton Vieira de Silles
 * Descricao: programa de testes para a funcao PreencherPoligono

 * $Author: ewerton.silles $ 
 * $Date: 2019/10/14 21:05:48 $ 
 * $Log: aula0802.c,v $
 * Revision 1.1  2019/10/14 21:05:48  ewerton.silles
 * Initial revision
 *
*/

#include <stdio.h>
#include <stdlib.h>

#include "aula0801.h"

#define OK									0
#define NUMERO_ARGUMENTOS_INVALIDO	1
#define ARGUMENTO_INVALIDO				2
#define ARGUMENTO_NEGATIVO				3
#define NUMERO_LINHAS_INVALIDO		4
#define NUMERO_COLUNAS_INVALIDO		5

#define NUMERO_ARGUMENTOS 				10

#define EOS									'\0'

int main (int argc, char *argv [ ]) {
	unsigned short linha, coluna, indice;
	char *validacao;
	unsigned args [NUMERO_ARGUMENTOS - 1];
	unsigned maximoLinhas, maximoColunas, ordenadaCantoEsquerdo, abscissaCantoEsquerdo,
	         ordenadaCantoDireito, abscissaCantoDireito, ordenada, abscissa;
	__useconds_t tempoEspera;
	tipoPixel monitor [NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS];
	tipoErros codigoRetorno;
	if (argc != NUMERO_ARGUMENTOS) {
		printf ("Uso: %s <linhas> <colunas> <ordenada_esquerda> <abscissa_esquerda> <ordenada_direita> <abscissa_direita> <ordenada_ponto> <abscissa_ponto> <tempo>", argv [0]);
		exit (NUMERO_ARGUMENTOS_INVALIDO);
	}
	for (indice = 1; indice < argc; indice++) {
		if (argv[indice][0] == '-') {
			printf("Entre apenas com numeros positivos.\n");
			exit(ARGUMENTO_NEGATIVO);
		}
		args[indice - 1] = (unsigned) strtoul(argv[indice], &validacao, 10);
		if (*validacao != EOS) {
			printf ("Argumento invalido.\n");
			printf ("Primeiro caractere invalido: \"%c\"\n", validacao[0]);
			exit (ARGUMENTO_INVALIDO);
		}
	}
	maximoLinhas = args[0];
	if (maximoLinhas > NUMERO_MAXIMO_LINHAS) {
		printf("Numero maximo de linhas ultrapassado.\n");
		exit(NUMERO_LINHAS_INVALIDO);
	}
	maximoColunas = args[1];
	if (maximoColunas > NUMERO_MAXIMO_COLUNAS) {
		printf("Numero maximo de linhas ultrapassado.\n");
		exit(NUMERO_COLUNAS_INVALIDO);
	}
	ordenadaCantoEsquerdo = args[2];
	abscissaCantoEsquerdo = args[3];
	ordenadaCantoDireito = args[4];
	abscissaCantoDireito = args[5];
	ordenada = args[6];
	abscissa = args[7];
	tempoEspera = (__useconds_t) args[8];
	for (linha = 0; linha < maximoLinhas; linha++)
		for (coluna = 0; coluna < maximoColunas; coluna++)
			monitor [linha][coluna] = aceso;
	codigoRetorno = LimparMonitor(monitor, maximoLinhas, maximoColunas, tempoEspera);
	if (codigoRetorno) {
		printf("Erro executando a funcao LimparMonitor.\n");
		printf("Erro: #%u\n", codigoRetorno);
		exit(OK);
	}
	codigoRetorno = MostrarMonitor(monitor, maximoLinhas, maximoColunas, tempoEspera);
	if (codigoRetorno) {
		printf("Erro executando a funcao MostrarMonitor.\n");
		printf("Erro: #%u\n", codigoRetorno);
		exit(OK);
	}
	codigoRetorno = DesenharRetangulo(monitor, maximoLinhas, maximoColunas, ordenadaCantoEsquerdo,
	                                  abscissaCantoEsquerdo, ordenadaCantoDireito, abscissaCantoDireito, tempoEspera);
	if (codigoRetorno) {
		printf("Erro executando a funcao DesenharRetangulo.\n");
		printf("Erro: #%u\n", codigoRetorno);
		exit(OK);
	}
	codigoRetorno = PreencherPoligono(monitor, maximoLinhas, maximoColunas, ordenada, abscissa, tempoEspera);
	if (codigoRetorno) {
		printf("Erro executando a funcao PreencherPoligono.\n");
		printf("Erro: #%u\n", codigoRetorno);
		exit(OK);
	}
	return OK;
}
