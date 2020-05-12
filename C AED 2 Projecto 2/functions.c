/*
* Author: Yuri Lemos E João Figueiredo
* Description: Este Programa faz leitura de uma fichero ".txt" e com estes dados recolhidos efetua calculos estatisticos
* Data: 14 / 3 / 2020 
* Version: 1.0
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <math.h>
#include <locale.h>
#include "structs.h"
#include "functions.h"
#define MAX 255
#define Texto "actorsBig.txt"

/**
 *!                                                 FUNCTIONS
*/
/**
 *?----------------------------------------------Funçoes de Carregamento--------------------------------------------------------------
*/
/**
 *! Exercicio 1
*/
Actor* LoadFile()
{
    char *a, *b, *c, *line;
    int i = 0;
    Actor *actor = NULL;
    FILE *ficheiro;
    ficheiro = fopen("actorsBig.txt", "r");
    
    line = (char*)malloc(255*sizeof(char));    
    a = (char *)malloc(sizeof(char)*127);
    b = (char *)malloc(sizeof(char)*127);
    c = (char *)malloc(sizeof(char)*127);
    
    if (ficheiro == NULL)
    {
        printf("Não foi possivel abrir o ficheiro para leitura!\n");
    }
    else
    {
        while (fgets(line, 255, ficheiro) != NULL)
        {            
            a = DevolveId(line);
            c = DevolveGender(line);
            b = DevolveName(line);            
                       
            actor = HeadInsertNode(actor, a, b, c);
            i++;
        }
    }
    system("cls");
    printf("Total de Registros: %d\n", i);
    fclose(ficheiro);
    return actor;
    
}


Actor *HeadInsertNode(Actor *actor, char *id, char *nome, char *sexo)
{
    Actor *new = (Actor *)malloc(sizeof(Actor));
    int a, b, c;
    if (actor == NULL)
    {
        return NewNode(id, nome, sexo);
    }
    else
    {
        a = strlen(id);
        b = strlen(nome);
        c = strlen(sexo);
        new->id = (char *)malloc((a + 1) * (sizeof(char)));
        new->nome = (char *)malloc((b + 1) * (sizeof(char)));
        new->sexo = (char *)malloc((c + 1) * (sizeof(char)));
        strcpy(new->id, id);
        strcpy(new->nome, nome);
        strcpy(new->sexo, sexo);
        
        new->next = actor;
        return new;
    }
}

Actor *NewNode(char *id, char *nome, char *sexo)
{
    Actor *new = (Actor *)malloc(sizeof(Actor));
    int a, b, c;
    a = strlen(id);
    b = strlen(nome);
    c = strlen(sexo);
    new->id = (char *)malloc((a + 1) * (sizeof(char)));
    new->nome = (char *)malloc((b + 1) * (sizeof(char)));
    new->sexo = (char *)malloc((c + 1) * (sizeof(char)));
    strcpy(new->id, id);
    strcpy(new->nome, nome);
    strcpy(new->sexo, sexo);
    
    new->next = NULL;
    return new;
}


char *DevolveId(char line[])
{
    char *aux;
    int i = 0, j = 0;

    while (line[i] != '\0' && line[i] != '\t')
    {
        i++;
    }
    aux = (char *)malloc((i + 1) * sizeof(char));

    for (j = 0; j < i; j++)
    {
        aux[j] = line[j];
    }
    aux[j] = '\0';
    

    return aux;
}

char *DevolveName(char line[])
{
    char *aux, *aux1;

    int i = 0,j = 0;
    int a, b;
    a = strlen(line);
    aux1 = (char *)malloc((a + 1) * sizeof(char));
    strcpy(aux1, line);

    a = a - 2;

    aux1[a] = '\0';

    while (line[i] != '\0' && line[i] != '\t')
    {
        i++;
    }
    i++;

    b = (a - i) + 1;

    aux = (char *)malloc(b * sizeof(char));
    for(i; i < a-1; i++)
    {

        aux[j] = aux1[i];
        j++;
    }
    aux[j] = '\0';
    return aux;
}
char *DevolveGender(char line[])
{

    char *aux = (char *)malloc(2 * sizeof(char));
    int a;
    a = strlen(line);
    
    aux[0] = line[a - 2];
    aux[1] = '\0';

   
    return aux;
}

void MostraDados(Actor* actors){
    while(actors){
        printf("|%s|\t|%s|\t\n",actors->id,actors->nome);
        actors = (actors->next ? actors->next : NULL);
    }
}

int GetIdNumber(char* idString){
    int id,size,i=0,j=0;
    char *aux;
    size = strlen(idString);
    aux = (char*)malloc(sizeof(char)*size);
    
    for(i=2;i<size;i++){
        
        aux[j] = idString[i];
        j++;
    }
    id = atoi(aux);
    
    return id;
}

