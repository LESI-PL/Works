/**
** Author: Yuri Lemos E João Figueiredo
** Description: Este Programa faz leitura de uma fichero ".txt" e com estes dados recolhidos efetua calculos estatisticos
** Data: 14 / 3 / 2020 
* Version: 1.0
*/
#ifndef STRUCTS_H_
#define STRUCTS_H_
#define MAX 100

/**
 *!                                                 STRUCTS
*/
typedef struct LineMorph
{
    char originWord[MAX];
    char wordRoot[MAX];
    char morphAnalise[MAX];
    float rightProb;
    int quantidade;
    int total;
    struct LineMorph *right;
    struct LineMorph *left;
}Morph;


typedef struct _Geral  /* Struct Foi Alterada*/
{
    char *nome;
    float medidaDeCerteza;
    float media;
    float desvioPadrao;
    int qtdAbs;
    int lenght;
    float *valores;
    int total;
    float qtdRelativa;
    struct _Geral *right;
    struct _Geral *left;

} Geral;
/**
 *!                                              END OF STRUCTS
*/

#endif