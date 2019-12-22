
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

typedef struct pessoa Pessoa;
struct pessoa{
    int posicao;
    Pessoa *prox;
};

Pessoa *inicio;
Pessoa *fim;
Pessoa *matadord;
Pessoa *caminhador;

void insereLista(int x){
    Pessoa *novo;
    novo = malloc(sizeof(Pessoa));

    novo->posicao = x;
    novo->prox = inicio;

    if(inicio == NULL){
        inicio = novo;
        fim = novo;
    }

    fim->prox = novo;
    fim = novo;
}

//ELE PASSA COMO PARAMETRO O ANTERIOR DO QUE IRA MORRER
void removeLista(Pessoa *p){
    Pessoa *morto;

    if(p != matadord){
        matadord = p;
        if (p->prox != inicio){
        morto = p->prox;
        p->prox = morto->prox;
        free(morto);
        }
        else{
            inicio = p->prox->prox;
            morto = p->prox;
            p->prox = morto->prox;
            free(morto);
        }
    }
    else{
        p = p->prox;
        caminhador = p;
        removeLista(p);
    }

}


void imprimeLista(){
    Pessoa *p = inicio;

    do{
    printf("%d ", p->posicao);
    p = p->prox;
    }while (p != inicio);

    printf("\n");
}

//OTIMIZAR QUANDO m == 1
int pisoLogR(int x)
{
    if ( x == 1)
        return 0;
    else {
        if ( x <= 3)
            return 1;
    }

    return 1 + pisoLogR(x/2);
}

Pessoa* walk(Pessoa *p){
    return p->prox;
}


//IRA RETORNAR A POSIÇÃO SOBREVIVENTE
int resolveJosephus (int n, int m){
    int i,u, vivo;


    for(i=0; i<n; i++){
        insereLista(i+1);
    }

    //printf("\n");
    //imprimeLista();
    
    caminhador = inicio;

    if(m != 1){
    for(u = 0 ; u < (m-1) ; u++){

        caminhador = walk(caminhador);
    }
    if (caminhador->prox == inicio){
    inicio = caminhador->prox->prox;
    }
    removeLista(caminhador);
    }
    else{
        removeLista(caminhador);
    }

    for(i=0; i < (m*n) - m ; i= i+m){

        if(m != 1){
            for(u = 0 ; u < (m) ; u++){
                caminhador = walk(caminhador);
        }
            if(walk(caminhador) == inicio && walk(inicio) == caminhador)
                caminhador = caminhador->prox;

            if(walk(caminhador) ==  inicio && walk(caminhador->prox) == inicio){
                vivo = inicio->posicao;
                return vivo;
            }else
                removeLista(caminhador);

        }else
        {
            caminhador = walk(caminhador);

            if(walk(caminhador) ==  inicio && walk(caminhador->prox) == inicio){
                vivo = inicio->posicao;
                return vivo;
            }else
                removeLista(caminhador);
        }
    }

    vivo = inicio->posicao;
    return vivo;
}

int main(){

    int nroexecs;

    scanf("%d", &nroexecs);
    int *n = malloc(nroexecs * sizeof(int));
    int *p = malloc(nroexecs * sizeof(int));

    for (int i = 0; i < nroexecs; i++){
    scanf("%d", &n[i]);
    scanf("%d", &p[i]);
    }

    for(int i = 0; i < nroexecs; i++){
        printf("Usando n=%d, m=%d, resultado=%d\n", n[i], p[i], resolveJosephus(n[i], p[i]));
        inicio = NULL;
        fim = NULL;
    }
return 0;
}
