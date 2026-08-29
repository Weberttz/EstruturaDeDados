#include <stdio.h>

int soma(int a, int b){return a + b;}
int subtrai(int a, int b){return a - b;}
int multiplica(int a, int b){return a * b;}

// passsagem de função como parâmetro
int calcula(int a, int b, int (*funcao)(int, int)){
    return funcao(a, b);
}

int main() {
    int a, b, opcao, resultado;
    printf("Digite dois numeros: ");
    scanf("%d %d", &a, &b);

    printf("\n1 - Soma\n");
    printf("2 - Subtracao\n");
    printf("3 - Multiplicacao\n");

    printf("Escolha: ");
    scanf("%d", &opcao);

    int (*funcoes[3])(int, int) = {soma, subtrai, multiplica};
    resultado = calcula(a, b, funcoes[opcao-1]);

    printf("Resultado: %d\n", resultado);
    return 0;
}