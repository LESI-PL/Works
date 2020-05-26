#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <math.h>
#include <locale.h>

#define MAX 64
#define TXTACTOR "actorsBig.txt"
#define TXTCOACTOR "co-actorsBig.txt"

#define DEBUG 0
//typedef struct  Actor3;

typedef struct _CoActor2
{
    char id[16];
    int contagem;
    struct _CoActor2 *seguinte;
    struct _Actor3 *actorProprio;
} CoActor2;

typedef struct _Actor2
{
    char id[16];
    char nome[128];
    char genero[2];
    int numElementos;
    int soTemMulher;
    struct _Actor2 *seguinte;
    struct _CoActor2 *incidencia;
} Actor2;

typedef struct _Actor3
{
    char id[16];
    char nome[128];
    char genero[2];
    int numAtuacoes;
    int numCoActoresDiferentes;
    int soTemMulher;
    struct _Actor3 *seguinte, *anterior;
    struct _CoActor2 *incidencia;
} Actor3;

Actor3 *LoadFileActors(Actor3 *actor);
Actor2 *InsereListaActor(Actor2 *aux, char *nome, char *genero, char *id);
Actor2 *FindActorList(Actor2 *actor, char *id);
void ShowListActor(Actor2 *actor);

void *LoadFileCoActors(Actor3 *actor);
CoActor2 *InsereListaCoActor(CoActor2 *aux, char *id);
void ShowListCo_Actor(Actor2 *actor);
void MaisPessoas(Actor2 *actor);
void ProcurarPessoaNome(Actor2 *actor);
void ShowListar_com_Contracenou(Actor2 *actor);

char *DevolveGender(char line[]);
int GetIdNumber(char *idString);
char *DevolveName(char line[]);
char *DevolveId(char line[]);

Actor3 *NewNode(char *id, char *nome, char *sexo);
Actor3 *InsertTreeNode(Actor3 *actor, char *id, char *nome, char *sexo);
Actor3 *FindActorManual1(Actor3 *actors, char *id);
void ListarTreeActors(Actor3 *actor);
void ListarTreeActors1(Actor3 *actor);
void ListarTreeActors_Coatores(Actor3 *actor);
Actor3 *FindActorManualIterativa(Actor3 *actors, char *id);

void ListarCoAtores2Recursivo(CoActor2 *CoActor);
void ImprimirActor(Actor3 *actor);
void FindCoactors(Actor3 *actor);
void FindActorsWho_act_only_whith_females(Actor3 *actor);
void WriteTree(Actor3 *actor);
void PercorrerTree(Actor3 *actor, FILE *dados);
void main()
{

    Actor3 *actor = NULL;

    //system("C:\\Users\\Lenovo\\AppData\\Local\\Programs\\Opera\\launcher.exe c:\\export\\a.html");
    //system("C:\\Users\\Lenovo\\AppData\\Local\\Programs\\Opera\\launcher.exe c:\\export\\actors.txt");

    actor = LoadFileActors(actor);
    printf("Ficheiro carregado!\n");
    LoadFileCoActors(actor);
    printf("\nVou listar, prima uma tecla para continuar: \n");
    getchar();
    WriteTree(actor);
    //FindActorsWho_act_only_whith_females(actor);
    //ListarTreeActors(actor);
    //FindCoactors(actor);
    //ListarTreeActors(actor);
    printf("Ficheiro carregado e listado e com coatores\n");
    getchar();
}

Actor3 *LoadFileActors(Actor3 *actor)
{
    FILE *ficheiro;
    Actor3 *aux = (Actor3 *)malloc(sizeof(Actor3));
    aux = NULL;
    char *a, *b, *c, *line;
    int i = 0;

    ficheiro = fopen(TXTACTOR, "r");

    line = (char *)malloc(MAX * sizeof(char));
    a = (char *)malloc(sizeof(char) * 11);
    b = (char *)malloc(sizeof(char) * 50);
    c = (char *)malloc(sizeof(char) * 2);

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

            aux = InsertTreeNode(aux, a, b, c);
            i++;
        }
    }
    system("cls");
    printf("Total de Registros: %d\n", i);
    fclose(ficheiro);
    free(a);
    free(b);
    free(c);
    free(line);
    return aux;
}

