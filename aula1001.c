/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2019/2
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Ewerton Vieira de Silles
 * Descricao: Funcao que converte arquivo Unix em Dos
 *            Funcao que converte arquivo Dos em Unix

 * $Author: ewerton.silles $
 * $Date: 2019/11/05 01:46:25 $
 * $Log: aula1001.c,v $
 * Revision 1.1  2019/11/05 01:46:25  ewerton.silles
 * Initial revision
 *
 */

#include <stdio.h>
#include <string.h>
#include "aula1001.h"

tipoErros
ConverterArquivoFormatoUnixFormatoDos(char *original, char *convertido) {
	FILE *leitura, *escrita;
	char buffer [COMPRIMENTO_BUFFER];
	unsigned short indice;
	if (!original|!convertido)
		return argumentoInvalido;
	if (!(leitura = fopen (original, "r")))
		return leituraInvalida;
	if (!(escrita = fopen (convertido, "w")))
		return escritaInvalida;
	while(fgets(buffer, COMPRIMENTO_BUFFER, leitura)) {
		indice = strlen(buffer) - 1; 
		if (buffer[indice] == EOUL) {
			if (indice > 0 && buffer[indice - 1] == EODL) {
				fclose (leitura);
				fclose (escrita);
				return formatoUnixInvalido;
			}
			buffer[indice] = EODL;
			buffer[indice + 1] = EOUL;
			buffer[indice + 2] = EOS;
		}
		fprintf(escrita, "%s", buffer);
	}
	if (ferror(leitura)) {
		fclose (leitura);
		fclose (escrita);
		remove(convertido);
		return erroNaLeitura;
	}
	fclose (leitura);
	fclose (escrita);
	return ok;
}

tipoErros
ConverterArquivoFormatoDosFormatoUnix (char *original, char *convertido) {
	FILE *leitura, *escrita;
	char buffer [COMPRIMENTO_BUFFER];
	unsigned short indice;
	if (!original|!convertido)
		return argumentoInvalido;
	if (!(leitura = fopen (original, "r")))
		return leituraInvalida;
	if (!(escrita = fopen (convertido, "w")))
		return escritaInvalida;
	while(fgets(buffer, COMPRIMENTO_BUFFER, leitura)) {
		indice = strlen(buffer) - 1; 
		if (buffer[indice] == EOUL) {
			if (indice == 0 || buffer[indice - 1] != EODL) {
				fclose (leitura);
				fclose (escrita);
				return formatoDosInvalido;
			}
			buffer[indice - 1] = EOUL;
			buffer[indice] = EOS;
		}
		fprintf(escrita, "%s", buffer);
	}
	if (ferror(leitura)) {
		fclose (leitura);
		fclose (escrita);
		remove(convertido);
		return erroNaLeitura;
	}
	fclose (leitura);
	fclose (escrita);
	return ok;
}
