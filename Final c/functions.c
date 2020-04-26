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
Morph *CarregarDados()           /*Funcao responsavel para o carregamento dos dados a partir do ficheiro*/
{
    Morph *lista = NULL;
    FILE *f;
    char a[MAX], b[MAX], c[MAX];
    float d = 0;
    int i = 0;

    f = fopen(Texto, "r");
    if (f == NULL)
    {
        printf("Erro na leitura do ficheiro!\n");
    }
    else
    {

        while (fscanf(f, "%s %s %s %f", a, b, c, &d) != EOF)
        {
            if (checkWord(a) == 1 && checkWord(b) == 1 && checkWord(c) == 1)
            {
                lista = HeadInsert(lista, a, b, c, d);          /*Aqui faz insercao á cabeca, sendo por isso mais rapida*/
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
Geral *Ex2Load(Morph *morph)            /*Funcao que faz o carregamento de dados a partir da lista inicial*/
{
    Morph *aux;
    Geral *dados = NULL, *dadosOrg = NULL;
    for (aux = morph; aux; aux = aux->right)
    {
        dados = Ex2InsertNode(dados, aux);      /*Faz a insercao de nodos numa lista*/
    }
    for (; dados; dados = dados->right)
    {
        dadosOrg = Ex2InsertOrdenada(dadosOrg, dados);   /*Ordena a lista em funcao da quantidade absoluta*/
    }
    dadosOrg = Ex2CalcularFreqRel(dadosOrg, morph->total);   /*Calcula a frequencia relativa */
    return dadosOrg;
}

/**
 *! Fim Exercicio 2
*/

/**
 *! Exercicio 3
*/
Geral *Ex3Load(Morph *morph)                                             /*Funcao que faz o carregamento de dados a partir da lista inicial*/
{
    Morph *aux;
    Geral *dadosEx3 = NULL, *dadosEx3Org = NULL;
    for (aux = morph; aux; aux = aux->right)
    {
        dadosEx3 = Ex3InsertNode(dadosEx3, aux);                        /*Faz a insercao de nodos numa lista*/
    }
    for (; dadosEx3; dadosEx3 = dadosEx3->right)
    {
        dadosEx3Org = Ex3InsertOrdenada(dadosEx3Org, dadosEx3);          /*Ordena a lista em funcao da quantidade absoluta*/
    }
    dadosEx3Org = Ex3CalcularFreqRel(dadosEx3Org, morph->total);        /*Calcula a frequencia relativa */
    return dadosEx3Org;
}

/**
 *! Fim Exercicio 3
*/

/**
 *! Exercicio 6
*/
Ex6 *Ex6Load(Morph *morph)                           /*Funcao que faz o carregamento de dados a partir da lista inicial*/
{
    Morph *aux = morph;
    Ex6 *ex6tree = NULL, *ex6Lista = NULL;
    while (aux)
    {

        ex6tree = Ex6InsertNode(ex6tree, aux->originWord);              /*Faz a insercao de nodos numa arvore*/
        aux = (aux->right ? aux->right : NULL);
    }
    ex6Lista = Ex6TreeToList(ex6Lista, ex6tree);                         /*Passa de uma arvore para uma lista*/

    return ex6Lista;
}

Ex6 *Ex6Load_Ordenada(Ex6 *ex6)                                             /*Funcao que faz o carregamento de dados a partir da lista do Ex6*/
{
    Ex6 *ex6Lista = NULL, *ex6Ordenada = NULL;
    ex6Lista = Ex6ContarAbs(ex6Lista, ex6);                                 /*Agrupa palavras que tenham a mesma qtdAbs*/
    for (; ex6Lista; ex6Lista = ex6Lista->right)
    {
        ex6Ordenada = Ex6InsertOrdenada(ex6Ordenada, ex6Lista);             /*Ordena a lista em funcao da quantidade total*/
    }
    return ex6Ordenada;
}

/**
 *! Fim Exercicio 6
*/

/**
 *! Exercicio 7
*/
Ex7 *Ex7Load(Morph *morph)                                               /*Funcao que faz o carregamento de dados a partir da lista inicial*/
{
    Morph *aux = morph;
    Ex7 *ex7tree = NULL, *ex7Lista = NULL, *ex7ListaOrdenada = NULL;
    while (aux)
    {
        ex7tree = Ex7InsertNode(ex7tree, aux->rightProb);                   /*Faz a insercao de nodos numa lista*/
        aux = (aux->right ? aux->right : NULL);
    }

    ex7Lista = Ex7TreeToList(ex7Lista, ex7tree);                            /*Passa de uma arvore para uma lista*/
    
    for (; ex7Lista; ex7Lista = ex7Lista->right)
    {
        ex7ListaOrdenada = Ex7InsertOrdenada(ex7ListaOrdenada, ex7Lista);           /*Ordena a lista em funcao da quantidade absoluta*/
    }

    return ex7ListaOrdenada;
}

/**
 *! Fim Exercicio 7
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
Morph *HeadInsert(Morph *lista, char a[], char b[], char c[], float d)          /*Funcao que faz a insercao a cabecas dos dados lidos a partir do ficheiro*/
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

void destroy_ListaDL(Morph *DLlista)                           /*Funcao que destroi a lista incial do carregamento do ficheiro*/
{
    Morph *aux;
    for (; DLlista; DLlista = aux)
    {
        aux = DLlista->right;
        free(DLlista);
    }
}

/**
 *! Fim Exercicio 1
*/

/**
 *! Exercicio 2
*/
Geral *Ex2NewNode(Morph *morph)                             /*Funcao que cria um nodo do tipo Geral, so com os campos essenciais ao utilizador*/
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
Geral *Ex2InsertNode(Geral *dadosEx2, Morph *dados)                 /* Funcao que insere um nodo do tipo Geral numa lista*/
{
    if (dadosEx2 == NULL)
    {

        return Ex2NewNode(dados);           /*Funcao que cria um nodo do tipo Geral, so com os campos essenciais ao utilizador*/
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
        dadosEx2->right = Ex2InsertNode(dadosEx2->right, dados);        /* Funcao que insere um nodo do tipo Geral numa lista*/
    }
    return dadosEx2;
}
Geral *Ex2InsertOrdenada(Geral *lista, Geral *dados)                /*Funcao que ordena a lista em funcao da quantidade absoluta*/
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
Geral *Ex3NewNode(Morph *morph)                 /* Funcao que cria um nodo do tipo Geral, so com os campos essenciasi ao utilizador*/
{
    Geral *temp;
    temp = (Geral *)malloc(sizeof(Geral));
    temp->lenght = strlen(morph->originWord);
    temp->qtdAbs = 1;
    temp->qtdRelativa = 0;
    temp->right = NULL;
    return temp;
}

Geral *Ex3InsertNode(Geral *dadosEx3, Morph *dados)                 /* Funcaoque insere um nodo na lista */
{
    int a = 0;
    a = strlen(dados->originWord);
    if (dadosEx3 == NULL)
    {

        return Ex3NewNode(dados);                       /* Funcao que cria um nodo do tipo Geral, so com os campos essenciasi ao utilizador*/
    }
    else
    {
        if (dadosEx3->lenght == a)
        {
            dadosEx3->qtdAbs++;
        }
        else
        {
            dadosEx3->right = Ex3InsertNode(dadosEx3->right, dados);             /* Funcaoque insere um nodo na lista */
        }
    }
    return dadosEx3;
}

Geral *Ex3InsertOrdenada(Geral *dadosEx3Org, Geral *dadosEx3)           /* Funcaoque que ordena a lista em funcao do comprimento */
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
Ex6 *Ex6NewNode(char *ori)                   /* Funcao que cria um nodo do tipo Ex6*/
{
    Ex6 *new = (Ex6 *)malloc(sizeof(Ex6));
    strcpy(new->nome, ori);
    new->qtdAbs = 1;
    new->left = NULL;
    new->right = NULL;
    return new;
}
Ex6 *Ex6InsertNode(Ex6 *bTree, char *ori)            /* Funcao que insere um nodo numa arvore*/
{
    if (bTree == NULL)
    {
        return Ex6NewNode(ori);                     /* Funcao que cria um nodo do tipo Ex6*/
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

            bTree->right = Ex6InsertNode(bTree->right, ori);         /* Funcao que insere um nodo numa arvore*/
        }
    }
    return bTree;
}

Ex6 *Ex6ListNewNode(Ex6 *dadosTree)                 /* Funcao que cria um nodo para uma lista*/
{
    Ex6 *temp;
    temp = (Ex6 *)malloc(sizeof(Ex6));
    strcpy(temp->nome, dadosTree->nome);
    temp->qtdAbs = dadosTree->qtdAbs;
    temp->total = 1;
    temp->right = NULL;
    return temp;
}

Ex6 *Ex6ListInsertNode(Ex6 *dadoslist, Ex6 *dadosTree)          /* Funcao que insere um nodo para uma lista*/
{
    if (dadoslist == NULL)
    {

        return Ex6ListNewNode(dadosTree);               /* Funcao que cria um nodo para uma lista*/
    }
    else
    {
        if (dadoslist->qtdAbs == dadosTree->qtdAbs)
        {
            dadoslist->total++;
        }
        else
        {
            dadoslist->right = Ex6ListInsertNode(dadoslist->right, dadosTree);          /* Funcao que insere um nodo para uma lista*/
        }
    }
    return dadoslist;
}
Ex6 *Ex6ContarAbs(Ex6 *lista, Ex6 *dados)               /* Funcao que conta a quantidade absoluta lista*/
{
    while (dados)
    {
        lista = insertPorAbs(lista, dados);                 /* Funcao que ordena a lista pela quantidade absoluta */

        dados = (dados->right ? dados->right : NULL);
    }
    return lista;
}
Ex6 *insertNewPorAbs(Ex6 *dados)                    /*Funcao que cria um nodo do tipo Ex6 */
{
    Ex6 *temp = (Ex6 *)malloc(sizeof(Ex6));
    temp->qtdAbs = dados->qtdAbs;
    temp->total = 1;
    temp->right = NULL;
    return temp;
}
Ex6 *insertPorAbs(Ex6 *lista, Ex6 *dados)                   /*Funcao que insere um nodo ordenado  na lista */
{
    if (lista == NULL)
    {
        return insertNewPorAbs(dados);                  /*Funcao que cria um nodo do tipo Ex6 */
    }
    else
    {
        if (lista->qtdAbs == dados->qtdAbs)
        {
            lista->total++;
        }
        else
        {
            lista->right = insertPorAbs(lista->right, dados);           /*Funcao que insere um nodo ordenado  na lista */
        }
    }
    return lista;
}

Ex6 *Ex6InsertOrdenada(Ex6 *dadosEx6Org, Ex6 *dadosEx6)                 /* Funcao que ordena a lista pela quantidade absoluta */
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
Ex6 *Ex6HeadInsert(Ex6 *lista, Ex6 *tree)     /*Funcao que faz insercao a cabeca numa lista a partir de uma arvore*/
{
    Ex6 *new = (Ex6 *)malloc(sizeof(Ex6));
    strcpy(new->nome, tree->nome);
    new->qtdAbs = tree->qtdAbs;
    new->right = lista;
    if (new->right)
    {
        new->right->left = new;
        new->left = NULL;
    }
    return new;
}
Ex6 *Ex6TreeToList(Ex6 *lista, Ex6 *tree)           /*Funcao que passa uma arvore para uma lista*/
{
    if (tree)
    {
        lista = Ex6TreeToList(lista, tree->left);           /*Funcao que passa uma arvore para uma lista*/
        lista = Ex6HeadInsert(lista, tree);                 /*Funcao que faz insercao a cabeca numa lista a partir de uma arvore*/
        lista = Ex6TreeToList(lista, tree->right);          /*Funcao que passa uma arvore para uma lista*/
    }
    return lista;
}
/**
 *! Fim Exercicio 6
*/

/**
 *! Exercicio 7
*/
Ex7 *Ex7NewNode(float prob)                                 /*Funcao que cria um nodo do tipo Ex7*/
{
    Ex7 *new = (Ex7 *)malloc(sizeof(Ex7));
    new->rigthProb = prob;
    new->qtdAbs = 1;
    new->left = NULL;
    new->right = NULL;
    return new;
}
Ex7 *Ex7InsertNode(Ex7 *tree, float prob)                /*Funcao que insere um nodo numa arvore*/
{
    if (tree == NULL)
    {
        return Ex7NewNode(prob);                         /*Funcao que cria um nodo do tipo Ex7*/
    }
    else
    {
        if (tree->rigthProb == prob)
        {
            tree->qtdAbs++;
        }
        else
        {
            if (tree->rigthProb < prob)
            {
                tree->right = Ex7InsertNode(tree->right, prob);     /*Funcao que insere um nodo numa arvore*/
            }
            else if (tree->rigthProb > prob)
            {
                tree->left = Ex7InsertNode(tree->left, prob);           /*Funcao que insere um nodo numa arvore*/
            }
        }
    }
    return tree;
}

Ex7 *Ex7HeadInsert(Ex7 *lista, Ex7 *tree)                                   /*Funcao que faz insercao a cabeca numa lista a partir de uma arvore*/
{
    Ex7 *new = (Ex7 *)malloc(sizeof(Ex7));
    new->rigthProb = tree->rigthProb;
    new->qtdAbs = tree->qtdAbs;
    new->right = lista;
    if (new->right)
    {
        new->right->left = new;
        new->left = NULL;
    }
    return new;
}

Ex7 *Ex7TreeToList(Ex7 *dadoslist, Ex7 *dadosTree)                          /*Funcao que passa uma arvore para uma lista*/
{
    if (dadosTree)
    {
        dadoslist = Ex7TreeToList(dadoslist, dadosTree->left);              /*Funcao que passa uma arvore para uma lista*/
        dadoslist = Ex7HeadInsert(dadoslist, dadosTree);                    /*Funcao que faz insercao a cabeca numa lista a partir de uma arvore*/
        dadoslist = Ex7TreeToList(dadoslist, dadosTree->right);             /*Funcao que passa uma arvore para uma lista*/
    }
    return dadoslist;
}

Ex7 *Ex7InsertOrdenada(Ex7 *dadosEx7Org, Ex7 *dadosEx7)                     /*Funcao que insere um nodo numa lista de forma ordenada*/
{
    Ex7 *new = (Ex7 *)malloc(sizeof(Ex7));
    new->qtdAbs = dadosEx7->qtdAbs;
    new->rigthProb = dadosEx7->rigthProb;
    if (!dadosEx7Org || new->rigthProb < dadosEx7Org->rigthProb)
    {
        new->right = dadosEx7Org;
        dadosEx7Org = new;
    }
    else
    {
        Ex7 *aux = dadosEx7Org;
        while (aux->right && new->rigthProb > aux->right->rigthProb)
        {
            aux = aux->right;
        }
        new->right = aux->right;
        aux->right = new;
    }
    return dadosEx7Org;
}
/**
 *! Fim Exercicio 7
*/
/**
 *?----------------------------------------------------Fim-----------------------------------------------------------------------------
*/

/**
 *?----------------------------------------------Verificacoes de dados----------------------------------------------------------------
*/
int checkWord(char palavra[])           /*Funcao que seleciona se as palvras apresentam certas caracteristicas*/
{
    int i;
    for (i = 0; i < contWord(palavra); i++)         /*Funcao que conta as letras das palvras para alocar memoria dinamicamente*/
    {
        if (!((palavra[i] > 64 && palavra[i] < 91) || (palavra[i] > 96 && palavra[i] < 123)))
        {
            return 0;
        }
    }
    return 1;
}

char *checkLetra(char *palavra)             /*Funcao que converte a primeira letra em maiusculas, para depois poder usar em comparaçoes*/
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
int contWord(char *string)                   /*Funcao que conta as letras das palvras para alocar memoria dinamicamente*/
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
Geral *Ex2CalcularFreqRel(Geral *dados, int totalDados)         /*Funcao que calcula  a frequencia relativa para o exercicio 2*/
{
    if (dados == NULL)
    {
        return dados;
    }
    else
    {
        dados->right = Ex2CalcularFreqRel(dados->right, totalDados);            /*Funcao que calcula  a frequencia relativa para o exercicio 2*/
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
Geral *Ex3CalcularFreqRel(Geral *dadosEx3, int totalDados)                  /*Funcao que calcula  a frequencia relativa para o exercicio 3*/
{
    if (dadosEx3 == NULL)
    {
        return dadosEx3;
    }
    else
    {
        dadosEx3->right = Ex3CalcularFreqRel(dadosEx3->right, totalDados);          /*Funcao que calcula  a frequencia relativa para o exercicio 3*/
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
Geral *Ex4CalcularMedia(Geral *dados)                               /*Funcao que calcula  a frequencia relativa para o exercicio 4*/
{
    if (dados)
    {
        dados->right = Ex4CalcularMedia(dados->right);              /*Funcao que calcula  a frequencia relativa para o exercicio 4*/
        dados->media = dados->medidaDeCerteza / dados->qtdAbs;
    }
    else if (dados == NULL)
    {
        return dados;
    }
    return dados;
}

Geral *Ex4CalcularDp(Geral *dados)                              /*Funcao que calcula  o desvio padrao para o exercicio 4*/
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

float Media_comprimento(Geral *ex3, int total)              /*Funcao que calcula a media do comprimento para o exercicio 5*/
{
    Geral *aux = ex3;
    float media = 0;
    for (; aux; aux = aux->right)
    {
        media += (aux->lenght * aux->qtdAbs);
    }
    media = (media / total);
    return media;
}
int Mediana_Comprimento(Geral *ex3, int total)                /*Funcao que calcula a mediana do comprimento para o exercicio 5*/
{
    Geral *aux1 = ex3, *aux2 = ex3;
    int classeXK = 0, classeXK1 = 0;
    int k = 0, cpaux = 0, cpaux1 = 0, abs_acumulada = 0;
    int mediana = 0;
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
    return mediana;
}
int Moda_comprimento(Geral *ex3)                    /*Funcao que calcula a moda do comprimento para o exercicio 5*/
{

    Geral *aux3 = ex3;
    int maior = 0, moda = 0;
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
    return moda;
}

float Desvio_padrao_comprimento(Geral *ex3, int total, float media)                 /*Funcao que calcula o desvio padrao para comprimento para o exercicio 5*/
{
    Geral *aux4 = ex3;
    float variancia = 0, desvio = 0;
    while (aux4 != NULL)
    {
        variancia += aux4->qtdAbs * pow(aux4->lenght - media, 2);
        aux4 = (aux4->right ? aux4->right : NULL);
    }
    variancia = (variancia / total);
    desvio = sqrt(variancia);
    return desvio;
}

/**
 *! Exercicio 6 Cpmprimento
*/

float Ex6_Quartil_1(Geral *ex3, int total)                      /*Funcao que calcula o primeiro quartil para o exercicio 6*/
{

    Geral *aux = ex3, *aux1 = ex3;
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
            posaux = aux->lenght;
            abs_acumulada += aux->qtdAbs;
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

            posaux = aux->lenght;
            abs_acumulada += aux->qtdAbs;
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
            posaux1 = aux1->lenght;
            abs_acumulada += aux1->qtdAbs;
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

float Ex6_Quartil_2(Geral *ex3, int total)                      /*Funcao que calcula o segundo quartil para o exercicio 6*/
{

    Geral *aux = ex3, *aux1 = ex3;
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
            posaux = aux->lenght;
            abs_acumulada += aux->qtdAbs;
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

            posaux = aux->lenght;
            abs_acumulada += aux->qtdAbs;
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
            posaux1 = aux1->lenght;
            abs_acumulada += aux1->qtdAbs;
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

float Ex6_Quartil_3(Geral *ex3, int total)                      /*Funcao que calcula o terceiro quartil para o exercicio 6*/
{

    Geral *aux = ex3, *aux1 = ex3;
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
            posaux = aux->lenght;
            abs_acumulada += aux->qtdAbs;
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

            posaux = aux->lenght;
            abs_acumulada += aux->qtdAbs;
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
            posaux1 = aux1->lenght;
            abs_acumulada += aux1->qtdAbs;
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
/**
 *! Fim Exercicio 6 Comprimento
*/

/**
 *! Exercicio 6 - ocorrencia de palavra
*/
float Ex6_Quartil_1_2(Ex6 *ex6, int total)                      /*Funcao que calcula o primeiro quartil para o exercicio 6- Ocorrencias*/
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
float Ex6_Quartil_2_2(Ex6 *ex6, int total)                       /*Funcao que calcula o segundo quartil para o exercicio 6- Ocorrencias*/
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
float Ex6_Quartil_3_2(Ex6 *ex6, int total)                           /*Funcao que calcula o terceiro quartil para o exercicio 6- Ocorrencias*/
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

int Existe_Palavra(Ex6 *ex6, char *palavra)                      /*Funcao que verifica se uma palavra existe ou nao, exercicio 6- Ocorrencias*/
{
    Ex6 *aux = ex6;
    while (aux != NULL && strcmp(aux->nome, palavra) != 0)
    {
        aux = (aux->right ? aux->right : NULL);
    }
    if (aux == NULL)
    {
        return 0;
    }
    return 1;
}
int pegaTotal(Ex6 *ex6)                      /*Funcao que calcula total de ocorrencias exercicio 6- Ocorrencias*/
{
    int total = 0;
    while (ex6)
    {
        total += ex6->total;
        ex6 = (ex6->right ? ex6->right : NULL);
    }
    return total;
}
int Ex6_Total_Ocorrencias(Ex6 *ex6, int numero)    /*Funcao que indica o total de ocorrencias de uma palavra 6- Ocorrencias*/
{
    Ex6 *aux = ex6;
    while (aux != NULL)
    {
        if (aux->qtdAbs == numero)
        {
            return aux->total;
        }
        aux = (aux->right ? aux->right : NULL);
    }
    return -1;
}
int Ex6_Numero_Ocorrencias(Ex6 *ex6, char *palavra)                /*Funcao que indica o numero de ocorrencias que uma palavra tem, 6- Ocorrencias*/
{
    Ex6 *aux = ex6;
    while (aux != NULL)
    {
        if (strcmp(aux->nome, palavra) == 0)
        {
            return aux->qtdAbs;
        }
        aux = (aux->right ? aux->right : NULL);
    }
    return -1;
}

/**
 *! Fim Exercicio 6 - ocorrencia de palavra
*/

/**
 *! Exercicio 7
*/

float Max_IntervaloDaCerteza(Ex7 *ex7)    /*Funcao que calcula o valor maximo da certeza da palavra - Exerccio 7*/
{
    Ex7 *aux = ex7;
    float xmax = 0;
    xmax = aux->rigthProb;
    for (; aux; aux = aux->right)
    {
        if (aux->rigthProb > xmax)
        {
            xmax = aux->rigthProb;
        }
    }
    return xmax;
}
float Min_IntervaloDaCerteza(Ex7 *ex7)              /*Funcao que calcula o valor minimo da certeza da palavra - Exerccio 7*/
{
    Ex7 *aux = ex7;
    float xmin = 0;
    xmin = aux->rigthProb;
    for (; aux; aux = aux->right)
    {
        if (aux->rigthProb < xmin)
        {
            xmin = aux->rigthProb;
        }
    }
    return xmin;
}
float NumeroClasses(int total)              /*Funcao que calcula o numero de classes para o Exercico 7*/
{
    float classes = 0;
    classes = (1 + (3.3 * log10(total)));
    return classes;
}
int Total(Ex7 *ex7)                 /*Funcao que calcula o numero total de amostras para o Exercico 7*/
{
    int total = 0;
    while (ex7)
    {
        total += ex7->qtdAbs;
        ex7 = (ex7->right ? ex7->right : NULL);
    }
    return total;
}
float Amplitude(float max, float min, int numclasses)         /*Funcao que calcula a amplitude de das classes para o Exercico 7*/
{
    float amplitude = 0, intervalo = 0;
    intervalo = (max - min);
    amplitude = intervalo / numclasses;
    return amplitude;
}

int Conta_valoresE(Ex7 *dados)                  /*Funcao que calcula os diferentes tipos de certezas de palavras - Exercico 7*/
{
    Ex7 *aux = dados, *aux1 = dados;
    int i = 0;
    for (; aux; aux = aux->right)
    {
        for (; aux1; aux1 = aux1->right)
        {
            if (aux1->rigthProb != aux->rigthProb)
            {
                i++;
            }
        }
    }
    return i;
}
float *ArrayClasses(Ex7 *ex7, int total, float amplitude, int numclasses, float min, float max)
{
        /*Funcao que passa para um array os intervalos de das classes - Exercicio 7*/
    Ex7 *aux = ex7;
    int valores[50];
    int i = 0, somavalores = 0;
    float *classes, soma = 0;
    classes = (float *)malloc(numclasses * sizeof(float));
    classes[0] = min + amplitude;
    classes[1] = classes[0] + amplitude;

    for (i = 2; i < numclasses; i++)
    {
        if (i == (numclasses - 1))
        {
            classes[i] = max;
        }
        else
        {
            classes[i] = classes[i - 1] + amplitude;
        }
    }
    return classes;
}

float *ArrayValores(Ex7 *ex7, int total, float amplitude, int numclasses, float min, float max)
{   
    /*Funcao que passa para um array a frequencia relativa de cada intervalo de classe - Exercicio 7*/
    Ex7 *aux = ex7;
    int valores[50];
    int i = 0, somavalores = 0;
    float *fqReal, classes[50], soma = 0;
    fqReal = (float *)malloc(numclasses * sizeof(float));
    classes[0] = min + amplitude;
    classes[1] = classes[0] + amplitude;

    for (i = 2; i < numclasses; i++)
    {
        if (i == (numclasses - 1))
        {
            classes[i] = max;
        }
        else
        {
            classes[i] = classes[i - 1] + amplitude;
        }
    }

    i = 0;
    for (; aux; aux = aux->right)
    {
        if (aux->rigthProb <= classes[i])
        {
            soma += aux->qtdAbs;
            valores[i] = soma;
        }
        else
        {
            i++;
            soma = 0;
            soma = aux->qtdAbs;
        }
    }

    for (i = 0; i < numclasses; i++)
    {

        somavalores += valores[i];
    }
    for (i = 0; i < numclasses; i++)
    {

        fqReal[i] = ((float)valores[i] / total);
    }

    return fqReal;
}

float ValorMaximoArray(float *valoresArray, int classes)        /*Funcao que calcula o maximo valor da frequencia relativa - Exercicio 7*/
{
    int i;
    float max = valoresArray[0];
    for (i = 0; i < classes; i++)
    {
        if (valoresArray[i] > max)
        {
            max = valoresArray[i];
        }
    }
    return max;
}
/**
 *! Fim Exercicio 7
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
char ShowMenu()                         /*Menu principal*/
{
    char op;
    system("cls");
    printf("\n|-----------------------------------------------------------------------------------------------------|");
    printf("\n| 1) Exercicio 2 - Categoria Gramatical Ordenada  | 2) Exercicio 3 - Comprimento das palavras         |");
    printf("\n|-----------------------------------------------------------------------------------------------------|");
    printf("\n| 3) Exercicio 4- Coluna 3 e 4 Media e Desvio     | 4) Exercicio 5 - Comprimento das palavras         |");
    printf("\n|                                                 |    Medidas de Localizacao e Dispersao             |");
    printf("\n|-----------------------------------------------------------------------------------------------------|");
    printf("\n| 5) Exercicio 6 (AED) - Frequencia de palavras   | 6) Exercicio 6 (Est.) - Comprimento das Palavras  |");
    printf("\n|    Mostrar o quartil que a palavra pertence     |    Quartis em relacao ao comprimento              |");
    printf("\n|-----------------------------------------------------------------------------------------------------|");
    printf("\n| 7) Construir histograma das probabilidades      |                                                   |");
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
void Cabecalho(char *nome)     /*Cabecalho generico*/
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
void ListarE2(Geral *ex2)           /*Procedimento para listar o Exercicio 2*/
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
void RodapeEx2(int abs, float rel)              /*Rodape Generico*/
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
void ListarE3(Geral *ex3)                       /*Procedimento para listar o Exercicio 2*/
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
void Ex4Cabecalho(char *nome)               /*Cabecalho Generico*/
{
    int i;
    printf("\t%s\n", nome);
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
void ListarE4(Geral *dados)                     /*Procedimento para listar o Exercicio 4*/
{
    Geral *aux;
    int i;
    dados = Ex4CalcularMedia(dados);
    dados = Ex4CalcularDp(dados);
    system("cls");
    Ex4Cabecalho("Tabela de Media e Desvio Padrao");
    for (aux = dados; aux; aux = aux->right)
    {
        printf("| %4s  |     %.6f     |    %.6f   |\n", aux->nome, aux->media, aux->desvioPadrao);
    }
     for (i = 0; i < 44; i++)
    {
        printf("%c", '_');
    }
    printf("\n");
    getchar();
}
/**
 *! Fim Exercicio 4
*/

/**
 *! Exercicio 5
*/
void ListarE5(Geral *ex3, int total)                        /*Procedimento para listar o Exercicio 5*/
{
    Geral *aux = ex3, *aux1 = ex3, *aux2 = ex3, *aux3 = ex3;
    float media = 0, desvio = 0;
    int i, mediana = 0, moda = 0;

    media = Media_comprimento(aux, total);

    moda = Moda_comprimento(aux1);

    mediana = Mediana_Comprimento(aux2, total);

    desvio = Desvio_padrao_comprimento(aux3, total, media);

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
void ListarE6_1(Geral *ex3, int total)                  /*Procedimento para listar o Exercicio 6-Comprimento*/
{
    Geral *aux = ex3, *aux1 = ex3, *aux2 = ex3;
    int x = 25, y = 50, z = 75;
    float q1 = 0, q2 = 0, q3 = 0;
    q1 = Ex6_Quartil_1(aux, total);
    q2 = Ex6_Quartil_2(aux1, total);
    q3 = Ex6_Quartil_3(aux2, total);
    system("cls");
    printf("\t\t\tQuartis dos Comprmentos das Palavras\n\n\n");
    printf("|                  Q 1                 Q 2                 Q 3                  |\n");
    printf("|-------------------|-------------------|-------------------|-------------------|\n");
    printf("|%20.0f%20.0f%20.0f%20s\n", q1, q2, q3, "|");

    printf("\n\n%d %% das palavras tem %.0f letras de comprimento, e os restantes %d %% tem mais do que %.0f letras.\n", x, q1, z, q1);
    printf("%d %% das palavras tem %.0f letras de comprimento, e os restantes %d %% tem mais do que %.0f letras.\n", y, q2, y, q2);
    printf("%d %% das palavras tem %.0f letras de comprimento, e os restantes %d %% tem mais do que %.0f letras.\n", z, q3, x, q3);
    fflush(stdin);
    getchar();
}

void Ex6_Palavra_Inserida(Ex6 *ex6, Ex6 *ordenada)          /*Procedimento para listar o Exercicio 6-Ocorrencias*/
{
    Ex6 *aux2 = ex6, *aux3 = ex6, *aux4 = ex6;
    Ex6 *ord1 = ordenada, *ord2 = ordenada, *ord3 = ordenada, *aux = ordenada, *aux1 = ordenada;
    char palavra[MAX], palavra2[MAX];
    int ocorrencias = 0, numero_total = 0, total = 0, q1 = 0, q2 = 0, q3 = 0;

    total = pegaTotal(aux);

    do
    {
        system("cls");
        printf("Por favor digite a sua Palavra.\n");
        scanf("%s", palavra);

        strcpy(palavra2, strupr(palavra));

        if (Existe_Palavra(aux2, palavra2) == 0)
        {
            printf("Palavra nao Existe\n");
            fflush(stdin);
            getchar();
        }
    } while (Existe_Palavra(aux3, palavra2) == 0);

    ocorrencias = Ex6_Numero_Ocorrencias(aux4, palavra2);

    numero_total = Ex6_Total_Ocorrencias(aux1, ocorrencias);

    q1 = Ex6_Quartil_1_2(ord1, total);
    q2 = Ex6_Quartil_2_2(ord2, total);
    q3 = Ex6_Quartil_3_2(ord3, total);

    printf("\n|                  Q 1                 Q 2                 Q 3                  |\n");
    printf("|-------------------|-------------------|-------------------|-------------------|\n");
    printf("|%20.0d%20.0d%20.0d%20s\n", q1, q2, q3, "|");

    if (ocorrencias <= q1)
    {
        printf("\nA palavra pertence ao Primeiro quartil!\nOcorre %d vezes e o numero de palavras com a mesma ocorrencia e %d.\n", ocorrencias, numero_total);
    }
    else if (ocorrencias > q1 && ocorrencias <= q2)
    {
        printf("\nA palavra pertence ao Segundo quartil!\nOcorre %d vezes e o numero de palavras com a mesma ocorrencia e %d.\n", ocorrencias, numero_total);
    }
    else if (ocorrencias > q1 && ocorrencias > q2 && ocorrencias <= q3)
    {
        printf("\nA palavra pertence ao Terceiro quartil!\nOcorre %d vezes e o numero de palavras com a mesma ocorrencia e %d.\n", ocorrencias, numero_total);
    }
    else
    {
        printf("\nA palavra pertence ao Quarto quartil!\nOcorre %d vezes e o numero de palavras com a mesma ocorrencia e %d.\n", ocorrencias, numero_total);
    }
    fflush(stdin);
    getchar();
}

void ListarE6List(Ex6 *dados)                   /*Procedimento para listar o Exercicio 6*/
{
    while (dados)
    {
        printf("  Ocorrencias:%d   Total:%d\n", dados->qtdAbs, dados->total);
        dados = (dados->right ? dados->right : NULL);
    }
}
/**
 *! Fim Exercicio 6
*/

/**
 *! Exercicio 7
*/
void ListarE7List(Ex7 *dados)
{
    int i = 0;
    while (dados)
    {
        i++;
        printf(" lista prob %f Total:%d\n", dados->rigthProb, dados->qtdAbs);

        dados = (dados->right ? dados->right : NULL);
    }
    printf("total valores da lista %d", i);
}

void ListarE7tree(Ex7 *dados)               /*Procedimento para listar o Exercicio 7*-arvore*/
{
    if (dados)
    {
        ListarE7tree(dados->left);
        printf("prob %f Total:%d\n", dados->rigthProb, dados->qtdAbs);
        ListarE7tree(dados->right);
    }
}



void Histograma2(Ex7 *ex7)     /*Procedimento para listar o Exercicio 7*/
{
    Ex7 *aux = ex7, *aux1 = ex7, *aux2 = ex7, *aux3 = ex7, *aux4 = ex7, *aux5 = ex7;
    float *valoresArray, *classesArray;
    float min = 0, max = 0, amplitude = 0, maxArray = 0, escala = 0.025;
    int minimografico = 0;
    int classes = 0, total = 0, valores = 0, j, i, p = 0;
    char percentagem[] = "PERCENTAGEM";
    total = Total(aux2);
    min = Min_IntervaloDaCerteza(aux);
    max = Max_IntervaloDaCerteza(aux1);
    classes = NumeroClasses(total);

    amplitude = Amplitude(max, min, classes);
    classesArray = ArrayClasses(aux5, total, amplitude, classes, min, max);
    valores = Conta_valoresE(aux3);
    valoresArray = ArrayValores(aux4, total, amplitude, classes, min, max);
    maxArray = ValorMaximoArray(valoresArray, classes);
    system("cls");
    for (i = 80; i >= minimografico; i--)
    {
        if (i < 19 && i > 7)
        {
            printf("%c %5d|", percentagem[p], i);
            p++;
        }
        else
        {
            printf("  %5d|", i);
        }
        for (j = 0; j < classes; j++)
        {
            (valoresArray[j] * 100) >= ((float)i) ? printf("%c%c%c%c%c%c ", 178, 178, 178, 178, 178, 178) : printf("       ");
        }

        printf("\n");
    }
    printf("       |-----------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("        [%.2f;", min);
    for (i = 0; i < classes - 1; i++)
    {
        printf(" [%.2f;", classesArray[i]);
    }
    printf("\n");
    printf("         %.2f] ", classesArray[0]);
    for (i = 1; i < classes; i++)
    {
        printf(" %.2f] ", classesArray[i]);
    }
    printf("\n");
    getchar();
}

/**
 *! Fim Exercicio 7
*/
/**
 *?----------------------------------------------------Fim-----------------------------------------------------------------------------
*/
/**
 *!                                                END FUNCTION
*/