/*
HM? 
000 
001
010
011
100 
101
110
111
*/
/**
** Author: Yuri Lemos E João Figueiredo
** Description: Este Programa faz leitura de uma fichero ".txt" e com estes dados recolhidos efetua calculos estatisticos
** Data: 14 / 3 / 2020 
* Version: 1.0
*/
#ifndef STRUCTS_H_
#define STRUCTS_H_


/**
 *!                                                 STRUCTS
*/

typedef struct _Actor{
    char *id;
    char *nome;
    char *sexo;
    int numElementos;
    int temMulher;
    struct _Actor *right;
    struct _CoActor *incidencia;
    struct _Actor *left; 
}Actor;

typedef struct _CoActor{
    char *id;
    struct _CoActor *right;
    struct _CoActor *left;
}CoActor;


/**
 *!                                              END OF STRUCTS
*/

#endif