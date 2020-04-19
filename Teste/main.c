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
    int totalListaDL;
    char op;
    float quartil;

    Morph *listaDL = NULL;
    Geral *ex2 = NULL, *ex3 = NULL, *ex6=NULL; /*Struct para coluna 3 com sua qtd absoluta*/

    /**
     * ! Exercicio 1
    */
    /* Carregameto dos dados*/
    listaDL = CarregarDados();
    totalListaDL = listaDL->total;
    printf("Done! %d\n", totalListaDL);
    printf("Ficheiro Carregado\n");
    
    /**
     * ! Fim Exercicio 1
    */

    /**
     *! Exercicio 2
    */
    ex2 = Ex2Load(listaDL);
    printf("Ex2 Carregada!\n");
    
    /**
     *! Fim Exercicio2 
    */

    /**
     *! Exercicio 3
    */
    ex3 = Ex3Load(listaDL);
    printf("Ex3 Carregada!\n");
    /**
     *! Fim Exercicio 3 
    */
    /**
     *! Exercicio 6
    */
   /*ex6 = Ex6Load(listaDL);
   ListarE6(ex6);
   CalcularQuartis(ex6);*/
    /**
     *! Fim Exercicio 6
    */
    do
    {

        /*Mostra o menu e retorna a escolha do utilizador*/
        op = ShowMenu();

        switch (op)
        {
        case '1': /*Exercicio 1*/
            /**
             * !          Ex1)  listagem dos dados
            */
            system("cls");

            getchar();

            break;
        case '2': /*Exercicio 2*/
            ListarE2(ex2);
            break;
        case '3': /*Exercicio 3*/
            ListarE3(ex3);
            break;
        case '4': /*Exercicio 4*/
            ListarE4(ex2);
            break;
        case '5': /*Exercicio 5*/
            ListarE5(ex3,totalListaDL);
            break;
        case '6': /*Exercicio  - Comprimento*/
            ListarE6_1(ex3,totalListaDL);
            break;
        default:
            break;
        }

    } while (op != 's');
    return 0;
}