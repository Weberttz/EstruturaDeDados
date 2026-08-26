#include <stdio.h>

int main(){
    int v[5] = {1, 2, 3, 4, 5};
    printf("%p %p %p\n", &v[0], &v[1], &v[2]);

    // tamanho de 1 int = 4bytes
    printf("tamanho de 1 int = %zu bytes\n", sizeof(int));
    printf("Note que o endereço de v[0] = %p\n", &v[0]);
    printf("E note também que o endereço de v[1] = %p\n", &v[1]);
    printf("Observe que cada endereço de elementos adjacentes soma 4, que é o tamanho de um int");

    return 0;
}