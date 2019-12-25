/*
 * Uversidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2019/2
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Ewerton Vieira de Silles
 * Descricao: funcao que gera o digito verificador de um pis/pasep
 *            funcao que verifica o ultimo digito de um pis/pasep

 * $Author: ewerton.silles $
 * $Date: 2019/09/28 00:27:58 $
 * $Log: aula0604.c,v $
 * Revision 1.4  2019/09/28 00:27:58  ewerton.silles
 * *** empty log message ***
 *
 * Revision 1.3  2019/09/27 22:22:56  ewerton.silles
 * *** empty log message ***
 *
 * Revision 1.2  2019/09/27 02:33:19  ewerton.silles
 * *** empty log message ***
 *
 * Revision 1.1  2019/09/24 04:37:30  ewerton.silles
 * Initial revision
 *
*/

#include <stdlib.h>
#include <string.h>
#include "aula0604.h"

tipoErros
GerarDigitoVerificadorPisPasep (char *entrada, char *saida) {
	unsigned short indice;	
	char *validacao;
	byte pisPasep [COMPRIMENTO_PIS_PASEP];
	byte pesos [10] = {3,2,9,8,7,6,5,4,3,2};
	unsigned soma = 0;
	if (!entrada)
		return argumentoNulo;
	if (!saida)
		return argumentoNulo;
	if (strlen(entrada) != COMPRIMENTO_PIS_PASEP - 1)
		return tamanhoInvalido;
	if (entrada[0] == '-')
		return argumentoNegativo;
	strtoul(entrada, &validacao, 10);
	if (*validacao != EOS)
		return argumentoInvalido;
	for (indice = 0; indice < COMPRIMENTO_PIS_PASEP - 1; indice++) {
		pisPasep [indice] = (byte) (entrada[indice] - '0');
		soma += pisPasep[indice] * pesos [indice];
	}
	for (indice = 0; indice < COMPRIMENTO_PIS_PASEP; indice++)
		saida[indice] = entrada[indice];
	if (soma % 11 == 0 || soma % 11 == 1)
		saida[10] = '0';
	else
		saida[10] = (11 - (soma % 11) + '0');
	saida[COMPRIMENTO_PIS_PASEP] = EOS;
	return ok;
}

tipoErros
ValidarPisPasep (char *pisPasep) {
	unsigned short indice;
	char *validacao;
	char pisPasepSemDigito [COMPRIMENTO_PIS_PASEP];
	char pisPasepVerificador [COMPRIMENTO_PIS_PASEP];
	tipoErros codigoRetorno;
	if (!pisPasep)
		return argumentoNulo;
	if (pisPasep [COMPRIMENTO_PIS_PASEP - 1] == '-') {
		pisPasep [COMPRIMENTO_PIS_PASEP - 1] = pisPasep[COMPRIMENTO_PIS_PASEP];
		pisPasep [COMPRIMENTO_PIS_PASEP] = pisPasep[COMPRIMENTO_PIS_PASEP + 1];
	}
	if (strlen(pisPasep) != COMPRIMENTO_PIS_PASEP)
		return tamanhoInvalido;
	if (pisPasep[0] == '-')
		return argumentoNegativo;
	strtoul(pisPasep, &validacao, 10);
	if (*validacao != EOS)
		return argumentoInvalido;
	for (indice = 0; indice < COMPRIMENTO_PIS_PASEP - 1; indice++)
		pisPasepSemDigito [indice] = pisPasep [indice];
	pisPasepSemDigito [COMPRIMENTO_PIS_PASEP - 1] = EOS;
	codigoRetorno = GerarDigitoVerificadorPisPasep(pisPasepSemDigito, pisPasepVerificador);
	if (codigoRetorno)
		return codigoRetorno;
	if (pisPasep [10] != pisPasepVerificador [10])
		return digitoInvalido;
	return ok;
}
