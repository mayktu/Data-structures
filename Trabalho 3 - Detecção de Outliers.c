
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

//Função de comparação
int cmpfunc2(const void *a, const void *b) {
   if (*(double*)a > *(double*)b) {
      return 1;
   } else if (*(double*)a < *(double*)b) {
      return -1;
   } else {
      return 0;
   }
}


int main(int argc, char *argv[])
{

   char file_name[MAX];
    double **v, limiar;
    int n, k, i, j;
    FILE *entrada;
    int outliers = 0;
    double *aux;

    //Entrada por arquivo disponibilizada pelo Professor
    scanf("%s", file_name);
    entrada = fopen(file_name, "r");
    if (entrada == NULL)
    {
        printf("\nNão encontrei o arquivo!\n");
        exit(EXIT_FAILURE);
    }

    //Entrada do N,K,L
    fscanf(entrada, "%d %d %lf", &n, &k, &limiar);
    //printf("%d %d %lf\n", n, k, limiar);

    //Alocação da matriz
    v = (double **)malloc(n * sizeof(double *));

    for (i = 0; i < n; i++)
    {
        //Alocações dos vetores usados 
        aux = malloc(n*sizeof(double));
        v[i] = (double *)malloc(n * sizeof(double));


        for (j = 0; j < n; j++){
            fscanf(entrada, "%lf", &v[i][j]);
            aux[j] = v[i][j];
            //printf("[1]: %lf\t",v[i][j]);
        }

        //Vetor para ordenar, quantidade de numeros, tipo de cada elemento e a função de comparação
        qsort(aux, n, sizeof(double), cmpfunc2);

        //Um invariante que conta a quantidade de Outliers ate a linha i
        if(aux[k+1] > limiar)
            outliers++;
        free(aux);
    }
    fclose(entrada);


    //Saída da quantiade de Outliers
    printf("%d\n",outliers);

    //Libera os elementos e depois o vetor
    for (i = 0; i < n; i++)
        free(v[i]);
    free(v);

    return 0;
}
