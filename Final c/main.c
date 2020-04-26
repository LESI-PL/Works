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

    Morph *listaDL = NULL;
    Geral *ex2 = NULL, *ex3 = NULL; /*Struct para coluna 3 com sua qtd absoluta*/
    Ex6 *ex6 = NULL, *ex6Ordenada = NULL;
    Ex7 *ex7 = NULL;
    system("cls");
    /**
     * ! Exercicio 1
    */
    /* Carregameto dos dados*/
    listaDL = CarregarDados();
    totalListaDL = listaDL->total;
    printf("Exercicio 1) Ficheiro Carregado!!!\n");
    printf("A carregar dados...");

    /**
     * ! Fim Exercicio 1
    */

    /**
     *! Exercicio 2
    */
    ex2 = Ex2Load(listaDL);

    /**
     *! Fim Exercicio2 
    */

    /**
     *! Exercicio 3
    */
    ex3 = Ex3Load(listaDL);
    /**
     *! Fim Exercicio 3 
    */
    /**
     *! Exercicio 6
    */
    ex6 = Ex6Load(listaDL);
    ex6Ordenada = Ex6Load_Ordenada(ex6);
    /**
     *! Fim Exercicio 6
    */

    /**
     *! Exercicio 7
    */
    ex7 = Ex7Load(listaDL);
    /**
     *! Fim Exercicio 7
    */
    destroy_ListaDL(listaDL);
    do
    {

        /*Mostra o menu e retorna a escolha do utilizador*/
        op = ShowMenu();
        /**
         * !        Listagem dos dados
        */

        switch (op)
        {
        case '1': /*Exercicio 2*/
            ListarE2(ex2);
            break;
        case '2': /*Exercicio 3*/
            ListarE3(ex3);
            break;
        case '3': /*Exercicio 4*/
            ListarE4(ex2);
            break;
        case '4': /*Exercicio 5*/
            ListarE5(ex3, totalListaDL);
            break;
        case '5': /*Exercicio 6*/
            /*Q1=usar "firstladyship"    Q2= usar "ola"      Q3= usar "camouflage"    Q4= usar "to"*/
            Ex6_Palavra_Inserida(ex6, ex6Ordenada);
            break;
        case '6': /*Exercicio  - Comprimento*/
            ListarE6_1(ex3, totalListaDL);
            break;
        case '7':/*Exercicio 7*/
            Histograma2(ex7);
            break;
        default:
            break;
        }

    } while (op != 's');
    return 0;
}