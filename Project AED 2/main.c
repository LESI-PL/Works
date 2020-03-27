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
    int abs = 0, i;
    Morph *morph = NULL;
    coluna *coluna3 = NULL, *cl3, *col3Ordenada = NULL;
    Coluna1 *colunaAux = NULL, *cl4, *colunaAux_Ordenada = NULL;
    TipoLetra *letras = NULL;

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
                    printf("Falha ao carregar o ficheiro!");
                else
                    printf("Ficheiro carregado com sucesso!");
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
            
            
            letras = CalcularMedia(letras);
            letras = CalcularDp(letras);
            ShowListEx4(letras);
            /*printf("\n\n");
            ShowListEx42(letras);*/

            fflush(stdin);
            getchar();
            break;
        case '5':
            system("cls");

            ShowList_3(cl4, colunaAux_Ordenada);

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
