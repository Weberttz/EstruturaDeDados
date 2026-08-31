#include <stdio.h>
#include <stdlib.h>

struct Aluno{
    char nome[50];
    int idade;
    float nota;
};

struct Aluno* retornar_maior(struct Aluno *vetor, int quantidade){

    if(quantidade == 0) return NULL;

    struct Aluno *p = vetor;
    struct Aluno *p_maior = vetor;

    for(int i=0; i<quantidade; i++){
        if((*p).nota > (*p_maior).nota) p_maior = p;
        p++;    
    }

    return p_maior;
}

int main(){
    
    int qnt = 4;

    struct Aluno alunos[] = {
        {"Jonh", 20, 10.0},
        {"Davi", 20, 9.9},
        {"Rafael", 18, 8.2},
        {"Antônio", 18, 9.92}
    };
    
    struct Aluno *ptr = retornar_maior(alunos, qnt);

    if(ptr ==  NULL) {
        printf("Vetor nulo!\n");
        return 0;
    }

    printf("Endereço = %p\n", ptr);
    printf("Nome = %s\n", ptr->nome);
    printf("Idade = %d\n", ptr->idade);
    printf("Nota = %f\n", ptr->nota);

    return 0;
}