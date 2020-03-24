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
#include "structs.h"
#include "functions.h"
#define MAX 100

/**
 *!                                                 FUNCTION
*/

Morph *LoadFile()
{
    int i;
    char *a, *b, *c;
    float d;
    Morph *temp = NULL;
    FILE *f = NULL;
    f = fopen("frase.txt", "r");

    a = (char *)malloc(MAX * sizeof(char));
    b = (char *)malloc(MAX * sizeof(char));
    c = (char *)malloc(MAX * sizeof(char));

    if (f == NULL)
    {
        printf("Ficheiro nao encontrado\n");
    }
    else
    {
        i = 0;
        fscanf(f, "%s %s %s %f", a, b, c, &d);
        temp = NewNode(a, b, c, d);
        i++;
        while (fscanf(f, "%s %s %s %f", a, b, c, &d) != EOF)
        {
            temp = InsertNode(temp, a, b, c, d);
            i++;
        }
    }
    fclose(f);
    return temp;
}

int contWord(char *string)
{
    int i = 0;
    while (string[i] != '\0')
    {
        i++;
    }
    return i;
}

Morph *NewNode(char *oriWord, char *wordRoot, char *morphAnalise, float rightProb)
{
    Morph *temp = (Morph *)malloc(sizeof(Morph));
    temp->originWord = (char *)malloc((contWord(oriWord) + 1) * sizeof(char));
    temp->wordRoot = (char *)malloc((contWord(wordRoot) + 1) * sizeof(char));
    temp->morphAnalise = (char *)malloc((contWord(morphAnalise) + 1) * sizeof(char));
    strcpy(temp->originWord, oriWord);
    strcpy(temp->wordRoot, wordRoot);
    strcpy(temp->morphAnalise, morphAnalise);
    temp->rightProb = rightProb;
    temp->next = NULL;
    temp->preview = NULL;
    return temp;
}

Morph *InsertNode(Morph *m, char *oriWord, char *wordRoot, char *morphAnalise, float rightProb)
{
    if (m == NULL)
        return NewNode(oriWord, wordRoot, morphAnalise, rightProb);
    if (m->preview == NULL)
    {
        m->next = InsertNode(m->next, oriWord, wordRoot, morphAnalise, rightProb);
    }
    return m;
}

void ShowList(Morph *morph)
{
    while (morph != NULL)
    {
        printf("%s %s %s %f\n", morph->originWord, morph->wordRoot, morph->morphAnalise, morph->rightProb);
        morph = (morph->next ? morph->next : NULL);
    }
}
void ShowList1(coluna *coluna3)
{
    int x = 0;
    int i;
    float y = 0;
    printf("\t\t\t\t\t\tTabela de Frequencias Da Terceira Coluna\n");
    for (i = 0; i < 142; i++)
        printf("%c", '_');
    printf("\n|%20s|%23s|%23s|%35s|%35s|\n", "Categoria", "Frequencia Absoluta", "Frequencia Relativa", "Frequencia Absoluta Acumulada", "Frequencia Relativa Acumulada");
    for (i = 0; i < 142; i++)
        printf("%c", '_');
    printf("\n");
    while (coluna3 != NULL)
    {
        x += coluna3->qtdAbs;
        y += coluna3->qtdrelativa;
        printf("|%20s|%23d|%23.10f|%35d|%35.10f|\n", coluna3->nome, coluna3->qtdAbs, coluna3->qtdrelativa, x, y);
        coluna3 = (coluna3->next ? coluna3->next : NULL);
    }
    for (i = 0; i < 142; i++)
        printf("%c", '_');
    printf("\n|%20s|%23d|%23f|%35s|%35s|\n", "Total", x, y, "", "");
    for (i = 0; i < 142; i++)
        printf("%c", '_');
}

