#include <iostream>
#include "Arvore.h"
#include "Busca.h"
#include "Propriedades.h"

using namespace std;

void exibirMenu() {
    cout << "\n=== Arvore Binaria ===\n";
    cout << "1. Inserir no\n";
    cout << "2. Remover no\n";
    cout << "3. Buscar valor\n";
    cout << "4. Exibir em ordem\n";
    cout << "5. Exibir pre-ordem\n";
    cout << "6. Exibir pos-ordem\n";
    cout << "7. Analisar propriedades (altura, tipo, etc)\n";
    cout << "0. Sair\n";
    cout << "Escolha: ";
}

int main() {
    No* raiz = nullptr;
    int opcao = -1;
    int valor;

    while (opcao != 0) {
        exibirMenu();
        
        if (!(cin >> opcao)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Entrada invalida. Tente novamente.\n";
            continue;
        }

        switch (opcao) {
            case 1:
                cout << "Digite o valor para inserir: ";
                cin >> valor;
                inserir(raiz, valor);
                break;
                
            case 2:
                cout << "Digite o valor para remover: ";
                cin >> valor;
                remover(raiz, valor);
                cout << "Remocao finalizada.\n";
                break;
                
            case 3:
                cout << "Digite o valor para buscar: ";
                cin >> valor;
                if (buscar(raiz, valor)) {
                    cout << ">>> Valor " << valor << " esta na arvore.\n";
                } else {
                    cout << ">>> Valor " << valor << " nao encontrado.\n";
                }
                break;
                
            case 4:
                cout << "Em ordem: ";
                emOrdem(raiz);
                cout << "\n";
                break;
                
            case 5:
                cout << "Pre-ordem: ";
                preOrdem(raiz);
                cout << "\n";
                break;
                
            case 6:
                cout << "Pos-ordem: ";
                posOrdem(raiz);
                cout << "\n";
                break;
                
            case 7:
                if (estaVazia(raiz)) {
                    cout << ">>> A arvore esta vazia!\n";
                } else {
                    cout << "\n=== PROPRIEDADES DA ARVORE ===\n";
                    cout << "- Total de nos: " << totalNos(raiz) << "\n";
                    cout << "- Altura: " << altura(raiz) << "\n";
                    cout << "- Estritamente Binaria? " << (ehEstritamenteBinaria(raiz) ? "Sim" : "Nao") << "\n";
                    cout << "- Arvore Cheia? " << (ehCheia(raiz) ? "Sim" : "Nao") << "\n";
                    cout << "- Arvore Quase Completa? " << (ehQuaseCompleta(raiz) ? "Sim" : "Nao") << "\n";
                    cout << "- Arvore Degenerada? " << (ehDegenerada(raiz) ? "Sim" : "Nao") << "\n";
                    cout << "==============================\n";
                }
                break;
                
            case 0:
                destruir(raiz);
                cout << "Encerrando...\n";
                break;
                
            default:
                cout << "Opcao invalida!\n";
        }
    }

    return 0;
}
