#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include <math.h>
#define MAX 200

#pragma region Structs
typedef struct LineMorph
{
    char originWord[MAX];
    char wordRoot[MAX];
    char morphAnalise[MAX];
    float rightProb;
    int quantidade;
    int total;
    struct LineMorph *right;
    struct LineMorph *left;
} Morph;
typedef struct _Geral /* Struct Foi Alterada*/
{
    char *nome;
    float medidaDeCerteza;
    float media;
    float desvioPadrao;
    int qtdAbs;
    int lenght;
    float *valores;
    int total;
    float qtdRelativa;
    struct _Geral *right;
    struct _Geral *left;

} Geral;
#pragma endregion
#pragma region Signatures
Morph *CarregarDados();

Morph *HeadInsert(Morph *lista, char *a, char *b, char *c, float d);
int checkWord(char palavra[]);
char *checkLetra(char *palavra);
int contWord(char *string);
void ListarMorph(Morph *tree);

/**
 *! Exercicio 2
*/
Geral *Ex2Load(Morph *morph, Geral *dados);
Geral *Ex2LoadTree(Geral *dados, Geral *dadosOrganizados);

Geral *Ex2NewNode(Morph *morph);
Geral *Ex2InsertNode(Geral *dadosEx2, Morph *dados);
Geral *Ex2InsertNewTree(Geral *dados);
Geral *Ex2OrganizarTree(Geral *dados, Geral *dadosOrganizados);

int AbsAcomulada(Geral *ex2, int sum);
float RelAcomulada(Geral *ex2, float sum);
Geral *Ex2CalcularFreqRel(Geral *dados, int totalDados);

void ListarEx2(Geral *ex2);
void ListarEx2Tree(Geral *ex2, int absAcomulada, float relAcomulada);
/**
 *! Fim Exercicio 2
*/

#pragma endregion

/*Exercicio 4*/
Geral *Ex4CalcularMedia(Geral *dados);
void ListarEx4(Geral *dados);
Geral *Ex4CalcularDp(Geral *dados);
/*Fim*/

int main()
{
    Morph *listaDL = NULL;

    listaDL = CarregarDados();
    printf("Done!\nTotal:%d\n",listaDL->total);
    getchar();

    return 0;
}

#pragma region Functions

Morph *CarregarDados()
{
    Morph *lista = NULL;
    FILE *f;
    char a[200], b[200], c[200];
    float d;
    int i=0;

    f = fopen("slate-tagged.txt", "r");
    if (f == NULL)
    {
        printf("Erro na leitura do ficheiro!");
    }
    else
    {

        while (fscanf(f, "%s %s %s %f", a, b, c, &d) != EOF)
        {
            if (checkWord(a) == 1 && checkWord(b) == 1 && checkWord(c) == 1)
            {
                lista = HeadInsert(lista, a, b, c, d);
                i++;
            }
        }
        fclose(f);
    }
    lista->total = i;
    return lista;
}

Morph *HeadInsert(Morph *lista, char a[], char b[], char c[], float d)
{
    Morph *new = (Morph *)malloc(sizeof(Morph));
    strcpy(new->originWord, a);
    strcpy(new->wordRoot, b);
    strcpy(new->morphAnalise, c);
    new->rightProb = d;
    new->right = lista;
    if(new->right){
        new->right->left=new;
        new->left = NULL;
    }
    return new;
}
int checkWord(char palavra[])
{
    int i;
    for (i = 0; i < contWord(palavra); i++)
    {
        if (!((palavra[i] > 64 && palavra[i] < 91) || (palavra[i] > 96 && palavra[i] < 123)))
        {
            return 0;
        }
    }
    return 1;
}

char *checkLetra(char *palavra)
{
    char *aux, *aux2;
    aux = (char *)malloc(20 * sizeof(char));
    aux2 = (char *)malloc(20 * sizeof(char));
    strcpy(aux, palavra);
    strcpy(aux2, aux);
    aux2 = strupr(aux2);
    if (aux[0] >= 97 && aux[0] <= 122)
    {
        aux[0] = aux2[0];
    }
    return aux;
}
int contWord(char *string)
{
    int i = 0;
    while (string[i] != '\0')
    {
        i++;
    }
    return i;
}
void ListarMorph(Morph *tree)
{
    int i;
    if (tree)
    {
        ListarMorph(tree->left);
        for (i = 0; i < tree->quantidade; i++)
        {
            printf("%s %s %s %f\n", tree->originWord, tree->wordRoot, tree->morphAnalise, tree->rightProb);
        }
        ListarMorph(tree->right);
    }
}

/**
 *! Exercicio 2
*/
Geral *Ex2Load(Morph *morph, Geral *dados)
{
    int i;
    if (morph)
    {
        dados = Ex2Load(morph->left, dados);
        for (i = 0; i < morph->quantidade; i++)
        {
            dados = Ex2InsertNode(dados, morph);
        }

        dados = Ex2Load(morph->right, dados);
    }
    return dados;
}
Geral *Ex2LoadTree(Geral *dados, Geral *dadosOrganizados)
{
    if (dados != NULL)
    {
        dadosOrganizados = Ex2LoadTree(dados->right, dadosOrganizados);

        dadosOrganizados = Ex2OrganizarTree(dados, dadosOrganizados);
    }
    return dadosOrganizados;
}

