/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2019/2
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Ewerton Vieira de Silles
 * Descricao: Funcao que codifica base 64
 *            Funcao que decodifica base 64

 * $Author: ewerton.silles $
 * $Date: 2019/11/05 01:46:25 $
 * $Log: aula0901.c,v $
 * Revision 1.3  2019/11/05 01:46:25  ewerton.silles
 * *** empty log message ***
 *
 * Revision 1.2  2019/10/22 04:26:31  ewerton.silles
 * *** empty log message ***
 *
 * Revision 1.1  2019/10/20 05:36:29  ewerton.silles
 * Initial revision
 *
 */

#include <string.h>
#include "aula0901.h"

tipoErros
CodificarBase64 (byte *entrada, unsigned numeroBytes, char *saida) {
	unsigned indice1 = 0, indice2 = 0, indice3 = 0;
	char aux [NUMERO_MAXIMO_SAIDA];
	if (!entrada||!saida)
		return argumentoInvalido;
	while (indice1 + 2 < numeroBytes) {
		saida[indice2] = CONJUNTO_BASE_64[(entrada[indice1] >> 2) & 0x3F];
		saida[indice2 + 1] = CONJUNTO_BASE_64[((entrada[indice1] << 4) & 0x30) | ((entrada[indice1 + 1] >> 4) & 0xF)];
		saida[indice2 + 2] = CONJUNTO_BASE_64[((entrada[indice1 + 1] << 2) & 0x3C) | ((entrada[indice1 + 2] >> 6) & 0x3)];
		saida[indice2 + 3] = CONJUNTO_BASE_64[entrada[indice1 + 2] & 0x3F];
		indice1 += 3;
		indice2 += 4;
	}
	if (indice1 < numeroBytes) {
		saida[indice2] = CONJUNTO_BASE_64[(entrada[indice1] >> 2) & 0x3F];
		if (indice1 + 1 < numeroBytes) {
			saida[indice2 + 1] = CONJUNTO_BASE_64[((entrada[indice1] << 4) & 0x30) | ((entrada[indice1 + 1] >> 4) & 0xF)];
			saida[indice2 + 2] = CONJUNTO_BASE_64[(entrada[indice1 + 1] << 2) & 0x3C];
			saida[indice2 + 3] = PADDING;
			saida[indice2 + 4] = EOS;
		} else {
			saida[indice2 + 1] = CONJUNTO_BASE_64[(entrada[indice1] << 4) & 0x30];
			saida[indice2 + 2] = PADDING;
			saida[indice2 + 3] = PADDING;
			saida[indice2 + 4] = EOS;
		}
	} else
		saida[indice2] = EOS;
	if (strlen(saida) > TAMANHO_MAXIMO_LINHA) {
		strcpy(aux, saida);
		indice2 = 0;
		while (aux[indice3] != EOS) {
			for (indice1 = 0; indice1 < TAMANHO_MAXIMO_LINHA && aux[indice3] != EOS; indice1++, indice2++, indice3++)
				saida[indice2] = aux[indice3];
			if (aux[indice3] == EOS)
				break;
			saida[indice2] = '\r';
			saida[indice2 + 1] = '\n';
			indice2 +=2;
		}
		saida[indice2] = EOS;
	}	
	return ok;
}

tipoErros
DecodificarBase64 (char *entrada, byte *saida, unsigned *numeroBytes) {
	unsigned indice1, indice2 = 0;
	char aux1 [2] = "0\0", aux2 [2] = "0\0", entradaNumaLinha [NUMERO_MAXIMO_SAIDA];
	if (!entrada||!saida||!numeroBytes)
		return argumentoInvalido;
	for (indice1 = 0, indice2 = 0; entrada[indice2] != EOS; indice1++, indice2++) {
		if (entrada[indice2] == '\r' || entrada[indice2] == '\n')
			indice1--;
		else
			entradaNumaLinha[indice1] = entrada[indice2];
	}
	entradaNumaLinha[indice1] = EOS;
	for (indice1 = 0; indice1 < strlen(entradaNumaLinha) - 2; indice1++) {
		aux1[0] = entradaNumaLinha[indice1];
		if (strstr(CONJUNTO_BASE_64, aux1) == NULL)
			return caracterInvalido;
	}
	for (indice2 = 0; indice2 < 2; indice1++, indice2++) {
		aux1[0] = entradaNumaLinha[indice1];
		if (strstr(CONJUNTO_BASE_64, aux1) == NULL && strstr("=", aux1) == NULL)
			return caracterInvalido;
	}
	if(strlen(entradaNumaLinha) % 4)
		return tamanhoInvalido;
	indice1 = 0;
	indice2 = 0;
	while (entradaNumaLinha[indice1] != EOS) {
		aux1[0] = entradaNumaLinha[indice1];
		aux2[0] = entradaNumaLinha[indice1 + 1];
		saida[indice2] = (((TAMANHO_BASE_64 - strlen(strstr(CONJUNTO_BASE_64, aux1))) << 2) & 0xFC) |
		                 (((TAMANHO_BASE_64 - strlen(strstr(CONJUNTO_BASE_64, aux2))) >> 4) & 0x3);
		indice2++;
		if (entradaNumaLinha[indice1 + 2] != PADDING) {
			aux1[0] = entradaNumaLinha[indice1 + 1];
			aux2[0] = entradaNumaLinha[indice1 + 2];
			saida[indice2] = (((TAMANHO_BASE_64 - strlen(strstr(CONJUNTO_BASE_64, aux1))) << 4) & 0xF0) |
		   	                  (((TAMANHO_BASE_64 - strlen(strstr(CONJUNTO_BASE_64, aux2))) >> 2) & 0xF);
			indice2++;
		}
		if (entradaNumaLinha[indice1 + 3] != PADDING) {
			aux1[0] = entradaNumaLinha[indice1 + 2];
			aux2[0] = entradaNumaLinha[indice1 + 3];
			saida[indice2] = (((TAMANHO_BASE_64 - strlen(strstr(CONJUNTO_BASE_64, aux1))) << 6) & 0xC0) |
		   	                  ((TAMANHO_BASE_64 - strlen(strstr(CONJUNTO_BASE_64, aux2))) & 0x3F);
			indice2++;
		}
		indice1 += 4;
	}
	*numeroBytes = indice2;
	return ok;
}
