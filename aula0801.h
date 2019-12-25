/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2019/2
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Ewerton Vieira de Silles
 * Descricao: Prototipo de uma funcao que mostra o monitor
 *            Prototipo de uma funcao que limpa o monitor
 *            Prototipo de uma funcao que desenha um retangulo
 *            Prototipo de uma funcao que preenche um poligono

 * $Author: ewerton.silles $
 * $Date: 2019/10/14 21:05:48 $
 * $Log: aula0801.h,v $
 * Revision 1.1  2019/10/14 21:05:48  ewerton.silles
 * Initial revision
 *
 */

#ifndef AULA0801
#define AULA0801 					"@(#)aula0801.h $Revision: 1.1 $"

#include <unistd.h>

#define APAGADO							"0"
#define ACESO								"1"
#define NUMERO_MAXIMO_LINHAS			280
#define NUMERO_MAXIMO_COLUNAS			800

typedef enum
{
	ok,
	ordenadaInvalida,
	abscissaInvalida,
	argumentoInvalido,
	ordenadaCantoEsquerdoInvalida,
	abscissaCantoEsquerdoInvalida,
	ordenadaCantoDireitoInvalida,
	abscissaCantoDireitoInvalida,
	retanguloInvalido,
	linhaInvalida,
	colunaInvalida
}
tipoErros;

typedef enum
{
	apagado,
	aceso
}
tipoPixel;

tipoErros
MostrarMonitor (tipoPixel monitor [NUMERO_MAXIMO_LINHAS] [NUMERO_MAXIMO_COLUNAS],
                unsigned maximoLinhas, unsigned maximoColunas, __useconds_t tempoEspera);

tipoErros
LimparMonitor (tipoPixel monitor [NUMERO_MAXIMO_LINHAS] [NUMERO_MAXIMO_COLUNAS],
                unsigned maximoLinhas, unsigned maximoColunas, __useconds_t tempoEspera);

tipoErros
DesenharRetangulo (tipoPixel monitor [NUMERO_MAXIMO_LINHAS] [NUMERO_MAXIMO_COLUNAS],
                   unsigned maximoLinhas, unsigned maximoColunas, unsigned ordenadaCantoEsquerdo,
                   unsigned abscissaCantoEsquerdo, unsigned ordenadaCantoDireito,
                   unsigned abscissaCantoDireito, __useconds_t tempoEspera);
tipoErros
PreencherPoligono (tipoPixel monitor [NUMERO_MAXIMO_LINHAS] [NUMERO_MAXIMO_COLUNAS],
                   unsigned maximoLinhas, unsigned maximoColunas, unsigned linha,
                   unsigned coluna, __useconds_t tempoEspera);
#endif
