#include <stdio.h>
#include <stdlib.h>

int max(const int *v, int n){
    int num = 0, maior = 0;

    if (n <= 0) return -1;

    for (int i=0; i<n; i++){
        num = *(v + i);
        if (num > maior) maior = num;
    }

    return maior;
}

int min(const int *v, int n){
    if (n <= 0) return -1;

    int num = 0, menor = *(v);

    for (int i=0; i<n; i++){
        num = *(v + i);
        if (num < menor) menor = num;
    }

    return menor;
}

int somar(const int *v, int n){
    if (n <= 0) return -1;

    int soma = 0;

    for (int i=0; i<n; i++){
        soma +=*(v + i);
    }

    return soma;
}

float calcular_media(const int *v, int n){
    int soma = somar(v, n);
    float media = (float) soma / n;

    return media;
}

int* alocar_memoria(int n){
    return malloc(n * sizeof(int));
}

void ler_vetor(int *v, int n){
    for(int i=0; i<n; i++){
        printf("Digite o valor de v[%d]: ", i);
        scanf("%d", &*(v + i));
    }
}

int main(){

    int n;

    printf("Digite o valor de n: ");
    scanf("%d", &n);

    int *v = alocar_memoria(n);

    if(v == NULL){
        printf("Alocação de memória falhou");
        return 0;
    }

    ler_vetor(v, n);

    int maior = max(v, n);
    int menor = min(v, n);
    int soma = somar(v, n);
    float media = calcular_media(v, n);

    printf("Maior = %d\n", maior);
    printf("Menor = %d\n", menor);
    printf("Soma = %d\n", soma);
    printf("Média = %.2f\n", media);

    free(v);
}