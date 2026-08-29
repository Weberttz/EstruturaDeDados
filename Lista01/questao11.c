#include <stdio.h>
#include <stdlib.h>

int* formar_vetor_par(int n){

    int *vetor = malloc(((int) n/2) * sizeof(int));

    int par = 0;
    for(int i=0; i <= (n/2); i++){
        *(vetor + i) = par;
        par+=2;
    }

    return vetor;
}

int main(){

    int n;

    printf("Digite o valor de n: ");
    scanf("%d", &n);

    int *vetor = formar_vetor_par(n);

    for(int i=0; i<=(n/2); i++){
        printf("%d ", *(vetor + i));
    }

    free(vetor);
    vetor = NULL;

    return 0;
}