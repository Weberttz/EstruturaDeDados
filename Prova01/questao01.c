#include <stdio.h>
#include <stdlib.h>

int *filtrar(int *v, int n, int corte, int *qnt){

    if (n == 0) {
        *qnt = 0;
        return NULL;
    }

    int *v2 = malloc(n * sizeof(int));

    for(int i=0; i<n; i++){
        if(*(v+i) >= corte){ 
            *(v2 + *qnt) = *(v+i);
            (*qnt)++;
        }    
    }

    int *tmp = realloc(v2, *qnt * sizeof(int));

    if(tmp == NULL){
        *qnt = 0;
        return NULL;
    }

    return tmp;
}

int main(){

    int corte = 5, n = 5, qnt = 0;
    int *vetor = malloc(5 * sizeof(int));

    vetor[0] = 2;
    vetor[1] = 7;
    vetor[2] = 3;
    vetor[3] = 10;
    vetor[4] = 5;

    int *v = filtrar(vetor, n, corte, &qnt);

    if(v == NULL){
        printf("Erro ao filtrar!");
        return 0;
    }

    printf("Vetor resultante = ");
    for(int i=0; i<qnt; i++){
        printf("%d ", *(v+i));
    }
    printf("\nQuantidade = %d\n", qnt);

    free(v);
    return 0;
}