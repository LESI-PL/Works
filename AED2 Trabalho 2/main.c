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
#include <locale.h>
#include "functions.h"
#include "structs.h"

/**
 *!                                                     Main
 * */

int main()
{
    Actor *actors = NULL;
    getchar();
    setlocale(LC_ALL, "Portuguese");
    actors = LoadFileActors(actors);
    actors = LoadFileCoActors(actors);
    FindActor(actors,"nm0917715");
    printf("Passagem de dados concluida!\nAperte 's' para sair!");getchar();
    
    /*do
    {
        op = getch();
        

        switch (op)
        {
        case '1': 
            
            break;
        case '2': 
            
            break;
        case '3': 
            
            break;
        case '4': 
            
            break;
        case '5': 
            
            break;
        case '6': 
            
            break;
        case '7':
            
            break;
        default:
            break;
        }

    } while (op != 's');*/
    return 0;
}