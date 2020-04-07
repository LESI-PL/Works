/*
* Author: Yuri Lemos E João Figueiredo
* Description: Este Programa faz leitura de uma fichero ".txt" e com estes dados recolhidos efetua calculos estatisticos
* Data: 14 / 3 / 2020 
* Version: 1.0
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <math.h>
#include "structs.h"
#include "functions.h"
#define MAX 200

/**
 *!                                                 FUNCTIONS
*/
/**
 *?----------------------------------------------Funçoes de Carregamento--------------------------------------------------------------
*/
Morph *CarregarDados()
{
    Morph *dados = NULL, *temp = NULL;
    FILE *f;
    int i = 0;
    dados = (Morph *)malloc(sizeof(Morph));

    f = fopen("frase.txt", "r");
    if (f == NULL)
    {
        printf("Erro na leitura do ficheiro!");
    }
    else
    {

        while (fscanf(f, "%s %s %s %f", dados->originWord, dados->wordRoot, dados->morphAnalise, &dados->rightProb) != EOF)
        {

            if (checkWord(dados->originWord) == 1 && checkWord(dados->wordRoot) == 1 && checkWord(dados->morphAnalise) == 1)
            {
                temp = InsertNode(temp, dados);
                i++;
            }
        }
    }
    temp->total = i;
    fclose(f);
    return temp;
}

/**
 *?----------------------------------------------------Fim-----------------------------------------------------------------------------
*/

/**
 *?----------------------------------------------Manuseamento de Struct----------------------------------------------------------------
*/
Morph *NewNode(Morph *dados)
{
    Morph *temp = (Morph *)malloc(sizeof(Morph));
    strcpy(temp->originWord, dados->originWord);
    strcpy(temp->wordRoot, dados->wordRoot);
    strcpy(temp->morphAnalise, dados->morphAnalise);
    temp->rightProb = dados->rightProb;
    temp->quantidade = 1;
    temp->total = 0;
    temp->right = NULL;
    temp->left = NULL;
    return temp;
}
Morph *InsertNode(Morph *temp, Morph *dados)
{
    char *aux = (char *)malloc((contWord(dados->originWord) + 1) * sizeof(char));
    char *aux1;
    aux = checkLetra(dados->originWord);
    if (temp == NULL)
    {
        return NewNode(dados);
    }
    else
    {
        aux1 = (char *)malloc((contWord(temp->originWord) + 1) * sizeof(char));
        aux1 = checkLetra(temp->originWord);
        if (strcmp(aux1, aux) > 0)
        {
            temp->left = InsertNode(temp->left, dados);
        }
        if (strcmp(aux1, aux) < 0)
        {
            temp->right = InsertNode(temp->right, dados);
        }
        if (strcmp(aux1, aux) == 0)
        {
            temp->quantidade++;
        }
    }
    return temp;
}

/*Geral *newNode(Morph *morph)
{
    Geral *temp = (Geral *)malloc(sizeof(Geral));
    temp->nome = (char *)malloc((contWord(morph->originWord) + 1) * sizeof(char));
    temp->qtdAbs = (int *)malloc(sizeof(int));

    strcpy(temp->nome, morph->originWord);
    temp->qtdAbs = 1;
}*/
/**
 *?----------------------------------------------------Fim-----------------------------------------------------------------------------
*/

/**
 *?----------------------------------------------Verificacoes de dados----------------------------------------------------------------
*/
int checkWord(char palavra[])
{
    int i;
    for (i = 0; i < contWord(palavra); i++)
    {
        if (!((palavra[i] > 64 && palavra[i] < 91) || (palavra[i] > 96 && palavra[i] < 123)))
        {
            return 0;
        }
    }
    return 1;
}

char *checkLetra(char *palavra)
{
    char *aux, *aux2;
    aux = (char *)malloc(20 * sizeof(char));
    aux2 = (char *)malloc(20 * sizeof(char));
    strcpy(aux, palavra);
    strcpy(aux2, aux);
    aux2 = strupr(aux2);
    if (aux[0] >= 97 && aux[0] <= 122)
    {
        aux[0] = aux2[0];
    }
    return aux;
}
/**
 *?----------------------------------------------------Fim-----------------------------------------------------------------------------
*/

/**
 *?--------------------------------------------------Calculos--------------------------------------------------------------------------
*/
int contWord(char *string)
{
    int i = 0;
    while (string[i] != '\0')
    {
        i++;
    }
    return i;
}
/**
 *?----------------------------------------------------Fim-----------------------------------------------------------------------------
*/

/**
 *?-------------------------------------------------Mostrar Dados----------------------------------------------------------------------
*/
char ShowMenu()
{
    char op;
    system("cls");
    printf("\n|-----------------------------------------------------------------------------------------------------|");
    printf("\n| 1) Exercicio 1 - Carregar Ficheiro          | 2) Exercicio 2 - Categoria Gramatical Ordenada        |");
    printf("\n|-----------------------------------------------------------------------------------------------------|");
    printf("\n| 3) Exercicio 3 - Comprimento das palavras   | 4) Exercicio 4 - Coluna 3 e 4 Media e Desvio          |");
    printf("\n|-----------------------------------------------------------------------------------------------------|");
    printf("\n| 5) Exercicio 5 - Comprimento das palavras   | 6) exercicio 6 - Frequencia de palavras               |");
    printf("\n|        Medidas de Localizacao e Dispersao   |    Mostrar o quartil que a palavra pertence           |");
    printf("\n|-----------------------------------------------------------------------------------------------------|");
    printf("\n| 7) Construir histograma das probabilidades  |                                                       |");
    printf("\n|-----------------------------------------------------------------------------------------------------|");
    printf("\n|                                          s)Sair                                                     |");
    printf("\n|-----------------------------------------------------------------------------------------------------|\n\n");
    op = getch();
    return op;
}

void ListarMorph(Morph *tree)
{
    int i;
    if (tree)
    {
        ListarMorph(tree->left);
        for(i = 0; i < tree->quantidade; i++)
        {
            printf("%s %s %s %f\n", tree->originWord, tree->wordRoot, tree->morphAnalise, tree->rightProb);
        }
        ListarMorph(tree->right);
    }
}
/**
 *?----------------------------------------------------Fim-----------------------------------------------------------------------------
*/
/**
 *!                                                END FUNCTION
*/