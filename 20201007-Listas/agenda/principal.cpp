#include <iostream>
#include <string>

#include "agenda.hpp"
#include "contato.hpp"
#include "menu.hpp"


int main() {
  Agenda a;
  Contato ficha;
  string filtro;
  bool acabou = false;

  while (!acabou) {
    switch (menu()) {
    case 1: // inserir
      break;
    case 2: // remover
      break;
    case 3: // alterar
      break;
    case 4: // listar
      break;
    case 5: // filtrar
      break;
    case 6: // sair
      acabou = true;
      break;
    default:
      cerr << "opcao escolhida nao foi implementada" << endl;
      exit(0);
    }
  }

  return 0;
}