#include <stdio.h>

struct Aluno{
    char nome[50];
    int idade;
    float nota;
};

void aumentar_notas(struct Aluno *alunos, int quantidade){
    for(int i=0; i<quantidade; i++){
        int nota = (alunos + i)->nota;
        (alunos + i)->nota += (alunos + i)->nota/10;

        if((alunos + i)->nota > 10.0) (alunos + i)->nota = 10.0;
    }
}

void imprimir_vetor(struct Aluno *alunos, int quantidade){
    for (int i = 0; i < quantidade; i++)
    {
        printf("Nome %s\tIdede: %d\tNota: %.2f\n", alunos->nome, alunos->idade, alunos->nota);
        alunos++;
    }
}

int main(){
    int qnt = 4;
    struct Aluno alunos[] = {
        {"Jonh", 20, 5.0},
        {"Davi", 20, 8.9},
        {"Rafael", 18, 1.2},
        {"Antônio", 18, 8.92}
    };

    printf("Valores originais:\n");
    imprimir_vetor(alunos, qnt);
    aumentar_notas(alunos, qnt);
    printf("Valores após o aumento de 10%%");
    imprimir_vetor(alunos, qnt);

    /*
    A passagem por ponteiro permite modificar os valores, pois, passa o endereço da variável que salva aqueles dados.
    Isso permite modificar diretamente no espaço de memória.

    A passagem por valor, decai para um ponteiro que aponta para a cabeça de um vetor, otimização da linguagem para não copiar todos
    os elementos do vetor novamente em memória.
    */

    return 0;
}