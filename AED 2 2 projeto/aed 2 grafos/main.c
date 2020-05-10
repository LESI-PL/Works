/*
	Name: Yuri Lemos Serediuk
	Number:19256
	Name: João Pedro Marques Figueiredo
	Number:19337
	Date: 09/05/20 20:42
	Description:This program creats a graph to showm the connection of actors
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _incidenceList
{
    char *id_Coator;
    struct _incidenceList *next;
} IncidenceList;

typedef struct _graph
{
    char *id;
    char *name;
    char *gender;
    IncidenceList *right;
    struct _graph *next;
} Graph;

//------------------------------------------------------------Assinaturas----------------------------------------------------------

Graph *LoadFileGraph();
Graph *HeadInsertNode(Graph *grafo, char *id, char *name, char *gender);
Graph *NewNode(char *id, char *name, char *gender);
void ShowGraph(Graph *grafo);
char *DevolveId(char line[]);
char *DevolveName(char line[]);
char *DevolveGender(char line[]);
IncidenceList *HeadInsertNodeIncidenceList(Graph *grafo, char *origin, char *target);
IncidenceList *NewNodeMatrix(Graph *grafo, char *origin, char *end);
Graph *SearchEdge(Graph *grafo, char *origin);
IncidenceList *ExisteConnection(Graph *grafo, char *origin, char *target);
Graph *MatrizIncidencia(Graph *grafo);
void ShowMatrix(Graph *grafocompleto);
Graph *AddIncidenceList(Graph *grafo, char *origin, char *target);
//--------------------------------------------------------------------------------------------------------------------------------
int main(int argc, char *argv[])
{
    Graph *graph = NULL, *grafo_completo;
    printf("ola\n");
    graph = LoadFileGraph();
    printf("acabei\n");
    //ShowGraph(graph);
    grafo_completo = MatrizIncidencia(graph);
    printf("acabei\n");
    printf("id %s\n", grafo_completo->id);
    printf("connection %s\n", grafo_completo->right->id_Coator);
    printf("connection %s\n", grafo_completo->right->next->id_Coator);
    getchar();
    ShowMatrix(grafo_completo);
    getchar();

    return 0;
}

Graph *LoadFileGraph()
{

    Graph *grafo = NULL;
    FILE *ficheiro;
    ficheiro = fopen("actors.txt", "r");
    char line[255];
    char *a, *b, *c;
    a = (char *)malloc(sizeof(char));
    b = (char *)malloc(sizeof(char));
    c = (char *)malloc(sizeof(char));
    int i = 0;
    if (ficheiro == NULL)
    {
        printf("Não foi possivel abrir o ficheiro para leitura!\n");
    }
    else
    {
        while (fgets(line, 255, ficheiro) != NULL)
        {

            //printf("entrei\n");
            //printf("%s\n", line);
            a = DevolveId(line);
            c = DevolveGender(line);
            b = DevolveName(line);

            i++;
            printf("id %s\n", a);
            printf("nome %s\n", b);
            printf("sexo %s\n\n", c);
            //printf("%s\n",DevolveId(line));
            //printf("ola 3\n");
            grafo = HeadInsertNode(grafo, a, b, c);
        }
    }
    printf("total %d", i);
    getchar();
    fclose(ficheiro);
    return grafo;
}

Graph *NewNode(char *id, char *name, char *gender)
{
    Graph *new = (Graph *)malloc(sizeof(Graph));
    int a, b, c;
    a = strlen(id);
    b = strlen(name);
    c = strlen(gender);
    new->id = (char *)malloc((a + 1) * (sizeof(char)));
    new->name = (char *)malloc((b + 1) * (sizeof(char)));
    new->gender = (char *)malloc((c + 1) * (sizeof(char)));
    strcpy(new->id, id);
    strcpy(new->name, name);
    strcpy(new->gender, gender);
    new->right = NULL;
    new->next = NULL;
}
IncidenceList *NewNodeMatrix(Graph *grafo, char *origin, char *end)
{
    Graph *aux = (Graph *)malloc(sizeof(Graph));
    aux = SearchEdge(grafo, origin);
    IncidenceList *new = (IncidenceList *)malloc(sizeof(IncidenceList));
    int a;
    a = strlen(end);
    new->id_Coator = (char *)malloc((a + 1) * (sizeof(char)));
    strcpy(new->id_Coator, end);
    new->next = NULL;
    aux->right = new;
    return new;
}
Graph *HeadInsertNodeMatrix(Graph *grafo, char *origin, char *target)
{
    Graph *aux = grafo, *aux1 = grafo;

    if (SearchEdge(aux, origin) != NULL && ExisteConnection(aux, origin, target) != NULL)
    {
        aux->right = HeadInsertNodeIncidenceList(aux, origin, target);
        if (SearchEdge(aux1, target) != NULL && ExisteConnection(aux1, target, origin) != NULL)
        {
            aux1->right = HeadInsertNodeIncidenceList(aux1, target, origin);
        }
        else
        {
            return aux1;
        }
    }
    else
    {
        return aux;
    }
}
IncidenceList *ExisteConnection(Graph *grafo, char *origin, char *target)
{
    Graph *aux1 = grafo;
    while (aux1 && strcmp(aux1->id, origin) != 0)
    {
        aux1 = (aux1->next ? aux1->next : NULL);
    }
    if (aux1)
    {
        IncidenceList *aux = grafo->right;
        while (aux && strcmp(aux->id_Coator, target) != 0)
        {
            aux = (aux->next ? aux->next : NULL);
        }
        return aux;
    }
    else
    {
        return NULL;
    }
}

Graph *SearchEdge(Graph *grafo, char *origin)
{
    Graph *aux = grafo;
    while (aux && strcmp(aux->id, origin) != 0)
    {
        aux = (aux->next ? aux->next : NULL);
    }
    return aux;
}
IncidenceList *HeadInsertNodeIncidenceList(Graph *grafo, char *origin, char *target)
{
    IncidenceList *new = (IncidenceList *)malloc(sizeof(IncidenceList));
    Graph *aux = (Graph *)malloc(sizeof(Graph));
    aux = SearchEdge(grafo, origin);
    int a;
    if (aux->right == NULL)
    {
        return NewNodeMatrix(grafo, origin, target);
    }
    else
    {
        a = strlen(target);
        new->id_Coator = (char *)malloc((a + 1) * (sizeof(char)));
        strcpy(new->id_Coator, target);
        new->next = NULL;
        grafo->right = new;
        return new;
    }
}

Graph *HeadInsertNode(Graph *grafo, char *id, char *name, char *gender)
{
    Graph *new = (Graph *)malloc(sizeof(Graph));
    int a, b, c;
    if (grafo == NULL)
    {
        return NewNode(id, name, gender);
    }
    else
    {
        a = strlen(id);
        b = strlen(name);
        c = strlen(gender);
        new->id = (char *)malloc((a + 1) * (sizeof(char)));
        new->name = (char *)malloc((b + 1) * (sizeof(char)));
        new->gender = (char *)malloc((c + 1) * (sizeof(char)));
        strcpy(new->id, id);
        strcpy(new->name, name);
        strcpy(new->gender, gender);
        new->right = NULL;
        new->next = grafo;
        return new;
    }
}
Graph *MatrizIncidencia(Graph *grafo)
{

    FILE *ficheiro;
    Graph *aux = grafo;
    int i = 1;
    char *a, *b;
    a = (char *)malloc(15 * sizeof(char));
    b = (char *)malloc(15 * sizeof(char));
    ficheiro = fopen("co-actors.txt", "r");
    if (ficheiro == NULL)
    {
        printf("Não foi possivel abrir o ficheiro dos co atores!\n");
    }
    else
    {

        while (fscanf(ficheiro, "%s %s", a, b) != EOF)
        {
            //printf("origin %s  target %s numero %d\n", a, b, i);
            i++;

            aux = AddIncidenceList(aux, a, b);
            aux = AddIncidenceList(aux, b, a);
        }
    }
    fclose(ficheiro);
    return aux;
}

void ShowGraph(Graph *grafo)
{
    int i = 1;

    while (grafo != NULL)
    {

        printf("id %s name %s gender %s  numero %d\n", grafo->id, grafo->name, grafo->gender, i);
        i++;
        grafo = (grafo->next ? grafo->next : NULL);
    }
    getchar();
}

char *DevolveId(char line[])
{

    int i = 0, j = 0;

    while (line[i] != '\0' && line[i] != '\t')
    {
        i++;
    }
    char *aux = (char *)malloc((i + 1) * sizeof(char));

    for (j = 0; j < i; j++)
    {
        aux[j] = line[j];
    }
    aux[j] = '\0';
    //printf("codigo %s\n", aux);

    return aux;
}

char *DevolveName(char line[])
{
    char *aux1;
    char *aux;
    int i = 0, a, b, j = 0;
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
    for (i; i < a; i++)
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
    //printf("line %s\n", line);
    aux[0] = line[a - 2];
    aux[1] = '\0';

    //printf("aux gender %s\n", aux);
    return aux;
}

void ShowMatrix(Graph *grafocompleto)
{
    IncidenceList *aux=NULL;
    while (grafocompleto)
    {
        printf("ator name: %s id: %s gender:%s\n", grafocompleto->name, grafocompleto->id, grafocompleto->gender);
        aux=grafocompleto->right;
        for(;aux;aux=aux->next)
        {
            
            printf("\t\tConnection %s\n", aux->id_Coator);
            //aux = (aux->next ? aux->next : NULL);
        }
        getchar();

        grafocompleto = (grafocompleto->next ? grafocompleto->next : NULL);
    }
    getchar();
}

Graph *AddIncidenceList(Graph *grafo, char *origin, char *target)
{
    Graph *edge = SearchEdge(grafo, origin);
    if (edge)
    {
        //printf("primeira vez edge %s\n", edge->id);
        if (ExisteConnection(grafo, origin, target) != NULL)
        {
            return grafo;
        }
        else
        {
            IncidenceList *new = (IncidenceList *)malloc(sizeof(IncidenceList));
            new->id_Coator = target;
            new->next = edge->right;
            edge->right = new;
        }
    }
    return grafo;
}