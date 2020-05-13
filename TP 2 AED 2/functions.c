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
#define Texto "actors.txt"

/**
 *!                                                 FUNCTIONS
*/
/**
 *?----------------------------------------------Funçoes de Carregamento--------------------------------------------------------------
*/
/**
 *! Exercicio 1
*/
Actor* LoadFile(Actor* actor)
{
    char *a, *b, *c, *line;
    int i = 0;
    actor = NULL;
    FILE *ficheiro;
    ficheiro = fopen(Texto, "r");
    
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
                       
            actor = InsertTreeNode(actor, a, b, c);
            i++;
        }
    }
    system("cls");
    printf("Total de Registros: %d\n", i);
    fclose(ficheiro);
    return actor;
}


Actor *InsertTreeNode(Actor *actor, char *id, char *nome, char *sexo)
{
    Actor *new = (Actor *)malloc(sizeof(Actor));
    int a, b, c;
    if (actor == NULL)
    {
        return NewNode(id, nome, sexo);
    }
    else
    {
        if(GetIdNumber(id)<GetIdNumber(actor->id)){

            actor->right = InsertTreeNode(actor->right, id, nome, sexo);

        }else if(GetIdNumber(id)>GetIdNumber(actor->id)){

            actor->left = InsertTreeNode(actor->left, id, nome, sexo);
        }
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
    
    new->right = NULL;
    new->left = NULL;
    new->incidencia = NULL;
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

void ShowTree(Actor* actor){
    if(actor){
        ShowTree(actor->left);
        printf("%s %s %s\n",actor->id,actor->nome,actor->sexo);
        ShowTree(actor->right);
    }
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