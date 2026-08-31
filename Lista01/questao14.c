#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Aluno {
    char nome[50];
    int idade;
    float nota;
};

int remove_aluno(struct Aluno **v, int n, int idx) {
    if (idx < 0 || idx >= n) return 0;

    // jogar os sucessores para trás, cobrindo os valores de v[idx]
    for (int i = idx; i < n - 1; i++) {
        (*v)[i] = (*v)[i + 1];
    }  

    // alocar em temporária para evitar erros
    struct Aluno *tmp = realloc(*v, (n - 1) * sizeof(struct Aluno));

    // se a alocação não funcionar, retorna 0
    if (tmp == NULL && n - 1 > 0) return 0;

    // se funcionou, trocar o endereço da cabeça para um novo local em memória
    *v = tmp; 

    return 1;
}

void imprimir_vetor(struct Aluno *alunos, int quantidade) {
    for (int i = 0; i < quantidade; i++) {
        printf("Nome: %s\tIdade: %d\tNota: %.2f\n", alunos[i].nome, alunos[i].idade, alunos[i].nota);
    }
}

int main() {
    int qnt = 4;
    
    // Alocação inicial
    struct Aluno *p1 = malloc(qnt * sizeof(struct Aluno));
    if (p1 == NULL) return 1;

    // Inicialização dos dados
    strcpy(p1[0].nome, "Jonh"); p1[0].idade = 20; p1[0].nota = 5.0;
    strcpy(p1[1].nome, "Davi"); p1[1].idade = 20; p1[1].nota = 8.9;
    strcpy(p1[2].nome, "Rafael"); p1[2].idade = 18; p1[2].nota = 1.2;
    strcpy(p1[3].nome, "Antônio"); p1[3].idade = 18; p1[3].nota = 8.92;

    imprimir_vetor(p1, qnt);
    
    if(remove_aluno(&p1, qnt, 2)) {
        printf("\nAluno removido!\n");
        qnt--;
    }else 
        printf("\nFalha ao remover aluno.\n");
    
    imprimir_vetor(p1, qnt);

    free(p1);
    return 0;
}
