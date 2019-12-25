/*
 * Uversidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2019/2
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Ewerton Vieira de Silles
 * Descricao: funcao que gera o digito verificador de um pis/pasep
 *            funcao que verifica o ultimo digito de um pis/pasep
 *            funcao que gera um pis/pasep

 * $Author: ewerton.silles $
 * $Date: 2019/09/27 23:06:24 $
 * $Log: aula0601.c,v $
 * Revision 1.6  2019/09/27 23:06:24  ewerton.silles
 * *** empty log message ***
 *
 * Revision 1.5  2019/09/24 23:56:23  ewerton.silles
 * *** empty log message ***
 *
 * Revision 1.4  2019/09/24 17:12:59  ewerton.silles
 * *** empty log message ***
 *
 * Revision 1.3  2019/09/24 01:56:30  ewerton.silles
 * *** empty log message ***
 *
 * Revision 1.2  2019/09/23 22:55:21  ewerton.silles
 * *** empty log message ***
 *
 * Revision 1.1  2019/09/23 21:25:19  ewerton.silles
 * Initial revision
 *
*/

#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "aula0601.h"

tipoErros
GerarDigitoVerificadorPisPasep (byte pisPasep [COMPRIMENTO_PIS_PASEP]) {
	unsigned short contador;
	byte pesos [10] = {3,2,9,8,7,6,5,4,3,2};
	unsigned soma = 0;
	if (!pisPasep)
		return argumentoNulo;
	for (contador = 0; contador < COMPRIMENTO_PIS_PASEP - 1; contador++) {
		if (pisPasep[contador] > 9)
			return argumentoInvalido;
		soma += pisPasep[contador] * pesos [contador];
	}
	if (soma % 11 == 0 || soma % 11 == 1)
		pisPasep [10] = 0;
	else
		pisPasep [10] = 11 - (soma % 11);
	return ok;
}

tipoErros
ValidarPisPasep (byte pisPasep [COMPRIMENTO_PIS_PASEP]) {
	byte pisPasepVerificador [COMPRIMENTO_PIS_PASEP];
	unsigned short indice;
	tipoErros codigoRetorno;
	if (!pisPasep)
		return argumentoNulo;
	for (indice = 0; indice < COMPRIMENTO_PIS_PASEP; indice++)
		if (pisPasep[indice] > 9)
			return argumentoInvalido;
	for (indice = 0; indice < COMPRIMENTO_PIS_PASEP - 1; indice++)
		pisPasepVerificador [indice] = pisPasep [indice];
	codigoRetorno = GerarDigitoVerificadorPisPasep(pisPasepVerificador);
	if (codigoRetorno)
		return codigoRetorno;
	if (pisPasep [10] != pisPasepVerificador [10])
		return digitoInvalido;
	return ok;
}

tipoErros
GerarPisPasep (byte *pisPasep) {
	unsigned short indice;
	tipoErros codigoRetorno;
	if (pisPasep == NULL)
		return argumentoNulo;
	srand ((unsigned) time (NULL));
	for (indice = 0; indice < COMPRIMENTO_PIS_PASEP - 1; indice++)
		pisPasep [indice] = (byte) rand () % 10;
	codigoRetorno = GerarDigitoVerificadorPisPasep(pisPasep);
	if (codigoRetorno)
		return codigoRetorno;
	return ok;
}
