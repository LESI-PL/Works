/*
* Author: Yuri Lemos e João Figueiredo
* Description: Este Programa faz leitura de uma fichero ".txt" e com estes dados recolhidos efetua calculos estatisticos
* Data: 14 / 3 / 2020 
* Version: 1.0
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include "functions.h"
#include "structs.h"
/**
 *!                                                     Main
 * */
int main()
{
    char op;
    int abs = 0, i = 0;
    Morph *morph = NULL;
    coluna *coluna3 = NULL, *cl3, *col3Ordenada = NULL;
    Coluna1 *colunaAux = NULL, *cl4, *colunaAux_Ordenada = NULL, *cl41 = NULL;
    TipoLetra *letras = NULL;
    float media_comprimento = 0;
    int mediana_comprimento = 0;
    int *moda_comprimento;
    int moda = 0;
    int contamodas = 0;
    int ordem = 0;
    float dp_comprimento = 0;

    morph = LoadFile();
    coluna3 = LoadCol3(morph);
    colunaAux = LoadCol4(morph);
    letras = LoadCol5(morph);
    abs = ContaTotalCol3(coluna3);
    CalcularRelativa(coluna3, abs);
    CalcularRelativa_Comprimento(colunaAux, abs);
    cl3 = coluna3;
    cl4 = colunaAux;

    do
    {
        op = ShowMenu();
        switch (op)
        {
        case '1': /*Exercicio 1*/
            system("cls");

            if (morph == NULL)
            {

                morph = LoadFile();
                if (morph == NULL)
                    printf("Falha ao carregar o ficheiro!\n");
                else
                    printf("Ficheiro carregado com sucesso!\n");
            }
            ShowList(morph);
            getchar();

            break;
        case '2': /*Exercicio 2*/
            system("cls");

            ShowListEx2(cl3, col3Ordenada);

            getchar();

            break;
        case '3': /*Exercicio 3*/
            system("cls");

            ShowList_3(cl4, colunaAux_Ordenada);

            getchar();

            break;
        case '4': /*Exercicio 4*/
            system("cls");

            letras = CalcularMedia(letras);
            letras = CalcularDp(letras);
            ShowListEx4(letras);
            /*printf("\n\n");
            ShowListEx42(letras);*/

            fflush(stdin);
            getchar();
            break;
        case '5': /*Exercicio 5*/
            system("cls");

            cl41 = Ordennar_Lista3(cl4, colunaAux_Ordenada);
            media_comprimento = CalcularMediaComprimento(cl4);
            printf(" media = %.2f", media_comprimento);
            moda = ProcuraModa(cl41);
            printf("moda = %d\n", moda);
            moda_comprimento = ProcuraModas(cl41, moda);
            contamodas = ContarModas(cl41, moda);

            printf("cheguei\n");
            ordem = ProcurarMediana(abs);
            printf("ordem %d\n", ordem);
            mediana_comprimento = CalcularMedianaComprimento(cl41, ordem, abs);
            printf(" mediana = %d\n", mediana_comprimento);
            dp_comprimento = DesvioPadraoComprimento(cl41, abs, media_comprimento);
            printf("desvio %.2f",dp_comprimento);


            getchar();
            break;
        case '6':
            printf("Entrou em %c", op);
            getchar();
            break;
        default:
            break;
        }

    } while (op != 's');

    return 0;
}
/**
 *!                                                    End Main
 * */
