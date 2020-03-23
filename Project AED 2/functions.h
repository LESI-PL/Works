/*
* Author: Yuri Lemos E João Figueiredo
* Description: Este Programa faz leitura de uma fichero ".txt" e com estes dados recolhidos efetua calculos estatisticos
* Data: 14 / 3 / 2020 
* Version: 1.0
*/

#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

#include "structs.h"

/**
 *!                                                 SIGNATURES FUNCTION
*/

/** Morph LoadFile()
 ** Funçao:LoadFile
 *  Funcao de carregamento de um ficheiro ".txt"
 *! Os campos no ficheiro tem que cumprir este formato %s %s %s %f
 *  @return Morph
*/
Morph *LoadFile();

/** int contWord(char *string)
 ** Funçao:ContWord
 *  Conta o numero de caracteres que contem numa string
 *  @param char* string
 *  @return int
*/
int contWord(char *string);

/**  Morph *NewNode(char *oriWord, char *wordRoot, char *morphAnalise, float rightProb)
 *  Funçao:NewNode
 *  Cria um novo node numa determinada lista ligada
 *  @param char string1, @param char string2, @param char string3, @param float num 
 *  @return Morph
*/
Morph* NewNode(char *oriWord, char *wordRoot, char *morphAnalise, float rightProb);

/** Morph *InsertNode(Morph *m,char *oriWord, char *wordRoot, char *morphAnalise, float rightProb)
 ** Funçao:Insert Node
 *  Esta funçao insere um node numa lista ligada, caso não exista nada na lista, é criado então a cabeça de lista
 *  @param Morph morph, @param char string1, @param char string2, @param char string3, @param float num
 *  @return Morph
*/
Morph* InsertNode(Morph *m,char *oriWord, char *wordRoot, char *morphAnalise, float rightProb);

/** void ShowList(Morph *morph)
 ** Funçao:ShowList
 *  Apresenta a lista ligada
 *  @param Morph morph
 *  @return void
*/
void ShowList(Morph *morph);
/**  Syntax Da Funcao
 **  Funçao:Nome da Funcao
 *   Descrição: Aqui
 *   @param parametros da funçao aqui
 *   @return valor de retorno aqui
 */
void ShowList1(coluna *coluna3);

void ShowList_3(Coluna1 *colunaAux);

void ShowList2(coluna *coluna3);
/**  Syntax Da Funcao
 *  Funçao:Nome da Funcao
 **  Descrição: Aqui
 *!  Alertas Aqui
 *   @param parametros da funçao aqui
 *   @return valor de retorno aqui
 */
char ShowMenu();

coluna* NewNodeCol(char *nome);

coluna* InsertInCol(coluna* coluna,char* nome);

coluna* LoadCol3(Morph *morph);

int ContaTotalCol3(coluna* col);

void CalcularRelativa(coluna* col,int total);
int Comprimento_zero(Morph *morph); /* comprimento da palavra*/
coluna *Ordenado(coluna *lista, char *string, int num, float flo);


/*! isto eu fiz com base no teu codigo, nao estou a conseguir ordenar, mas ja apresenta qualquer coisa, ve e depois diz qualquer coisa*/
Coluna1 *InsertInCol1(Coluna1 *coluna, char *nome);
Coluna1 *NewNodeCol1(char *nome);
Coluna1 *LoadCol4(Morph *morph);
void CalcularRelativa_Comprimento(Coluna1 *col, int total);
Coluna1 *Ordenado_Comprimento(Coluna1 *lista, int num, int qtdAbs, float flo);

/**
 *!                                                END OF SIGNATURES
*/
#endif