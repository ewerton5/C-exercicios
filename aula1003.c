/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2019/2
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Ewerton Vieira de Silles
 * Descricao: Pograma com 4 funcionalidades:
 *            - Converter um arquivo texto do formato Unix para o formato Microsoft
 *            - Converter um arquivo texto do formato Microsoft para o formato Unix
 *            - Codificar o arquivo na base 64
 *            - Decodificar o arquivo na base 64

 * $Author: ewerton.silles $
 * $Date: 2019/11/05 14:31:08 $
 * $Log: aula1003.c,v $
 * Revision 1.2  2019/11/05 14:31:08  ewerton.silles
 * *** empty log message ***
 *
 * Revision 1.1  2019/11/05 03:38:07  ewerton.silles
 * Initial revision
 *
*/

#ifdef __linux__
#define _GNU_SOURCE
#endif

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <getopt.h>
#include "aula1001.h"

#define NUMERO_MINIMO_ARGUMENTOS			2 

#define OK										0
#define NUMERO_ARGUMENTOS_INVALIDO		1

#define NUMERO_MAXIMO_BYTES				1024
#define TAMANHO_MAXIMO_LINHA_BYTES		TAMANHO_MAXIMO_LINHA*3/4

int main (int argc, char *argv []) {
	const char *options = "dDeEhHmMuU";
	const struct option opcoesLongas[] = {
      {"decode", 0, 0, 'd'},
      {"encode", 0, 0, 'e'},
      {"help", 0, 0, 'h'},
      {"unix", 0, 0, 'u'},
      {"dos", 0, 0, 'm'},
		{NULL, 0, NULL, 0}
   };
	int selectedOption;
	opterr = 0;
	FILE *leitura, *escrita;
	unsigned numeroBytes;
	unsigned short indice;
	tipoErros codigoRetorno;
	byte decodificadobyte [NUMERO_MAXIMO_BYTES];
	char decodificadostr [COMPRIMENTO_BUFFER];
	char codificadostr [COMPRIMENTO_BUFFER];
	if (argc < NUMERO_MINIMO_ARGUMENTOS) {
		printf ("Uso: %s\n", argv [0]);
		printf ("\t\t-m <filename> <converted_filename>\n");
		printf ("\t\t\tConvert a text file from Unix format to Microsoft format\n");
		printf ("\t\t\tConverter um arquivo texto do formato Unix para o formato Microsoft\n");
		printf ("\t\t-u <filename> <converted_filename>\n");
		printf ("\t\t\tConvert a text file from Microsoft format to Unix format\n");
		printf ("\t\t\tConverter um arquivo texto do formato Microsoft para o formato Unix\n");
		printf ("\t\t-e <filename> <coded_filename>\n");
		printf ("\t\t\tEncode a file in base 64\n");
		printf ("\t\t\tCodificar um arquivo na base 64\n");
		printf ("\t\t-d <filename> <decoded_filename>\n");
		printf ("\t\t\tDecode a file in base 64\n");
		printf ("\t\t\tDecodificar um arquivo na base 64\n");
		printf ("\t\t-h [<language>]\n");
		printf ("\t\t\tHelp\n");
		printf ("\t\t\tAjuda\n");
		exit (NUMERO_ARGUMENTOS_INVALIDO);
	}
	while ((selectedOption = getopt_long (argc, argv, options, opcoesLongas, NULL)) != -1) {
		switch (selectedOption) {
			case 'd':
			case 'D':
				if (optind >= argc) {
					printf("No filename detected.\n");
					break;
				}
				if (argv [optind][0] == '-') {
					printf("No filename detected.\n");
					break;
				}
				if (optind + 1 >= argc) {
					printf("Second filename not detected.\n");
					break;
				}
				if (argv [optind + 1][0] == '-') {
					printf("Second filename not detected.\n");
					break;
				}
				if (!(leitura = fopen (argv [optind], "r"))) {
					printf("Error trying to open %s file.\n", argv [optind]);
					break;
				}
				if (!(escrita = fopen (argv [optind + 1], "wb"))) {
					printf("Error trying to open %s file.\n", argv [optind + 1]);
					break;
				}
				while(fgets(codificadostr, COMPRIMENTO_BUFFER, leitura)) {
					codigoRetorno = DecodificarBase64(codificadostr, decodificadobyte, &numeroBytes);
					if (codigoRetorno) {
						fclose (leitura);
						fclose (escrita);
						printf("Error executing DecodificarBase64 function.\n");
						printf("Error: #%u\n", codigoRetorno);
						break;
					}
					for (indice = 0; indice < numeroBytes; indice++)
						decodificadostr[indice] = (char) decodificadobyte[indice];
					decodificadostr[indice] = EOS;
					fprintf(escrita, "%s", decodificadostr);
				}
				if (ferror(leitura)) {
					fclose (leitura);
					fclose (escrita);
					remove(argv[optind]);
					printf("Error while reading file.\n");
					break;
				}
				fclose (leitura);
				fclose (escrita);
				printf("File successfully decoded.\n");
			break;
			case 'e':
			case 'E':
				if (optind >= argc) {
					printf("No filename detected.\n");
					break;
				}
				if (argv [optind][0] == '-') {
					printf("No filename detected.\n");
					break;
				}
				if (optind + 1 >= argc) {
					printf("Second filename not detected.\n");
					break;
				}
				if (argv [optind + 1][0] == '-') {
					printf("Second filename not detected.\n");
					break;
				}
				if (!(leitura = fopen (argv [optind], "rb"))) {
					printf("Error trying to open %s file.\n", argv [optind]);
					break;
				}
				if (!(escrita = fopen (argv [optind + 1], "w"))) {
					printf("Error trying to open %s file.\n", argv [optind + 1]);
					break;
				}
				while((numeroBytes = fread(codificadostr, 1, TAMANHO_MAXIMO_LINHA_BYTES, leitura))) {
					for (indice = 0; codificadostr[indice] != EOS ; indice++)
						decodificadobyte[indice] = (byte) codificadostr[indice];
					codigoRetorno = CodificarBase64(decodificadobyte, numeroBytes, codificadostr);
					if (codigoRetorno) {
						fclose (leitura);
						fclose (escrita);
						printf("Error executing CodificarBase64 function.\n");
						printf("Error: #%u\n", codigoRetorno);
						break;
					}
					strcat(codificadostr, "\r\n");
					fprintf(escrita, "%s", codificadostr);
				}
				if (ferror(leitura)) {
					fclose (leitura);
					fclose (escrita);
					remove(argv[optind]);
					printf("Error while reading file.\n");
					break;
				}
				fclose (leitura);
				fclose (escrita);
				printf("File successfully coded.\n");
			break;
			case 'h':
			case 'H':
				if (optind < argc)
					if (!strcmp(argv[optind], "portugues") || !strcmp(argv[optind], "pt")) {
						printf ("\t\t-m <nome_do_arquivo> <nome_do_arquivo_convertido>\n");
						printf ("\t\t\tConverter um arquivo texto do formato Unix para o formato Microsoft\n");
						printf ("\t\t-u <nome_do_arquivo> <nome_do_arquivo_convertido>\n");
						printf ("\t\t\tConverter um arquivo texto do formato Microsoft para o formato Unix\n");
						printf ("\t\t-e <nome_do_arquivo> <nome_do_arquivo_codificado>\n");
						printf ("\t\t\tCodificar um arquivo na base 64\n");
						printf ("\t\t-d <nome_do_arquivo> <nome_do_arquivo_decopdificado>\n");
						printf ("\t\t\tDecodificar um arquivo na base 64\n");
						printf ("\t\t-h [<idioma>]\n");
						printf ("\t\t\tAjuda\n");
					} else {
						printf ("\t\t-m <filename> <converted_filename>\n");
						printf ("\t\t\tConvert a text file from Unix format to Microsoft format\n");
						printf ("\t\t-u <filename> <converted_filename>\n");
						printf ("\t\t\tConvert a text file from Microsoft format to Unix format\n");
						printf ("\t\t-e <filename> <coded_filename>\n");
						printf ("\t\t\tEncode a file in base 64\n");
						printf ("\t\t-d <filename> <decoded_filename>\n");
						printf ("\t\t\tDecode a file in base 64\n");
						printf ("\t\t-h [<language>]\n");
						printf ("\t\t\tHelp\n");
					}
				else {
					printf ("\t\t-m <filename> <converted_filename>\n");
					printf ("\t\t\tConvert a text file from Unix format to Microsoft format\n");
					printf ("\t\t-u <filename> <converted_filename>\n");
					printf ("\t\t\tConvert a text file from Microsoft format to Unix format\n");
					printf ("\t\t-e <filename> <coded_filename>\n");
					printf ("\t\t\tEncode a file in base 64\n");
					printf ("\t\t-d <filename> <decoded_filename>\n");
					printf ("\t\t\tDecode a file in base 64\n");
					printf ("\t\t-h [<language>]\n");
					printf ("\t\t\tHelp\n");
				}
			break;
			case 'm':
			case 'M':
				if (optind >= argc) {
					printf("No filename detected.\n");
					break;
				}
				if (argv [optind][0] == '-') {
					printf("No filename detected.\n");
					break;
				}
				if (optind + 1 >= argc) {
					printf("Second filename not detected.\n");
					break;
				}
				if (argv [optind + 1][0] == '-') {
					printf("Second filename not detected.\n");
					break;
				}
				codigoRetorno = ConverterArquivoFormatoUnixFormatoDos(argv [optind], argv [optind + 1]);
				if (codigoRetorno) {
					printf("Error executing ConverterArquivoFormatoUnixFormatoDos function.\n");
					printf("Error: #%u\n", codigoRetorno);
					break;
				}
				printf("File successfully coverted.\n");
			break;
			case 'u':
			case 'U':
				if (optind >= argc) {
					printf("No filename detected.\n");
					break;
				}
				if (argv [optind][0] == '-') {
					printf("No filename detected.\n");
					break;
				}
				if (optind + 1 >= argc) {
					printf("Second filename not detected.\n");
					break;
				}
				if (argv [optind + 1][0] == '-') {
					printf("Second filename not detected.\n");
					break;
				}
				codigoRetorno = ConverterArquivoFormatoDosFormatoUnix(argv [optind], argv [optind + 1]);
				if (codigoRetorno) {
					printf("Error executing ConverterArquivoFormatoDosFormatoUnix function.\n");
					printf("Error: #%u\n", codigoRetorno);
					break;
				}
				printf("File successfully coverted.\n");
			break;
			default:
				printf ("Invalid option\n");
		}
	}
	return OK;
}
