#include <stdio.h>

int max(int *v, int n){
    int num = 0, maior = 0;

    if (n <= 0) return -1;

    for (int i=0; i<n; i++){
        num = *(v + i);
        if (num > maior) maior = num;
    }

    return maior;
}

int main(){
    int v[] = {1, 2, 3, 4, 5};

    int tamanho = sizeof(v)/sizeof(v[0]); // má prática

    int maior = max(v, tamanho);

    if (maior == -1){
        printf("vetor tem tamanho 0\n");
        return 0;
    }

    printf("Maior = %d\n", maior);

    return 0;
}