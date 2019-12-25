/*
 * Universidade Federal do Rio de Janeiro 
 * Escola Politecnica 
 * Departamento de Eletronica e de Computacao 
 * EEL270 - Computacao II - Turma 2019/2
 * Prof. Marcelo Luiz Drumond Lanza 
 * Autor: Ewerton Vieira de Silles
 * Descricao: Tipos basicos, modificadores de sinal e largura

 * $Author: ewerton.silles $ 
 * $Date: 2019/08/15 18:46:46 $ 
 * $Log: aula0104.c,v $
 * Revision 1.1  2019/08/15 18:46:46  ewerton.silles
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
	printf("void\n\t\t%lu %s\n\n", sizeof(void), (sizeof(void) == 1) ? "byte" : "bytes");
	int contador;
	for(contador = 1; contador <= 80; contador++)
		printf("-");
	printf("\n\n\t\'Modificadores de Sinal:\'\n\n");
	printf("signed\n\t\t%lu %s\n", sizeof(signed), (sizeof(signed) == 1) ? "byte" : "bytes");
	printf("unsigned\n\t\t%lu %s\n\n", sizeof(unsigned), (sizeof(unsigned) == 1) ? "byte" : "bytes");
	for(contador = 1; contador <= 80; contador++)
		printf("-");
	printf("\n\n\t\'Modificadores de Largura:\'\n\n");
	printf("short\n\t\t%lu %s\n", sizeof(short), (sizeof(short) == 1) ? "byte" : "bytes");
	printf("long\n\t\t%lu %s\n", sizeof(long), (sizeof(long) == 1) ? "byte" : "bytes");
	printf("long long\n\t\t%lu %s\n", sizeof(long long), (sizeof(long long) == 1) ? "byte" : "bytes");
	return OK;
}
