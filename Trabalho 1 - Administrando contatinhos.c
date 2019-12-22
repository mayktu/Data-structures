
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef char* Chave;
typedef int Valor;

typedef struct celTS{
    Chave chave;
    Valor valor;
    struct celTS *prox;
}CelTS;

static CelTS **tab = NULL;
static int nChaves = 0;


//tamanho da tabela
static int M = 100000;

int hash(Chave chave, int M){
    int i, h = 0;
    int primo = 13259;
    for(i = 0; chave[i] != '\0'; i++){
        h = (h * primo + chave[i]) % M;
    }
    return h;
}



void stInit(int max){
    int h;
    M = max;
    nChaves = 0;
    tab = malloc(M * sizeof(CelTS *));
    for(h = 0; h < M; h++)
        tab[h] = NULL;
}

void stSearch(Chave chave){
    CelTS *p;
    int h = hash(chave, M);
    p = tab[h];
    while(p != NULL && strcmp(p->chave, chave) != 0){
        p = p->prox;
    }
    if (p != NULL){
        printf("Contatinho encontrado: telefone %d\n", p->valor);
    }
    else{
        printf("Contatinho nao encontrado\n");
    }

}

void stAltera(Chave chave, Valor valor){
    CelTS *p;
    int h = hash(chave, M);
    p = tab[h];
    while(p != NULL && strcmp(p->chave, chave) != 0)
        p = p->prox;
    if (p != NULL){
        p->valor = valor;
    }
    else
    {
        printf("Operacao invalida: contatinho nao encontrado\n");
    }
}

Chave copyString(Chave stringfrase){
    char* str = NULL;
    int len = strlen(stringfrase) + 1;
    str = malloc(len *sizeof(char));
    strncpy(str,stringfrase,len);
    return str;
}


void stInsert(Chave chave, Valor valor){
    CelTS *p;
    int h = hash(chave, M);
    p = tab[h];
    while(p != NULL && strcmp(p->chave, chave))
        p = p->prox;
    if(p == NULL){
        p = malloc(sizeof(*p));
        p->chave = copyString(chave);
        nChaves += 1;
        p->prox = tab[h];
        tab[h] = p;
        p->valor = valor;
    }
    else{
        printf("Contatinho ja inserido\n");
    }
}

void stDelete(Chave chave){
    CelTS *p, *aux;
    int h = hash(chave, M);
    p = tab[h];
    if(p == NULL){
        printf("Operacao invalida: contatinho nao encontrado\n");
        return;
    }    

    if(strcmp(p->chave,chave) == 0){
        tab[h] = p->prox;
        free(p->chave);
        free(p);
        nChaves--;
        return;
    }
    while(p->prox != NULL && strcmp((p->prox)->chave, chave) != 0)
        p = p->prox;
    if(p->prox != NULL){
        aux = p->prox;
        p->prox= aux->prox;
        free(aux->chave);
        free(aux);
        nChaves--;
    }
    else{
        printf("Operacao invalida: contatinho nao encontrado\n");
    }
}

void stFree(){
    CelTS *p = NULL, *q = NULL;
    int h;
    for(h = 0; h < M; h++){
        p = tab[h];
        while(p){
            q = p;
            p = p->prox;
            //Liberando a chave string de cada celula
            free(q->chave);
            free(q);
        }
    }
    free(tab);
    tab = NULL;
    nChaves = 0;
}

int tratamento(char* stringfrase, char* nome){
    int i, j = 0, k = 0, space = 1, telefone;
    char aux[15];
    
    for(i = 2; stringfrase[i] != '\0' && stringfrase[i] != '\n'; i++){
        if(stringfrase[i] == ' '){
            space++;
        }
        if(space == 1){
            nome[k++] = stringfrase[i];
        }
        else{
            aux[j++] = stringfrase[i];
        }
        
    }

    nome[k] = '\0';
    telefone = atoi(aux);
    return telefone;
}

int main(){
    char tipo;
    char nome[100];
    char stringfrase[25];
    int telefone;

    fgets(stringfrase, sizeof(char)*25,stdin);
    strtok(stringfrase, "\r");
    tipo = stringfrase[0];
    telefone = tratamento(stringfrase, nome);

    //Inicia a Hash
    stInit(M);

    while(tipo != '0'){
        //printf("nome: %s, tipo: %c, telefone: %d\n", nome,tipo,telefone);
        if(tipo  == 'I'){ //Insere
            stInsert(nome,telefone);
        }
        if(tipo == 'R'){ //Remove
            stDelete(nome);         
        }
        if(tipo == 'A'){ //Altera Telefone
            stAltera(nome,telefone);
        }
        if(tipo == 'P'){ //Pesquisa
            stSearch(nome);
        }

        fgets(stringfrase, sizeof(char)*25,stdin);
        strtok(stringfrase, "\r");
        tipo = stringfrase[0];
        telefone = tratamento(stringfrase, nome);
    }

    return 0;

}

