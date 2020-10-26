#include <iostream>
#include <string>
using namespace std;

#include"eleitores.h"

Eleitor::Eleitor()
{
   this->nome = "";
   this->email = "";
   this->cpf = "";
   votou = false;
}       
        
void   Eleitor::setNome(string valor)  { nome = valor;   }
void   Eleitor::setCPF(string valor)   { cpf = valor;    }
void   Eleitor::setEmail(string valor) { email = valor;  }
void   Eleitor::setVotou(bool valor)   { votou = valor;  }

string Eleitor::getNome()              { return nome;    }
string Eleitor::getCPF()               { return cpf;     }
string Eleitor::getEmail()             { return email;   }
bool   Eleitor::getVotou()             { return votou;   }
        
void Eleitor::mostrar()
{
   cout << "Nome:" << nome << endl;
   cout << "CPF:" << cpf << endl;
   cout << "Email:" << email << endl;
   cout << "Votou:" << votou << endl;
}
        
void Eleitor::ler()
{
    char letra;
    cout << "Nome:";      getline(cin, nome);
    cout << "CPF:";       getline(cin, cpf);
    cout << "Email:";     getline(cin, email);
    votou = false;
}


Eleitores::Eleitores()                         { qtd = 0;              } 
void Eleitores::inserir(Eleitor e)             { V[qtd] = e; qtd ++;   }
Eleitor Eleitores::getPos(int pos)             { return V[pos];        }
void Eleitores::setPos(int pos, Eleitor e)     { V[pos] = e;           }
int Eleitores::getQtd()                        { return qtd;           }

int Eleitores::obterIndice(string cpf)
{
    bool achou=false;
    int i=0;
    while (!achou && i<qtd)
    {
      cout << "[" << cpf << "]" << "   [" << V[i].getCPF() << "]" << endl;
      if (cpf == V[i].getCPF())
        achou = true;
      else
        i++;
    }
    return achou?i:-1;
    /*
    if (achou)
      return i;
    else
      return-1;
    */
}


