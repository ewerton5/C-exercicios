/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2019/2
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Ewerton Vieira de Silles
 * Descricao: Prototipo de uma funcao que gera o digito verificador de um pis/pasep
 *            Prototipo de uma funcao que verifica o ultimo digito de um pis/pasep

 * $Author: ewerton.silles $
 * $Date: 2019/09/27 02:33:19 $
 * $Log: aula0604.h,v $
 * Revision 1.2  2019/09/27 02:33:19  ewerton.silles
 * *** empty log message ***
 *
 * Revision 1.1  2019/09/24 04:37:30  ewerton.silles
 * Initial revision
 *
 */

#ifndef AULA0604
#define AULA0604 					"@(#)aula0604.h $Revision: 1.2 $"

#define COMPRIMENTO_PIS_PASEP 			11
#define EOS										'\0'

typedef enum
{
	ok,
	argumentoNulo,
	tamanhoInvalido,
	argumentoNegativo,
	argumentoInvalido,
	digitoInvalido
}
tipoErros;

typedef unsigned char byte;

tipoErros
GerarDigitoVerificadorPisPasep (char * /* entrada */ , char * /* saida */);

tipoErros
ValidarPisPasep (char *);

#endif
