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
    int abs=0;
    Morph *morph = NULL;
    coluna *coluna3= NULL;
    
    morph=LoadFile();
    coluna3=LoadCol3(morph);
    abs = ContaTotalCol3(coluna3);
    CalcularRelativa(coluna3,abs);
    do{
        op=ShowMenu();
        switch (op)
        {
        case '1':
            printf("|   Nome   |   ABS   |    REL.  |\n");
            printf("|    %s    |    %d    |   %.3f  |\n",coluna3->nome,coluna3->qtdAbs,coluna3->qtdrelativa);
            printf("|    %s   |    %d    |   %.3f  |\n",coluna3->next->nome,coluna3->next->qtdAbs,coluna3->next->qtdrelativa);
            printf("|    %s    |    %d    |   %.3f  |\n",coluna3->next->next->nome,coluna3->next->next->qtdAbs,coluna3->next->next->qtdrelativa);
            printf("|    %s    |    %d    |   %.3f  |\n",coluna3->next->next->next->nome,coluna3->next->next->next->qtdAbs,coluna3->next->next->next->qtdrelativa);
            printf("|   Total  |    %d    |          |\n",abs);
            fflush(stdin);getchar();       
            break;
        case '2':
            printf("NOME:%s QTD:%d",coluna3->nome,coluna3->qtdAbs);fflush(stdin);getchar();
            break;
        case '3':
            printf("Entrou em %c",op);getchar();
            break;
        case '4':
            printf("Entrou em %c",op);getchar();
            break;
        case '5':
            printf("Entrou em %c",op);getchar();
            break;
        case '6':
            printf("Entrou em %c",op);getchar();
            break;
        default:
            break;
        }

    }while(op != 's');
    
    return 0;
}
/**
 *!                                                    End Main
 * */

