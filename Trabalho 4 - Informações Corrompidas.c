
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 1000000

void preprocess_strong_suffix(int *shift, int *bpos, char *pat, int m)
{
    int i=m, j=m+1;
    bpos[i]=j;

    while(i>0)
    {
        while(j<=m && pat[i-1] != pat[j-1])
        {
            if (shift[j]==0)
                shift[j] = j-i;
            j = bpos[j];
        }
        i--;j--;
        bpos[i] = j;
    }
}

void preprocess_case2(int *shift, int *bpos, char *pat, int m)
{
    int i, j;
    j = bpos[0];
    for(i=0; i<=m; i++)
    {
        if(shift[i]==0)
            shift[i] = j;
        if (i==j)
            j = bpos[j];
    }
}

/*Algoritmo de Boyer Moore with Good suffix rule - coletado e adaptado do geek for geeks */
void search(char *text, char *pat, int tam_ruido, int tam_text)
{
    int s=0, j;
    //int m = strlen(pat);
    //int n = strlen(text);
    int bpos[tam_ruido+1], shift[tam_ruido+1];

    for(int i=0;i<tam_ruido+1;i++)
      shift[i]=0;

    preprocess_strong_suffix(shift, bpos, pat, tam_ruido);
    preprocess_case2(shift, bpos, pat, tam_ruido);

    while(s <= tam_text-tam_ruido)
    {
        j = tam_ruido-1;
        while(j >= 0 && pat[j] == text[s+j])
            j--;
        if (j<0)
        {
            printf("%d\n", s);
            s += shift[0];
        }
        else
            s += shift[j+1];
    }
}

int main(int argc, char *argv[])
{
    char file_name[MAX];
    FILE *entrada;
    char frase[MAX];
    char ruido[MAX];
    int tam_text, tam_ruido;

    //Entrada por arquivo
    scanf("%s", file_name);
    entrada = fopen(file_name, "r");
    if (entrada == NULL)
    {
        printf("\nNão encontrei o arquivo!\n");
        exit(EXIT_FAILURE);
    }

    //Entrada pelo arquivotam_
    fscanf(entrada,"%d %d", &tam_text, &tam_ruido);
    fscanf(entrada,"%s", frase);
    fscanf(entrada,"%s", ruido);

    //printf("tam_text : %d \ntam_ruido : %d\nfrase: %s\nruido: %s\n",tam_text, tam_ruido,frase,ruido);

    search(frase, ruido, tam_ruido, tam_text);
    return 0;
}
