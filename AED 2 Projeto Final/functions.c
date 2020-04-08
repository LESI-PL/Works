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
/**
 *! Exercicio 1
*/
Morph *CarregarDados(){
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
 *! Fim Exercicio 1
*/


/**
 *! Exercicio 2
*/
Geral *Ex2Load(Morph *morph, Geral *dados){
    int i;
    if (morph)
    {
        dados = Ex2Load(morph->left, dados);
        for (i = 0; i < morph->quantidade; i++)
        {
            dados = Ex2InsertNode(dados, morph);
        }

        dados = Ex2Load(morph->right, dados);
    }
    return dados;
}
Geral *Ex2LoadTree(Geral *dados, Geral *dadosOrganizados){
    if (dados != NULL)
    {
        dadosOrganizados = Ex2LoadTree(dados->right, dadosOrganizados);

        dadosOrganizados = Ex2OrganizarTree(dados, dadosOrganizados);
    }
    return dadosOrganizados;
}
/**
 *! Fim Exercicio 2
*/
/**
 *?----------------------------------------------------Fim-----------------------------------------------------------------------------
*/

/**
 *?----------------------------------------------Manuseamento de Struct----------------------------------------------------------------
*/
/**
 *! Exercicio 1
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
/**
 *! Fim Exercicio 1
*/



/**
 *! Exercicio 2
*/
Geral *Ex2NewNode(Morph *morph){
    Geral *temp;
    temp = (Geral *)malloc(sizeof(Geral));
    temp->nome = (char *)malloc((contWord(morph->morphAnalise) + 1) * sizeof(char));

    strcpy(temp->nome, morph->morphAnalise);
    temp->qtdAbs = 1;
    temp->qtdRelativa = 0;
    temp->right = NULL;
    temp->left = NULL;
    return temp;
}
Geral *Ex2InsertNode(Geral *dadosEx2, Morph *dados){
    if (dadosEx2 == NULL)
    {
        return Ex2NewNode(dados);
    }
    else if (strcmp(dados->morphAnalise, dadosEx2->nome) == 0)
    {
        dadosEx2->qtdAbs++;
    }
    else
    {
        dadosEx2->right = Ex2InsertNode(dadosEx2->right, dados);
    }
    return dadosEx2;
}
Geral *Ex2InsertNewTree(Geral *dados){
    Geral *temp = (Geral *)malloc(sizeof(Geral));
    temp->nome = (char *)malloc((contWord(dados->nome) + 1) * sizeof(char));

    strcpy(temp->nome, dados->nome);
    temp->qtdAbs = dados->qtdAbs;
    temp->qtdRelativa = dados->qtdRelativa;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
Geral *Ex2OrganizarTree(Geral *dados, Geral *dadosOrganizados){
    if (dadosOrganizados == NULL)
    {
        /*printf("Dados: %s\n",dados->nome);getchar();*/
        return Ex2InsertNewTree(dados);
    }
    else
    {
        if (dados->qtdAbs > dadosOrganizados->qtdAbs)
        {   /*Right*/
            /*printf("Right   dados:%s %d  |  dadosOrg: %s  %d",dados->nome,dados->qtdAbs,dadosOrganizados->nome,dadosOrganizados->qtdAbs);getchar();*/
            dadosOrganizados->right = Ex2OrganizarTree(dados, dadosOrganizados->right);
        }
        else if (dados->qtdAbs >= dadosOrganizados->qtdAbs)
        {   /*Left*/
            /*printf("Left   dados:%s %d  |  dadosOrg: %s  %d",dados->nome,dados->qtdAbs,dadosOrganizados->nome,dadosOrganizados->qtdAbs);getchar();*/
            dadosOrganizados->left = Ex2OrganizarTree(dados, dadosOrganizados->left);
        }
    }
    return dadosOrganizados;
}
/**
 *! Fim Exercicio 2
*/
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
/**
 *! Gerericas
*/
int contWord(char *string){
    int i = 0;
    while (string[i] != '\0')
    {
        i++;
    }
    return i;
}

/**
 *! Exercicio 2
*/
int AbsAcomulada(Geral* ex2, int sum){
    if(ex2){
        sum = ex2->qtdAbs + AbsAcomulada(ex2->left,sum);
    }
    return sum;
}
float RelAcomulada(Geral* ex2, float sum){
    if(ex2){
        sum = ex2->qtdRelativa + RelAcomulada(ex2->left,sum);
    }
    return sum;
}
Geral *Ex2CalcularFreqRel(Geral *dados, int totalDados){
    if (dados == NULL)
    {
        return dados;
    }
    else
    {
        dados->right = Ex2CalcularFreqRel(dados->right, totalDados);
        dados->qtdRelativa = dados->qtdAbs / (float)totalDados;
    }
    return dados;
}
/**
 *! Fim Exercicio 2
*/
/**
 *?----------------------------------------------------Fim-----------------------------------------------------------------------------
*/

/**
 *?-------------------------------------------------Mostrar Dados----------------------------------------------------------------------
*/
/**
 *! Exercicio 1
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
        for (i = 0; i < tree->quantidade; i++)
        {
            printf("%s %s %s %f\n", tree->originWord, tree->wordRoot, tree->morphAnalise, tree->rightProb);
        }
        ListarMorph(tree->right);
    }
}
/**
 *! Fim Exercicio 1
*/




/**
 *! Exercicio 2
*/
void ListarEx2(Geral *ex2)
{
    while (ex2)
    {
        printf("%s %d \n", ex2->nome, ex2->qtdAbs);
        ex2 = (ex2->right ? ex2->right : NULL);
    }
}

void ListarEx2Tree(Geral *ex2, int absAcomulada, float relAcomulada)
{
    if (ex2)
    {
        ListarEx2Tree(ex2->left,absAcomulada,relAcomulada);
        absAcomulada = AbsAcomulada(ex2,absAcomulada);
        relAcomulada = RelAcomulada(ex2,relAcomulada);
        printf("| %4s | %7d      |   %f   | %10d         |       %f     |\n", ex2->nome, ex2->qtdAbs, ex2->qtdRelativa, absAcomulada, relAcomulada);
        ListarEx2Tree(ex2->right,absAcomulada,relAcomulada);
    }
}
/**
 *! Fim Exercicio 2
*/
/**
 *?----------------------------------------------------Fim-----------------------------------------------------------------------------
*/
/**
 *!                                                END FUNCTION
*/