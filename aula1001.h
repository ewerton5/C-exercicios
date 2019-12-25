/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2019/2
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Ewerton Vieira de Silles
 * Descricao: Prototipo de uma funcao que converte arquivo Unix em Dos
 *            Prototipo de uma funcao que converte arquivo Dos em Unix

 * $Author: ewerton.silles $
 * $Date: 2019/11/05 01:46:25 $
 * $Log: aula1001.h,v $
 * Revision 1.1  2019/11/05 01:46:25  ewerton.silles
 * Initial revision
 *
 */

#include "aula0901.h"

#ifndef _AULA1001_
#define _AULA1001_ 					"@(#)aula1001.h $Revision: 1.1 $"

#define COMPRIMENTO_BUFFER			512
#define EOS								'\0'
#define EOUL							'\n'
#define EODL							'\r'

tipoErros
ConverterArquivoFormatoUnixFormatoDos(char *original, char *convertido);

tipoErros
ConverterArquivoFormatoDosFormatoUnix (char *original, char *convertido);
#endif