/**
 * !AQUI
*/
Geral *Ex2NewNode(Morph *morph) /* Funcao Foi Alterada*/
{
    Geral *temp;
    temp = (Geral *)malloc(sizeof(Geral));
    temp->nome = (char *)malloc((contWord(morph->morphAnalise) + 1) * sizeof(char));
    temp->valores = (float *)malloc(sizeof(float));

    strcpy(temp->nome, morph->morphAnalise);
    temp->qtdAbs = 1;
    temp->qtdRelativa = 0;
    temp->valores[temp->qtdAbs - 1] = morph->rightProb;
    temp->medidaDeCerteza = morph->rightProb;
    temp->right = NULL;
    temp->left = NULL;
    return temp;
}
Geral *Ex2InsertNode(Geral *dadosEx2, Morph *dados) /* Funcao Foi Alterada*/
{
    if (dadosEx2 == NULL)
    {
        return Ex2NewNode(dados);
    }
    else if (strcmp(dados->morphAnalise, dadosEx2->nome) == 0)
    {
        dadosEx2->qtdAbs++;
        dadosEx2->valores = (float *)realloc(dadosEx2->valores, dadosEx2->qtdAbs * sizeof(float));
        dadosEx2->valores[dadosEx2->qtdAbs - 1] = dados->rightProb;
        dadosEx2->medidaDeCerteza += dados->rightProb;
    }
    else
    {
        dadosEx2->right = Ex2InsertNode(dadosEx2->right, dados);
    }
    return dadosEx2;
}
Geral *Ex2InsertNewTree(Geral *dados)
{
    Geral *temp = (Geral *)malloc(sizeof(Geral));
    temp->nome = (char *)malloc((contWord(dados->nome) + 1) * sizeof(char));

    strcpy(temp->nome, dados->nome);
    temp->qtdAbs = dados->qtdAbs;
    temp->qtdRelativa = dados->qtdRelativa;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
Geral *Ex2OrganizarTree(Geral *dados, Geral *dadosOrganizados)
{
    if (dadosOrganizados == NULL)
    {
        /*printf("Dados: %s\n",dados->nome);getchar();*/
        return Ex2InsertNewTree(dados);
    }
    else
    {
        if (dados->qtdAbs > dadosOrganizados->qtdAbs)
        { /*Right*/
            /*printf("Right   dados:%s %d  |  dadosOrg: %s  %d",dados->nome,dados->qtdAbs,dadosOrganizados->nome,dadosOrganizados->qtdAbs);getchar();*/
            dadosOrganizados->right = Ex2OrganizarTree(dados, dadosOrganizados->right);
        }
        else if (dados->qtdAbs >= dadosOrganizados->qtdAbs)
        { /*Left*/
            /*printf("Left   dados:%s %d  |  dadosOrg: %s  %d",dados->nome,dados->qtdAbs,dadosOrganizados->nome,dadosOrganizados->qtdAbs);getchar();*/
            dadosOrganizados->left = Ex2OrganizarTree(dados, dadosOrganizados->left);
        }
    }
    return dadosOrganizados;
}

int AbsAcomulada(Geral *ex2, int sum)
{
    if (ex2)
    {
        sum = ex2->qtdAbs + AbsAcomulada(ex2->left, sum);
    }
    return sum;
}
float RelAcomulada(Geral *ex2, float sum)
{
    if (ex2)
    {
        sum = ex2->qtdRelativa + RelAcomulada(ex2->left, sum);
    }
    return sum;
}
Geral *Ex2CalcularFreqRel(Geral *dados, int totalDados)
{
    if (dados == NULL)
    {
        return dados;
    }
    else
    {
        dados->right = Ex2CalcularFreqRel(dados->right, totalDados);
        dados->qtdRelativa = dados->qtdAbs / (float)totalDados;
    }
    return dados;
}

void ListarEx2(Geral *ex2)
{
    while (ex2)
    {
        printf("%s %d %f\n", ex2->nome, ex2->qtdAbs, ex2->medidaDeCerteza);
        ex2 = (ex2->right ? ex2->right : NULL);
    }
}
void ListarEx2Tree(Geral *ex2, int absAcomulada, float relAcomulada)
{
    if (ex2)
    {
        ListarEx2Tree(ex2->left, absAcomulada, relAcomulada);
        absAcomulada = AbsAcomulada(ex2, absAcomulada);
        relAcomulada = RelAcomulada(ex2, relAcomulada);
        printf("| %4s | %7d      |   %f   | %10d         |       %f     |\n", ex2->nome, ex2->qtdAbs, ex2->qtdRelativa, absAcomulada, relAcomulada);
        ListarEx2Tree(ex2->right, absAcomulada, relAcomulada);
    }
}
/**
 *! Fim Exercicio 2
*/
#pragma endregion

/*Exercicio 4*/
Geral *Ex4CalcularMedia(Geral *dados)
{
    if (dados)
    {
        dados->right = Ex4CalcularMedia(dados->right);
        dados->media = dados->medidaDeCerteza / dados->qtdAbs;
    }
    else if (dados == NULL)
    {
        return dados;
    }
    return dados;
}

Geral *Ex4CalcularDp(Geral *dados)
{
    Geral *temp = dados;
    int i = 0;
    float dp;
    while (dados)
    {
        dp = 0;
        for (i = 0; i < dados->qtdAbs; i++)
        {
            dp += pow(dados->valores[i] - dados->media, 2);
        }
        dp = dp / dados->qtdAbs;
        dp = sqrt(dp);
        dados->desvioPadrao = dp;
        dados = (dados->right ? dados->right : NULL);
    }
    return temp;
}
void ListarEx4(Geral *dados)
{
    int i;
    while (dados)
    {
        printf("%s  %f  %f\n", dados->nome, dados->media, dados->desvioPadrao);
        dados = (dados->right ? dados->right : NULL);
    }
}
/*Fim*/