int GetHighestId(Actor* actors){
    int highest = GetIdNumber(actors->id),value;

    while(actors){
        value = GetIdNumber(actors->id);
        if(value > highest)highest = value;
        actors = (actors->next ? actors->next:NULL);
    }
    return highest;
}

HashTreeActors* CreateHash(Actor* actors){
    HashTreeActors *hash=NULL;
    int intervals,highestId,i,j=0,key=65,divisions=25;
    highestId = GetHighestId(actors);
    /*intervals = (int)(highestId/log10((double)highestId));*/
    intervals = highestId / divisions;
    
    hash = (HashTreeActors*)malloc(sizeof(HashTreeActors)*(divisions+3));
    for(i=0;i<highestId;i+=intervals){
        
        hash[j].idMin = i;
        hash[j].idMax = i+intervals;
        hash[j].key = key; 
        hash[j].list = NULL;    
        key++;
        j++;
    }
    hash[j].key = '\0';
    return hash;
}
HashTreeActors* Add(HashTreeActors* hash,Actor* actors){
    int id = GetIdNumber(actors->id),i=0;
    while(hash[i].key != '\0'){
        if(id > hash[i].idMin && id < hash[i].idMax){
            /*printf("I: %d  id: %d  hash:%c   IDACTOR:%s  NOME:%s  SEXO:%s\n",i,id, hash[i].key,actors->id,actors->nome,actors->sexo);*/
            hash[i].list = HashHeadInsertNode(hash[i].list,actors->id,actors->nome,actors->sexo);
            
            return hash;
        }
        
        i++;
    }
    return hash;
}
HashTreeActors* insertInHash(HashTreeActors* hash,Actor* actors){
    
    while(actors){
        hash = Add(hash,actors);
        actors = (actors->next ? actors->next : NULL);
    }
    
    return hash;
}
void ShowHash(HashTreeActors* hash){
    int i=0;
    while(hash[i].key!='\0'){
        printf("Key: %c   Interval:[%d  ;  %d]\n",hash[i].key,hash[i].idMin,hash[i].idMax);
        i++;
    }
}
/**
 *! Fim Exercicio 1
*/

/**
 *! Exercicio 2
*/
Actor *HashHeadInsertNode(Actor *actor, char *id, char *nome, char *sexo)
{
    if (actor == NULL)
    {
        return HashNewNode(id, nome, sexo);
    }
    else
    {
        actor->next = HashHeadInsertNode(actor->next,id,nome,sexo);
    }
}

Actor *HashNewNode(char *id, char *nome, char *sexo)
{
    Actor *new = (Actor *)malloc(sizeof(Actor));
    int a, b, c;
    a = strlen(id);
    b = strlen(nome);
    c = strlen(sexo);
    new->id = (char *)malloc((a + 1) * (sizeof(char)));
    new->nome = (char *)malloc((b + 1) * (sizeof(char)));
    new->sexo = (char *)malloc((c + 1) * (sizeof(char)));
    strcpy(new->id, id);
    strcpy(new->nome, nome);
    strcpy(new->sexo, sexo);
    
    new->next = NULL;
    return new;
}

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
 *! Exercicio 7
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
 *! Genericas
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
 *! Exercicio 6 Cpmprimento
*/


/**
 *! Fim Exercicio 6 Comprimento
*/

/**
 *! Exercicio 6 - ocorrencia de palavra
*/

/**
 *! Fim Exercicio 6 - ocorrencia de palavra
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
 *! Exercicio 1
*/
char ShowMenu()                         /*Menu principal*/
{
    char op;
    system("cls");
    printf("\n|-----------------------------------------------------------------------------------------------------|");
    printf("\n| 1) Exercicio 2 - Categoria Gramatical Ordenada  | 2) Exercicio 3 - Comprimento das palavras         |");
    printf("\n|-----------------------------------------------------------------------------------------------------|");
    printf("\n| 3) Exercicio 4- Coluna 3 e 4 Media e Desvio     | 4) Exercicio 5 - Comprimento das palavras         |");
    printf("\n|                                                 |    Medidas de Localizacao e Dispersao             |");
    printf("\n|-----------------------------------------------------------------------------------------------------|");
    printf("\n| 5) Exercicio 6 (AED) - Frequencia de palavras   | 6) Exercicio 6 (Est.) - Comprimento das Palavras  |");
    printf("\n|    Mostrar o quartil que a palavra pertence     |    Quartis em relacao ao comprimento              |");
    printf("\n|-----------------------------------------------------------------------------------------------------|");
    printf("\n| 7) Construir histograma das probabilidades      |                                                   |");
    printf("\n|-----------------------------------------------------------------------------------------------------|");
    printf("\n|                                          s)Sair                                                     |");
    printf("\n|-----------------------------------------------------------------------------------------------------|\n\n");
    op = getch();
    return op;
}
/**
 *! Fim Exercicio 1
*/

/**
 * ! Generico
*/

/**
 * ! FIM
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
 *!                                                END FUNCTION
*/