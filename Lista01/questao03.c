#include <stdio.h>
#include <stdlib.h>

void f(int v[]) {
    printf("\nDentro de f: ");
    printf("sizeof(v)= %zu\n", sizeof(v));

    printf("Quando o veror é passado como parâmetro de uma função, na verdade é passado o endereço de memória");
    printf("do início do vetor");

    printf("Isso se chama deacimento de vetor\n");

    printf("O sizeof dentro de f é o tamanho que o ponteiro ocupa ao apontar para a cabeça do vetor v");

    getchar();
    system("clear");

    printf("STACK: v[0] -> v[9] + *p -> &v\n");
}

int main() {
    int v[10];

    printf("No main: ");
    printf("sizeof(v)= %zu\n", sizeof(v));

    printf("Como o tamanho do vetor é 10, e cada int ocupa 4 bytes, então o tamanho inteiro que o vetor ocupa é: 40");
    f(v);

    printf("Os valores são diferentes, pois, na main é feito o calculo da quantidade de espaços em memória que o vetor ocupa\n");
    printf("Na função f, é realizado o cálculo da quantidade de espaços de memória que o ponteiro que aponta para o inicio");
    printf("do vetor ocupa");
    

    return 0;
}