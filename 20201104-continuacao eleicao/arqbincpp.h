#ifndef _ARQBINCPP_H_
#define _ARQBINCPP_H_

#include <string>
#include <fstream>
#include "eleicao.h"

class ArqBinCPP
{
   private:
      string nome;
      Eleicao *conj;
      void lerEleitores(string nomeArq);
      void lerCandidatos(string nomeArq);
      void gravarEleitores(string nomeArq);
      void gravarCandidatos(string nomeArq);
   public:
      ArqBinCPP(string aNome, Eleicao& aConj);
      void ler();
      void gravar();
};

#endif