void ShowList2(coluna *coluna3)
{
    int x = 0;
    float y = 0;
    while (coluna3!=NULL)
    {
        x += coluna3->qtdAbs;
        y += coluna3->qtdrelativa;
        printf("|%20s|%20d|%20.10f|%35d|%35.10f|\n", coluna3->nome, coluna3->qtdAbs, coluna3->qtdrelativa, x, y);
        coluna3 = (coluna3->next ? coluna3->next : NULL);
    }
}
void ShowList_3(Coluna1 *coluna3)
{
    int x = 0;
    int i;
    float y = 0;
    printf("\t\t\t\t\t\tTabela de Frequencias Do Comprimento Das Palavras\n");
    for (i = 0; i < 142; i++)
        printf("%c", '_');
    printf("\n|%20s|%23s|%23s|%35s|%35s|\n", "Categoria", "Frequencia Absoluta", "Frequencia Relativa", "Frequencia Absoluta Acumulada", "Frequencia Relativa Acumulada");
    for (i = 0; i < 142; i++)
        printf("%c", '_');
    printf("\n");
    while (coluna3 != NULL)
    {
        x += coluna3->qtdAbs;
        y += coluna3->qtdrelativa;
        printf("|N%c Letras: %d%8c|%23d|%23.10f|%35d|%35.10f|\n",248, coluna3->lenght,' ', coluna3->qtdAbs, coluna3->qtdrelativa, x, y);
        coluna3 = (coluna3->next ? coluna3->next : NULL);
    }
    for (i = 0; i < 142; i++)
        printf("%c", '_');
    printf("\n|%20s|%23d|%23f|%35s|%35s|\n", "Total", x, y, "", "");
    for (i = 0; i < 142; i++){
        printf("%c", '_');
    }
        
    printf("\n");
}


char ShowMenu()
{
    char op;
    system("cls");
    printf("\n|------------------------------------------------------------------------------------|");
    printf("\n| 1) Tabela de Frequencias Da Terceira Coluna          | 2) Exercicio 2              |");
    printf("\n|------------------------------------------------------------------------------------|");
    printf("\n| 3) Exercicio 3  \t\t\t\t\t | 4) Exercicio 4            |");
    printf("\n|------------------------------------------------------------------------------------|");
    printf("\n| 5) Exercicio 5    \t\t\t\t      | 6) exercicio 6               |");
    printf("\n|------------------------------------------------------------------------------------|");
    printf("\n|\t\t\t\t\ts)Sair\t\t\t\t\t     |");
    printf("\n|------------------------------------------------------------------------------------|\n\n");
    op = getch();
    return op;
}

coluna *NewNodeCol(char *nome)
{
    coluna *temp = (coluna *)malloc(sizeof(coluna));
    temp->nome = (char *)malloc((contWord(nome) + 1) * sizeof(char));
    strcpy(temp->nome, nome);
    temp->qtdAbs = 1;
    temp->next = NULL;
    return temp;
}


coluna *InsertInCol(coluna *coluna, char *nome)
{
    if (coluna == NULL)
        return NewNodeCol(nome);
    if (strcmp(coluna->nome, nome) == 0)
    {
        coluna->qtdAbs++;
    }
    else
    {
        coluna->next = InsertInCol(coluna->next, nome);
    }
    return coluna;
}

coluna *LoadCol3(Morph *morph)
{
    coluna *col;

    col = NewNodeCol(morph->morphAnalise);
    morph = (morph->next ? morph->next : NULL);
    while (morph != NULL)
    {
        /*printf("%s\n",morph->morphAnalise);*/
        InsertInCol(col, morph->morphAnalise);
        morph = (morph->next ? morph->next : NULL);
    }

    return col;
}


int ContaTotalCol3(coluna *col)
{
    int i = 0;
    while (col != NULL)
    {
        i += col->qtdAbs;
        col = (col->next ? col->next : NULL);
    }
    return i;
}

void CalcularRelativa(coluna *col, int total)
{
    while (col != NULL)
    {
        col->qtdrelativa = (float)col->qtdAbs / total;
        col = (col->next ? col->next : NULL);
    }
}

