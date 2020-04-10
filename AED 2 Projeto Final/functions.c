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
 *! Fim Exercicio 1
*/

/**
 *! Exercicio 2
*/
Geral *Ex2Load(Morph *morph, Geral *dados)
{
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
Geral *Ex2LoadTree(Geral *dados, Geral *dadosOrganizados)
{
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
 *! Exercicio 3
*/
Geral *Ex3Load(Morph *morph, Geral *dados)
{
    int i;
    if (morph)
    {
        dados = Ex3Load(morph->left, dados);
        for (i = 0; i < morph->quantidade; i++)
        {
            dados = Ex3InsertNode(dados, morph);
        }

        dados = Ex3Load(morph->right, dados);
    }
    return dados;
}
Geral *Ex3LoadTree(Geral *dados, Geral *dadosOrganizados)
{
    if (dados != NULL)
    {
        dadosOrganizados = Ex3LoadTree(dados->right, dadosOrganizados);

        dadosOrganizados = Ex3OrganizarTree(dados, dadosOrganizados);
    }
    return dadosOrganizados;
}
/**
 *! Fim Exercicio 3
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
Geral *Ex2NewNode(Morph *morph)/* Funcao Foi Alterada*/
{
    Geral *temp;
    temp = (Geral *)malloc(sizeof(Geral));
    temp->nome = (char *)malloc((contWord(morph->morphAnalise) + 1) * sizeof(char));
    temp->valores = (float *)malloc(sizeof(float));

    strcpy(temp->nome, morph->morphAnalise);
    temp->qtdAbs = 1;
    temp->qtdRelativa = 0;
    temp->valores[temp->qtdAbs - 1] = morph->rightProb;
    temp->medidaDeCerteza = morph->rightProb;
    temp->right = NULL;
    temp->left = NULL;
    return temp;
}
Geral *Ex2InsertNode(Geral *dadosEx2, Morph *dados)/* Funcao Foi Alterada*/
{
    if (dadosEx2 == NULL)
    {
        return Ex2NewNode(dados);
    }
    else if (strcmp(dados->morphAnalise, dadosEx2->nome) == 0)
    {
        dadosEx2->qtdAbs++;
        dadosEx2->valores = (float *)realloc(dadosEx2->valores, dadosEx2->qtdAbs * sizeof(float));
        dadosEx2->valores[dadosEx2->qtdAbs - 1] = dados->rightProb;
        dadosEx2->medidaDeCerteza += dados->rightProb;
    }
    else
    {
        dadosEx2->right = Ex2InsertNode(dadosEx2->right, dados);
    }
    return dadosEx2;
}
Geral *Ex2InsertNewTree(Geral *dados)
{
    Geral *temp = (Geral *)malloc(sizeof(Geral));
    temp->nome = (char *)malloc((contWord(dados->nome) + 1) * sizeof(char));

    strcpy(temp->nome, dados->nome);
    temp->qtdAbs = dados->qtdAbs;
    temp->qtdRelativa = dados->qtdRelativa;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
Geral *Ex2OrganizarTree(Geral *dados, Geral *dadosOrganizados)
{
    if (dadosOrganizados == NULL)
    {
        /*printf("Dados: %s\n",dados->nome);getchar();*/
        return Ex2InsertNewTree(dados);
    }
    else
    {
        if (dados->qtdAbs > dadosOrganizados->qtdAbs)
        { /*Right*/
            /*printf("Right   dados:%s %d  |  dadosOrg: %s  %d",dados->nome,dados->qtdAbs,dadosOrganizados->nome,dadosOrganizados->qtdAbs);getchar();*/
            dadosOrganizados->right = Ex2OrganizarTree(dados, dadosOrganizados->right);
        }
        else if (dados->qtdAbs >= dadosOrganizados->qtdAbs)
        { /*Left*/
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
 *! Exercicio 3
*/
Geral *Ex3NewNode(Morph *morph)
{
    Geral *temp;
    temp = (Geral *)malloc(sizeof(Geral));
    temp->lenght = strlen(morph->originWord);
    temp->qtdAbs = 1;
    temp->qtdRelativa = 0;
    temp->right = NULL;
    temp->left = NULL;
    return temp;
}
Geral *Ex3InsertNode(Geral *dadosEx3, Morph *dados)
{
    int a;
    if (dadosEx3 == NULL)
    {
        return Ex3NewNode(dados);
    }
    else
    {
        a = strlen(dados->originWord);

        if (dadosEx3->lenght == a)
        {

            dadosEx3->qtdAbs++;
        }

        if (dadosEx3->lenght > a)
        {
            dadosEx3->left = Ex3InsertNode(dadosEx3->left, dados);
        }
        if (dadosEx3->lenght < a)
        {
            dadosEx3->right = Ex3InsertNode(dadosEx3->right, dados);
        }
    }
    return dadosEx3;
}

Geral *Ex3InsertNewTree(Geral *dados)
{
    Geral *temp = (Geral *)malloc(sizeof(Geral));
    temp->lenght = dados->lenght;
    temp->qtdAbs = dados->qtdAbs;
    temp->qtdRelativa = dados->qtdRelativa;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
Geral *Ex3OrganizarTree(Geral *dados, Geral *dadosOrganizados)
{
    if (dadosOrganizados == NULL)
    {
        /*printf("Dados: %s\n",dados->nome);getchar();*/
        return Ex3InsertNewTree(dados);
    }
    else
    {
        if (dados->qtdAbs > dadosOrganizados->qtdAbs)
        { /*Right*/
            /*printf("Right   dados:%s %d  |  dadosOrg: %s  %d",dados->nome,dados->qtdAbs,dadosOrganizados->nome,dadosOrganizados->qtdAbs);getchar();*/
            dadosOrganizados->right = Ex3OrganizarTree(dados, dadosOrganizados->right);
        }
        else if (dados->qtdAbs >= dadosOrganizados->qtdAbs)
        { /*Left*/
            /*printf("Left   dados:%s %d  |  dadosOrg: %s  %d",dados->nome,dados->qtdAbs,dadosOrganizados->nome,dadosOrganizados->qtdAbs);getchar();*/
            dadosOrganizados->left = Ex3OrganizarTree(dados, dadosOrganizados->left);
        }
    }
    return dadosOrganizados;
}
/**
 *! Fim Exercicio 3
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
    aux2 = strupr(aux);
  
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
 *! Genericas
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
 *! Exercicio 2
*/
int AbsAcomulada(Geral *ex2, int sum)
{
    if (ex2)
    {
        sum = ex2->qtdAbs + AbsAcomulada(ex2->left, sum);
    }
    return sum;
}
int buscarTotalAcumulado(Geral *ex2, int total)
{

    if (ex2 != NULL)
    {
        buscarTotalAcumulado(ex2->left, total);
        total = AbsAcomulada(ex2, total);
        buscarTotalAcumulado(ex2->right, total);
    }
    else
    {
        return total;
    }

}
float RelAcomulada(Geral *ex2, float sum)
{
    if (ex2)
    {
        sum = ex2->qtdRelativa + RelAcomulada(ex2->left, sum);
    }
    return sum;
}
float buscarTotalRelAcumulada(Geral *ex2, float total)
{

    if (ex2 != NULL)
    {
        buscarTotalRelAcumulada(ex2->left, total);
        total = RelAcomulada(ex2, total);
        buscarTotalRelAcumulada(ex2->right, total);
    }
    else
    {
        return total;
    }
    return total;
    
}
Geral *Ex2CalcularFreqRel(Geral *dados, int totalDados)
{
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
 *! Exercicio 3
*/
int AbsAcomuladaEx3(Geral *ex3, int sum)
{
    if (ex3)
    {
        printf("\nantes sum %d",sum);
        sum = ex3->qtdAbs + AbsAcomuladaEx3(ex3->left, sum);
        printf("\ndepois sum %d",sum);getchar();
    }
    return sum;
}
int buscarTotalAcumuladoEx3(Geral *ex3, int total)
{

    if (ex3)
    {
        buscarTotalAcumuladoEx3(ex3->left, total);
        total = AbsAcomuladaEx3(ex3, total);
        buscarTotalAcumuladoEx3(ex3->right, total);
    }
    else
    {
        return total;
    }

}
float RelAcomuladaEx3(Geral *ex3, float sum)
{
    if (ex3)
    {
        sum = ex3->qtdRelativa + RelAcomuladaEx3(ex3->left, sum);
    }
    return sum;
}
float buscarTotalRelAcumuladaEx3(Geral *ex3, float total)
{

    if (ex3 != NULL)
    {
        buscarTotalRelAcumuladaEx3(ex3->left, total);
        total = RelAcomuladaEx3(ex3, total);
        buscarTotalRelAcumuladaEx3(ex3->right, total);
    }
    else
    {
        return total;
    }
   
}

Geral *Ex3CalcularFreqRelEx3(Geral *dados, int totalDados)
{
    if (dados == NULL)
    {
        return dados;
    }
    else
    {
        dados->right = Ex3CalcularFreqRelEx3(dados->right, totalDados);
        dados->qtdRelativa = dados->qtdAbs / (float)totalDados;
    }
    return dados;
}
/**
 *! Fim Exercicio 3
*/



/**
 *! Exercicio 4
*/
Geral *Ex4CalcularMedia(Geral *dados)
{
    if (dados)
    {
        dados->right = Ex4CalcularMedia(dados->right);
        dados->media = dados->medidaDeCerteza / dados->qtdAbs;
    }
    else if (dados == NULL)
    {
        return dados;
    }
    return dados;
}

Geral* Ex4CalcularDp(Geral* dados){
    Geral *temp = dados;
    int i = 0;
    float dp;
    while (dados)
    {
        dp = 0;
        for (i = 0; i < dados->qtdAbs; i++)
        {
            dp += pow(dados->valores[i] - dados->media,2);
        }
        dp = dp/dados->qtdAbs;
        dp = sqrt(dp);
        dados->desvioPadrao = dp;
        dados = (dados->right ? dados->right : NULL);
    }
    return temp;
}

/**
 *! Fim Exercicio 4
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
 * ! Generico
*/
void Cabecalho(char *nome)
{
    int i;
    printf("\t\t%s\n", nome);
    for (i = 0; i < 81; i++)
    {
        printf("%c", '_');
    }
    printf("\n| %5s | %s | %s | %s | %s |\n", "Nome", "Qtd Absoluta", "Qtd Relativa", "Absoluta Acumulada", "Relativa Acumulada");
    for (i = 0; i < 81; i++)
    {
        printf("%c", '_');
    }
    printf("\n");
}
/**
 * ! FIM
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

void RodapeEx2(int abs, float rel)
{
    int i;
    for (i = 0; i < 81; i++)
    {
        printf("%c", '_');
    }

    printf("\n| %s | %10d | %10.f | %20s | %20s |\n", "Total", abs, rel, "", "");
    for (i = 0; i < 81; i++)
    {
        printf("%c", '_');
    }
    printf("\n");
}

void ListarEx2Tree(Geral *ex2, int absAcomulada, float relAcomulada)
{
    if (ex2)
    {
        ListarEx2Tree(ex2->left, absAcomulada, relAcomulada);
        absAcomulada = AbsAcomulada(ex2, absAcomulada);
        relAcomulada = RelAcomulada(ex2, relAcomulada);
        printf("| %5s | %7d      |   %f   | %10d         |       %f     |\n", ex2->nome, ex2->qtdAbs, ex2->qtdRelativa, absAcomulada, relAcomulada);
        ListarEx2Tree(ex2->right, absAcomulada, relAcomulada);
    }
}
/**
 *! Fim Exercicio 2
*/

/**
 *! Exercicio 3
*/
void ListarEx3(Geral *ex3)
{
    if(ex3)
    {
        ListarEx3(ex3->left);
        printf("%d %d \n", ex3->lenght, ex3->qtdAbs);
        ListarEx3(ex3->right);
    }
}

void RodapeEx3(int abs, float rel)
{
    int i;
    for (i = 0; i < 81; i++)
    {
        printf("%c", '_');
    }

    printf("\n| %s | %10d | %10.f | %20s | %20s |\n", "Total", abs, rel, "", "");
    for (i = 0; i < 81; i++)
    {
        printf("%c", '_');
    }
    printf("\n");
}

void ListarEx3Tree(Geral *ex3, int absAcomulada, float relAcomulada)
{
    if (ex3)
    {
        ListarEx3Tree(ex3->left, absAcomulada, relAcomulada);
        absAcomulada = AbsAcomuladaEx3(ex3, absAcomulada);
        relAcomulada = RelAcomuladaEx3(ex3, relAcomulada);
        printf("| %5d | %7d      |   %f   | %10d         |       %f     |\n", ex3->lenght, ex3->qtdAbs, ex3->qtdRelativa, absAcomulada, relAcomulada);
        ListarEx3Tree(ex3->right, absAcomulada, relAcomulada);
    }
}
/**
 *! Fim Exercicio 3
*/


/**
 *! Exercicio 4
*/
void Ex4Cabecalho(char *nome)
{
    int i;
    printf("\t\t%s\n", nome);
    for (i = 0; i < 65; i++)
    {
        printf("%c", '_');
    }
    printf("\n| %5s | %s | %s | %s |\n", "Nome", "Medida de Certeza ", "Media Aritmetica", "Desvio Padrao");
    for (i = 0; i < 65; i++)
    {
        printf("%c", '_');
    }
    printf("\n");
}
void ListarEx4(Geral *dados)
{
    int i;
    while (dados)
    {
        printf("| %4s  |      %f      |     %f     |    %f   |\n", dados->nome,dados->medidaDeCerteza, dados->media, dados->desvioPadrao);
        dados = (dados->right ? dados->right : NULL);
    }
    for (i = 0; i < 65; i++)
    {
        printf("%c", '_');
    }
    printf("\n");
}

/**
 *! Fim Exercicio 4
*/
/**
 *?----------------------------------------------------Fim-----------------------------------------------------------------------------
*/
/**
 *!                                                END FUNCTION
*/