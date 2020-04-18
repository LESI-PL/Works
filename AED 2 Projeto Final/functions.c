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
    Geral *dados = NULL, *dadosOrg = NULL;
    for (aux = morph; aux; aux = aux->right)
    {
        dados = Ex2InsertNode(dados, aux);
    }
    for (; dados; dados = dados->right)
    {
        dadosOrg = Ex2InsertOrdenada(dadosOrg, dados);
    }
    dadosOrg = Ex2CalcularFreqRel(dadosOrg, morph->total);
    return dadosOrg;
}

/**
 *! Fim Exercicio 2
*/

/**
 *! Exercicio 3
*/
Geral *Ex3Load(Morph *morph)
{
    Morph *aux;
    Geral *dadosEx3 = NULL, *dadosEx3Org = NULL;
    for (aux = morph; aux; aux = aux->right)
    {
        dadosEx3 = Ex3InsertNode(dadosEx3, aux);
    }
    for (; dadosEx3; dadosEx3 = dadosEx3->right)
    {
        dadosEx3Org = Ex3InsertOrdenada(dadosEx3Org, dadosEx3);
    }
    dadosEx3Org = Ex3CalcularFreqRel(dadosEx3Org, morph->total);
    return dadosEx3Org;
}

/**
 *! Fim Exercicio 3
*/

/**
 *! Exercicio 6
*/
Ex6 *Ex6Load(Morph *morph)
{
    Morph *aux = morph;
    Ex6 *ex6tree = NULL,*ex6Lista=NULL,*ex6Ordenada=NULL;
    while (aux)
    {
        
        ex6tree = Ex6InsertNode(ex6tree, aux->originWord);
        aux = (aux->right ? aux->right : NULL);
    }
    ex6Lista = Ex6ContarAbs(ex6Lista,ex6tree);
    for (; ex6Lista; ex6Lista = ex6Lista->right){
        ex6Ordenada = Ex6InsertOrdenada(ex6Ordenada,ex6Lista);
    }
    
    ListarE6List(ex6Ordenada);
    getchar();
    return ex6Ordenada;
}

/**
 *! Fim Exercicio 6
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
Geral *Ex2InsertOrdenada(Geral *lista, Geral *dados)
{
    Geral *new = (Geral *)malloc(sizeof(Geral));
    strcpy(new->nome, dados->nome);
    new->qtdAbs = dados->qtdAbs;
    new->qtdRelativa = dados->qtdRelativa;
    new->medidaDeCerteza = dados->medidaDeCerteza;
    new->valores = dados->valores;

    if (!lista || new->qtdAbs < lista->qtdAbs)
    {
        new->right = lista;
        lista = new;
    }
    else
    {
        Geral *aux = lista;
        while (aux->right && new->qtdAbs > aux->right->qtdAbs)
        {
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
Geral *Ex3NewNode(Morph *morph) /* Funcao Foi Alterada*/
{
    Geral *temp;
    temp = (Geral *)malloc(sizeof(Geral));
    temp->lenght = strlen(morph->originWord);
    temp->qtdAbs = 1;
    temp->qtdRelativa = 0;
    temp->right = NULL;
    return temp;
}

Geral *Ex3InsertNode(Geral *dadosEx3, Morph *dados) /* Funcao Foi Alterada*/
{
    int a = 0;
    a = strlen(dados->originWord);
    if (dadosEx3 == NULL)
    {

        return Ex3NewNode(dados);
    }
    else
    {
        if (dadosEx3->lenght == a)
        {
            dadosEx3->qtdAbs++;
        }
        else
        {
            dadosEx3->right = Ex3InsertNode(dadosEx3->right, dados);
        }
    }
    return dadosEx3;
}

Geral *Ex3InsertOrdenada(Geral *dadosEx3Org, Geral *dadosEx3)
{
    Geral *new = (Geral *)malloc(sizeof(Geral));
    new->lenght = dadosEx3->lenght;
    new->qtdAbs = dadosEx3->qtdAbs;
    new->qtdRelativa = dadosEx3->qtdRelativa;
    if (!dadosEx3Org || new->lenght < dadosEx3Org->lenght)
    {
        new->right = dadosEx3Org;
        dadosEx3Org = new;
    }
    else
    {
        Geral *aux = dadosEx3Org;
        while (aux->right && new->lenght > aux->right->lenght)
        {
            aux = aux->right;
        }
        new->right = aux->right;
        aux->right = new;
    }
    return dadosEx3Org;
}

/**
 *! Fim Exercicio 3
*/

