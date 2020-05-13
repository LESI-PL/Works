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
Actor* LoadFile();

Actor *HeadInsertNode(Actor *actor, char *id, char *nome, char *sexo);
Actor *NewNode(char *id, char *nome, char *sexo);

char *DevolveId(char line[]);
char *DevolveName(char line[]);
char *DevolveGender(char line[]);

void MostraDados(Actor* actors);

int GetHighestId(Actor* actors);
int GetIdNumber(char* idString);
Actor *InsertInTree(Actor *actor, char *id, char *nome, char *sexo);
void ListarActor(Actor *actors);
Actor *FindActor(Actor *actors, char *id);
Actor *InsertInMatrix(Actor *actor, char *id_actor, char *id_coactor);
Actor *LoadMatrix(Actor *actors);
Actor *NewNodeCoatores(Actor *actor,char *id_coator);
Actor *FindActorManual(Actor *actors, char *id);

/*HashTreeActors* CreateHash(Actor* actors);
void ShowHash(HashTreeActors* hash);


HashTreeActors* Add(HashTreeActors* hash,Actor* actors);
HashTreeActors* insertInHash(HashTreeActors* hash,Actor* actors);*/

/**
 *! Fim Exercicio 1
*/

/**
 *! Exercicio 2
*/
/*
Actor *HashHeadInsertNode(Actor *actor, char *id, char *nome, char *sexo);
Actor *HashNewNode(char *id, char *nome, char *sexo);*/
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