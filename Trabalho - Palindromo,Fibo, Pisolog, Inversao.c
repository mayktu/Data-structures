#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int palindromoR(int i, int f, char *s)
{
    // implemente essa função recursiva
    // i = 0
    // f = tamanho de s-1
    // s = string
    if ( i >= f){
        return 1;
    }
    
    if (s[i] == s[f])
        return palindromoR(i+1, f-1, s);
    else 
        return 0;
}

void palindromo(char *s)
{
    int saida = palindromoR(0, strlen(s) - 1, s);

    printf("\"");
    printf("%s", s);
    printf("\" ");

    if (saida)
    {
        printf("eh palindromo\n");
    }
    else
    {
        printf("nao eh palindromo\n");
    }
}

void inversaR(char *str)
{
    int tam = strlen(str);
    int i;
    char copy[tam];
    for(i=0; i<=tam-1; i++)
        copy[i] = str[i];
    if(tam>0){
        printf("%c", copy[tam-1]);
        copy[strlen(str)-1] = '\0';
        inversaR(copy);
    }
}

void inversa(char *s)
{
    printf("inversa de \"");
    printf("%s", s);
    printf("\" = ");

    inversaR(s);

    printf("\n");
}



int fibonacciR(int n)
{
    // implemente essa função recursiva
    if( n == 0)
        return 0;
    if(n == 1)
        return 1;
    
    return fibonacciR(n-1) + fibonacciR(n-2);
}

void fibonacci(int n)
{
    int i;

    printf("%d primeiros numeros de fibonacci = ", n);
    for (i = 0; i < n; i++)
        printf("%d ", fibonacciR(i));

    printf("\n");
}


int pisoLogR(int x)
{
    // implemente essa função recursiva
    if ( x == 1)
        return 0;
    else {
        if ( x <= 3)
            return 1;
    }

    return 1 + pisoLogR(x/2);
}



void pisoLog(int x)
{
    int valor = 0;
    printf("piso de log base 2 de %d = ", x);
    valor = pisoLogR(x);
    printf("%d\n", valor);
}

int main(int argc, char *argv[])
{
    int t;

    scanf("%d", &t);

    if (t < 1 || t > 4)
    {
        printf("Parametros incorretos.\n");
        printf("Ex:\n");
        printf("tp01_recursao 1 [para testar palindromo]\n");
        printf("tp01_recursao 2 [para testar inversa]\n");
        printf("tp01_recursao 3 [para testar fibonacci]\n");
        printf("tp01_recursao 4 [para testar pisoLog]\n");
    }

    if (t == 1)
    {
        printf("\nTestando palindromo()\n\n");
        palindromo("");
        palindromo("1");
        palindromo("77");
        palindromo("505");
        palindromo("1111");
        palindromo("2112");
        palindromo("369963");
        palindromo("10101");
        palindromo("1001001");
        palindromo("12");
        palindromo("12451");
        palindromo("100011");
    }
    else if (t == 2)
    {
        printf("\nTestando inversa()\n\n");
        inversa("ab");
        inversa("gato");
        inversa("minerva");
    }
    else if (t == 3)
    {
        printf("\nTestando fibonacci()\n\n");
        fibonacci(0);
        fibonacci(1);
        fibonacci(2);
        fibonacci(4);
        fibonacci(10);
    }
    else if (t == 4)
    {
        printf("\nTestando pisoLog()\n\n");
        pisoLog(1);
        pisoLog(2);
        pisoLog(3);
        pisoLog(4);
        pisoLog(5);
        pisoLog(15);
        pisoLog(16);
        pisoLog(17);
        pisoLog(127);
        pisoLog(256);
        pisoLog(511);
        pisoLog(512);
    }

    return 0;
}
