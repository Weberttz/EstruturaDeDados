#include <stdio.h>

void inicializa(int *v, int n) {

    int *p = v;
    while (p <= v + n) {
        *p = 0;
        p++;
    }
}

int main(){

    int v[] = {1, 2, 3, 4};

    inicializa(v, 4);

    printf("A função inicializa(int *v, int n) zera todos os elementos do vetor\n");

    for(int i=0; i<4; i++)
        printf("%d", v[i]);

    printf("O erro do código era pela falta de função main");

    return 0;
}
