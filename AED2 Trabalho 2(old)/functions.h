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
Actor* LoadFileActors(Actor* actor);
Actor* LoadFileCoActors(Actor* actor);

Actor *InsertTreeNode(Actor *actor, char *id, char *nome, char *sexo);
Actor *NewNode(char *id, char *nome, char *sexo);

CoActor *InsertTreeNodeInc(CoActor *coActor, char *id);
CoActor *NewNodeInc(char *id);

char *DevolveId(char line[]);
char *DevolveName(char line[]);
char *DevolveGender(char line[]);

void ShowTree(Actor* actor);
void ShowTreeCo(CoActor* coActor);

int GetHighestId(Actor* actors);
int GetIdNumber(char* idString);


int FindActor(Actor* actors,char* id);

Actor* InsertIncidence(Actor* a,char* rootId, char* incidenceId);


Actor* FindActorManual1(Actor* actors, char *id);

void FreeAll(CoActor* coActor);

void ShowListCo(CoActor* coActor);
/**
 *! Fim Exercicio 1
*/

/**
 *! Exercicio 2
*/

/**
 *! Fim Exercicio 2
*/

/**
 *! Exercicio 3
*/


/**
 *! Fim Exercicio 3
*/

/**
 *! Exercicio 6
*/


/**
 *! Fim Exercicio 6
*/

/**
 *! Exercicio 7
*/

/**
 *! Fim Exercicio 7
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

/**
 *! Fim Exercicio 1
*/

/**
 *! Exercicio 2
*/


/**
 *! Fim Exercicio 2
*/

/**
 *! Exercicio 3
*/


/**
 *! Fim Exercicio 3
*/

/**
 *! Exercicio 6
*/

/**
 *! Fim Exercicio 6
*/

/**
 *!  Exercicio 7
*/


/**
 *! Fim Exercicio 7
*/
/**
 *?----------------------------------------------------Fim-----------------------------------------------------------------------------
*/

/**
 *?----------------------------------------------Verificacoes de dados----------------------------------------------------------------
*/



/**
 *?----------------------------------------------------Fim-----------------------------------------------------------------------------
*/

/**
 *?--------------------------------------------------Calculos--------------------------------------------------------------------------
*/


/**
 *! Exercicio 2
*/


/**
 *! Fim Exercicios 2
 */

/**
 *! Exercicio 3
*/

/**
 *! Fim Exercicios 3
 */

/**
 *! Exercicio 4
*/

/**
 *! Fim Exercicios 4
 */

/**
 *! Exercicio 5
*/


/**
 *! Fim Exercicios 5
 */
/**
 *! Exercicio 6
*/

/**
 *! Fim Exercicios 6
 */

/**
 *! Exercicio 7
*/


/**
 *! Fim Exercicio 7
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

/**
 *! Fim 
*/

/**
 *! Exercicio 1
*/

/**
 *! Fim Exercicio 1
*/

/**
 *! Exercicio 2
*/

/**
 *! Fim Exercicio 2
*/

/**
 *! Exercicio 3
*/

/**
 *! Fim Exercicio 3
*/

/**
 *! Exercicio 4
*/


/**
 *! Fim Exercicio 4
*/

/**
 *! Exercicio 5
*/

/**
 *! Fim Exercicio 5
*/

/**
 *! Exercicio 6
*/


/**
 *! Fim Exercicio 6
*/

/**
 *! Exercicio 7
*/

/**
 *! Fim Exercicio 7
*/
/**
 *?----------------------------------------------------Fim-----------------------------------------------------------------------------
*/

/**
 *!                                                END OF SIGNATURES
*/

#endif