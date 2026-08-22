#include <iostream>
#include "Arvore.h"

void inserir(No*& raiz, int valor) {
    if (raiz == nullptr) {
        raiz = new No{valor, nullptr, nullptr}; 
        return; // encerra aqui se a arvore estiver vazia
    }

    char lado;
    std::cout << "Inserir " << valor << " à esquerda (e) ou direita (d) de " << raiz->valor << "? ";
    std::cin >> lado;

    if (lado == 'e') {
        inserir(raiz->esquerda, valor); // passa referência do filho esquerdo
    } else {
        inserir(raiz->direita, valor); // passa referência do filho direito
    }
}



/* ========== REMOVER ========== */
void remover(No*& raiz, int valor) {
    if (raiz == nullptr) return; // valor não encontrado

    if (raiz->valor == valor) {
        // caso 1: folha sem filhos
        if (raiz->esquerda == nullptr && raiz->direita == nullptr) {
            delete raiz; // libera memória
            raiz = nullptr;
            return;
        }

        // caso 2: só tem filho direito
        if (raiz->esquerda == nullptr) {
            No* temp = raiz->direita;
            delete raiz;
            raiz = temp; // ponteiro original aponta pro filho direito
            return;
        }

        // caso 3: só tem filho esquerdo
        if (raiz->direita == nullptr) {
            No* temp = raiz->esquerda;
            delete raiz;
            raiz = temp;
            return;
        }

        // caso 4: dois filhos
        // Pega o nó mais à direita da subárvore esquerda para substituir
        No* temp = raiz->esquerda;
        while (temp->direita != nullptr) {
            temp = temp->direita;
        }
        // Substitui o valor do nó atual
        raiz->valor = temp->valor;
        // Remove o nó substituto original da subárvore esquerda
        remover(raiz->esquerda, temp->valor);
        return;
    }

    // continua buscando nos dois lados
    remover(raiz->esquerda, valor);
    remover(raiz->direita, valor);
}



/* ========== DESTRUIR ========== */
void destruir(No*& raiz) {
    if (raiz == nullptr) return;
    destruir(raiz->esquerda);
    destruir(raiz->direita);
    delete raiz;
    raiz = nullptr; // evita dangling pointer;
}