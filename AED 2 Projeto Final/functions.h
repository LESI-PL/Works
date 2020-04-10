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
/**
 *! Exercicio 1
*/
Morph *CarregarDados();
/**
 *! Fim Exercicio 1
*/

/**
 *! Exercicio 2
*/
Geral *Ex2Load(Morph *morph, Geral *dados);
Geral *Ex2LoadTree(Geral *dados, Geral *dadosOrganizados);
/**
 *! Fim Exercicio 2
*/

/**
 *! Exercicio 3
*/
Geral *Ex3Load(Morph *morph, Geral *dados);
Geral *Ex3LoadTree(Geral *dados, Geral *dadosOrganizados);
/**
 *! Fim Exercicio 3
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
Morph *NewNode(Morph *dados);
Morph *InsertNode(Morph *temp, Morph *dados);
/**
 *! Fim Exercicio 1
*/

/**
 *! Exercicio 2
*/
Geral *Ex2NewNode(Morph *morph);
Geral *Ex2InsertNode(Geral *dadosEx2, Morph *dados);
Geral *Ex2InsertNewTree(Geral *dados);
Geral *Ex2OrganizarTree(Geral *dados, Geral *dadosOrganizados);
/**
 *! Fim Exercicio 2
*/

/**
 *! Exercicio 3
*/
Geral *Ex3NewNode(Morph *morph);
Geral *Ex3InsertNode(Geral *dadosEx3, Morph *dados);
Geral *Ex3InsertNewTree(Geral *dados);
Geral *Ex3OrganizarTree(Geral *dados, Geral *dadosOrganizados);
/**
 *! Fim Exercicio 3
*/


/**
 *?----------------------------------------------------Fim-----------------------------------------------------------------------------
*/

/**
 *?----------------------------------------------Verificacoes de dados----------------------------------------------------------------
*/

int checkWord(char palavra[]);
char *checkLetra(char *palavra);

/**
 *?----------------------------------------------------Fim-----------------------------------------------------------------------------
*/

/**
 *?--------------------------------------------------Calculos--------------------------------------------------------------------------
*/
int contWord(char *string);

/**
 *! Exercicio 2
*/
int AbsAcomulada(Geral *ex2, int sum);
float RelAcomulada(Geral *ex2, float sum);
Geral *Ex2CalcularFreqRel(Geral *dados, int totalDados);
int buscarTotalAcumulado(Geral *ex2, int abs);
float buscarTotalRelAcumulada(Geral *ex2, float rel);
/**
 *! Fim Exercicios 2
 */


/**
 *! Exercicio 3
*/
int AbsAcomuladaEx3(Geral *ex2, int sum);
float RelAcomuladaEx3(Geral *ex2, float sum);
Geral *Ex3CalcularFreqRelEx3(Geral *dados, int totalDados);
int buscarTotalAcumuladoEx3(Geral *ex2, int abs);
float buscarTotalRelAcumuladaEx3(Geral *ex2, float rel);
/**
 *! Fim Exercicios 3
 */

/**
 *! Exercicio 4
*/
Geral *Ex4CalcularMedia(Geral *dados);
Geral* Ex4CalcularDp(Geral* dados);
/**
 *! Fim Exercicios 4
 */
/**
 *?----------------------------------------------------Fim-----------------------------------------------------------------------------
*/

/**
 *?-------------------------------------------------Mostrar Dados----------------------------------------------------------------------
*/
/**
 * ! Genericos
*/
void Cabecalho(char *nome);
/**
 *! Fim 
*/

/**
 *! Exercicio 1
*/
char ShowMenu();
void ListarMorph(Morph *tree);
/**
 *! Fim Exercicio 1
*/

/**
 *! Exercicio 2
*/
void ListarEx2(Geral *ex2);
void ListarEx2Tree(Geral *ex2, int absAcomulada, float relAcomulada);
void RodapeEx2(int abs, float rel);
/**
 *! Fim Exercicio 2
*/

/**
 *! Exercicio 3
*/
void ListarEx3(Geral *ex3);
void ListarEx3Tree(Geral *ex3, int absAcomulada, float relAcomulada);
void RodapeEx3(int abs, float rel);
/**
 *! Fim Exercicio 3
*/

/**
 *! Exercicio 4
*/
void ListarEx4(Geral *dados);

/**
 *! Fim Exercicio 4
*/
/**
 *?----------------------------------------------------Fim-----------------------------------------------------------------------------
*/

/**
 *!                                                END OF SIGNATURES
*/

#endif