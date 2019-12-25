/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2019/2
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Ewerton Vieira de Silles
 * Descricao: Prototipo de uma funcao que multiplica duas matrizes

 * $Author: ewerton.silles $
 * $Date: 2019/10/02 02:10:50 $
 * $Log: aula0701.h,v $
 * Revision 1.1  2019/10/02 02:10:50  ewerton.silles
 * Initial revision
 *
 */

#ifndef AULA0701
#define AULA0701 					"@(#)aula0701.h $Revision: 1.1 $"

#define NUMERO_LINHAS_1			5
#define NUMERO_COLUNAS_1		3
#define NUMERO_LINHAS_2			3
#define NUMERO_COLUNAS_2		4

typedef enum
{
	ok,
	argumentoNulo,
}
tipoErros;

tipoErros
MultiplicarMatrizes (float [NUMERO_LINHAS_1][NUMERO_COLUNAS_1],
                     float [NUMERO_LINHAS_2][NUMERO_COLUNAS_2],
                     float [NUMERO_LINHAS_1][NUMERO_COLUNAS_2]);
#endif
