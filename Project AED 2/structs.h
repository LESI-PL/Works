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
/**
 *?  Struct: Morph
 *?  Descrição: Esta estrutura é uma lista ligada e contém as seguintes variaveis-
 *+       originWord   = corresponde a palavra da frase original;
 *+       wordRoot     = corresponde ao seu lema (raiz da palavra);
 *+       morphAnalise = corresponde a sua análise morfossintática;
 *+       rightProb    = corresponde a certeza da ferramenta em relação a análise realizada;
 *+       next         = corresponde a próxima posição;
 *+       preview      = corresponde a posição anterior;
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

typedef struct Column
{
    char *nome;
    int qtdAbs;
    float qtdrelativa;
    struct Column *next;
    struct Column *preview;
}coluna;


/**
 *!                                              END OF STRUCTS
*/

#endif