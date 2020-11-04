#ifndef _ARQTEXTOCPP_H_
#define _ARQTEXTOCPP_H_

#include <string>
#include <fstream>
#include "eleicao.h"

class ArqTextoCPP
{
   private:
      string nome;
      Eleicao *conj;
      char* lerAte(ifstream &arq, int max, char strDestino[]);
      void lerEleitores(string nomeArq);
      void lerCandidatos(string nomeArq);
      void gravarEleitores(string nomeArq);
      void gravarCandidatos(string nomeArq);
   public:
      ArqTextoCPP(string aNome, Eleicao& aConj);
      void ler();
      void gravar();
};

#endif