Actor2 *InsereListaActor(Actor2 *aux, char *nome, char *genero, char *id)
{

    Actor2 *new = (Actor2 *)malloc(sizeof(Actor2));
    strcpy(new->nome, nome);
    strcpy(new->genero, genero);
    strcpy(new->id, id);
    new->soTemMulher = 0;
    new->numElementos = 0;
    new->incidencia = NULL;
    new->seguinte = aux;
    return new;
}

CoActor2 *sorted_insert(CoActor2 *lst, char *id, Actor3 *Ator, Actor3 *ProprioAtor)
{
    if (!lst || GetIdNumber(id) < GetIdNumber(lst->id))
    {
        CoActor2 *new = (CoActor2 *)malloc(sizeof(CoActor2));
        strcpy(new->id, id);
        new->seguinte = lst;
        new->contagem = 1;
        new->actorProprio = ProprioAtor;
        lst = new;
        Ator->numCoActoresDiferentes++;
    }
    else
    {
        if (lst && GetIdNumber(id) == GetIdNumber(lst->id))
            lst->contagem++;
        else
            lst->seguinte = sorted_insert(lst->seguinte, id, Ator, ProprioAtor);
    }

    return lst;
}

void *LoadFileCoActors(Actor3 *actor)
{
    FILE *ficheiro;
    Actor3 *aux = (Actor3 *)malloc(sizeof(Actor3));
    Actor3 *aux2 = (Actor3 *)malloc(sizeof(Actor3));
    Actor3 *aux3 = actor;
    CoActor2 *coAtor = (CoActor2 *)malloc(sizeof(CoActor2));
    coAtor = NULL;
    aux = NULL;
    int i = 0;
    char *a, *b;

    ficheiro = fopen(TXTCOACTOR, "r");

    a = (char *)malloc(sizeof(char) * 16);
    b = (char *)malloc(sizeof(char) * 16);

    if (ficheiro == NULL)
    {
        printf("Não foi possivel abrir o ficheiro para leitura!\n");
    }
    else
    {
        while (fscanf(ficheiro, "%s %s", a, b) != EOF)
        {
            i++;

            aux = FindActorManualIterativa(aux3, a);
            aux2 = FindActorManualIterativa(aux3, b);

            if (aux != NULL && aux2 != NULL)
            {
                //--------------------------------- primeira insercao--------------------------------------
                //CoActor2 *new = (CoActor2 *)malloc(sizeof(CoActor2));
                //strcpy(new->id, b);
                //new->seguinte = aux->incidencia;
                //aux->incidencia = new;
                //aux->numElementos++;
                aux->incidencia = sorted_insert(aux->incidencia, b, aux, aux2);
                aux->numAtuacoes++;
                //--------------------------------- Segunda insercao--------------------------------------
                i++;
                /*                 CoActor2 *new2 = (CoActor2 *)malloc(sizeof(CoActor2));
                strcpy(new2->id, a);
                new2->seguinte = aux2->incidencia;
                aux2->incidencia = new2;
                aux2->numElementos++; */

                aux2->incidencia = sorted_insert(aux2->incidencia, a, aux2, aux);
                aux2->numAtuacoes++;
                if (aux->genero[0] != 'F')
                {
                    aux2->soTemMulher = -1;
                }
                if (aux2->genero[0] != 'F')
                {
                    aux->soTemMulher = -1;
                }

                if (DEBUG == 1)
                {
                    if (i % 13000 == 0)
                    {
                        printf("%d - %d Percent done.....\n", i, (i / 13000));
                    }
                }
            }
            else
            {
                if (DEBUG == 1)
                    printf("Nao encontrei na arvore a linha %d %s %s\n", i, a, b);
            }
        }
    }

    printf("acabei coatores\n");
    printf("%d\n", i);
    fclose(ficheiro);
}

