/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2019/2
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Ewerton Vieira de Silles
 * Descricao: Prototipo de uma funcao que gera o digito verificador de um pis/pasep
 *            Prototipo de uma funcao que gera um pis/pasep

 * $Author: ewerton.silles $
 * $Date: 2019/09/28 01:59:15 $
 * $Log: aula0608.h,v $
 * Revision 1.2  2019/09/28 01:59:15  ewerton.silles
 * *** empty log message ***
 *
 * Revision 1.1  2019/09/28 00:20:20  ewerton.silles
 * Initial revision
 *
 */

#ifndef AULA0608
#define AULA0608 					"@(#)aula0608.h $Revision: 1.2 $"

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
GerarDigitoVerificadorPisPasep (char *);

tipoErros
GerarPisPasep (char *);

#endif
