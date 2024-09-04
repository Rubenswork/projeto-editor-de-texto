#include <iostream>
#include "editor.hpp"

using namespace std;

int main() {
    int escolha, sistema;
    string conteudo;
    char R='S';
    
    //Faz a verificacao do sistema do usuario para saber qual comando usar na limpagem de tela
    #if defined(_WIN32) || defined(_WIN64)
        sistema=1;
    #elif defined(__APPLE__) || defined(__MACH__)
        sistema=2;
    #elif defined(__linux__)
        sistema=2;
    #elif defined(__unix__) || defined(__unix)
        sistema=2;
    #elif defined(__FreeBSD__)
        sistema=2;
    #else
        sistem=0;
    #endif
    
    do {
        R='S';
        mostrarMenu();
        cin >> escolha;
        cin.ignore(); // Reseta o buffer de entrada
        
        switch(escolha) {
            case 1:
                criarNovoArquivo();
                break;
            case 2:
                abrirArquivo();
                break;
            case 3:
                cout << "Digite o novo conteúdo para o arquivo\n";
                getline(cin, conteudo); // Lê o conteúdo até o fim
                substituir(conteudo);
                formatarTexto(conteudo);
                cout << "Conteúdo atualizado:\n" << conteudo << "\n";
                break;
            case 4:
                cout << "Saindo...\n";
                break;
            default:
                cout << "Escolha inválida! Tente novamente.\n";
        }
        
        cout << "Quer continuar? [S/N]";
        cin >> R;
        cin.ignore();
        OSteste(sistema);
        
    } while(escolha != 4 || R=='S');
    
    return 0;
}