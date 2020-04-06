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

    do
    {
        op = ShowMenu();
        switch (op)
        {
        case '1': /*Exercicio 1*/
            system("cls");

            
            getchar();

            break;
        case '2': /*Exercicio 2*/
            system("cls");

            

            getchar();

            break;
        case '3': /*Exercicio 3*/
            system("cls");

            

            getchar();

            break;
        case '4': /*Exercicio 4*/
            
            

            fflush(stdin);
            getchar();
            break;
        case '5':
            system("cls");

            

            getchar();
            break;
        case '6':
            system("cls");
            
            getchar();
            break;
        default:
            break;
        }

    } while (op != 's');
}