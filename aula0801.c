/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2019/2
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Ewerton Vieira de Silles
 * Descricao: Funcao que mostra o monitor
 *            Funcao que limpa o monitor
 *            Funcao que desenha um retangulo

 * $Author: ewerton.silles $
 * $Date: 2019/10/14 21:05:48 $
 * $Log: aula0801.c,v $
 * Revision 1.1  2019/10/14 21:05:48  ewerton.silles
 * Initial revision
 *
 */

#include 			<stdio.h>
#include 			<stdlib.h>
#include				"aula0801.h"

tipoErros
MostrarMonitor (tipoPixel monitor [NUMERO_MAXIMO_LINHAS] [NUMERO_MAXIMO_COLUNAS],
                unsigned maximoLinhas, unsigned maximoColunas, __useconds_t tempoEspera) {
	unsigned short linha, coluna;
	if (!monitor)
		return argumentoInvalido;
	if (maximoLinhas > NUMERO_MAXIMO_LINHAS)
		return ordenadaInvalida;
	if (maximoColunas > NUMERO_MAXIMO_COLUNAS)
		return abscissaInvalida;
	system("clear");
	for (linha = 0; linha < maximoLinhas; linha++) {
		for (coluna = 0 ;coluna < maximoColunas; coluna++)
			(monitor [linha][coluna] == aceso)? printf(ACESO) : printf(APAGADO);
		printf("\n");
	}
	usleep(tempoEspera);
	return ok;
}

tipoErros
LimparMonitor (tipoPixel monitor [NUMERO_MAXIMO_LINHAS] [NUMERO_MAXIMO_COLUNAS],
               unsigned maximoLinhas, unsigned maximoColunas, __useconds_t tempoEspera) {
	unsigned short linha, coluna;
	tipoErros codigoRetorno;
	if (!monitor)
		return argumentoInvalido;
	if (maximoLinhas > NUMERO_MAXIMO_LINHAS)
		return ordenadaInvalida;
	if (maximoColunas > NUMERO_MAXIMO_COLUNAS)
		return abscissaInvalida;
	for (linha = 0; linha < maximoLinhas; linha++)
		for (coluna = 0; coluna < maximoColunas; coluna++)
			monitor [linha][coluna] = apagado;
	codigoRetorno = MostrarMonitor (monitor, maximoLinhas, maximoColunas, tempoEspera);
	if (codigoRetorno)
		return codigoRetorno;
	return ok;
}

tipoErros
DesenharRetangulo (tipoPixel monitor [NUMERO_MAXIMO_LINHAS] [NUMERO_MAXIMO_COLUNAS],
                   unsigned maximoLinhas, unsigned maximoColunas, unsigned ordenadaCantoEsquerdo,
                   unsigned abscissaCantoEsquerdo, unsigned ordenadaCantoDireito,
                   unsigned abscissaCantoDireito, __useconds_t tempoEspera) {
	unsigned short linha, coluna, aux;
	tipoErros codigoRetorno;
	if (!monitor)
		return argumentoInvalido;
	if (maximoLinhas > NUMERO_MAXIMO_LINHAS)
		return ordenadaInvalida;
	if (maximoColunas > NUMERO_MAXIMO_COLUNAS)
		return abscissaInvalida;
	if (ordenadaCantoEsquerdo > maximoLinhas - 1)
		return ordenadaCantoEsquerdoInvalida;
	if (abscissaCantoEsquerdo > maximoColunas - 1)
		return abscissaCantoEsquerdoInvalida;
	if (ordenadaCantoDireito > maximoLinhas - 1)
		return ordenadaCantoDireitoInvalida;
	if (abscissaCantoDireito > maximoColunas - 1)
		return abscissaCantoDireitoInvalida;
	if (abscissaCantoEsquerdo == abscissaCantoDireito || ordenadaCantoEsquerdo == ordenadaCantoDireito)
		return retanguloInvalido;
	if (ordenadaCantoEsquerdo > ordenadaCantoDireito) {
		aux = ordenadaCantoEsquerdo;
		ordenadaCantoEsquerdo = ordenadaCantoDireito;
		ordenadaCantoDireito = aux;
	}
	if (abscissaCantoEsquerdo > abscissaCantoDireito) {
		aux = abscissaCantoEsquerdo;
		abscissaCantoEsquerdo = abscissaCantoDireito;
		abscissaCantoDireito = aux;
	}
	for (linha = 0; linha < maximoLinhas; linha++)
		for (coluna = 0; coluna < maximoColunas; coluna++)
			if (((linha == ordenadaCantoEsquerdo || linha == ordenadaCantoDireito) && coluna >= abscissaCantoEsquerdo
			    && coluna <= abscissaCantoDireito) || ((coluna == abscissaCantoEsquerdo || coluna == abscissaCantoDireito)
			    && linha >= ordenadaCantoEsquerdo && linha <= ordenadaCantoDireito))
				monitor [linha][coluna] = aceso;
			else
				monitor [linha][coluna] = apagado;
	codigoRetorno = MostrarMonitor (monitor, maximoLinhas, maximoColunas, tempoEspera);
	if (codigoRetorno)
		return codigoRetorno;
	return ok;
}

tipoErros
PreencherPoligono (tipoPixel monitor [NUMERO_MAXIMO_LINHAS] [NUMERO_MAXIMO_COLUNAS],
                   unsigned maximoLinhas, unsigned maximoColunas, unsigned linha,
                   unsigned coluna, __useconds_t tempoEspera) {
	tipoErros codigoRetorno;
	if (!monitor)
		return argumentoInvalido;
	if (maximoLinhas > NUMERO_MAXIMO_LINHAS)
		return ordenadaInvalida;
	if (maximoColunas > NUMERO_MAXIMO_COLUNAS)
		return abscissaInvalida;
	if (linha > maximoLinhas - 1)
		return linhaInvalida;
	if (coluna > maximoColunas - 1)
		return colunaInvalida;
	if (monitor [linha][coluna] == apagado) {
		monitor [linha][coluna] = aceso;
		if (coluna > 0)
			PreencherPoligono (monitor , maximoLinhas, maximoColunas, linha, coluna - 1, tempoEspera);
		if (linha > 0)
			PreencherPoligono (monitor , maximoLinhas, maximoColunas, linha - 1, coluna, tempoEspera);
		if (coluna < maximoColunas - 1)
			PreencherPoligono (monitor , maximoLinhas, maximoColunas, linha, coluna + 1, tempoEspera);
		if (linha < maximoLinhas - 1)
			PreencherPoligono (monitor , maximoLinhas, maximoColunas, linha + 1, coluna, tempoEspera);
		codigoRetorno = MostrarMonitor (monitor, maximoLinhas, maximoColunas, tempoEspera);
		if (codigoRetorno)
			return codigoRetorno;
	}
	return ok;
}
