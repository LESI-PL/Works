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
#define MAX 100
/*#define Texto "frase.txt"*/
#define Texto "slate-tagged.txt"

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
    Morph *lista = NULL;
    FILE *f;
    char a[MAX], b[MAX], c[MAX];
    float d;
    int i = 0;

    f = fopen(Texto, "r");
    if (f == NULL)
    {
        printf("Erro na leitura do ficheiro!");
    }
    else
    {

        while (fscanf(f, "%s %s %s %f", a, b, c, &d) != EOF)
        {
            if (checkWord(a) == 1 && checkWord(b) == 1 && checkWord(c) == 1)
            {
                lista = HeadInsert(lista, a, b, c, d);
                i++;
            }
        }
        fclose(f);
    }
    lista->total = i;
    return lista;
}
/**
 *! Fim Exercicio 1
*/

/**
 *! Exercicio 2
*/
Geral *Ex2Load(Morph *morph)
{
    Morph *aux;
    Geral *dados = NULL,*dadosOrg = NULL;
    for (aux = morph; aux; aux = aux->right)
    {
        dados = Ex2InsertNode(dados, aux);
    }
    for (; dados; dados = dados->right){
        dadosOrg = Ex2InsertOrdenada(dadosOrg,dados);
    }
    dadosOrg = Ex2CalcularFreqRel(dadosOrg,morph->total);
    return dadosOrg;
}

/**
 *! Fim Exercicio 2
*/

/**
 *! Exercicio 3
*/

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
Morph *HeadInsert(Morph *lista, char a[], char b[], char c[], float d)
{
    Morph *new = (Morph *)malloc(sizeof(Morph));
    strcpy(new->originWord, a);
    strcpy(new->wordRoot, b);
    strcpy(new->morphAnalise, c);
    new->rightProb = d;
    new->right = lista;
    if (new->right)
    {
        new->right->left = new;
        new->left = NULL;
    }
    return new;
}
/**
 *! Fim Exercicio 1
*/

/**
 *! Exercicio 2
*/
Geral *Ex2NewNode(Morph *morph) /* Funcao Foi Alterada*/
{
    Geral *temp;
    temp = (Geral *)malloc(sizeof(Geral));
    temp->valores = (float *)malloc(sizeof(float));

    strcpy(temp->nome, morph->morphAnalise);
    temp->qtdAbs = 1;
    temp->qtdRelativa = 0;
    temp->valores[temp->qtdAbs - 1] = morph->rightProb;
    temp->medidaDeCerteza = morph->rightProb;
    temp->right = NULL;
    return temp;
}
Geral *Ex2InsertNode(Geral *dadosEx2, Morph *dados) /* Funcao Foi Alterada*/
{
    if (dadosEx2 == NULL)
    {

        return Ex2NewNode(dados);
    }
    else
    {
        /*printf("DadosEx:%s    Morph:%s\n",dadosEx2->nome,dados->morphAnalise);*/
        if (strcmp(dados->morphAnalise, dadosEx2->nome) == 0)
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
    }
    return dadosEx2;
}
Geral* Ex2InsertOrdenada(Geral* lista, Geral* dados){
    Geral* new = (Geral*)malloc(sizeof(Geral));
    strcpy(new->nome,dados->nome);
    new->qtdAbs = dados->qtdAbs;
    new->qtdRelativa = dados->qtdRelativa;

    if(!lista || new->qtdAbs < lista->qtdAbs){
        new->right = lista;
        lista = new;
    }else{
        Geral* aux = lista;
        while (aux->right && new->qtdAbs > aux->right->qtdAbs){
            aux = aux->right;
        }
        new->right = aux->right;
        aux->right = new;
        
    }
    return lista;
}
/**
 *! Fim Exercicio 2
*/

/**
 *! Exercicio 3
*/

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
int AbsAcomulada(Geral *ex2, int sum)
{
    if (ex2)
    {
        AbsAcomulada(ex2->left, sum);
        sum = ex2->qtdAbs+AbsAcomulada(ex2->right,sum);
        AbsAcomulada(ex2->right, sum);
        
    }
    return sum;
}
int buscarTotalAcumulado(Geral *ex2, int total)
{

    if (ex2 != NULL)
    {
        buscarTotalAcumulado(ex2->left, total);
        return total =  AbsAcomulada(ex2, total);
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
/**
 *! Fim Exercicio 2
*/

/**
 *! Exercicio 3
*/

/**
 *! Fim Exercicio 3
*/

/**
 *! Exercicio 4
*/

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
void ListarE2(Geral *ex2)
{
    Geral* aux;
    int i=0, absAcomulada=0;
    float relacomulada=0;
    for(aux=ex2;aux;aux=aux->right){
        absAcomulada += aux->qtdAbs;
        relacomulada += aux->qtdRelativa;
        printf("%s    %d    %f    %d     %f\n", aux->nome, aux->qtdAbs, aux->qtdRelativa, absAcomulada, relacomulada);
        i += aux->qtdAbs;
    }
    printf("TOTAL: %d\n",i);
}

void ListarEx2Tree(Geral *ex2, int absAcomulada, float relAcomulada)
{
    
    if (ex2)
    {
        ListarEx2Tree(ex2->left, absAcomulada, relAcomulada);
        absAcomulada = ex2->qtdAbs + AbsAcomulada(ex2->left,absAcomulada);
        printf("| %5s | %7d      |   %f   | %10d         |       %f     |\n", ex2->nome, ex2->qtdAbs, ex2->qtdRelativa, absAcomulada, relAcomulada);
        
        ListarEx2Tree(ex2->right, absAcomulada, relAcomulada);
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

/**
 *! Fim Exercicio 2
*/

/**
 *! Exercicio 3
*/

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

/**
 *! Fim Exercicio 4
*/
/**
 *?----------------------------------------------------Fim-----------------------------------------------------------------------------
*/
/**
 *!                                                END FUNCTION
*/