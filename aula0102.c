/*
 * Universidade Federal do Rio de Janeiro 
 * Escola Politecnica 
 * Departamento de Eletronica e de Computacao 
 * EEL270 - Computacao II - Turma 2019/2
 * Prof. Marcelo Luiz Drumond Lanza 
 * Autor: Ewerton Vieira de Silles
 * Descricao: Tipos basicos

 * $Author: ewerton.silles $ 
 * $Date: 2019/08/14 01:36:58 $ 
 * $Log: aula0102.c,v $
 * Revision 1.1  2019/08/14 01:36:58  ewerton.silles
 * Initial revision
 *
*/

#include <stdio.h>

#define OK			0

int main(int argc, char *argv[]){
	printf("\t\'Tipos Basicos:\'\n\n");
	printf("char\n\t\t%lu %s\n", sizeof(char), (sizeof(char) == 1) ? "byte" : "bytes");
	printf("int\n\t\t%lu %s\n", sizeof(int), (sizeof(int) == 1) ? "byte" : "bytes");
	printf("float\n\t\t%lu %s\n", sizeof(float), (sizeof(float) == 1) ? "byte" : "bytes");
	printf("double\n\t\t%lu %s\n", sizeof(double), (sizeof(double) == 1) ? "byte" : "bytes");
	printf("void\n\t\t%lu %s\n", sizeof(void), (sizeof(void) == 1) ? "byte" : "bytes");
	return OK;
}
