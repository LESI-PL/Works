/*
* Author: Yuri Lemos E João Figueiredo
* Description: Este Programa faz leitura de uma fichero ".txt" e com estes dados recolhidos efetua calculos estatisticos
* Data: 14 / 3 / 2020 
* Version: 1.0
*/
#ifndef STRUCTS_H_
#define STRUCTS_H_

/**
 *!                                                 STRUCTS
*/

typedef struct LineMorph
{
    char *originWord;
    char *wordRoot;
    char *morphAnalise;
    float rightProb;
    struct LineMorph *next;
    struct LineMorph *preview;
}Morph;

/**
 *!                                              END OF STRUCTS
*/

#endif