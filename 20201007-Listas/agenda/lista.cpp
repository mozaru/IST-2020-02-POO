#include "lista.hpp"

#include <iostream>
#include <string>

#include "contato.hpp"

using namespace std;

Lista::Lista() { qtd = 0; }

bool Lista::vazia() { return qtd == 0; }
bool Lista::cheia() { return qtd == _MAX_; }
int Lista::obterQtd() { return qtd; }

TInfo Lista::obterElemento(int pos) {
  if (pos < 0 || pos >= qtd) {
    cerr << "indice invalido no obterElemento" << endl;
    exit(0);
  }
  return v[pos];
}

void Lista::alterarElemento(int pos, TInfo info) {
  if (pos < 0 || pos >= qtd) {
    cerr << "indice invalido no obterElemento" << endl;
    exit(0);
  }
  v[pos] = info;
}

int Lista::obterIndice(string info) {
  bool achou = false;
  int i = 0;
  while (!achou && i < qtd)
    if (info == v[i].getNome() || info == v[i].getTelefone())
      achou = true;
    else
      i++;
  return achou ? i : -1;
}

bool Lista::existe(string info) { return obterIndice(info) != -1; }

void Lista::inserirNoInicio(TInfo info) {
  if (cheia()) {
    cerr << "lista cheia ao tentar inserir no inicio" << endl;
    exit(0);
  } else {
    int i;
    for (i = qtd - 1; i >= 0; i--)
      v[i + 1] = v[i];
    v[0] = info;
    qtd++;
  }
}

void Lista::inserirNoFinal(TInfo info) {
  if (cheia()) {
    cerr << "lista cheia ao tentar inserir no final" << endl;
    exit(0);
  } else {
    v[qtd] = info;
    qtd++;
  }
}

void Lista::inserirOrdenado(TInfo info) {
  if (cheia()) {
    cerr << "lista cheia ao tentar inserir ordenado" << endl;
    exit(0);
  } else {
    int i;
    i = qtd - 1;
    while (i >= 0 && v[i].getNome() > info.getNome()) {
      v[i + 1] = v[i];
      i--;
    }
    v[i + 1] = info;
    qtd++;
  }
}

void Lista::inserir(int pos, TInfo info) {
  if (cheia()) {
    cerr << "lista cheia ao tentar inserir" << endl;
    exit(0);
  } else {
    int i;
    for (i = qtd - 1; i >= pos; i--)
      v[i + 1] = v[i];
    v[pos] = info;
    qtd++;
  }
}

void Lista::removerNoInicio() {
  if (vazia()) {
    cerr << "lista vazia ao tentar remover no inicio" << endl;
    exit(0);
  } else {
    int i;
    for (i = 1; i < qtd; i++)
      v[i - 1] = v[i];
    qtd--;
  }
}

void Lista::removerNoFinal() {
  if (vazia()) {
    cerr << "lista vazia ao tentar remover no final" << endl;
    exit(0);
  } else
    qtd--;
}

void Lista::remover(string info) {
  if (vazia()) {
    cerr << "lista vazia ao tentar remover a informacao" << endl;
    exit(0);
  } else {
    int pos = obterIndice(info);
    if (pos == -1) {
      cerr << "tentativa de remover uma informacao inexistente" << endl;
      exit(0);
    } else
      remover(pos);
  }
}

void Lista::remover(int pos) {
  if (vazia()) {
    cerr << "lista vazia ao tentar remover na posicao" << endl;
    exit(0);
  } else {
    int i;
    for (i = pos + 1; i < qtd; i++)
      v[i - 1] = v[i];
    qtd--;
  }
}
