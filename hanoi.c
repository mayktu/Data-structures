#include<stdio.h> 

void hanoi(int n, char orig, char aux, char dest) {
    if (n == 0)
        return;
    hanoi (n - 1, orig, dest, aux);
    printf ("\n mover de %c para %c", orig, dest);
    hanoi (n-1, aux, orig, dest);
}


int main() { 
    hanoi(3, 'a', 'b', 'c');
    printf ("\n\n");
    return 0;
}
