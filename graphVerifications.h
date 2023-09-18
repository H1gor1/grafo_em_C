
#ifndef GRAPHS_GRAPHVERIFICATIONS_H
#define GRAPHS_GRAPHVERIFICATIONS_H
#include "graph.h"

int verificaCategoriaDirec(graph *g);
int verificaCategoriaNDirec(graph *g);
/*
categorias:
0 - grafo dirigido
1 - multigrafo dirigido
2 - pseudografo
3 - multigrafo
4 - grafo simples
*/
int verificalacos(graph *g);
int verificaArestaMult(graph *g);
int verificaSumidouro(graph *g);
int verificaFonte(graph *g);
void contaGrauSimples(graph *g, int *grauSimples, int vertice);
void contaGrauDirec(graph *g, int *grauIn, int *grauOut, int vertice);
int verificaAdjac(graph *g, int vertice1, int vertice2);

#endif //GRAPHS_GRAPHVERIFICATIONS_H
