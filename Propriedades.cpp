#include "Propriedades.h"
#include <algorithm>
#include <cmath>

bool estaVazia(No* raiz) {
    return raiz == nullptr;
}

int altura(No* raiz) {
    if (raiz == nullptr) return -1;
    return 1 + std::max(altura(raiz->esquerda), altura(raiz->direita));
}

int totalNos(No* raiz) {
    if (raiz == nullptr) return 0;
    return 1 + totalNos(raiz->esquerda) + totalNos(raiz->direita);
}

bool ehEstritamenteBinaria(No* raiz) {
    if (raiz == nullptr) return true;
    if (raiz->esquerda == nullptr && raiz->direita == nullptr) return true;
    if (raiz->esquerda != nullptr && raiz->direita != nullptr) 
        return ehEstritamenteBinaria(raiz->esquerda) && ehEstritamenteBinaria(raiz->direita);
    return false;
}

bool ehCheia(No* raiz) {
    if (raiz == nullptr) return true;
    int h = altura(raiz);
    int n = totalNos(raiz);
    return n == (std::round(std::pow(2, h + 1)) - 1);
}

bool ehDegenerada(No* raiz) {
    if (raiz == nullptr) return true;
    if (raiz->esquerda == nullptr && raiz->direita == nullptr) return true;
    if (raiz->esquerda != nullptr && raiz->direita != nullptr) return false;
    return ehDegenerada(raiz->esquerda ? raiz->esquerda : raiz->direita);
}

bool verificaCompleta(No* raiz, int indice, int n) {
    if (raiz == nullptr) return true;
    if (indice >= n) return false;
    return verificaCompleta(raiz->esquerda, 2 * indice + 1, n) &&
           verificaCompleta(raiz->direita, 2 * indice + 2, n);
}

bool ehQuaseCompleta(No* raiz) {
    return verificaCompleta(raiz, 0, totalNos(raiz));
}
