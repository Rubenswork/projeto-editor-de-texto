#ifndef EDITOR_HPP
#define EDITOR_HPP

#include <string>

// Declaração das funções
void mostrarMenu();
void criarNovoArquivo();
void abrirArquivo();
void salvarArquivo(const std::string& conteudo, const std::string& nome);
void substituir(std::string& conteudo);
void formatarTexto(std::string& conteudo);
void OSteste(int sistema);

#endif // EDITOR_HPP