#include <stdio.h>
#include <stdlib.h>

struct Aluno
{
    char nome[50];
    int idade;
    float nota;
};


struct Aluno* criar_aluno(int idade, float nota){
    struct Aluno *a = malloc(sizeof(struct Aluno));

    if(a == NULL) return NULL;

    a->idade = idade;
    a->nota = nota;

    return a;
}

int main(){

    struct Aluno *aluno = criar_aluno(10, 10);

    printf("%d", aluno->idade);
    printf("%f", aluno->nota);

    return 0;
}