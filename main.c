#include <stdio.h>
#include "graph.h"
#include "graphVerifications.h"

int main() {
    graph grafo;
    int escolha, dir, vertices;
    int Vert1, Vert2;
    int categoria, fonte, sumidouro;
    int grauNaoDirecionado;
    int grauIn, grauOut;

    do {
        printf("\nEscolha o que deseja fazer: \n"
                     "1- Criar grafo\n"
                     "2- Inserir Aresta\n"
                     "3- Verificar categoria\n"
                     "4- Verificar se eh direcionado\n"
                     "5- Grau do vertice\n"
                     "6- Verificar ligacao de vertices\n"
                     "7- Imprimir grafo\n"
                     "8- Sair\n");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                printf("Escolha o tipo de grafo: \n"
                             "0- Nao direcionado\n"
                             "1- Direcionado\n");
                scanf("%d", &dir);

                printf("Digite o total de vertices do grafo (max de 6): ");
                scanf("%d", &vertices);

                criaGrafo(&grafo, vertices, dir);
                break;
            case 2:
                printf("Digite os vertices que deseja criar uma adjacencia: ");
                scanf("%d", &Vert1);
                if(Vert1 > grafo.vertices){
                    do {
                        printf("Vertice não existe no seu grafo, digite novamente: ");
                        scanf("%d", &Vert1);
                    } while (Vert1 > grafo.vertices);
                }
                scanf("%d", &Vert2);
                if(Vert2 > grafo.vertices){
                    do {
                        printf("Vertice não existe no seu grafo, digite novamente: ");
                        scanf("%d", &Vert2);
                    } while (Vert2 > grafo.vertices);
                }

                if(grafo.direcionado == 0){
                    insereArestaNDir(&grafo, Vert1, Vert2);
                } else {
                    insereArestaDir(&grafo, Vert1, Vert2);
                }
                break;
            case 3:
                if(grafo.direcionado == 0){
                    categoria = verificaCategoriaNDirec(&grafo);
                } else{
                    categoria = verificaCategoriaDirec(&grafo);
                }

                switch (categoria) {
                    case 0:
                        printf("O Grafo é da categoria: GRAFO DIRIGIDO\n");
                        break;
                    case 1:
                        printf("O Grafo é da categoria: MULTIGRAFO DIRIGIDO\n");
                        break;
                    case 2:
                        printf("O Grafo é da categoria: PSEUDOGRAFO\n");
                        break;
                    case 3:
                        printf("O Grafo é da categoria: MULTIGRAFO\n");
                        break;
                    case 4:
                        printf("O Grafo é da categoria: GRAFO SIMPLES\n");
                        break;
                    default:
                        printf("ERRO!\n");
                        break;
                }
                break;
            case 4:
                if(grafo.direcionado == 0){
                    printf("O grafo não é direcionado\n");
                    break;
                } else {
                    fonte = verificaFonte(&grafo);
                    sumidouro = verificaSumidouro(&grafo);
                }

                if (fonte == -1){
                    printf("Nao existe fonte\n");
                } else{
                    printf("A fonte é o vértice: %d\n", fonte);
                }

                if (sumidouro == -1){
                    printf("Nao existe sumidouro\n");
                } else{
                    printf("O sumidouro é o vértice: %d\n", sumidouro);
                }
                break;
            case 5:
                printf("Digite o vertice que deseja verificar o grau: ");
                scanf("%d", &vertices);
                if(grafo.direcionado == 0){
                    contaGrauSimples(&grafo, &grauNaoDirecionado, vertices);
                    printf("Grau do vertice: %d\n", grauNaoDirecionado);
                } else {
                    contaGrauDirec(&grafo, &grauIn, &grauOut,vertices);
                    printf("Grau de entrada do vertice: %d\n", grauIn);
                    printf("Grau de saida do vertice: %d\n", grauOut);
                }
                break;
            case 6:
                printf("Digite os vertices que deseja verificar adjacencia: ");
                scanf("%d", &Vert1);
                scanf("%d", &Vert2);

                int result = verificaAdjac(&grafo,Vert1, Vert2);

                if(result == TRUE){
                    printf("Os vertices sao adjacentes!!\n");
                } else if(result == FALSE){
                    printf("Os vertices nao possuem nenhuma adjacencia nem ligacao!\n");
                } else {
                    printf("Os vertices possuem uma ligacao através do vertice: %d\n", result);
                }
                break;
            case 7:
                imprimeGrafo(grafo);
                break;
            case 8:
                printf("Saindo...");
                break;
            default:
                printf("Opcao incorreta\n");
                break;
        }
    } while (escolha != 8);
    return 0;
}
