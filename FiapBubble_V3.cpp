#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main() {
    // Lista de números inicial
    vector<int> L = {15, 7, 1};
    string entrada;

    // Adicionar novos itens à lista
    cout << "Digite números para adicionar à lista (ou pressione Enter para parar):\n";
    while (true) {
        cout << "Número: ";
        getline(cin, entrada);  // Lê a entrada como string

        // Verifica se o usuário pressionou Enter sem digitar nada
        if (entrada.empty()) {
            break;  // Sai do loop
        }

        // Tenta converter a entrada para um número inteiro
        stringstream ss(entrada);
        int novo_item;
        if (ss >> novo_item) {
            L.push_back(novo_item);  // Adiciona o número à lista
        } else {
            cout << "Entrada inválida! Digite apenas números inteiros.\n";
        }
    }

    // Tamanho da lista
    int fim = L.size();
    bool trocou;

    // Algoritmo Bubble Sort
    while (fim > 1) {
        trocou = false;  // Flag para verificar se houve troca
        for (int i = 0; i < fim - 1; i++) {
            if (L[i] > L[i + 1]) {
                // Troca os elementos se estiverem fora de ordem
                swap(L[i], L[i + 1]);
                trocou = true;  // Marca que houve troca
            }
        }
        if (!trocou) {
            break;  // Se não houve troca, a lista já está ordenada
        }
        fim--;  // Reduz o limite da comparação
    }

    // Exibir a lista ordenada
    cout << "\nLista ordenada:\n";
    for (int i = 0; i < L.size(); i++) {
        cout << L[i] << endl;
    }

    return 0;
}