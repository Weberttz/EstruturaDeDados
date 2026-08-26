#include <stdio.h>

int main() {
    const int v[3] = {10, 20, 30};
    const int *p = v;

    printf("*(p) = %d em %p\n\n", *(p), p);

    printf("*(p + 1) = %d em %p\n", *(p + 1), p+1); // 20

    printf("*(p + 1) acessa a posição inicial de v + sizeof(int) = %p + 4. ", p);
    printf("Logo &v[0] + 4 bytes = &v[1]\n\n");

    printf("p[2] = %d em %p\n", p[2], p+2); // 30
    printf("p[2] equivale a *(p + 2), que acessa a posição de v + 2 sizeof(int).");
    printf("Logo, acessoa &v[0] + 8 bytes = &v[2]\n\n");

    printf("*(v + 0) = %d em %p\n", *(v + 0), p); // 10
    printf("*(v + 0) acessa exatamente o &v[0]");


    printf("A linguagem C permite tratar arrays e ponteiros de forma semelhante, pois isso ajuda na eficiência da aplicação");
    printf("Mas arrays se comportam de maneira estática e ponteiros permitem alocações dinâmicas");

    return 0;
}