
    
#include<stdio.h>
#define MAX 1000

int main(){

int i,j,aux,tam,guard = 0;
int a[MAX];

//ENTRADA DO TAMANHO DO VETOR
scanf("%d",&tam);

//PREEENCHIMENTO DO VETOR
for(i=0;i<tam;i++){
scanf("%d",&a[i]);
}

//BUBLLESORT DO VETOR
for (i=0;i<tam;i++){
	for (j=i+1;j<tam;j++){
		if (a[i]>a[j]){
			aux=a[i];
			a[i]=a[j];
			a[j]=aux;
			guard++;
		}
	}
}

//SAIDA ESPERADA
printf("%d\n",guard);	
return 0;	
}