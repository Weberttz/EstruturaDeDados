#include <stdio.h>

void inverter(int *v, int n){
    for(int i=0; i<(n/2); i++){
        int a = *(v+i);
        *(v+i) = *(v + n - i -1);
        *(v + n - i - 1) = a;
    }
}

void inverter2(int*v, int n){
    for(int i = (n-1); i >= (n/2); i--){
        int b = *(v-i+(n-1));
        *(v-i+n-1) = *(v+i);
        *(v+i) = b;
    }
}

void imprimir(const int *v, int n){
    for (int i=0; i<n; i++){
        printf("%d ", v[i]);
    }
}

int main(){
    int v[] = {1, 2, 3, 6, 4, 5};

    printf("Vetor original: ");
    imprimir(v, 6); 

    inverter(v, 6);

    printf("\nVetor invertido: ");
    imprimir(v, 6);

    printf("\nNão é preciso de memória adicional, pois só precisa trocar os elementos equidistantes\n");
    printf("Pense como dois ponteiros, um vindo do inicio, outro vindo do fim, daí, trocamos os elementos equidistantes\n");
    printf("v[0] <-> v[n - 1] , v[1] <-> v[n - 2] , ... , v[int(n/2)] <-> v[n - 1 - int(n/2)]\n");

    return 0;
}