/**
 *! Exercicio 6
*/
Ex6 *Ex6NewNode(char *ori)
{
    Ex6 *new = (Ex6 *)malloc(sizeof(Ex6));
    strcpy(new->nome, ori);
    new->qtdAbs = 1;
    new->left = NULL;
    new->right = NULL;
    return new;
}
Ex6 *Ex6InsertNode(Ex6 *bTree, char *ori)
{
    if (bTree == NULL)
    {
        return Ex6NewNode(ori);
    }
    else
    {
        if (strcmp(strupr(bTree->nome), strupr(ori)) == 0)
        {
           
            bTree->qtdAbs++;
        }
        else if (strcmp(strupr(bTree->nome), strupr(ori)) < 0)
        {
            
            bTree->left = Ex6InsertNode(bTree->left, ori);
        }
        else if (strcmp(strupr(bTree->nome), strupr(ori)) > 0)
        {
            
            bTree->right = Ex6InsertNode(bTree->right, ori);
        }
    }
    return bTree;
}


Ex6 *Ex6ListNewNode(Ex6 *dadosTree) 
{
    Ex6 *temp;
    temp = (Ex6*)malloc(sizeof(Ex6));
    temp->qtdAbs = dadosTree->qtdAbs;
    temp->total = 1;
    temp->right = NULL;
    return temp;
}

Ex6 *Ex6ListInsertNode(Ex6 *dadoslist, Ex6 *dadosTree) 
{
    int a = 0;
    if (dadoslist == NULL)
    {

        return Ex6ListNewNode(dadosTree);
    }
    else
    {
        if (dadoslist->qtdAbs == dadosTree->qtdAbs)
        {
            dadoslist->total++;
        }
        else
        {
            dadoslist->right = Ex6ListInsertNode(dadoslist->right, dadosTree);
        }
    }
    return dadoslist;
}
Ex6 *Ex6ContarAbs(Ex6* lista,Ex6* dadosTree){
    if(dadosTree){
        lista = Ex6ContarAbs(lista,dadosTree->left);
        lista = Ex6ListInsertNode(lista,dadosTree);
        lista = Ex6ContarAbs(lista,dadosTree->right);
    }
    return lista;
}

Ex6 *Ex6InsertOrdenada(Ex6 *dadosEx6Org, Ex6 *dadosEx6)
{
    Ex6 *new = (Ex6 *)malloc(sizeof(Ex6));
    new->qtdAbs = dadosEx6->qtdAbs;
    new->total = dadosEx6->total;
    if (!dadosEx6Org || new->qtdAbs < dadosEx6Org->qtdAbs)
    {
        new->right = dadosEx6Org;
        dadosEx6Org = new;
    }
    else
    {
        Ex6 *aux = dadosEx6Org;
        while (aux->right && new->qtdAbs > aux->right->qtdAbs)
        {
            aux = aux->right;
        }
        new->right = aux->right;
        aux->right = new;
    }
    return dadosEx6Org;
}
/**
 *! Fim Exercicio 6
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
    aux = (char *)malloc(100 * sizeof(char));
    aux2 = (char *)malloc(100 * sizeof(char));
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
/**
 *! Fim Exercicio 2
*/

