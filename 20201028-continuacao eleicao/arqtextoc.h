#ifndef _ARQTEXTOC_H_
#define _ARQTEXTOC_H_

#include <string>
#include "eleicao.h"

class ArqTextoC
{
   private:
      string nome;
      Eleicao *conj;
      char* lerAte(FILE *arq, int max, char strDestino[]);
      void lerEleitores(string nomeArq);
      void lerCandidatos(string nomeArq);
      void gravarEleitores(string nomeArq);
      void gravarCandidatos(string nomeArq);
   public:
      ArqTextoC(string aNome, Eleicao& aConj);
      void ler();
      void gravar();
};

#endif