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
    int absAcomulada = 0;
    float relAcomulada = 0;
    Morph *tree = NULL;
    Geral *ex2 = NULL, *ex2Org = NULL; /*Struct para coluna 3 com sua qtd absoluta*/
    Geral *ex3 = NULL, *ex3Org = NULL;
    char Ex2Titulo[50], Ex3Titulo[70];

    /**
     * ! Exercicio 1
    */
    /* Carregameto dos dados*/
    tree = CarregarDados();
    /**
     * ! Fim Exercicio 1
    */

    /**
     *! Exercicio 2
    */
    /*Carrega os dados de tree para uma lista ligada somente com os dados que preciso da coluna 3*/
    ex2 = Ex2Load(tree, ex2);
    /*Usa o total de dados para calcular a Frequencia Relativa de cada letra*/
    ex2 = Ex2CalcularFreqRel(ex2, tree->total);
    /*Passa tudo para uma arvore binaria para que os dados fiquem organizados*/
    ex2Org = Ex2LoadTree(ex2, ex2Org);
    /**
     *! Fim Exercicio2 
    */

   /**
     *! Exercicio 3
    */
    /*Carrega os dados de tree para uma lista ligada somente com os dados que preciso da coluna 3*/
    ex3 = Ex3Load(tree, ex3);
    /*Usa o total de dados para calcular a Frequencia Relativa de cada tamanho da palavra*/
    ex3 = Ex3CalcularFreqRelEx3(ex3, tree->total);
    /**
     *! Fim Exercicio 3 
    */
    /**
     *! Exercicio 4
    */
    ex2 = Ex4CalcularMedia(ex2);
    ex2 = Ex4CalcularDp(ex2);
    /**
     *! Fim Exercicio 4
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
            ListarMorph(tree);
            printf("\nTotal:%d\n", tree->total);

            getchar();

            break;
        case '2': /*Exercicio 2*/
            /**
             * !          Ex2)  Categoria gramatical ordenada 
             * !   | Nome | Qtd Abs | Qtd Relativa | Abs acumulada | Relativa Acumulada |
            */
            system("cls");
            /*Faz a listagem dos dados; La dentro faz as acumuladas*/
            
            strcpy(Ex2Titulo, "Tabela de Frequencias Da Terceira Coluna");
            Cabecalho(Ex2Titulo);
            absAcomulada = 0;
            relAcomulada = 0;
            ListarEx2Tree(ex2Org, absAcomulada, relAcomulada);
            absAcomulada = 0;
            relAcomulada = 0;
            absAcomulada = buscarTotalAcumulado(ex2Org, absAcomulada);
            relAcomulada = buscarTotalRelAcumulada(ex2Org, relAcomulada);
            RodapeEx2(absAcomulada, relAcomulada);
            getchar();
            break;
        case '3': /*Exercicio 3*/
            /**
             * !          Ex3)  Comprimento das palavras ordenada 
             * !   | comprimento | Qtd Abs | Qtd Relativa | Abs acumulada | Relativa Acumulada |
            */
            system("cls");
            /*Faz a listagem dos dados; La dentro faz as acumuladas*/
            strcpy(Ex3Titulo, "Tabela de Frequencias Da Comprimentos das Palavras");
            Cabecalho(Ex3Titulo);
            absAcomulada = 0;
            relAcomulada = 0;
            ListarEx3Tree(ex3, absAcomulada, relAcomulada);
            absAcomulada = 0;
            relAcomulada = 0;
            absAcomulada = buscarTotalAcumuladoEx3(ex3, absAcomulada);
            relAcomulada = buscarTotalRelAcumuladaEx3(ex3, relAcomulada);
            RodapeEx3(absAcomulada, relAcomulada);
            getchar();

            break;
        case '4': /*Exercicio 4*/
            system("cls");
            ListarEx4(ex2);
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
    return 0;
}