/**
 *! Exercicio 3
*/
Geral *Ex3CalcularFreqRel(Geral *dadosEx3, int totalDados)
{
    if (dadosEx3 == NULL)
    {
        return dadosEx3;
    }
    else
    {
        dadosEx3->right = Ex3CalcularFreqRel(dadosEx3->right, totalDados);
        dadosEx3->qtdRelativa = dadosEx3->qtdAbs / (float)totalDados;
    }
    return dadosEx3;
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

Geral *Ex4CalcularDp(Geral *dados)
{
    Geral *temp = dados;
    int i = 0;
    float dp;
    while (dados)
    {
        dp = 0;
        for (i = 0; i < dados->qtdAbs; i++)
        {
            dp += pow(dados->valores[i] - dados->media, 2);
        }
        dp = dp / dados->qtdAbs;
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
 *! Exercicio 5
*/
void Ex5CalcularMedidas_de_Centrais(Geral *ex3, int total)
{
    Geral *aux = ex3, *aux1 = ex3, *aux2 = ex3, *aux3 = ex3, *aux4 = ex3;
    float media = 0, variancia = 0, desvio = 0;
    int classeXK = 0, classeXK1 = 0;
    int i, k = 0, cpaux = 0, cpaux1 = 0, abs_acumulada = 0;
    int mediana = 0, maior = 0, moda = 0;

    for (; aux; aux = aux->right)
    {
        media += (aux->lenght * aux->qtdAbs);
    }
    media = (media / total);

    if (total % 2 == 0)
    {

        k = (total / 2);
        while (aux1 != NULL && abs_acumulada <= k)
        {
            abs_acumulada += aux1->qtdAbs;
            cpaux = aux1->lenght;
            if (abs_acumulada >= k)
            {
                classeXK = cpaux;
            }
            aux1 = (aux1->right ? aux1->right : NULL);
        }
        abs_acumulada = 0;
        while (aux2 != NULL && abs_acumulada <= k + 1)
        {
            abs_acumulada += aux2->qtdAbs;
            cpaux1 = aux2->lenght;
            if (abs_acumulada >= k)
            {
                classeXK1 = cpaux1;
            }
            aux2 = (aux2->right ? aux2->right : NULL);
        }
        mediana = (classeXK + classeXK1) / 2;
    }
    else
    {
        k = (total + 1) / 2;
        while (aux1 != NULL && abs_acumulada <= k)
        {

            cpaux = aux1->lenght;
            abs_acumulada += aux1->qtdAbs;
            if (abs_acumulada >= k)
            {
                mediana = cpaux;
                /* break;*/
            }
            aux1 = (aux1->right ? aux1->right : NULL);
        }
    }
    maior = aux3->qtdAbs;

    while (aux3 != NULL)
    {
        if (aux3->qtdAbs > maior)
        {
            maior = aux3->qtdAbs;
            moda = aux3->lenght;
        }
        aux3 = (aux3->right ? aux3->right : NULL);
    }

    while (aux4 != NULL)
    {
        variancia += aux4->qtdAbs * pow(aux4->lenght - media, 2);
        aux4 = (aux4->right ? aux4->right : NULL);
    }
    variancia = (variancia / total);
    desvio = sqrt(variancia);
    system("cls");
    printf("\t   MEDIDAS DE LOCALIZACAO DO COMPRIMENTO DAS PALAVRAS\n\n");
    for (i = 0; i < 67; i++)
    {
        printf("%c", '_');
    }
    printf("\n| %29s | %31s |\n", "Medidas de Tendencia Central", "Medida de Tendencia Nao Central");
    printf("%c", '|');
    for (i = 0; i < 65; i++)
    {
        printf("%c", '_');
    }
    printf("%c", '|');
    printf("\n| %10s | %6s | %6s | %31s |\n", "Media", "Mediana", "Moda", "Desvio Padrao");
    printf("| %10s | %7s | %6s | %31s |\n", "", "Me", "Mo", "S");
    printf("%c", '|');
    for (i = 0; i < 65; i++)
    {
        printf("%c", '_');
    }
    printf("%c", '|');
    printf("\n| %10.6f | %5d   | %6d | %31.6f |\n", media, mediana, moda, desvio);
    printf("%c", '|');
    for (i = 0; i < 65; i++)
    {
        printf("%c", '_');
    }
    printf("%c", '|');
    printf("\n");
    fflush(stdin);
    getchar();
}
/**
 *! Fim Exercicio 5
*/

/**
 *! Exercicio 6
*/
float Ex6_Quartil_1_2(Ex6 *ex6, int total)
{

    Ex6 *aux = ex6, *aux1 = ex6;
    int abs_acumulada = 0, xnp = 0, xnp1 = 0, posaux = 0, posaux1 = 0;
    float q1 = 0.25, quartil = 0;
    double fracionaria, inteira, np = 0;
    np = (total * q1);
    fracionaria = modf(np, &inteira);

    if (fracionaria > 0)
    {
        inteira += 1;
        while (aux != NULL && abs_acumulada <= inteira)
        {
            posaux = aux->qtdAbs;
            abs_acumulada += aux->total;
            if (abs_acumulada >= inteira)
            {
                xnp = posaux;
            }
            aux = (aux->right ? aux->right : NULL);
        }
        quartil = xnp;
    }
    else
    {

        while (aux != NULL && abs_acumulada <= inteira)
        {

            posaux = aux->qtdAbs;
            abs_acumulada += aux->total;
            if (abs_acumulada >= inteira)
            {
                xnp = posaux;
            }
            aux = (aux->right ? aux->right : NULL);
        }

        abs_acumulada = 0;
        inteira++;
        while (aux1 != NULL && abs_acumulada < inteira)
        {
            posaux1 = aux1->qtdAbs;
            abs_acumulada += aux1->total;
            if (abs_acumulada >= inteira)
            {
                xnp1 = posaux1;
            }
            aux1 = (aux1->right ? aux1->right : NULL);
        }

        quartil = (float)(xnp + xnp1);
        quartil = (quartil / 2);
    }
    return quartil;
}
float Ex6_Quartil_2_2(Ex6 *ex6, int total)
{

    Ex6 *aux = ex6, *aux1 = ex6;
    int abs_acumulada = 0, xnp = 0, xnp1 = 0, posaux = 0, posaux1 = 0;
    float q1 = 0.50, quartil = 0;
    double fracionaria, inteira, np = 0;
    np = (total * q1);
    fracionaria = modf(np, &inteira);

    if (fracionaria > 0)
    {
        inteira += 1;
        while (aux != NULL && abs_acumulada <= inteira)
        {
            posaux = aux->qtdAbs;
            abs_acumulada += aux->total;
            if (abs_acumulada >= inteira)
            {
                xnp = posaux;
            }
            aux = (aux->right ? aux->right : NULL);
        }
        quartil = xnp;
    }
    else
    {

        while (aux != NULL && abs_acumulada <= inteira)
        {

            posaux = aux->qtdAbs;
            abs_acumulada += aux->total;
            if (abs_acumulada >= inteira)
            {
                xnp = posaux;
            }
            aux = (aux->right ? aux->right : NULL);
        }

        abs_acumulada = 0;
        inteira++;
        while (aux1 != NULL && abs_acumulada < inteira)
        {
            posaux1 = aux1->qtdAbs;
            abs_acumulada += aux1->total;
            if (abs_acumulada >= inteira)
            {
                xnp1 = posaux1;
            }
            aux1 = (aux1->right ? aux1->right : NULL);
        }

        quartil = (float)(xnp + xnp1);
        quartil = (quartil / 2);
    }
    return quartil;
}
float Ex6_Quartil_3_2(Ex6 *ex6, int total)
{

    Ex6 *aux = ex6, *aux1 = ex6;
    int abs_acumulada = 0, xnp = 0, xnp1 = 0, posaux = 0, posaux1 = 0;
    float q1 = 0.75, quartil = 0;
    double fracionaria, inteira, np = 0;
    np = (total * q1);
    fracionaria = modf(np, &inteira);

    if (fracionaria > 0)
    {
        inteira += 1;
        while (aux != NULL && abs_acumulada <= inteira)
        {
            posaux = aux->qtdAbs;
            abs_acumulada += aux->total;
            if (abs_acumulada >= inteira)
            {
                xnp = posaux;
            }
            aux = (aux->right ? aux->right : NULL);
        }
        quartil = xnp;
    }
    else
    {

        while (aux != NULL && abs_acumulada <= inteira)
        {

            posaux = aux->qtdAbs;
            abs_acumulada += aux->total;
            if (abs_acumulada >= inteira)
            {
                xnp = posaux;
            }
            aux = (aux->right ? aux->right : NULL);
        }

        abs_acumulada = 0;
        inteira++;
        while (aux1 != NULL && abs_acumulada < inteira)
        {
            posaux1 = aux1->qtdAbs;
            abs_acumulada += aux1->total;
            if (abs_acumulada >= inteira)
            {
                xnp1 = posaux1;
            }
            aux1 = (aux1->right ? aux1->right : NULL);
        }

        quartil = (float)(xnp + xnp1);
        quartil = (quartil / 2);
    }
    return quartil;
}

/*bool Existe_palvra(Ex)

void Ver_quartil_Palavra(Ex6 *ex6){

}*/
/**
 *! Fim Exercicio 6
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
    Geral *aux;
    int i = 0, absAcomulada = 0;
    float relacomulada = 0;
    system("cls");
    printf("\t\t\t\t\t\tTabela de Frequencias Da Terceira Coluna\n");
    for (i = 0; i < 142; i++)
        printf("%c", '_');
    printf("\n| %20s | %23s | %23s | %30s | %30s |\n", "Categoria", "Frequencia Absoluta", "Frequencia Relativa", "Frequencia Absoluta Acumulada", "Frequencia Relativa Acumulada");
    printf("| %20s | %23s | %23s | %30s | %30s |\n", "Analise Morfologica", "ni", "fi", "Ni ou Cum ni", "Fi ou Cum fi");
    for (i = 0; i < 142; i++)
        printf("%c", '_');
    printf("\n");
    for (aux = ex2; aux; aux = aux->right)
    {
        absAcomulada += aux->qtdAbs;
        relacomulada += aux->qtdRelativa;
        printf("| %20s | %23d | %23.10f | %30d | %30.10f |\n", aux->nome, aux->qtdAbs, aux->qtdRelativa, absAcomulada, relacomulada);
        i += aux->qtdAbs;
    }
    for (i = 0; i < 142; i++)
        printf("%c", '_');
    printf("\n| %20s | %23d | %23.10f | %30s | %30s |\n", "Total", absAcomulada, relacomulada, "", "");
    for (i = 0; i < 142; i++)
        printf("%c", '_');
    printf("\n");
    fflush(stdin);
    getchar();
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
void ListarE3(Geral *ex3)
{
    Geral *aux;
    int i = 0, absAcomulada = 0;
    float relacomulada = 0;
    system("cls");
    printf("\t\t\t\t\t\tTabela de Frequencias Do Comprimento das Palavras\n");
    for (i = 0; i < 142; i++)
        printf("%c", '_');
    printf("\n| %20s | %23s | %23s | %30s | %30s |\n", "Categoria", "Frequencia Absoluta", "Frequencia Relativa", "Frequencia Absoluta Acumulada", "Frequencia Relativa Acumulada");
    printf("| %20s | %23s | %23s | %30s | %30s |\n", "Comprimento", "ni", "fi", "Ni ou Cum ni", "Fi ou Cum fi");
    for (i = 0; i < 142; i++)
        printf("%c", '_');
    printf("\n");
    for (aux = ex3; aux; aux = aux->right)
    {
        absAcomulada += aux->qtdAbs;
        relacomulada += aux->qtdRelativa;
        printf("| %20d | %23d | %23.10f | %30d | %30.10f |\n", aux->lenght, aux->qtdAbs, aux->qtdRelativa, absAcomulada, relacomulada);
        i += aux->qtdAbs;
    }
    for (i = 0; i < 142; i++)
        printf("%c", '_');
    printf("\n| %20s | %23d | %23.4f | %30s | %30s |\n", "Total", absAcomulada, relacomulada, "", "");
    for (i = 0; i < 142; i++)
        printf("%c", '_');
    printf("\n");
    fflush(stdin);
    getchar();
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
    for (i = 0; i < 44; i++)
    {
        printf("%c", '_');
    }
    printf("\n| %5s | %s | %s |\n", "Nome", "Media Aritmetica", "Desvio Padrao");
    for (i = 0; i < 44; i++)
    {
        printf("%c", '_');
    }
    printf("\n");
}
void ListarE4(Geral *dados)
{
    Geral *aux;
    dados = Ex4CalcularMedia(dados);
    dados = Ex4CalcularDp(dados);
    system("cls");
    Ex4Cabecalho("Tabela de Media e Desvio Padrao");
    for (aux = dados; aux; aux = aux->right)
    {
        printf("| %4s  |     %.6f     |    %.6f   |\n", aux->nome, aux->media, aux->desvioPadrao);
    }
    getchar();
}
/**
 *! Fim Exercicio 4
*/

void ListarE6(Ex6 *dados)
{
    if (dados)
    {
        ListarE6(dados->right);
        printf("%s %d\n", dados->nome, dados->qtdAbs);
        ListarE6(dados->left);
    }
}
void ListarE6List(Ex6 *dados){
    while(dados){
        printf("Ocorrencias:%d   Total:%d\n",dados->qtdAbs,dados->total);
        dados = (dados->right ? dados->right:NULL);
    }
}
int pegaTotal(Ex6* ex6){
    int total=0;
    while(ex6){
        total += ex6->total;
        ex6 = (ex6->right ? ex6->right:NULL);
    }
    return total;
}
void ListarE6_2(Ex6 *ex6, int total)
{
    Ex6 *aux = ex6, *aux1 = ex6, *aux2 = ex6;
    int x = 25, y = 50, z = 75;
    float q1 = 0, q2 = 0, q3 = 0;
    total = pegaTotal(ex6);
    printf("A:%d\n",total);getchar();
    q1 = Ex6_Quartil_1_2(aux, total);
    q2 = Ex6_Quartil_2_2(aux1, total);
    q3 = Ex6_Quartil_3_2(aux2, total);
    system("cls");
    printf("\t\t\tQuartis dos Comprmentos das Palavras\n\n\n");
    printf("|                  Q 1                 Q 2                 Q 3                  |\n");
    printf("|-------------------|-------------------|-------------------|-------------------|\n");
    printf("|%20.0f%20.0f%20.0f%20s\n", q1, q2, q3,"|");

    printf("\n\n%d %% das palavras tem %.0f letras de comprimento, e os restantes %d %% tem mais.\n",x,q1,z);
    printf("%d %% das palavras tem %.0f letras de comprimento, e os restantes %d %% tem mais.\n",y,q2,y);
    printf("%d %% das palavras tem %.0f letras de comprimento, e os restantes %d %% tem mais.\n",z,q3,x);
    getchar();
    
}
/**
 *?----------------------------------------------------Fim-----------------------------------------------------------------------------
*/
/**
 *!                                                END FUNCTION
*/