int Comprimento_zero(Morph *morph) /* para a segunda tabela*/
{
    int i = 0;
    while (morph != NULL)
    {
        /*printf("%d",strlen(morph->originWord));*/
        if (strlen(morph->originWord) == 0)
        {
            i++;
        }
        morph = (morph->next ? morph->next : NULL);
    }
    getchar();
    return i;
}

coluna *Ordenado(coluna *lista, char *string, int qtdAbs, float flo)
{
    coluna *aux = NULL;
    int b = qtdAbs;
    float c = flo;
    char* a = (char*)malloc((contWord(string) + 1) * sizeof(char));
    strcpy(a,string);
    
    
    if (lista == NULL)
    {
        /*printf("\nA");*/
        lista = (coluna *)malloc(sizeof(coluna));
        lista->nome = (char*)malloc((contWord(a) + 1) * sizeof(char));
        strcpy(lista->nome,a);
        lista->qtdAbs = b;
        lista->qtdrelativa = c;
        lista->next = NULL;
    }
    else
    {
        if (lista->qtdAbs <= b)
        {
            /*printf("\nB");*/
            lista->next = Ordenado(lista->next, a, b,c);
        }
        else
        {
            if (lista->qtdAbs > b)
            {
                aux = (coluna *)malloc(sizeof(coluna));
                aux->nome = (char*)malloc((contWord(a) + 1) * sizeof(char));
                /*printf("\nC");*/
                strcpy(aux->nome,a);
                aux->qtdAbs = b;
                aux->qtdrelativa = c;
                aux->next = lista;
                lista = aux;
            }
        }
    }
    return lista;
}
/**!**************   Daqui para baixo usei as tuas funcoes   nao esta a ordenar  ********************************/
Coluna1 *LoadCol4(Morph *morph)
{
    Coluna1 *col;

    col = NewNodeCol1(morph->originWord);
    morph = (morph->next ? morph->next : NULL);
    while (morph != NULL)
    {
        /*printf("%s\n",morph->morphAnalise);*/
        InsertInCol1(col, morph->originWord);
        morph = (morph->next ? morph->next : NULL);
    }

    return col;
}
Coluna1 *NewNodeCol1(char *nome)
{
    Coluna1 *temp = (Coluna1 *)malloc(sizeof(Coluna1));
    temp->lenght =strlen(nome);
    temp->qtdAbs = 1;
    temp->next = NULL;
    return temp;
}
Coluna1 *InsertInCol1(Coluna1 *coluna, char *nome)
{
    int a=strlen(nome);
    if (coluna == NULL)
        return NewNodeCol1(nome);
    if (a==coluna->lenght)
    {
        coluna->qtdAbs++;
    }
    else
    {
        coluna->next = InsertInCol1(coluna->next, nome);
    }
    return coluna;
}

void CalcularRelativa_Comprimento(Coluna1 *col, int total)
{
    while (col != NULL)
    {
        col->qtdrelativa = (float)col->qtdAbs / total;
        col = (col->next ? col->next : NULL);
    }
}
Coluna1 *Ordenado_Comprimento(Coluna1 *lista, int num, int qtdAbs, float flo)
{
    Coluna1 *aux = NULL;
    int a = num;
    int b = qtdAbs;
    float c = flo;
    
    
    
    if (lista == NULL)
    {
        /*printf("\nA");*/
        lista = (Coluna1 *)malloc(sizeof(Coluna1));
        lista->lenght=a;
        lista->qtdAbs = b;
        lista->qtdrelativa = c;
        lista->next = NULL;
    }
    else
    {
        if (lista->lenght <= a)
        {
            /*printf("\nB");*/
            lista->next = Ordenado_Comprimento(lista->next, a, b,c);
        }
        else
        {
            if (lista->lenght > a)
            {
                aux = (Coluna1 *)malloc(sizeof(Coluna1));
                aux->lenght=a;
                aux->qtdAbs = b;
                aux->qtdrelativa = c;
                aux->next = lista;
                lista = aux;
            }
        }
    }
    return lista;
}
/**
 *!                                                END FUNCTION
*/