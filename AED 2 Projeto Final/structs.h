/**
** Author: Yuri Lemos E João Figueiredo
** Description: Este Programa faz leitura de uma fichero ".txt" e com estes dados recolhidos efetua calculos estatisticos
** Data: 14 / 3 / 2020 
* Version: 1.0
*/
#ifndef STRUCTS_H_
#define STRUCTS_H_
#define MAX 200

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


typedef struct _Geral
{
    char *nome;
    int *qtdAbs;
    int *lenght;
    float *valores;
    float *media;
    float *desvioPadrao;
    int *total;
    float *qtdRelativa;
    struct _Geral* next;

}Geral;
/**
 *!                                              END OF STRUCTS
*/

#endif