#include <iostream>
#include <iomanip>
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
Eleitor& Eleitores::getPos(int pos)            { return V[pos];        }
void Eleitores::setPos(int pos, Eleitor e)     { V[pos] = e;           }
int Eleitores::getQtd()                        { return qtd;           }
void Eleitores::limpar()                       { qtd = 0;              }

int Eleitores::obterIndice(string cpf)
{
    bool achou=false;
    int i=0;
    while (!achou && i<qtd)
    {
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

void Eleitores::remover(string cpf)
{
    int pos = obterIndice(cpf);
    if (pos>-1)
    {
      V[pos] = V[qtd-1];
      qtd--;
    }
}

void Eleitores::alterar(string cpf, Eleitor e)
{
    int pos = obterIndice(cpf);
    if (pos>-1)
      V[pos] = e;
}


void Eleitores::listar()
{
   int i=0;
   cout << setw(4) << "#" << " " << setw(30) << left << "Nome" << " " << setw(20) << "CPF" << " " << setw(50) << "EMAIL" << " " << setw(5) << "VOTOU" << right << endl;
   for(i=0;i<113;i++)
    cout << '-';
   cout << endl;

   for (i=0;i<qtd;i++)
   {
      Eleitor e = V[i];
      cout <<setw(4) << i << " " << setw(30) << left <<  e.getNome() << " " << setw(20) << e.getCPF() << " " << setw(50) << e.getEmail() << " " << (e.getVotou()?" Sim ":" Nao ") << right << endl;
   }

   for(i=0;i<113;i++)
    cout << '-';
   cout << endl;
}

