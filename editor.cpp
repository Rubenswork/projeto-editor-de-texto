#include "editor.hpp"
#include <iostream>
#include <fstream>

using namespace std;

// Função para exibir o menu
void mostrarMenu() {
    cout << "\nEditor de Texto Avançado\n";
    cout << "1. Criar novo Arquivo\n";
    cout << "2. Abrir Arquivo Existente\n";
    cout << "3. Editar Arquivo\n";
    cout << "4. Sair\n";
    cout << "Escolha uma opção: ";
}

// Função para criar novo arquivo
void criarNovoArquivo() {
    string nome, conteudo;
    
    cout << "Digite o nome do arquivo: ";
    cin >> nome;
    cin.ignore(); // Limpa o buffer do cin
    
    cout << "Digite o conteúdo do arquivo:\n";
    getline(cin, conteudo); // Lê o conteúdo até o fim
    
    salvarArquivo(conteudo, nome);
}

// Função para abrir um arquivo existente
void abrirArquivo() {
    string nome, linha, conteudo;
    
    cout << "Digite o nome do arquivo para abrir: ";
    cin >> nome;
    cin.ignore();
    
    ifstream arquivo(nome);
    if(arquivo.is_open()) {
        while(getline(arquivo, linha)) {
            conteudo += linha + "\n";
        }
    
        arquivo.close();
    
        cout << "Conteúdo do Arquivo: \n";
        cout << conteudo << "\n";
    } else {
        cout << "Arquivo não encontrado.\n";
    }
}

// Função para salvar o conteúdo de um arquivo
void salvarArquivo(const string& conteudo, const string& nome) {
    ofstream arquivo(nome);
    if(arquivo.is_open()) {
        arquivo << conteudo;
        arquivo.close();
        cout << "Arquivo salvo com sucesso.\n";
    } else {
        cout << "Erro ao salvar o arquivo.\n";
    }
}

// Função para substituir texto
void substituir(string& conteudo) {
    string paraProcurar, paraSubstituir;
    
    cout << "Digite a palavra para buscar: ";
    cin >> paraProcurar;
    cout << "Digite a palavra para substituir: ";
    cin >> paraSubstituir;
    
    size_t pos = conteudo.find(paraProcurar);
    while(pos != std::string::npos) {
        conteudo.replace(pos, paraProcurar.length(), paraSubstituir);
        pos = conteudo.find(paraProcurar, pos + paraSubstituir.length());
    }
    
    cout << "Substituição concluída.\n";
}

// Função para formatar texto
void formatarTexto(string& conteudo) {
    int escolha;
    cout << "Escolha a formatação:\n";
    cout << "1. Negrito\n2. Itálico\nEscolha: ";
    cin >> escolha;
    
    string comecar, terminar;
    if(escolha == 1) {
        comecar = "<b>";
        terminar = "</b>";
    } else if(escolha == 2) {
        comecar = "<i>";
        terminar = "</i>";
    }
    
    string texto;
    cout << "Digite o texto a ser formatado: ";
    cin.ignore(); // Limpa o buffer de entrada
    getline(cin, texto);
    
    size_t pos = conteudo.find(texto);
    if(pos != std::string::npos) {
        conteudo.insert(pos, comecar);
        conteudo.insert(pos + comecar.length() + texto.length(), terminar);
    } else {
        cout << "Texto não encontrado.\n";
    }
}

void OSteste(int sistema){
    if(sistema==1) {
        system("cls");
    } else if(sistema==2) {
        system("clear");
    }
}