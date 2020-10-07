#ifndef _LISTA_HPP_
#define _LISTA_HPP_

#include<iostream>
#include<iomanip>

#include "Contato.hpp"

using namespace std;

#define _MAX_  100

typedef Contato TInfo;

class Lista
{
   private:
      TInfo v[_MAX_];
      int   qtd;
   public:
      Lista();
      bool vazia();
      bool cheia();
      int  obterQtd();
      TInfo obterElemento(int pos); 
      void alterarElemento(int pos, TInfo info);
      int obterIndice(string info);
      bool existe(string info);
      void inserirNoInicio(TInfo info);
      void inserirNoFinal(TInfo info);
      void inserirOrdenado(TInfo info);
      void inserir(int pos, TInfo info);
      void removerNoInicio();
      void removerNoFinal();
      void remover(string info);
      void remover(int pos);
};

#endif
