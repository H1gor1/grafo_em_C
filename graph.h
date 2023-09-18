//
// Created by higor on 15/09/2023.
//

#ifndef GRAPHS_GRAPH_H
#define GRAPHS_GRAPH_H
#define max 6
#define TRUE 7
#define FALSE 8

typedef struct graph{
    int mat[max][max];
    int vertices;
    int arestas;
    int direcionado; //0= nao eh direcionado 1= eh direcionado
}graph;


void criaGrafo(graph *g, int vertices, int dir);
void insereArestaNDir(graph *g, int Vert1, int Vert2);
void insereArestaDir(graph *g, int Vert1, int Vert2);
void imprimeGrafo(graph g);

#endif //GRAPHS_GRAPH_H
