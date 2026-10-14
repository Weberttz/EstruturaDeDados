#include <stdio.h>

int f1(int n) { 
    int s = 0; 
 
    // contar a quantidade de operações para n -> O(n²)
    for (int i = 0; i < n; i++) { // O(n)
        for (int j = 0; j < n; j++) { // O(n)
            s++; 
        } 
    } 

    // contar a quantidade de operações para n -> O(n log n)
    for (int k = 1; k < n; k = k * 2) { // O(log n)
        for (int t = 0; t < n; t++) { // O(n)
                s++; 
        } 
    } 
 
    return s; // retorna a quantidade de operações 
}

int f2(int *v, int n) { 
    if (n <= 0) { 
        return 0; 
    } 
 
    int soma = 0; 
    for (int i = 0; i < n; i++) { 
        soma += v[i]; 
    } 
 
    return soma + f2(v, n - 1); 
} 

int main(){

    printf("%d", f1(7));

    return 0;
}