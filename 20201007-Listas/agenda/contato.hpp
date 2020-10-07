#ifndef _CONTATO_HPP_
#define _CONTATO_HPP_

#include <string>

using namespace std;

class Contato {
private:
  string nome;
  string telefone;

public:
  void ler();
  string getNome();
  string getTelefone();
  void setNome(string aNome);
  void setTelefone(string aTelefone);
};

#endif