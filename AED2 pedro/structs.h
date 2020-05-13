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
typedef struct _coatores{

    char *idcoator;
    struct _coatores *coatores_left;
    struct _coatores *coatores_rigth;
    
}Coatores;


typedef struct _Actor{
    char *id;
    char *nome;
    char *sexo;
    int contador;
    Coatores *coatores;
    struct _Actor *left; 
    struct _Actor *rigth;
}Actor;


/*
typedef struct _HashActors{
    int idMin;
    int idMax;
    char key;
    Actor *list;
    struct _HashActors *next;

}HashTreeActors;
*/



/**
 *!                                              END OF STRUCTS
*/

#endif