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
    Actor3 *actor = NULL;
    Actor3 * GajoComMaisCenas;
    Actor3 * aux = (Actor3*)malloc(sizeof(Actor3));
    Actor3  *outroGajoMaisCenas = (Actor3 *) malloc(sizeof(Actor3));
    /* //system("C:\\Users\\Lenovo\\AppData\\Local\\Programs\\Opera\\launcher.exe c:\\export\\a.html");
    //system("C:\\Users\\Lenovo\\AppData\\Local\\Programs\\Opera\\launcher.exe c:\\export\\actors.txt"); */

    actor = LoadFileActors(actor);
    printf("Ficheiro carregado!\n");
    LoadFileCoActors(actor);
    printf("\nVou listar, prima uma tecla para continuar: \n");
    getchar();

    
    aux->numAtuacoes = -1;

    GajoComMaisCenas = (Actor3 *) malloc(sizeof(Actor3));
    /*MaisCenas( actor);*/
    printf("Gajo com cenas %s\n", GajoComMaisCenas->id);

    
    outroGajoMaisCenas = MaisCenas2( actor, outroGajoMaisCenas);
    printf("Gajo com cenas %s\n", outroGajoMaisCenas->id);


    getchar();
/* 
    //find(actor);
    //FindActorsWho_act_only_whith_females(actor); */
    WriteTree(actor);
    Actors_Name(actor);
    /* FindActorsWho_act_only_whith_females(actor);
    //ListarTreeActors(actor);
    //FindCoactors(actor);
    //ListarTreeActors(actor); */
    printf("Ficheiro carregado e listado e com coatores\n");
    getchar();
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