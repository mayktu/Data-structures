//CRIANDO ESTRUTURA LISTA ENCADEADA
typedef struct Node{
 int info;
 struct NOH* prox;
} NOH;


//ADICIONANDO UM NOVO NÓ
NOH *novono(int info){
 NOH *n = (NOH *) malloc(sizeof(NOH));
 if(n==NULL){
   printf("\nSEM ESPAÇO");
   return NULL;
 }
 n->info = info;
 n->next = NULL;
 return n;
}

//IMPRIMINDO LISTA
void imprime(NOH * lendo){
 if(lendo!=NULL){
   printf("\n%d",lendo->info);
   imprime(lendo->next);
 }
}

