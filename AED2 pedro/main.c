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
    
    Actor *actors = NULL,*aux=NULL;
    setlocale(LC_ALL, "Portuguese");
    actors = LoadFile();
    char *id=(char*)malloc(50*sizeof(char));
    printf("digite um codigo:");
    aux=FindActorManual(actors,scanf("%s",id));
    printf("%s %s %s\n",aux->nome,aux->id,aux->sexo);
    /*ListarActor(actors);*/
    printf("acabei\n");getchar();
    /*actors=LoadMatrix(actors);
    printf("acabei a matriz\n");getchar();
    ators);*/

    /*MostraDados(actors);getchar();
    hash = CreateHash(actors);
    ShowHash(hash);
    hash = insertInHash(hash, actors);
    cont = 0;*/
    /**
     * ! NUNCA ESQUECER QUE A HASH É UM VETOR!!! PERCORRER ELE COMO SE PERCORRE UM VETOR
     * ! CASO QUEIRA PERCORRER ESTE VETOR FAZER ---------- WHILE(HASH[POSICAO].KEY != '\0')  --------------------
     * ! Consigo Pegar todos do sexo M dentro de um intervalo
     * ! Consigo buscar uma pessoa com um id sem percorrer 80.072 dados 
     * ! No indice zero percorro 27.500 dados evitando de passar em 65% dos dados gerais, portanto percorro 33% dos dados gerais
     * ! O indice zero é o maior de todos, ou seja, no indice 1 contém 22.500 e estes valores vão diminuindo quanto maior o indice
    */
    /*i = 0;
    while (hash[i].key != '\0')
    {
        printf("%c intervalo:[%d;%d]\n", hash[i].key, hash[i].idMin, hash[i].idMax);
        list = hash[i].list;

        while (list)
        {

            printf("%s %s %s\n", list->id, list->nome, list->sexo);
            cont++;
            list = (list->next ? list->next : NULL);
        }
        i++;
    }

    printf("Contador:%d\n", cont);*/
    printf("Passagem de dados concluida!\nAperte 's' para sair!");

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