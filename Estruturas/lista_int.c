#include "lista_int.h"
#include <stdio.h>
#include <stdlib.h>

static No* node_new(int v) {
    No *n = (No*) malloc(sizeof(No));
    if (!n) return NULL;
    n->dado = v;
    n->prox = NULL;
    return n;
}

void list_init(ListInt *l) {
    l->inicio = NULL;
    l->size = 0;
}

void list_clear(ListInt *l) {
    No *cur = l->inicio;
    while (cur) {
        No *next = cur->prox;
        free(cur);
        cur = next;
    }
    l->inicio = NULL;
    l->size = 0;
}

int list_push_front(ListInt *l, int v) {
    No *n = node_new(v);
    if (!n) {
        printf("\nErro: memoria insuficiente!");
        return 0;
    }
    n->prox = l->inicio;
    l->inicio = n;
    l->size++;
    return 1;
}

int list_push_back(ListInt *l, int v) {
    No *n = node_new(v);
    if (!n) {
        printf("\nErro: memoria insuficiente!");
        return 0;
    }

    if (!l->inicio) {
        l->inicio = n;
        l->size++;
        return 1;
    }

    No *cur = l->inicio;
    while (cur->prox) cur = cur->prox;
    cur->prox = n;

    l->size++;
    return 1;
}

No* list_find(const ListInt *l, int v) {
    for (No *cur = l->inicio; cur; cur = cur->prox) {
        if (cur->dado == v) return cur;
    }
    return NULL;
}

int list_update_first(ListInt *l, int oldv, int newv) {
    No *n = list_find(l, oldv);
    if (!n) return 0;
    n->dado = newv;
    return 1;
}

int list_remove_first(ListInt *l, int v) {
    No *prev = NULL;
    No *cur = l->inicio;

    while (cur && cur->dado != v) {
        prev = cur;
        cur = cur->prox;
    }
    if (!cur) return 0;

    if (!prev) l->inicio = cur->prox;
    else prev->prox = cur->prox;

    free(cur);
    l->size--;
    return 1;
}

int list_insert_sorted(ListInt *l, int v) {
    No *n = node_new(v);
    if (!n) {
        printf("\nErro: memoria insuficiente!");
        return 0;
    }

    // lista vazia ou entra antes do primeiro
    if (!l->inicio || v < l->inicio->dado) {
        n->prox = l->inicio;
        l->inicio = n;
        l->size++;
        return 1;
    }

    // para no nó anterior ao ponto de inserção
    No *cur = l->inicio;
    while (cur->prox && cur->prox->dado <= v) {
        cur = cur->prox;
    }

    n->prox = cur->prox;
    cur->prox = n;
    l->size++;
    return 1;
}

void list_print(const ListInt *l) {
    if (!l->inicio) {
        printf("\nLista vazia!");
        return;
    }
    for (No *cur = l->inicio; cur; cur = cur->prox) {
        printf(" %d ", cur->dado);
    }
}

size_t list_size(const ListInt *l) {
    return l->size;
}

int list_is_empty(const ListInt *l) {
    return l->inicio == NULL;
}