#include <stdio.h>

int* f()
{
    int x = 10;
    return &x;
}

int main(){

    int *ptr = f();

    printf("%d", *ptr);

    return 0;
}

/*
    O erro é tentar retornar endereço de variável local com escopo em uma função

    Erro: function returns address of local variable [-Wreturn-local-addr]

    Tempo de vida da variável: Variável tem seu escopo local em f, logo só vive enquanto f estiver rodadando
    Região de memória envolvida: Stack, pois é uma variável estática
    Consequências práticas: aplicação deixa de rodar e dados se perdem
*/