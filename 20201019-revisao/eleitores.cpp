#include <iostream>
#include <string>
using namespace std;

#include"eleitores.h"


eleitor::eleitor()
{
   this->nome = "";
   this->idade = 0;
   votou = false;
}       
        
void   eleitor::setNome(string valor)  { nome = valor;  }
void   eleitor::setIdade(int valor)    { idade = valor; }
void   eleitor::setVotou(bool valor)   { votou = valor; }

string eleitor::getNome()              { return nome;   }
int    eleitor::getIdade()             { return idade;  }
bool   eleitor::getVotou()             { return votou;  }
        
void eleitor::mostrarDados()
{
   cout << "Nome:" << nome << endl;
   cout << "Idade:" << idade << endl;
   cout << "Votou:" << votou << endl;
}
        
void eleitor::ler()
{
   char letra;
   getline(cin, nome);
   cin >> idade;       cin.ignore();
   cin >> letra;       cin.ignore();
   votou = letra=='v';
}


eleitores::eleitores()                         { qtd = 0;              } 
void eleitores::inserir(eleitor e)             { V[qtd] = e; qtd ++;   }
eleitor eleitores::getPos(int pos)             { return V[pos];        }
void eleitores::setPos(int pos, eleitor e)     { V[pos] = e;           }
int eleitores::getQtd()                        { return qtd;           }

int eleitores::obterIndice(string nome)
{
    bool achou=false;
    int i=0;
    while (!achou && i<qtd)
      if (nome == V[i].getNome())
        achou = true;
      else
        i++;
    return achou?i:-1;
    /*
    if (achou)
      return i;
    else
      return-1;
    */
}


