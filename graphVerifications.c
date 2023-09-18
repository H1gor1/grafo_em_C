//
// Created by higor on 18/09/2023.
//

#include "graphVerifications.h"
#include "graph.h"

int verificaCategoriaDirec(graph *g){
    if(verificaArestaMult(g)){
        return 1; //multigrafo dirigido
    }
    return 0; //grafo dirigido
}

int verificaCategoriaNDirec(graph *g){
    if(verificalacos(g)){
        return 2; //pseudografo
    }else if(verificaArestaMult(g)){
        return 3; //mutigrafo
    }
    return 4; //grafo simples
}

int verificalacos(graph *g){
    for (int i = 0; i < g->vertices; ++i) {
        if(g->mat[i][i] != 0){
            return 1;
        }
    }
    return 0;
}

int verificaArestaMult(graph *g){
    for (int i = 0; i < g->vertices; ++i) {
        for (int j = 0; j < g->vertices; ++j) {
            if(g->mat[i][j] > 1){
                return 1;
            }
        }
    }
    return 0;
}

int verificaSumidouro(graph *g){
    int contador;
    for (int i = 0; i < g->vertices; ++i) {
        for (int j = 0; j < g->vertices; ++j) {
            contador+= g->mat[i][j];
        }
        if(contador == 0)
            return i;
    }
    return -1;
}

int verificaFonte(graph *g){
    int contador;
    for (int i = 0; i < g->vertices; ++i) {
        for (int j = 0; j < g->vertices; ++j) {
            contador+= g->mat[j][i];
        }
        if(contador == 0)
            return i;
    }
    return -1;
}

void contaGrauSimples(graph *g, int *grauSimples, int vertice){
    int grauAtual = 0;

    for (int i = 0; i < g->vertices; ++i) {
        grauAtual += g->mat[vertice][i];
    }
    *grauSimples = grauAtual;
}

void contaGrauDirec(graph *g, int *grauIn, int *grauOut, int vertice) {
    *grauOut = 0;
    *grauIn = 0;

    // Calcula o grau de saída para o vértice especificado
    for (int i = 0; i < g->vertices; ++i) {
        *grauOut += g->mat[vertice][i];
    }

    // Calcula o grau de entrada para o vértice especificado
    for (int i = 0; i < g->vertices; ++i) {
        *grauIn += g->mat[i][vertice];
    }
}

int verificaAdjac(graph *g, int vertice1, int vertice2){
    if(g->mat[vertice1][vertice2] != 0){
        return TRUE;
    } else {
        for (int i = 0; i < g->vertices; ++i) {
            if(g->mat[vertice1][i] && g->mat[i][vertice2]){
                return i;
            }
        }
    }
    return FALSE;
}