Actor2 *FindActorList(Actor2 *actor, char *id)
{
    Actor2 *aux = actor;
    while (aux)
    {
        if (strcmp(aux->id, id) == 0)
        {
            return aux;
        }
        aux = (aux->seguinte ? aux->seguinte : NULL);
    }
    return aux;
}
CoActor2 *InsereListaCoActor(CoActor2 *aux, char *id)
{

    CoActor2 *new2 = (CoActor2 *)malloc(sizeof(CoActor2));
    strcpy(new2->id, id);
    new2->seguinte = aux;
    return new2;
}

void ShowListActor(Actor2 *actor)
{
    Actor2 *aux = actor;
    int i = 0;
    system("cls");
    while (aux)
    {
        i++;
        printf("Id: %s Name: %s Gender: %s contador %d\n", aux->id, aux->nome, aux->genero, i);
        aux = (aux->seguinte ? aux->seguinte : NULL);
    }
    getchar();
    system("cls");
}

void ShowListCo_Actor(Actor2 *actor)
{
    Actor2 *aux = actor;
    CoActor2 *aux1 = (CoActor2 *)malloc(sizeof(CoActor2));
    int i = 0, j;
    system("cls");
    while (aux)
    {
        i++;
        printf("Com coatores Id: %s Name: %s Gender: %s total coatores:%d ||| contador %d\n", aux->id, aux->nome, aux->genero, aux->numElementos, i);
        getchar();
        //if (aux->incidencia)
        // {
        aux1 = aux->incidencia;
        while (aux1)
        {
            j = 0;
            j++;
            printf("Id coator: %s total %d\n", aux1->id, j);
            aux1 = (aux1->seguinte ? aux1->seguinte : NULL);
        }
        // }else{
        //    printf("nao tem\n");
        // }
        getchar();
        aux = (aux->seguinte ? aux->seguinte : NULL);
    }
    getchar();
    system("cls");
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
    for (i = i; i < a - 1; i++)
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
    int i = 0;
    char aux[16];

    while (idString[i] != 0)
    {
        aux[i - 2] = idString[i];
        i++;
    }

    aux[i - 2] = 0;

    i = atoi(aux);

    //printf("********** %d *************\n", i);

    return i;
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
void MaisPessoas(Actor2 *actor)
{
    Actor2 *aux = actor;
    int maior = aux->numElementos;
    char nome[64], genero[2], id[16];
    while (aux)
    {
        if (aux->numElementos > maior)
        {
            maior = aux->numElementos;
            strcpy(nome, aux->nome);
            strcpy(genero, aux->genero);
            strcpy(id, aux->id);
        }
        aux = (aux->seguinte ? aux->seguinte : NULL);
    }
    printf("Quem contracenou com mais pessoas foi %s %s %s com um total de %d pessoas", nome, genero, id, maior);
}
void ProcurarPessoaNome(Actor2 *actor)
{
    Actor2 *aux = actor;
    char procura[64];
    printf("Escreva o nome da Pessoa que deseja Procurar!\n");
    scanf("%s", procura);
    while (aux)
    {
        if (strcmp(aux->nome, procura) == 0)
        {
            printf("ID: %s  Name: %s\n", aux->id, aux->nome);
        }
    }
    getchar();
}

void ShowListar_com_Contracenou(Actor2 *actor)
{
    Actor2 *aux = actor;
    CoActor2 *aux1 = (CoActor2 *)malloc(sizeof(CoActor2));
    char procura[16];
    int i = 0, j;
    system("cls");
    printf("Escreva o ID da Pessoa da qual deseja ver com quem Contracenou!\n");
    scanf("%s", procura);
    while (aux)
    {
        if (strcmp(aux->id, procura) == 0)
        {
            printf("O %s com o Id: %s contracenou com %d pessoa(as)", aux->nome, aux->id, aux->numElementos);
            aux1 = aux->incidencia;
            while (aux1 && aux->numElementos > 0)
            {
                printf("Contracenou com o coator: %s\n", aux1->id);
                aux1 = (aux1->seguinte ? aux1->seguinte : NULL);
            }
        }
        break;
        aux = (aux->seguinte ? aux->seguinte : NULL);
    }
    getchar();
}
void Menu()
{
    char op;
    while (op != 115)
    {
        printf("_____________________________________________________________________\n");
        printf("|                                                                   |\n");
        printf("| 1- Mostrar Pessoas com o mesmo Nome                               |\n ");
        printf("| 2- Mostrar Individuos com que um(a) ator(atriz) contracenou       |\n ");
        printf("| 3- Apresentar Individuos que contracenaram apenas com Mulheres    |\n ");
        printf("| 4- Calcular quem contracenou com mais pessoas                     | \n");
        printf("| 5- Mostrar Caminho entre duas pessoas                             | \n");
        printf("|___________________________________________________________________|\n");
        printf("\nSelecione uma opcao!\n");
        scanf("%c", op);
        switch (op)
        {
        case 1:
            //ProcurarPessoaNome(actor);
            break;
        case 2:
            //ShowListar_com_Contracenou(actor);
            break;
        case 3:
            break;
        case 4:
            //MaisPessoas(actor);
            break;
        case 5:
            break;
        default:
            break;
        }
    }
}

Actor3 *InsertTreeNode(Actor3 *actor, char *id, char *nome, char *sexo)
{

    if (actor == NULL)
    {
        return NewNode(id, nome, sexo);
    }
    else
    {
        if (GetIdNumber(id) < GetIdNumber(actor->id))
        {

            actor->anterior = InsertTreeNode(actor->anterior, id, nome, sexo);
        }
        else if (GetIdNumber(id) > GetIdNumber(actor->id))
        {

            actor->seguinte = InsertTreeNode(actor->seguinte, id, nome, sexo);
        }
    }
    return actor;
}

Actor3 *NewNode(char *id, char *nome, char *sexo)
{
    Actor3 *new = (Actor3 *)malloc(sizeof(Actor3));
    int a, b, c;
    a = strlen(id);
    b = strlen(nome);
    c = strlen(sexo);
    strcpy(new->id, id);
    strcpy(new->nome, nome);
    strcpy(new->genero, sexo);
    new->numAtuacoes = 0;
    new->numCoActoresDiferentes = 0;
    new->soTemMulher = 0;
    new->anterior = NULL;
    new->seguinte = NULL;
    new->incidencia = NULL;
    return new;
}

Actor3 *FindActorManualIterativa(Actor3 *actors, char *id)
{
    int key = GetIdNumber(id);
    int code_tree = -1;
    Actor3 *aux = actors;

    while (aux != NULL && code_tree != key)
    {
        code_tree = GetIdNumber(aux->id);
        //printf("%d %d \t", code_tree, key);

        if (key < code_tree)
            aux = aux->anterior;
        else if (key > code_tree)
            aux = aux->seguinte;
    }
    /*    if (aux != NULL)
            printf("%s %d \n", aux->nome, aux->id);
        else
            printf("sai\n");  */

    return aux;
}

Actor3 *FindActorManual1(Actor3 *actors, char *id)
{
    //2,147,483,647

    int key, code_tree;
    if (actors)
    {

        key = GetIdNumber(id);
        code_tree = GetIdNumber(actors->id);
        if (key < code_tree)
        {

            return FindActorManual1(actors->anterior, id);
        }
        else if (key > code_tree)
        {
            return FindActorManual1(actors->seguinte, id);
        }
        else
        {
            printf("procura %s %s", actors->id, id);
            getchar();
            return actors;
        }
    }
    else
    {
        return NULL;
    }
}

void ListarTreeActors(Actor3 *actor)
{

    if (actor)
    {
        ListarTreeActors(actor->anterior);
        ImprimirActor(actor);

        if (actor->numCoActoresDiferentes != actor->numAtuacoes)
        {
            printf("Encontrei um ator com contracenacoes repetidas, prima uma tecla par aocntinuar");
            getchar();
        }

        ListarCoAtores2Recursivo(actor->incidencia);

        ListarTreeActors(actor->seguinte);
    }
}

void ImprimirActor(Actor3 *actor)
{

    printf("ID: %s  Name: %s Gender: %s N. Atuacoes: %d N. Atores diferentes:%d sotemMulher: %d\n", actor->id, actor->nome, actor->genero, actor->numAtuacoes, actor->numCoActoresDiferentes, actor->soTemMulher);
}
void ListarCoAtores2Recursivo(CoActor2 *CoActor)
{
    if (CoActor != NULL)
    {
        printf("%s\t%s\t%d\t%s \n", CoActor->actorProprio->nome, CoActor->id, CoActor->contagem, CoActor->actorProprio->genero);
        ListarCoAtores2Recursivo(CoActor->seguinte);
    }
}

void ListarTreeActors_Coatores(Actor3 *actor)
{

    if (actor)
    {
        ListarTreeActors(actor->anterior);
        printf("ID: %s  Name: %s Gender: %s\n", actor->id, actor->nome, actor->genero);
        if (actor->incidencia != NULL)
        {
            CoActor2 *aux = actor->incidencia;
            while (aux)
            {
                printf("CoAtor ID: %s\n", aux->id);
                aux = aux->seguinte;
            }
        }
        ListarTreeActors(actor->seguinte);
    }
}

void FindCoactors(Actor3 *actor)
{
    Actor3 *aux = NULL;
    char procura[16];
    do
    {
        printf("Indique o Id de um actor a procurar!\n");
        scanf("%s", procura);
        if (FindActorManualIterativa(actor, procura) == NULL)
        {
            printf("Actor nao existe! Tente novamente!\n");
        }
    } while (FindActorManualIterativa(actor, procura) == NULL);
    //------encontra o actor ----------
    aux = FindActorManualIterativa(actor, procura);

    system("cls");
    ImprimirActor(aux);

    ListarCoAtores2Recursivo(aux->incidencia);
    getchar();
}

void FindActorsWho_act_only_whith_females(Actor3 *actor)
{
    if (actor)
    {
        FindActorsWho_act_only_whith_females(actor->anterior);

        if (actor->soTemMulher == 0)
        {
            ImprimirActor(actor);
            ListarCoAtores2Recursivo(actor->incidencia);
        }

        FindActorsWho_act_only_whith_females(actor->seguinte);
    }
    getchar();
}

void WriteTree(Actor3 *actor)
{

    FILE *dados;

    dados = fopen("dadosFinais.txt", "w");
    if(dados==NULL)printf("nao abriu arquivo txt\n");
    PercorrerTree(actor, dados);
    fclose(dados);
    printf("Escrita completa\n");
    getchar();
}

void PercorrerTree(Actor3 *actor, FILE *dados)
{
    if (actor)
    {
        PercorrerTree(actor->anterior, dados);
        fprintf(dados, "%s %s %s %d %d %d", actor->id, actor->nome, actor->genero, actor->numAtuacoes, actor->numCoActoresDiferentes, actor->soTemMulher);
        PercorrerTree(actor->seguinte, dados);
    }
}

void Actor_with_More_Opposite_acts(Actor3 *actor){

    if(actor){
        Actor_with_More_Opposite_acts(actor->anterior);
        int maior=actor->numAtuacoes;
        if(actor->numAtuacoes>maior){
            Actor3*aux=NULL;
            maior =actor->numAtuacoes;
            aux=actor;
        }
        Actor_with_More_Opposite_acts(actor->seguinte);
    }
    printf("O Ator que contracenou com mais pessoas foi:\n");
    printf(" %s com o Id: %s e com o total de %d contrenacoes\n", aux->nome,aux->id,aux->);

}