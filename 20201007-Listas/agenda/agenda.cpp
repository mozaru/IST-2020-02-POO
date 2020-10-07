#include "agenda.hpp"

#include <iostream>
#include <string.h>
#include <string>


using namespace std;

void Agenda::inserir(Contato c) { l.inserirOrdenado(c); }

bool Agenda::remover(string info) {
  if (l.existe(info)) {
    l.remover(info);
    return true;
  } else
    return false;
}

bool Agenda::alterar(string info, Contato c) {
  int pos = l.obterIndice(info);
  if (pos > -1) {
    l.alterarElemento(pos, c);
    return true;
  } else
    return false;
}

void Agenda::listar() {
  cout << "---------------------------------------------" << endl;
  for (int i = 0; i < l.obterQtd(); i++) {
    Contato c = l.obterElemento(i);
    cout << c.getNome() << " " << c.getTelefone() << endl;
  }
  cout << "---------------------------------------------" << endl;
}

void Agenda::filtrar(string filtro) {
  cout << "---------------------------------------------" << endl;
  for (int i = 0; i < l.obterQtd(); i++) {
    Contato c = l.obterElemento(i);
    if (strstr(c.getNome().c_str(), filtro.c_str()) != NULL ||
        strstr(c.getTelefone().c_str(), filtro.c_str()) != NULL)
      cout << c.getNome() << " " << c.getTelefone() << endl;
  }
  cout << "---------------------------------------------" << endl;
}
