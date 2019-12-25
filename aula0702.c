/*
 * Universidade Federal do Rio de Janeiro 
 * Escola Politecnica 
 * Departamento de Eletronica e de Computacao 
 * EEL270 - Computacao II - Turma 2019/2
 * Prof. Marcelo Luiz Drumond Lanza 
 * Autor: Ewerton Vieira de Silles
 * Descricao: programa de testes para a funcao MultiplicarMatrizes

 * $Author: ewerton.silles $ 
 * $Date: 2019/10/02 02:10:50 $ 
 * $Log: aula0702.c,v $
 * Revision 1.1  2019/10/02 02:10:50  ewerton.silles
 * Initial revision
 *
*/

#include <stdio.h>
#include <stdlib.h>

#include "aula0701.h"

#define NUMERO_ARGUMENTOS					1 + NUMERO_LINHAS_1 * NUMERO_COLUNAS_1 + NUMERO_LINHAS_2 * NUMERO_COLUNAS_2

#define OK										0
#define NUMERO_ARGUMENTOS_INVALIDO		1
#define ARGUMENTO_INVALIDO					2

#define EOS										'\0'

int
main (int argc, char *argv []) 
{
  float matrizFator1 [NUMERO_LINHAS_1][NUMERO_COLUNAS_1];
  float matrizFator2 [NUMERO_LINHAS_2][NUMERO_COLUNAS_2];
  float matrizProduto [NUMERO_LINHAS_1][NUMERO_COLUNAS_2];
  unsigned linha, coluna;
  char *validacao;
  if (argc != NUMERO_ARGUMENTOS) {
    printf ("Uso: %s <a11> <a12> ... <a%u%u> <b11> <b12> ... <b%u%u>\n",
            argv [0], NUMERO_LINHAS_1, NUMERO_COLUNAS_1, NUMERO_LINHAS_2, NUMERO_COLUNAS_2);
    exit (NUMERO_ARGUMENTOS_INVALIDO);
  }
  for (linha = 0; linha < NUMERO_LINHAS_1; linha++)
    for (coluna = 0; coluna < NUMERO_COLUNAS_1; coluna++) {
      matrizFator1 [linha][coluna] = strtof (argv [coluna + (linha * NUMERO_COLUNAS_1) + 1], &validacao);
      if (*validacao != EOS) {
        printf ("Argumento invalido (#%u).\n Caractere invalido: %c\n",
                coluna + (linha * NUMERO_COLUNAS_1) + 1, *validacao);
        exit (ARGUMENTO_INVALIDO);
      }
	}
  for (linha = 0; linha < NUMERO_LINHAS_2; linha++)
    for (coluna = 0; coluna < NUMERO_COLUNAS_2; coluna++) {
      matrizFator2 [linha][coluna] = strtof (argv [coluna + (linha * NUMERO_COLUNAS_2) + (NUMERO_LINHAS_1 * NUMERO_COLUNAS_1) + 1], &validacao);
      if (*validacao != EOS) {
        printf ("Argumento invalido (#%u).\n Caractere invalido: %c\n",
                coluna + (linha * NUMERO_COLUNAS_2) + (NUMERO_LINHAS_1 * NUMERO_COLUNAS_1) + 1, *validacao);
        exit (ARGUMENTO_INVALIDO);
      }
    }
  MultiplicarMatrizes (matrizFator1, matrizFator2, matrizProduto);
  for (linha = 0; linha < NUMERO_LINHAS_1; linha++) {
    for (coluna = 0; coluna < NUMERO_COLUNAS_2; coluna++)
      printf ("\t%.04g", matrizProduto [linha][coluna]);
    printf ("\n");
  }
  return OK;
}
