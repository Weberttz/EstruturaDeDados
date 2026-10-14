#include <stdio.h>
#include "lista_int.h"

int main() {

    ListInt l;
    list_init(&l);

    list_push_back(&l, 10);
    printf("\nLista:");
    list_print(&l);

    list_push_front(&l, 5);
    printf("\nLista:");
    list_print(&l);

    list_insert_sorted(&l, 7);
    printf("\nLista:");
    list_print(&l);

    list_insert_sorted(&l, 7);
    printf("\nLista:");
    list_print(&l);

    list_push_back(&l, 20);

    printf("\nLista:");
    list_print(&l);

    printf("\n\nTamanho: %zu\n", list_size(&l));

    No *p = list_find(&l, 10);
    printf("Buscar 10: %s\n", p ? "achou" : "nao achou");

    list_update_first(&l, 7, 99);

    printf("\nDepois de alterar um 7 para 99:");
    list_print(&l);

    list_remove_first(&l, 99);

    printf("\n\nDepois de remover 99:");
    list_print(&l);

    list_clear(&l);
    printf("\n\nDepois de limpar:");
    list_print(&l);

    return 0;
}