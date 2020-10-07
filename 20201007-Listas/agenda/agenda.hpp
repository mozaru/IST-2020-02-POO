#ifndef _AGENDA_HPP_
#define _AGENDA_HPP_

#include <string>

#include "contato.hpp"
#include "lista.hpp"

using namespace std;

class Agenda {
private:
  Lista l;

public:
  void inserir(Contato c);
  bool remover(string info);
  bool alterar(string info, Contato c);
  void listar();
  void filtrar(string filtro);
};

#endif