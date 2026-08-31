#include <stdio.h>
#include <string.h>

void inicializa(int *v, int n) {
    int *p = v;
    while (p < v + n) {
        *p = 0;
        p++;
    }
}

int main(){

    int v[] = {1, 2, 3, 4};

    inicializa(v, 4);

    printf("A função inicializa(int *v, int n) zera todos os elementos do vetor\n");

    for(int i=0; i<4; i++){
        printf("%d ", v[i]);
    }

    printf("\nO erro do código é por conta da igualdade no while\n");
    printf("Existe um erro na linha 6\n");
    printf("O erro ocorre por acessar área adjacente fora do escopo do vetor, isso causa problemas se zerar ");

    return 0;
}
