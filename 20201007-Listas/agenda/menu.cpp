#include "menu.hpp"

#include <iostream>

using namespace std;

int menu() {
  int opc;
  do {
    cout << "1. inserir" << endl;
    cout << "2. remover" << endl;
    cout << "3. alterar" << endl;
    cout << "4. listar" << endl;
    cout << "5. filtrar" << endl;
    cout << "6. sair" << endl;
    cin >> opc;
  } while (opc < 1 || opc > 6);
  return opc;
}
