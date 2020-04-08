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
Morph *LoadFile()
{
    int i;
    char a[MAX], b[MAX], c[MAX];
    float d;
    Morph *temp = NULL;
    FILE *f = NULL;
    f = fopen("frase.txt", "r");

    if (f == NULL)
    {
        printf("Ficheiro nao encontrado\n");
    }
    else
    {
        i = 0;
        fscanf(f, "%s %s %s %f", a, b, c, &d);
        if (checkWord(a) == 1 && checkWord(b) == 1 && checkWord(c) == 1)
            temp = NewNode(a, b, c, d);
        i++;
        while (fscanf(f, "%s %s %s %f", a, b, c, &d) != EOF)
        {
            if (checkWord(a) == 1 && checkWord(b) == 1 && checkWord(c) == 1)
            {
                temp = InsertNode(temp, a, b, c, d);
                i++;
            }
        }
    }
    fclose(f);
    return temp;
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

TipoLetra *LoadCol5(Morph *morph)
{
    TipoLetra *col;

    col = NewNodeCol2(morph->morphAnalise, morph->rightProb);
    morph = (morph->next ? morph->next : NULL);
    while (morph != NULL)
    {
        /*printf("%s\n",morph->morphAnalise);*/
        InsertInCol2(col, morph->morphAnalise, morph->rightProb);
        morph = (morph->next ? morph->next : NULL);
    }
    /*col=CalcularMedia(col);*/
    return col;
}
/**
 *?----------------------------------------------------Fim-----------------------------------------------------------------------------
*/

/**
 *?----------------------------------------------Manuseamento de Struct----------------------------------------------------------------
*/

Morph *NewNode(char *oriWord, char *wordRoot, char *morphAnalise, float rightProb)
{
    Morph *temp = (Morph *)malloc(sizeof(Morph));
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

coluna *NewNodeCol(char *nome)
{
    coluna *temp = (coluna *)malloc(sizeof(coluna));
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

coluna *Ordenado(coluna *lista, char *string, int qtdAbs, float flo)
{
    coluna *aux = NULL;
    int b = qtdAbs;
    float c = flo;
    char *a = (char *)malloc((contWord(string) + 1) * sizeof(char));
    strcpy(a, string);

    if (lista == NULL)
    {
        /*printf("\nA");*/
        lista = (coluna *)malloc(sizeof(coluna));
        strcpy(lista->nome, a);
        lista->qtdAbs = b;
        lista->qtdrelativa = c;
        lista->next = NULL;
    }
    else
    {
        if (lista->qtdAbs <= b)
        {
            /*printf("\nB");*/
            lista->next = Ordenado(lista->next, a, b, c);
        }
        else
        {
            if (lista->qtdAbs > b)
            {
                aux = (coluna *)malloc(sizeof(coluna));
                /*printf("\nC");*/
                strcpy(aux->nome, a);
                aux->qtdAbs = b;
                aux->qtdrelativa = c;
                aux->next = lista;
                lista = aux;
            }
        }
    }
    return lista;
}

Coluna1 *NewNodeCol1(char *nome)
{
    Coluna1 *temp = (Coluna1 *)malloc(sizeof(Coluna1));
    temp->lenght = strlen(nome);
    temp->qtdAbs = 1;
    temp->next = NULL;
    return temp;
}
Coluna1 *InsertInCol1(Coluna1 *coluna, char *nome)
{
    int a = strlen(nome);
    if (coluna == NULL)
        return NewNodeCol1(nome);
    if (a == coluna->lenght)
    {
        coluna->qtdAbs++;
    }
    else
    {
        coluna->next = InsertInCol1(coluna->next, nome);
    }
    return coluna;
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
        lista->lenght = a;
        lista->qtdAbs = b;
        lista->qtdrelativa = c;
        lista->next = NULL;
    }
    else
    {
        if (lista->lenght <= a)
        {
            /*printf("\nB");*/
            lista->next = Ordenado_Comprimento(lista->next, a, b, c);
        }
        else
        {
            if (lista->lenght > a)
            {
                aux = (Coluna1 *)malloc(sizeof(Coluna1));
                aux->lenght = a;
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
 * !Funcoes TipoLetra para resolver o exercicio 4
*/
TipoLetra *NewNodeCol2(char *nome, float valor)
{
    TipoLetra *temp = (TipoLetra *)malloc(sizeof(TipoLetra));
    strcpy(temp->nome, nome);
    temp->total = 1;
    temp->valores = (float *)malloc(temp->total * sizeof(float));
    temp->valores[temp->total - 1] = valor;
    return temp;
}

TipoLetra *InsertInCol2(TipoLetra *coluna, char *nome, float valor)
{
    if (coluna == NULL)
        return NewNodeCol2(nome, valor);
    if (strcmp(coluna->nome, nome) == 0)
    {
        coluna->total++;
        coluna->valores = (float *)realloc(coluna->valores, coluna->total * sizeof(float));
        coluna->valores[coluna->total - 1] = valor;
    }
    else
    {
        coluna->next = InsertInCol2(coluna->next, nome, valor);
    }
    return coluna;
}

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

void Destroy(Morph *morph)
{
    if (morph != NULL)
    {
        Destroy(morph->next);
        free(morph->wordRoot);
        free(morph->morphAnalise);
        free(morph->originWord);
        free(morph);
    }
}

Coluna1 *Ordennar_Lista3(Coluna1 *cl4, Coluna1 *coluna3)
{

    while (cl4 != NULL)
    {
        coluna3 = Ordenado_Comprimento(coluna3, cl4->lenght, cl4->qtdAbs, cl4->qtdrelativa);
        cl4 = (cl4->next ? cl4->next : NULL);
    }
    return coluna3;
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

void CalcularRelativa_Comprimento(Coluna1 *col, int total)
{
    while (col != NULL)
    {
        col->qtdrelativa = (float)col->qtdAbs / total;
        col = (col->next ? col->next : NULL);
    }
}

TipoLetra *CalcularMedia(TipoLetra *letras)
{
    TipoLetra *temp = letras;
    int i = 0;
    float media;
    while (letras)
    {
        media = 0;
        for (i = 0; i < letras->total; i++)
        {
            media += letras->valores[i];
        }
        media = media / letras->total;
        letras->media = media;
        letras = (letras->next ? letras->next : NULL);
    }
    return temp;
}

TipoLetra *CalcularDp(TipoLetra *letras)
{
    TipoLetra *temp = letras;
    int i = 0;
    float dp;
    while (letras)
    {
        dp = 0;
        for (i = 0; i < letras->total; i++)
        {
            dp += pow(letras->valores[i] - letras->media, 2);
        }
        dp = dp / letras->total;
        dp = sqrt(dp);
        letras->desvioPadrao = dp;
        letras = (letras->next ? letras->next : NULL);
    }
    return temp;
}
/**
 * done __________________________________________________  fiz daqui para  baixo____________________________
*/
float CalcularMediaComprimento(Coluna1 *colunaAux_Ordenada)
{
    int i = 0, j = 0;
    float media = 0;
    while (colunaAux_Ordenada != NULL)
    {
        i += colunaAux_Ordenada->lenght * colunaAux_Ordenada->qtdAbs;
        j += colunaAux_Ordenada->qtdAbs;
        colunaAux_Ordenada = (colunaAux_Ordenada->next ? colunaAux_Ordenada->next : NULL);
    }
    media = (float)i / j;

    return media;
}

int ProcuraModa(Coluna1 *colunaAux_Ordenada)
{
    int moda;
    moda = colunaAux_Ordenada->qtdAbs;
    while (colunaAux_Ordenada != NULL)
    {
        if (colunaAux_Ordenada->qtdAbs > moda)
        {
            moda = colunaAux_Ordenada->qtdAbs;
        }
        colunaAux_Ordenada = (colunaAux_Ordenada->next ? colunaAux_Ordenada->next : NULL);
    }
    return moda;
}

int *ProcuraModas(Coluna1 *colunaAux_Ordenada, int moda)
{
    int *modas = (int *)malloc(sizeof(int));
    int i = 0, total = 1;

    while (colunaAux_Ordenada != NULL)
    {

        if (colunaAux_Ordenada->qtdAbs == moda)
        {

            total++;
            modas = (int *)realloc(modas, total * sizeof(int));
            modas[i] = colunaAux_Ordenada->lenght;
            i++;
        }

        colunaAux_Ordenada = (colunaAux_Ordenada->next ? colunaAux_Ordenada->next : NULL);
    }
    return modas;
}
int ContarModas(Coluna1 *colunaAux_Ordenada, int moda)
{
    int contamodas = 0;

    while (colunaAux_Ordenada != NULL)
    {

        if (colunaAux_Ordenada->qtdAbs == moda)
        {
            contamodas++;
        }

        colunaAux_Ordenada = (colunaAux_Ordenada->next ? colunaAux_Ordenada->next : NULL);
    }
    return contamodas;
}

int ProcurarMediana(int abs)
{
    int k;
    if (abs % 2 == 0)
    {
        k = abs / 2;
    }
    else
    {
        k = (abs + 1) / 2;
    }
    return k;
}
int CalcularMedianaComprimento(Coluna1 *cl41, int ordem, int abs)
{
    int abs_acumulada = 0;
    int classeXK = 0, classeXK1;
    int aux = 0, aux1 = 0;
    int mediana = 0;
    if (abs % 2 == 0)
    {
        printf("par\n");
        getchar();
        while (cl41 != NULL && abs_acumulada <= ordem)
        {
            abs_acumulada += cl41->qtdAbs;
            aux = cl41->lenght;
            aux1 = cl41->next->lenght;
            if (abs_acumulada >= ordem)
            {
                classeXK = aux;
                if (ordem + 1 <= abs_acumulada)
                {
                    classeXK1 = aux;
                }
                else
                {
                    classeXK1 = aux1;
                }
            }
            cl41 = (cl41->next ? cl41->next : NULL);
        }
        mediana = (classeXK + classeXK1) / 2;
    }
    else
    {
        while (cl41 != NULL && abs_acumulada <= ordem)
        {

            aux = cl41->lenght;
            abs_acumulada += cl41->qtdAbs;
            if (abs_acumulada >= ordem)
            {
                mediana = aux;
                /* break;*/
            }
            cl41 = (cl41->next ? cl41->next : NULL);
        }
    }
    return mediana;
}
/*int CalcularMedianaComprimento(Coluna1 *colunaAux_Ordenada, int abs)
{
    float mediana = 0;
    int k = 0, classeXK = 0, classeXK1 = 0, abs_acumulada = 0;
    Coluna1 *aux1 = colunaAux_Ordenada;
    Coluna1 *aux = NULL;
    aux->lenght = colunaAux_Ordenada->lenght;
    printf("entrei");
    getchar();
    if (colunaAux_Ordenada == NULL)
        printf("fodeu\n");

    while (colunaAux_Ordenada != NULL)
    {
        printf(" letra %d\n", colunaAux_Ordenada->lenght);
        colunaAux_Ordenada = (colunaAux_Ordenada->next ? colunaAux_Ordenada->next : NULL);
    }
    while (aux1 != NULL)
    {
        printf(" letra %d\n", aux1->lenght);
        aux1 = (aux1->next ? aux1->next : NULL);
    }
    /*printf("estou aqui\n");
    getchar();
    printf("abs %d", abs);
    getchar();
    aux->lenght = colunaAux_Ordenada->lenght;
    printf("aux %d", aux->lenght);
    getchar();
    if (abs % 2 == 0)
    {
        k = abs / 2;

        printf("k par %d", k);
        getchar();
        while (colunaAux_Ordenada != NULL)
        {
            abs_acumulada += colunaAux_Ordenada->qtdAbs;
            aux->lenght = colunaAux_Ordenada->lenght;
            if (abs_acumulada >= k)
            {
                classeXK = aux->lenght;
                classeXK1 = aux->next->lenght;
                mediana = (classeXK + classeXK1) / 2;
            }
            colunaAux_Ordenada = (colunaAux_Ordenada->next ? colunaAux_Ordenada->next : NULL);
        }
    }
    else
    {
        k = (abs + 1) / 2;
        printf("k impar %d\n", k);
        getchar();
        while (colunaAux_Ordenada != NULL)
        {
            printf("aqui\n");
            aux->lenght = colunaAux_Ordenada->lenght;
            printf("comprimento %d\n", aux);
            getchar();
            abs_acumulada += colunaAux_Ordenada->qtdAbs;
            printf("abs acumulada %d\n", abs_acumulada);
            if (abs_acumulada >= k)
            {
                mediana = aux->lenght;
            }
            colunaAux_Ordenada = (colunaAux_Ordenada->next ? colunaAux_Ordenada->next : NULL);
        }
    }
    printf("mediana %d\n", mediana);
    printf("estou aqui 2\n");
    getchar();
    return mediana;
}*/

float DesvioPadraoComprimento(Coluna1 *colunaAux_Ordenada, int abs, int media)
{
    float variancia = 0, desvio = 0;

    while (colunaAux_Ordenada != NULL)
    {
        variancia = colunaAux_Ordenada->qtdAbs * pow(colunaAux_Ordenada->lenght - media, 2);
        colunaAux_Ordenada = (colunaAux_Ordenada->next ? colunaAux_Ordenada->next : NULL);
    }
    variancia = variancia / abs;
    desvio = sqrt(variancia);
    return desvio;
}
float IntervaloDaCerteza(Morph *morph)
{
    float xmin = 0;
    float xmax = 0;
    xmin = morph->rightProb;
    xmax = morph->rightProb;
    while (morph != NULL)
    {
        if (morph->rightProb < xmin)
        {
            xmin = morph->rightProb;
        }
        morph = (morph->next ? morph->next : NULL);
    }
    while (morph != NULL)
    {
        if (morph->rightProb > xmax)
        {
            xmax = morph->rightProb;
        }
        morph = (morph->next ? morph->next : NULL);
    }

    return xmax - xmin;
}
float NumeroClasses(int abs)
{
    float constante = 3.3;
    return 1 + (constante * log10(abs));
}

float Amplitude(float intervalo, int numclasses)
{
    float amplitude = 0;
    amplitude = intervalo / numclasses;
    return amplitude;
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

void ShowList(Morph *morph)
{
    if (morph)
    {
        while (morph != NULL)
        {
            printf("%s %s %s %f\n", morph->originWord, morph->wordRoot, morph->morphAnalise, morph->rightProb);
            morph = (morph->next ? morph->next : NULL);
        }
    }
    else
    {
        system("cls");
        printf("Nao existe nada para listar.\n");
        getchar();
    }
}

void ShowListEx2(coluna *coluna3, coluna *colOrdenada)
{
    int x = 0;
    int i;
    float y = 0;
    while (coluna3 != NULL)
    {
        colOrdenada = Ordenado(colOrdenada, coluna3->nome, coluna3->qtdAbs, coluna3->qtdrelativa);
        coluna3 = (coluna3->next ? coluna3->next : NULL);
    }

    printf("\t\t\t\t\t\tTabela de Frequencias Da Terceira Coluna\n");
    for (i = 0; i < 142; i++)
        printf("%c", '_');
    printf("\n|%20s|%23s|%23s|%35s|%35s|\n", "Categoria", "Frequencia Absoluta", "Frequencia Relativa", "Frequencia Absoluta Acumulada", "Frequencia Relativa Acumulada");
    for (i = 0; i < 142; i++)
        printf("%c", '_');
    printf("\n");
    while (colOrdenada != NULL)
    {
        x += colOrdenada->qtdAbs;
        y += colOrdenada->qtdrelativa;
        printf("|%20s|%23d|%23.10f|%35d|%35.10f|\n", colOrdenada->nome, colOrdenada->qtdAbs, colOrdenada->qtdrelativa, x, y);
        colOrdenada = (colOrdenada->next ? colOrdenada->next : NULL);
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
    while (coluna3 != NULL)
    {
        x += coluna3->qtdAbs;
        y += coluna3->qtdrelativa;
        printf("|%20s|%20d|%20.10f|%35d|%35.10f|\n", coluna3->nome, coluna3->qtdAbs, coluna3->qtdrelativa, x, y);
        coluna3 = (coluna3->next ? coluna3->next : NULL);
    }
}
void ShowList_3(Coluna1 *cl4, Coluna1 *coluna3)
{
    int x = 0;
    int i;
    float y = 0;
    while (cl4 != NULL)
    {
        coluna3 = Ordenado_Comprimento(coluna3, cl4->lenght, cl4->qtdAbs, cl4->qtdrelativa);
        cl4 = (cl4->next ? cl4->next : NULL);
    }

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
        printf("|N%c Letras: %d%8c|%23d|%23.10f|%35d|%35.10f|\n", 248, coluna3->lenght, ' ', coluna3->qtdAbs, coluna3->qtdrelativa, x, y);
        coluna3 = (coluna3->next ? coluna3->next : NULL);
    }

    for (i = 0; i < 142; i++)
        printf("%c", '_');
    printf("\n|%20s|%23d|%23f|%35s|%35s|\n", "Total", x, y, "", "");
    for (i = 0; i < 142; i++)
    {
        printf("%c", '_');
    }

    printf("\n");
}

void ShowListEx4(TipoLetra *letras)
{
    printf("| %5s | %6s   | %12s | %5s |\n", "Letra", "Media", "Desvio Padrao", "Total");
    while (letras)
    {

        printf("| %4s  | %f |    %f   | %3d   |\n", letras->nome, letras->media, letras->desvioPadrao, letras->total);
        letras = (letras->next ? letras->next : NULL);
    }
}
void ShowListEx42(TipoLetra *letras)
{
    int i;
    while (letras)
    {
        printf("Letra: %s    ", letras->nome);
        for (i = 0; i < letras->total; i++)
        {
            printf("Valor: %f     ", letras->valores[i]);
        }
        printf("\n");
        letras = (letras->next ? letras->next : NULL);
    }
}
void ListarMedidasComprimento(Morph *morph, int contamodas, int *moda_comprimento, float media_comprimento, int mediana_comprimento, float dp_comprimento)
{
    int i = 0, j = 0;
    char aux[20];
    char aux1[20];
    if (morph)
    {
        printf("\t\t\tMedidas de tendecia central e medida de tendencia nao central\n\n");
        for (i = 0; i < 95; i++)
            printf("%c", '_');
        printf("\n\t\t\t\tMedidas de tendecia central\n");
        for (i = 0; i < 95; i++)
            printf("%c", '_');
        printf("\n|%30s|%20s|%20s|%20s|\n", "Categoria", "Media", "Mediana", "Moda(s)");
        for (i = 0; i < 95; i++)
            printf("%c", '_');
        printf("\n|%30s|%20.2f|%20d|%20d|\n", "Numero de Letras", media_comprimento, mediana_comprimento);
        /*if (contamodas > 1)
        {
            while (j < contamodas)
            {
                itoa(moda_comprimento[j],aux,10);
                strcpy(aux1[j],aux);
                j++;
            }
            itoa(moda_comprimento,aux,10);
            printf("estou aqui\n");
            printf("%s\n",aux1);
        }*/
        for (i = 0; i < 95; i++)
            printf("%c", '_');
        printf("\n\t\t\t\t\nMedidas de tendecia nao central\n\n");
        for (i = 0; i < 95; i++)
            printf("%c", '_');
        printf("\n|%30s|%62s|\n", "Categoria", "Desvio Padrao");
        for (i = 0; i < 95; i++)
            printf("%c", '_');
        printf("\n|%30s|%62.2f|\n", "Numero de Letras", dp_comprimento);
        for (i = 0; i < 95; i++)
            printf("%c", '_');
    }
    else
    {
        system("cls");
        printf("Nao existe nada para listar\n");
        getchar();
    }
}

/**
 * done -------------------------- aproveitei o exemplo do professor------------------------------------------------
*/
/* 
void Histograma(Morph *morph)
{
    int i = 0;

    //em windows use CLS
    system("clear"); //system("cls");

    while (pessoas[i].nome[0])
    {
        printf("%15s:", pessoas[i].nome);

        int n = 1;

        for (n = 1; n <= pessoas[i].idade; n++)
            printf("%c", 6);

        printf("  %2d ", pessoas[i].idade);

        while (n < 50) //para que todas as linhas tenham 50 chars de comprimento
        {
            printf("%c", ' '); //imprime um espaco
            n++;
        }

        printf("\n");
        i++;
    }

    //imprimir footer
    printf("                |....|....|....|....|....|....|....|....|....|....|....|....|\n");
    printf("                0         10        20        30        40        50       60\n\n");
}*/

/**
 *?----------------------------------------------------Fim-----------------------------------------------------------------------------
*/
/**
 *!                                                END FUNCTION
*/