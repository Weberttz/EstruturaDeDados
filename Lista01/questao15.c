#include <stdio.h>
#include <stdlib.h>

struct Vetor{
    int *dados;
    int tamanho;
};

struct Vetor inverter_copia(const struct Vetor *v){
    if(v->tamanho == 0) return *v;

    struct Vetor novo_vetor;
    novo_vetor.tamanho = v->tamanho;
    novo_vetor.dados = malloc(novo_vetor.tamanho * sizeof(int));

    if(novo_vetor.dados == NULL || novo_vetor.tamanho == 0) return *v;

    for(int i=0; i<novo_vetor.tamanho; i++){
        *(novo_vetor.dados + i) = *(v->dados + v->tamanho -1 - i);
    }

    return novo_vetor;
}

void imprimir_vetor(char str[], const struct Vetor *v){
    printf("%s", str);
    for(int i=0; i<v->tamanho; i++){
        printf("%d ", *(v->dados + i));
    }
    printf("\n");
}

int main(){
    int tamanho = 6;
    int v[6] = {1, 2, 3, 4, 5, 6};
    struct Vetor vetor;
    vetor.dados = v;
    vetor.tamanho = tamanho;

    struct Vetor vetor_invertido = inverter_copia(&vetor);

    imprimir_vetor("Vetor Original: ", &vetor);
    imprimir_vetor("Vetor Invertido: ", &vetor_invertido);

    free(vetor_invertido.dados);
    vetor.dados = NULL;

    return 0;
}

/* a) Cópia superficial vs Cópia profunda

Copiar um vetor inteiro é inviável, pois teríamos que dobrar a ocupação desse vetor em memória, para operar e retornar o invertido
Copiar apenas o ponteiro para o primeiro elemento faz com que pudessemos modificar o vetor original, sem precisar dobrar a quantidade
de memória
*/