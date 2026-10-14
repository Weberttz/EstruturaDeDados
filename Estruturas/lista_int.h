#ifndef LIST_INT_H
#define LIST_INT_H

#include <stddef.h>  // size_t

typedef struct No {
    int dado;
    struct No *prox;
} No;

typedef struct {
    No *inicio;
    size_t size;
} ListInt;

/* Vida do objeto */
void   list_init(ListInt *l);
void   list_clear(ListInt *l);

/* Inserções */
int    list_push_front(ListInt *l, int v);
int    list_push_back(ListInt *l, int v);
int    list_insert_sorted(ListInt *l, int v);

/* Busca/alteração/remoção */
No*    list_find(const ListInt *l, int v);        // retorna ponteiro do nó ou NULL
int    list_update_first(ListInt *l, int oldv, int newv);
int    list_remove_first(ListInt *l, int v);      // remove a primeira ocorrência

/* Utilidades */
void   list_print(const ListInt *l);
size_t list_size(const ListInt *l);
int    list_is_empty(const ListInt *l);

#endif