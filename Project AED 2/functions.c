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
    printf("\t\t\t\t\t\tTabela de Frequencias\n");
    for (i = 0; i < 136; i++)
        printf("%c", '_');
    printf("\n|%20s|%20s|%20s|%35s|%35s|\n", "Categoria", "Frequencia Absoluta", "Frequencia Relativa", "Frequencia Absoluta Aculumlada", "Frequencia Relativa Acumulada");
    for (i = 0; i < 136; i++)
        printf("%c", '_');
    printf("\n");
    while (coluna3 != NULL)
    {
        x += coluna3->qtdAbs;
        y += coluna3->qtdrelativa;
        printf("|%20s|%20d|%20.10f|%35d|%35.10f|\n", coluna3->nome, coluna3->qtdAbs, coluna3->qtdrelativa, x, y);
        coluna3 = (coluna3->next ? coluna3->next : NULL);
    }
    for (i = 0; i < 136; i++)
        printf("%c", '_');
    printf("\n|%20s|%20d|%20f|%35s|%35s|\n", "Total", x, y, "", "");
    for (i = 0; i < 136; i++)
        printf("%c", '_');
}

char ShowMenu()
{
    char op;
    system("cls");
    printf("\n|-------------------------------------------------------|");
    printf("\n| 1) Exercicio 1          | 2) Exercicio 2              |");
    printf("\n|-------------------------------------------------------|");
    printf("\n| 3) Exercicio 3          | 4) Exercicio 4              |");
    printf("\n|-------------------------------------------------------|");
    printf("\n| 5) Exercicio 5          | 6) exercicio 6              |");
    printf("\n|-------------------------------------------------------|");
    printf("\n|                        s)Sair                         |");
    printf("\n|-------------------------------------------------------|\n\n");
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
        if (strlen(morph->originWord) == 0)
        {
            i++;
        }
        morph = (morph->next ? morph->next : NULL);
    }
    return i;
}

coluna *Ordenado(coluna *lista, char *string, int qtdAbs, float flo)
{
    coluna *aux = NULL;
    /*coluna *c = (coluna *)malloc(sizeof(coluna));
    c = c3;*/

    printf("LString:%s     LQtdABS:%d\n",lista->nome,lista->qtdAbs);
    printf("String:%s     QtdABS:%d\n",string,qtdAbs);getchar();
    if (lista == NULL)
    {
        printf("\nA");
        lista = (coluna *)malloc(sizeof(coluna)*4);
        strcpy(lista->nome,string);
        lista->qtdAbs = qtdAbs;
        lista->qtdrelativa = flo;
        lista->next = NULL;
    }
    else
    {
        if (lista->qtdAbs <= qtdAbs)
        {
            printf("\nB");
            lista->next = Ordenado(lista->next, string, qtdAbs,flo);
        }
        else
        {
            if (lista->qtdAbs > qtdAbs)
            {
                aux = (coluna *)malloc(sizeof(coluna));
                printf("\nC");
                strcpy(aux->nome,string);
                aux->qtdAbs = qtdAbs;
                aux->qtdrelativa = flo;
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