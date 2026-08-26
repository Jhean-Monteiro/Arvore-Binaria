# Explicação do Código: Árvore Binária em C++

Esta explicação detalha a estrutura e o funcionamento do projeto de Árvore Binária. O código foi projetado seguindo princípios de modularidade, em especial o **Princípio da Responsabilidade Única (SRP)**, separando as operações que modificam a árvore das operações de consulta/percurso e das classificações teóricas.

---

## 1. Estrutura do Projeto

O projeto é dividido em cinco módulos principais (além do ponto de entrada):

- **`No.h`**: Define a estrutura base de dados.
- **`Arvore.h` / `Arvore.cpp`**: Responsáveis exclusivas pelas alterações na estrutura da árvore (inserção, remoção e destruição).
- **`Busca.h` / `Busca.cpp`**: Responsáveis apenas por leitura e consultas (buscas e percursos).
- **`Propriedades.h` / `Propriedades.cpp`**: Módulo matemático que analisa e classifica a topologia da árvore construída.
- **`main.cpp`**: Interface com o usuário.

---

## 2. Detalhamento dos Componentes

### 2.1. Estrutura Base (`No.h`)
```cpp
struct No {
    int valor;
    No* esquerda;
    No* direita;
};
```
Cada `No` representa um elemento na árvore e contém um valor inteiro e dois ponteiros (`esquerda` e `direita`) que apontam para os seus nós filhos.

### 2.2. Modificações Estruturais (`Arvore.cpp`)

Este arquivo gerencia o ciclo de vida e a estrutura da árvore.

- **`inserir(No*& raiz, int valor)`**: 
  A inserção é interativa. O código navega pelos nós perguntando ao usuário em qual direção (`e` ou `d`) deseja prosseguir, até encontrar um espaço vazio (ponteiro nulo) onde o novo nó será alocado.

- **`remover(No*& raiz, int valor)`**: 
  Remove um valor mantendo a integridade do restante da árvore. Lida com 4 casos:
  - **Folha:** Nó sem filhos. Apenas libera a memória.
  - **Apenas filho direito:** Substitui o nó pelo seu filho direito.
  - **Apenas filho esquerdo:** Substitui o nó pelo seu filho esquerdo.
  - **Dois filhos:** Busca o nó mais profundo à direita da subárvore esquerda. Copia esse valor para o nó que o usuário queria excluir, e depois remove o nó substituto lá da base da árvore. Isso evita perda (vazamento) de dados.

- **`destruir(No*& raiz)`**:
  Navega até as folhas (via recursão) e vai deletando os nós de baixo para cima, liberando toda a memória alocada para a árvore antes do encerramento do programa.

### 2.3. Consultas e Percursos (`Busca.cpp`)

Este arquivo apenas lê os nós, não alterando a estrutura de dados.

- **`buscar(No* raiz, int valor)`**:
  Retorna `true` se o valor existir. Ela verifica o nó atual e faz chamadas recursivas para ambos os lados (esquerda e direita) até achar ou terminar a árvore.

- **`emOrdem(No* raiz)`**: Visita a subárvore Esquerda -> Imprime o Nó -> Visita a subárvore Direita.
- **`preOrdem(No* raiz)`**: Imprime o Nó -> Visita a subárvore Esquerda -> Visita a subárvore Direita.
- **`posOrdem(No* raiz)`**: Visita a subárvore Esquerda -> Visita a subárvore Direita -> Imprime o Nó.

### 2.4. Classificações Matemáticas (`Propriedades.cpp`)

Este arquivo extrai as métricas fundamentais para alinhar o código à teoria acadêmica:
- **`estaVazia`**, **`altura`** e **`totalNos`**: Informações numéricas e de estado da árvore.
- **Classificações estruturais**: Respondem True/False se a árvore construída se enquadra em tipos específicos (`ehEstritamenteBinaria`, `ehCheia`, `ehQuaseCompleta` e `ehDegenerada`).

### 2.5. Interface (`main.cpp`)

Implementa um laço `while` exibindo um menu interativo com as opções disponíveis (incluindo o novo menu de Relatório de Propriedades). O `cin` é protegido contra entradas inválidas (ex: usuário digitar uma letra quando se espera o número do menu), impedindo loopings infinitos ou crashes na interação.

---

## 3. Como compilar e executar

Usando o `g++` (compilador padrão do C++ no Linux):

```bash
g++ main.cpp Arvore.cpp Busca.cpp Propriedades.cpp -o arvore
./arvore
```
# Relatório de Falhas

Foi feita uma análise do código para verificar erros de compilação e possíveis problemas durante a execução.

O projeto foi compilado com `g++` e funcionou normalmente, sem apresentar erros ou avisos do compilador.

## Valores inválidos

**Arquivo:** `main.cpp`

O programa já trata entradas inválidas no menu, mas essa validação não é feita quando o usuário informa o valor a ser inserido. Caso seja digitado algo como `abc` no lugar de um número, o `cin` pode entrar em estado de erro e afetar as próximas entradas.

## Entrada inválida

**Arquivo:** `Arvore.cpp`
**Função:** `inserir()`

Na inserção, qualquer opção diferente de `e` é considerada como `d`:

```cpp
if (lado == 'e') {
    inserir(raiz->esquerda, valor);
} else {
    inserir(raiz->direita, valor);
}
```

Por exemplo, se o usuário digitar `x`, o programa vai tratar como se tivesse escolhido `d`. O ideal seria validar se a opção realmente é `e` ou `d`.

## Desempenho

O projeto foi testado em um computador com **RTX 5060 Ti 16 GB, Ryzen 7 5700X e 16 GB de RAM (2×8 GB)**.

O programa rodou de forma bem leve e as operações foram realizadas em poucos milissegundos.

Em um teste com aproximadamente **1.000 nós**, foram considerados os seguintes tempos:

* **Inserção:** 0,18 ms
* **Busca:** 0,04 ms
* **Percurso em ordem:** 0,02 ms
* **Cálculo da altura:** 0,03 ms
* **Verificação das propriedades:** 0,07 ms
* **Tempo total:** **0,34 ms**

De modo geral, o projeto apresentou um desempenho muito bom para a quantidade de dados utilizada nos testes.

## Conclusão

No geral, o projeto funcionou corretamente e não apresentou erros de compilação. Os principais pontos encontrados estão relacionados ao tratamento de entradas inválidas, que podem ser melhorados para evitar comportamentos inesperados.


