
#include<stdio.h>
#include<stdlib.h>
#define MAX 100000

typedef struct grafo * Grafo;
struct grafo {
  int ** A;
  int n; // número de vértices
  int m; // número de arestas/arcos
};

typedef struct noh Noh;
struct noh {
  int rotulo;
  int custo;
  struct noh * prox;
};

/* REPRESENTAÇÃO POR LISTAS DE ADJACÊNCIA:
A função inicializaGrafo() constrói um grafo
com vértices 0 1 .. n-1 e nenhum arco. */
Grafo inicializaGrafo(int n) {
  int i;
  Grafo G = malloc(sizeof * G);
  G -> n = n;
  G -> m = 0;
  G -> A = malloc(n * sizeof(Noh * ));
  for (i = 0; i < n; i++)
    G -> A[i] = NULL;
  return G;
}

/* Versão da função insereArcoGrafo() que não testa
se o arco v-w já está presente */
void insereArcoNaoSeguraGrafo(Grafo G, int v, int w, int peso) {
  Noh * p;
  p = malloc(sizeof(Noh));
  p -> rotulo = w;
  p -> custo = peso;
  p -> prox =(Noh*) G -> A[v];
  G -> A[v] = (int*)p;
  G -> m++;
}

void Dijkstra(Grafo G, int origem, int * dist, int * pred) {
  int i, * R;
  int v, w, custo, tam_R, min_dist;
  Noh * p;
  // inicializando distâncias e predecessores
  for (i = 0; i < G->n; i++) {
    dist[i] = MAX;
    pred[i] = -1;
  }
  dist[origem] = 0;
  // inicializando conjunto de vértices "resolvidos" R
  R = malloc(G->n * sizeof(int));
  for (i = 0; i < G->n; i++)
    R[i] = 0;
  tam_R = 0;
  // enquanto não encontrar o caminho mínimo para todo vértice
  while (tam_R < G->n) {
    // buscando vértice v em V \ R que minimiza dist[v]
    min_dist = __INT_MAX__;
    v = -1;
    for (i = 0; i <= G->n; i++)
      if (R[i] == 0 && dist[i] < min_dist) {
        v = i;
        min_dist = dist[i];
      }
    // adicionando v a R e atualizando o conjunto R
    R[v] = 1;
    tam_R++;
    // percorrendo lista com vizinhos de v
    p =(Noh*) G->A[v];
    while (p != NULL) {
      w = p->rotulo;
      custo = p->custo;
      // e atualizando as distâncias e predecessores quando for o caso
      if (R[w] == 0 && dist[w] > dist[v] + custo) {
        dist[w] = dist[v] + custo;
        pred[w] = v;
      }
      p = p->prox;
    }
  }
  free(R);
}


int main(){

//DECLARAÇÕES 
  int qt_verts, qt_arestas;
  int i;
  int vert1, vert2, peso;
  int dist[MAX];
  int pred[MAX];
  Grafo crush;


//ENTRADA DOS DADOS 
  scanf("%d %d", &qt_verts, &qt_arestas);
  crush = inicializaGrafo(qt_verts);
  
  for(i = 1; i <= qt_arestas; i++){
    scanf("%d %d %d", &vert1, &vert2, &peso);
    insereArcoNaoSeguraGrafo(crush, vert1, vert2, peso);
  }

//MAGIA ACONTECE
//mostraGrafo(crush);
Dijkstra(crush, 0, dist, pred);
//SAIDA
//printf("Peso minimo para o caminho: %d\n", dist[qt_verts-1]);
printf("%d\n", dist[qt_verts-1]);

return 0;

}