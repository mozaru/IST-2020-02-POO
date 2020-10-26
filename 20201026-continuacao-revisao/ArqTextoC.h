#ifndef _ARQTEXTOC_H_
#define _ARQTEXTOC_H_

#include <string>
#include "eleitores.h"

class ArqTextoC
{
   private:
      string nome;
      eleitores *conj;
   public:
      ArqTextoC(string aNome, eleitroes *aConj);
      void ler();
      void gravar();
};


#endif