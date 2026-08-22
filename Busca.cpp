#include <iostream>
#include "Busca.h"

/* ========== BUSCAR ========== */
bool buscar(No* raiz, int valor) {
    if (raiz == nullptr) return false; // chegou ao fim da recursão sem achar
    if (raiz->valor == valor) return true;

    return buscar(raiz->esquerda, valor) || buscar(raiz->direita, valor);
}

/* ========== PERCURSOS ========== */
void emOrdem(No* raiz) {
    if (raiz == nullptr) return;
    emOrdem(raiz->esquerda); // esquerda primeiro
    std::cout << raiz->valor << " "; // visita o nó
    emOrdem(raiz->direita); // direita por último
}
 
void preOrdem(No* raiz) {
    if (raiz == nullptr) return;
    std::cout << raiz->valor << " "; // visita o nó primeiro
    preOrdem(raiz->esquerda);
    preOrdem(raiz->direita);
}
 
void posOrdem(No* raiz) {
    if (raiz == nullptr) return;
    posOrdem(raiz->esquerda);
    posOrdem(raiz->direita);
    std::cout << raiz->valor << " "; // visita o nó por último
}
