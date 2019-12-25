/*
 * Uversidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2019/2
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Ewerton Vieira de Silles
 * Descricao: funcao que gera o digito verificador de um pis/pasep
 *            funcao que gera um pis/pasep

 * $Author: ewerton.silles $
 * $Date: 2019/09/28 01:59:15 $
 * $Log: aula0608.c,v $
 * Revision 1.2  2019/09/28 01:59:15  ewerton.silles
 * *** empty log message ***
 *
 * Revision 1.1  2019/09/28 00:20:20  ewerton.silles
 * Initial revision
 *
*/

#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "aula0608.h"

tipoErros
GerarDigitoVerificadorPisPasep (char *entrada) {
	unsigned short indice;	
	char *validacao;
	byte pisPasep [COMPRIMENTO_PIS_PASEP];
	byte pesos [10] = {3,2,9,8,7,6,5,4,3,2};
	unsigned soma = 0;
	if (!entrada)
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
	if (soma % 11 == 0 || soma % 11 == 1)
		entrada[10] = '0';
	else
		entrada[10] = (11 - (soma % 11) + '0');
	entrada[COMPRIMENTO_PIS_PASEP] = EOS;
	return ok;
}

tipoErros
GerarPisPasep (char *pisPasep) {
	unsigned short indice;
	tipoErros codigoRetorno;
	if (pisPasep == NULL)
		return argumentoNulo;
	srand ((unsigned) time (NULL));
	for (indice = 0; indice < COMPRIMENTO_PIS_PASEP - 1; indice++)
		pisPasep [indice] = rand () % 10 + '0';
	codigoRetorno = GerarDigitoVerificadorPisPasep(pisPasep);
	if (codigoRetorno)
		return codigoRetorno;
	return ok;
}
