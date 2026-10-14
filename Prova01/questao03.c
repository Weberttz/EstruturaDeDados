#include <stdio.h> 
 
int main() { 
    int v[] = {10, 20, 30, 40, 50}; 
    int *p = v; 
 
    int a = *(p + 2); // vai imprimir 30
    int b = *(v + 4); // vai imprimir 50
    int c = *(p++); // vai imprimir 10
    int d = *p; // vai impimir 20
 
    printf("%d %d %d %d\n", a, b, c, d); 
 
    return 0; 
}