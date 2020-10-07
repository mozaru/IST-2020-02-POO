#include "contato.hpp"

#include <iostream>
#include <string>


using namespace std;

void Contato::ler() {
  cout << "Entre com o nome:";
  getline(cin, nome);
  cout << "Entre com o telefone:";
  getline(cin, telefone);
}

string Contato::getNome() { return nome; }

string Contato::getTelefone() { return telefone; }

void Contato::setNome(string aNome) { nome = aNome; }

void Contato::setTelefone(string aTelefone) { telefone = aTelefone; }
