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
typedef struct LineMorph                /* struc que vai receber os dados do ficheiro */
{
    char originWord[MAX];               /* esta variavel recebe a palavra original*/
    char wordRoot[MAX];                 /* esta variavel recebe a origem da palavra*/
    char morphAnalise[MAX];             /* esta variavel recebe a analise morfologica da palavra*/
    float rightProb;                    /* esta variavel recebe a medida de certeza da palavra*/
    int total;                          /* esta variavel recebe o total de palavras carregadas*/
    struct LineMorph *right;            /* esta variavel recebe o apontador para o proximo nodo do tipo Morph*/
    struct LineMorph *left;             /* esta variavel recebe o apontador para o nodo anterior do tipo Morph*/
}Morph;


typedef struct _Geral                   /* struc auxiliar que vai receber dados resultantes da struct Morph e necessarios para a resolução dos problemas */
{
    char nome[MAX];                     /* esta variavel recebe a analise morfologica da palavra a partir da stuct Morph*/
    float medidaDeCerteza;              /* esta variavel recebe a medida de certeza da palavra a partir da stuct Morph*/
    float media;                        /* esta variavel recebe a media, depende do contexto em que é usada, a partir dos valores da stuct Morph*/
    float desvioPadrao;                 /* esta variavel recebe o desvio padrao, depende do contexto em que é usada, a partir dos valores da stuct Morph*/
    int qtdAbs;                         /* esta variavel recebe a quantidade absoluta, depende do contexto em que é usada, a partir dos valores da stuct Morph*/
    int lenght;                         /* esta variavel recebe o comprimento das palavra a partir da stuct Morph*/
    float *valores;                     /* esta variavel recebe varias medidas de certeza da palavra,que tenha a mesma analise morfologica e guarda as num array,isto a partir da stuct Morph*/
    int total;                          /* esta variavel recebe um total, usado como um contador,depende do contexto em que é usada, a partir dos valores da stuct Morph*/
    float qtdRelativa;                  /* esta variavel recebe a quandidade relativa, depende do contexto em que é usada, a partir dos valores da stuct Morph*/
    struct _Geral *right;               /* esta variavel recebe o apontador para o proximo nodo do tipo Geral*/
    struct _Geral *left;                /* esta variavel recebe o apontador para o nodo anterior do tipo Geral*/

} Geral;

typedef struct _Ex6                     /* struc auxiliar e mais compacta que vai receber dados resultantes da struct Morph e necessarios para a resolução dos problemas */
{
    char nome[MAX];                     /* esta variavel recebe a palavra original a partir da stuct Morph*/
    int qtdAbs;                         /* esta variavel recebe o numero total de vezes que a palavra original apareceu a partir da stuct Morph*/
    int total;                          /* esta variavel recebe a total numero de palavras com o mesma qtdabs*/
    struct _Ex6 *left;                  /* esta variavel recebe o apontador para o nodo anterior do tipo Ex6*/
    struct _Ex6 *right;                 /* esta variavel recebe o apontador para o proximo nodo do tipo Ex6*/
}Ex6;

typedef struct _Ex7                     /* struc auxiliar e mais compacta que vai receber dados resultantes da struct Morph e necessarios para a resolução dos problemas */
{
    float rigthProb;                    /* esta variavel recebe a medida de certeza da palavra a partir da stuct Morph*/
    int qtdAbs;                         /* esta variavel recebe a quantidade de palavras com a mesma medida de certeza*/
    struct _Ex7 *left;                  /* esta variavel recebe o apontador para o nodo anterior do tipo Ex7*/
    struct _Ex7 *right;                 /* esta variavel recebe o apontador para o proximo nodo do tipo Ex7*/
}Ex7;



/**
 *!                                              END OF STRUCTS
*/

#endif