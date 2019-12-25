/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2019/2
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Ewerton Vieira de Silles
 * Descricao: Prototipo de uma funcao que gera o digito verificador de um pis/pasep
 *            Prototipo de uma funcao que verifica o ultimo digito de um pis/pasep
 *            Prototipo de uma funcao que gera um pis/pasep

 * $Author: ewerton.silles $
 * $Date: 2019/09/27 23:06:24 $
 * $Log: aula0601.h,v $
 * Revision 1.5  2019/09/27 23:06:24  ewerton.silles
 * *** empty log message ***
 *
 * Revision 1.4  2019/09/24 23:56:23  ewerton.silles
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

#ifndef AULA0601
#define AULA0601 					"@(#)aula0601.h $Revision: 1.5 $"

#define COMPRIMENTO_PIS_PASEP		11

typedef enum
{
	ok,
	argumentoNulo,
	argumentoInvalido,
	digitoInvalido
}
tipoErros;

typedef unsigned char byte;

tipoErros
GerarDigitoVerificadorPisPasep (byte [ ]);

tipoErros
ValidarPisPasep (byte [ ]);

tipoErros
GerarPisPasep (byte *);

#endif
