#include <stdio.h>
#include <stdlib.h>

int min(int a, int b){
    return (a < b)? a : b;
}

int* merge(int* vetor1, int* vetor2, int tam1, int tam2){

    int* vetor3 = malloc((tam1 + tam2) * sizeof(int));

    int p1 = 0, p2 = 0, p3 = 0;
    int num1 = 0, num2 = 0;

    while(p3 < (tam1 + tam2)){

        if(p1 < tam1) num1 = *(vetor1 + p1);
        else num1 = *(vetor2 + p2);

        if(p2 < tam2) num2 = *(vetor2 + p2);
        else num2 = *(vetor1 + p1);

        *(vetor3 + p3) = min(num1, num2);
        p3++;

        (num1 < num2)? p1++ : p2++;
    }

    return vetor3;
}

int main(){

    int vetor1[] = {1, 2, 3, 7, 8, 10};
    int vetor2[] = {4, 5, 9, 10, 11};

    int tam1 = 6, tam2 = 5;

    int *vetor3 = merge(vetor1, vetor2, tam1, tam2);

    for(int i=0; i<(tam1 + tam2); i++){
        printf("%d ", *(vetor3 + i));
    }

    free(vetor3);
    return 0;
}