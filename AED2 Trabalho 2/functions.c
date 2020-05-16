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
#define MAX 64
#define TXTACTOR "actorsBig.txt"
#define TXTCOACTOR "co-actorsBig.txt"

/**
 *!                                                 FUNCTIONS
*/
/**
 *?----------------------------------------------Funçoes de Carregamento--------------------------------------------------------------
*/
/**
 *! Exercicio 1
*/
Actor *LoadFileActors(Actor *actor)
{
    FILE *ficheiro;
    char *a, *b, *c, *line;
    int i = 0;
    actor = NULL;

    ficheiro = fopen(TXTACTOR, "r");

    line = (char *)malloc(MAX * sizeof(char));
    a = (char *)malloc(sizeof(char));
    b = (char *)malloc(sizeof(char));
    c = (char *)malloc(sizeof(char));

    if (ficheiro == NULL)
    {
        printf("Não foi possivel abrir o ficheiro para leitura!\n");
    }
    else
    {
        while (fgets(line, MAX, ficheiro) != NULL)
        {
            a = DevolveId(line);
            c = DevolveGender(line);
            b = DevolveName(line);

            actor = InsertTreeNode(actor, a, b, c);
            i++;
        }
    }
    system("cls");
    printf("Total de Registros: %d\n", i);
    fclose(ficheiro);
    free(a);free(b);free(c);free(line);
    return actor;
}
Actor *LoadFileCoActors(Actor *actor)
{
    FILE *ficheiro;
    char *a, *b;
    

    ficheiro = fopen(TXTCOACTOR, "r");

    a = (char *)malloc(sizeof(char));
    b = (char *)malloc(sizeof(char));

    if (ficheiro == NULL)
    {
        printf("Não foi possivel abrir o ficheiro para leitura!\n");
    }
    else
    {

        while (fscanf(ficheiro, "%s %s", a, b) != EOF)
        {
            
            actor = InsertIncidence(actor, a, b);
            actor = InsertIncidence(actor, b, a);
        }
    }

    fclose(ficheiro);
    return actor;
}

Actor *InsertTreeNode(Actor *actor, char *id, char *nome, char *sexo)
{
    
    if (actor == NULL)
    {
        return NewNode(id, nome, sexo);
    }
    else
    {
        if (GetIdNumber(id) < GetIdNumber(actor->id))
        {

            actor->left = InsertTreeNode(actor->left, id, nome, sexo);
        }
        else if (GetIdNumber(id) > GetIdNumber(actor->id))
        {

            actor->right = InsertTreeNode(actor->right, id, nome, sexo);
        }
    }
    return actor;
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
    new->numElementos = 0;
    new->temMulher = 0;

    new->right = NULL;
    new->left = NULL;
    new->incidencia = NULL;
    return new;
}
void FreeAll(CoActor* coActor){
    if(coActor){
        
        printf("A");
        FreeAll(coActor->right);
        free(coActor);   
    }   
    
}
CoActor *InsertTreeNodeInc(CoActor *coActor, char *id){
    /*HEAD INSERT CODE*/
        CoActor *new = (CoActor *)malloc(sizeof(CoActor));

        new->right = coActor;
        new->id = (char *)malloc(sizeof(char) * strlen(id + 1));
        strcpy(new->id, id);
        return new;
    
    /*if(coActor){
        
        if (GetIdNumber(id) < GetIdNumber(coActor->id))
        {
            coActor->left = InsertTreeNodeInc(coActor->left, id);
        }
        if (GetIdNumber(id) > GetIdNumber(coActor->id))
        {
            coActor->right = InsertTreeNodeInc(coActor->right, id);
        }          
    }else{
        
        return NewNodeInc(id);
         
    }
    return coActor;*/
}

CoActor *NewNodeInc(char *id)
{
    CoActor *new = (CoActor *)malloc(sizeof(CoActor));
    int a;
    a = strlen(id);
    new->id = (char *)malloc((a + 1) * (sizeof(char)));
    strcpy(new->id, id);
    new->right = NULL;
    new->left = NULL;
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

    int i = 0, j = 0;
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
    for (i=i; i < a - 1; i++)
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

int GetIdNumber(char *idString)
{
    int id, size, i = 0, j = 0;
    char *aux;
    size = strlen(idString);
    aux = (char *)malloc(sizeof(char) * size);

    for (i = 2; i < size; i++)
    {

        aux[j] = idString[i];
        j++;
    }
    id = atoi(aux);

    return id;
}
void ShowListCo(CoActor* coActor){
    while(coActor){
        printf("Id:%s\n",coActor->id);
        coActor = (coActor->right ? coActor->right:NULL);
    }
}
void ShowTreeCo(CoActor *coActor)
{
    if (coActor)
    {
        ShowTreeCo(coActor->left);
        printf("\nID:%s", coActor->id);
        ShowTreeCo(coActor->right);
    }
}

void ShowTree(Actor *actor)
{
    if (actor)
    {
        ShowTree(actor->left);
        printf("%s %s %s\n", actor->id, actor->nome, actor->sexo);
        ShowTreeCo(actor->incidencia);
        getchar();
        ShowTree(actor->right);
    }
}
int FindActor(Actor *actors, char *id)
{
    int idSearch = GetIdNumber(id);
    if (actors)
    {
        if (GetIdNumber(actors->id) < idSearch)
        {
            FindActor(actors->right, id);
        }
        else if (GetIdNumber(actors->id) > idSearch)
        {
            FindActor(actors->left, id);
        }
        else
        {
            printf("%s %s %s\nCo-Actors:", actors->id, actors->nome, actors->sexo);
            ShowListCo(actors->incidencia);
            /*ShowTreeCo(actors->incidencia);*/
            getchar();
            return 1;
        }
    }
    else
    {
        printf("Not Found\n");
        return -1;
    }
    return 1;
}
Actor *FindActorManual1(Actor *actors, char *id)
{    
    int key, code_tree;
    if (actors)
    {
        
        key = GetIdNumber(id);
        code_tree = GetIdNumber(actors->id);
        
        if (key < code_tree)
        {
            FindActorManual1(actors->left, id);
        }
        else if (key > code_tree)
        {
            FindActorManual1(actors->right, id);
        }
        else
        {          
            return actors;
        }
    }
    else
    {
        return actors;
    }   

}

Actor *InsertIncidence(Actor *a, char *rootId, char *incidenceId)
{
    
    int rootSearch = GetIdNumber(rootId);
    if (a)
    {
        if (GetIdNumber(a->id) < rootSearch)
        {
            InsertIncidence(a->right, rootId, incidenceId);
        }
        else if (GetIdNumber(a->id) > rootSearch)
        {
            InsertIncidence(a->left, rootId, incidenceId);
        }
        else
        {
            
            a->incidencia = InsertTreeNodeInc(a->incidencia, incidenceId);
        }
    }
    else
    {
        return a;
    }
    return a;
}

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
char ShowMenu() /*Menu principal*/
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