#include<stdio.h>
#define MAX 20

int solucoes = 0;
int rainha = 1;
int pos = 0;
//VETOR COM COLUNAS PROIBIDAS
int ColBLOCK[MAX] = {-1};
int tab[MAX][MAX] = {0};

int posicaolivre(int n, int rainha, int pos){
    int i,j,k;

    for(i = 0; i < rainha; i++){
        //VERIFICANDO COLUNAS
        if(ColBLOCK[i] != -1){
            if(pos == ColBLOCK[i]){
                return 0;
            }
        }
    }

    for(i = 0; i < rainha; i++){

        if(ColBLOCK[i] != -1){
            //VERIFICANDO DIAGONAL SL
            for(j = i+1, k = ColBLOCK[i]+1; ((j < n) && (k < n)); j++, k++){
                if(j == (rainha-1) && k == pos){
                    return 0;
                }
            }
            //VERIFICANDO DIAGONAL SO ARRUMAR       
            for(j = i+1, k = ColBLOCK[i]-1; j < n && k >= 0; j++, k--){
                if(j == (rainha-1) && k == pos){                
                    return 0;
                }
            }
            //VERIFICANDO DIAGONAL NL       
            for(j = i-1, k = ColBLOCK[i]+1; j > 0 && k < n; j--, k++){
                if(j == (rainha-1) && k == pos){
                    return 0;
                }
            }
            //VERIFICANDO DIAGONAL NO - 
            for(j = i-1, k = ColBLOCK[i]-1; j > 0 && k >= 0; j--, k--){
                if(j == (rainha-1) && k == pos){
                    return 0;
                }
            }
        }
        else{
            return 1;
        }

    }
    return 1;
}

int ResolveRAINHA(int n, int rainha,int pos){

    if (rainha ==  1 && pos == n)
        return solucoes;

    //Chegou na ultima coluna volta para tras
    if(pos == n || rainha == n+1){
        if(rainha == n+1){
            solucoes++;

        }
        //EXCLUI A ULTIMA POSICAO DA LINHA ANTERIOR E AVANÇA UMA POSICAO
        if(rainha > 1){
            pos = ColBLOCK[rainha-2] + 1;
            ColBLOCK[rainha-1] = -1; 
            ColBLOCK[rainha-2] = -1;
            rainha--;
            return ResolveRAINHA( n, rainha,pos);
        }
        else{
            pos = ColBLOCK[0] + 1;
            ColBLOCK[0] = -1;
            return ResolveRAINHA(n, rainha,pos);

        }
    }
    else{
        //Verifica se pode colocar na posição, se puder coloca e pula pra proxima rainha
        if((posicaolivre(n, rainha, pos)) == 1){
            tab[rainha-1][pos] = 1;
            ColBLOCK[rainha-1] = pos;
            rainha++;

            return ResolveRAINHA(n, rainha, 0);
        }
        else{
            return ResolveRAINHA( n, rainha, pos+1);
        }
    }
}


int main() 
{
    int n, total;

    scanf("%d", &n);

    total = ResolveRAINHA( n, rainha, pos);
    printf("%d\n", total);

    return 0;
}

