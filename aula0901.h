/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2019/2
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Ewerton Vieira de Silles
 * Descricao: Prototipo de uma funcao que codifica base 64
 *            Prototipo de uma funcao que decodifica base 64

 * $Author: ewerton.silles $
 * $Date: 2019/11/05 01:46:25 $
 * $Log: aula0901.h,v $
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

#ifndef AULA0901
#define AULA0901 					"@(#)aula0901.h $Revision: 1.3 $"

#define CONJUNTO_BASE_64		"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"
#define PADDING					'='
#define TAMANHO_BASE_64			64
#define EOS							'\0'
#define TAMANHO_MAXIMO_LINHA	76
#define NUMERO_MAXIMO_SAIDA	1366

typedef unsigned char byte;

typedef enum
{
	ok,
	argumentoInvalido,
	caracterInvalido,
	tamanhoInvalido,
	leituraInvalida,
	escritaInvalida,
	formatoUnixInvalido,
	formatoDosInvalido,
	erroNaLeitura,
	eofNaoAtingido,
}
tipoErros;

tipoErros
CodificarBase64 (byte *entrada, unsigned numeroBytes, char *saida);

tipoErros
DecodificarBase64 (char *entrada, byte *saida, unsigned *numeroBytes);

#endif
