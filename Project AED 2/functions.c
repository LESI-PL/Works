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
#include "structs.h"
#include "functions.h"
#define MAX 100


/**
 *!                                                 FUNCTION
*/

Morph *LoadFile(){
    int i;
    char *a,*b,*c;
    float d;
    Morph* temp=NULL;
    FILE *f=NULL;
    f=fopen("frase.txt","r");

    a =(char*) malloc(MAX*sizeof(char));
    b =(char*) malloc(MAX*sizeof(char));
    c =(char*) malloc(MAX*sizeof(char));
    
    if(f==NULL){
        printf("Ficheiro nao encontrado");
    }else
    {
        i=0; 
        fscanf (f , "%s %s %s %f",a,b,c,&d);
        temp = NewNode(a,b,c,d);
        i++;
        while (fscanf (f , "%s %s %s %f",a,b,c,&d) != EOF)
        {
            temp = InsertNode(temp,a,b,c,d);
            i++;                       
        }             
    }
    fclose(f); 
    return temp;
}


int contWord(char *string){
    int i=0;
    while(string[i] != '\0'){
        i++;
    }
    return i;
}


Morph* NewNode(char *oriWord, char *wordRoot, char *morphAnalise, float rightProb){
    Morph *temp = (Morph*)malloc(sizeof(Morph));
    temp->originWord = (char *)malloc((contWord(oriWord)+1)*sizeof(char));
    temp->wordRoot = (char *)malloc((contWord(wordRoot)+1)*sizeof(char));
    temp->morphAnalise = (char *)malloc((contWord(morphAnalise)+1)*sizeof(char));
    strcpy(temp->originWord,oriWord);
    strcpy(temp->wordRoot,wordRoot);
    strcpy(temp->morphAnalise,morphAnalise);
    temp->rightProb = rightProb;
    temp->next = NULL;
    temp->preview=NULL;
    return temp;
}


Morph* InsertNode(Morph* m,char *oriWord, char *wordRoot, char *morphAnalise, float rightProb){
    if(m==NULL)return NewNode(oriWord, wordRoot, morphAnalise, rightProb);
    if(m->preview==NULL){
        m->next = InsertNode(m->next,oriWord, wordRoot, morphAnalise, rightProb);
    }
    return m;
}


void ShowList(Morph *morph){
    while(morph != NULL)
	{
		printf("%s %s %s %f\n",morph->originWord, morph->wordRoot, morph->morphAnalise, morph->rightProb);
		morph = (morph->next ? morph->next : NULL) ;
	}
}
/**
 *!                                                END FUNCTION
*/