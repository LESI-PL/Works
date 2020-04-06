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
/**
 *?----------------------------------------------Funçoes de Carregamento--------------------------------------------------------------
*/

/** Morph LoadFile()
 ** Funçao:LoadFile
 *  Funcao de carregamento de um ficheiro ".txt"
 *! Os campos no ficheiro tem que cumprir este formato %s %s %s %f
 *  @return Morph
*/
Morph *LoadFile();

coluna* LoadCol3(Morph *morph);

Coluna1 *LoadCol4(Morph *morph);

TipoLetra *LoadCol5(Morph *morph);
/**
 *?----------------------------------------------------Fim-----------------------------------------------------------------------------
*/





/**
 *?----------------------------------------------Manuseamento de Struct----------------------------------------------------------------
*/


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

coluna* NewNodeCol(char *nome);

coluna* InsertInCol(coluna* coluna,char* nome);

coluna *Ordenado(coluna *lista, char *string, int qtdAbs, float flo);

Coluna1 *NewNodeCol1(char *nome);

Coluna1 *InsertInCol1(Coluna1 *coluna, char *nome);

Coluna1 *Ordenado_Comprimento(Coluna1 *lista, int num, int qtdAbs, float flo);

TipoLetra *NewNodeCol2(char *nome, float valor);

TipoLetra *InsertInCol2(TipoLetra *coluna, char *nome,float valor);

int checkWord(char palavra[]);

void Destroy(Morph *morph);

Coluna1* Ordennar_Lista3(Coluna1 *cl4, Coluna1 *cl3);


/**
 *?----------------------------------------------------Fim-----------------------------------------------------------------------------
*/





/**
 *?--------------------------------------------------Calculos--------------------------------------------------------------------------
*/
/** int contWord(char *string)
 ** Funçao:ContWord
 *  Conta o numero de caracteres que contem numa string
 *  @param char* string
 *  @return int
*/
int contWord(char *string);

int ContaTotalCol3(coluna *col);

void CalcularRelativa(coluna *col, int total);

int Comprimento_zero(Morph *morph);

void CalcularRelativa_Comprimento(Coluna1 *col, int total);

TipoLetra* CalcularMedia(TipoLetra* letras);

TipoLetra* CalcularDp(TipoLetra* letras);

float CalcularMediaComprimento(Coluna1* colunaAux_Ordenada);

/*int CalcularMedianaComprimento(Coluna1 *colunaAux_Ordenada, int abs);*/

int* CalcularModaComprimento(Coluna1 *colunaAux_Ordenada);

float DesvioPadraoComprimento(Coluna1 *colunaAux_Ordenada, int abs, int media);

float Amplitude(float intervalo, int numclasses);

float NumeroClasses(int abs);

float IntervaloDaCerteza(Morph *morph);

int ProcuraModa(Coluna1* colunaAux_Ordenada);

int* ProcuraModas(Coluna1* colunaAux_Ordenada,int moda);

int ContarModas(Coluna1 *colunaAux_Ordenada, int moda);

int ProcurarMediana(int abs);
int CalcularMedianaComprimento(Coluna1 *cl41, int ordem, int abs);


/**
 *?----------------------------------------------------Fim-----------------------------------------------------------------------------
*/




/**
 *?-------------------------------------------------Mostrar Dados----------------------------------------------------------------------
*/

/** void ShowList(Morph *morph)
 ** Funçao:ShowList
 *  Apresenta a lista ligada
 *  @param Morph morph
 *  @return void
*/
char ShowMenu();

void ShowList(Morph *morph);

void ShowListEx2(coluna *coluna3, coluna* colOrdenada);

void ShowList2(coluna *coluna3);

void ShowList_3(Coluna1 *cl4,Coluna1 *coluna3);

void ShowListEx4(TipoLetra *letras);
void ShowListEx42(TipoLetra* letras);

/**
 *?----------------------------------------------------Fim-----------------------------------------------------------------------------
*/

/**
 *!                                                END OF SIGNATURES
*/
#endif