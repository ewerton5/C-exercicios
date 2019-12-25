/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2019/2
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Ewerton Vieira de Silles
 * Descricao: Funcao que multiplica duas matrizes

 * $Author: ewerton.silles $
 * $Date: 2019/10/02 02:10:50 $
 * $Log: aula0701.c,v $
 * Revision 1.1  2019/10/02 02:10:50  ewerton.silles
 * Initial revision
 *
 */

#include				"aula0701.h"

tipoErros
MultiplicarMatrizes (float matrizFator1 [NUMERO_LINHAS_1][NUMERO_COLUNAS_1],
                     float matrizFator2 [NUMERO_LINHAS_2][NUMERO_COLUNAS_2],
                     float matrizProduto [NUMERO_LINHAS_1][NUMERO_COLUNAS_2]) {
	unsigned short linha, coluna;
	if (!matrizFator1 || !matrizFator2 || !matrizProduto)
		return argumentoNulo;
	for (linha = 0; linha < NUMERO_LINHAS_1; linha++)
		for (coluna = 0; coluna < NUMERO_COLUNAS_2; coluna++)
			matrizProduto [linha][coluna] = matrizFator1 [linha][0] * matrizFator2 [0][coluna] +
                                         matrizFator1 [linha][1] * matrizFator2 [1][coluna] +
                                         matrizFator1 [linha][2] * matrizFator2 [2][coluna];
	return ok;
}
