#include"eleicao.h"

#include <iostream>

#include "candidatos.h"
#include "eleitores.h"

using namespace std;

Eleicao::Eleicao()                              { estado = Preparacao;  }
EstadoEleicao Eleicao::getEstado()              { return estado;        }
void Eleicao::iniciarProcesso()                 { estado = Preparacao;  }
void Eleicao::iniciarVotacao()                  { estado = Iniciada;    }
void Eleicao::encerrarVotacao()                 { estado = Encerrada;   }
todo: as duas linhas abaixo nao funcionam
      explicar na proxima aula.
Candidatos Eleicao::getCandidatos()             { return c;             }
Eleitores Eleicao::getEleitores()               { return e;             }
void Eleicao::votar(string cpf, int numero)
{
    int pos = getEleitores().obterIndice(cpf);
    if (pos >= 0 )
        getEleitores().getPos(pos).setVotou(true);
    
    pos = getCandidatos().obterIndice(numero);
    if (pos >= 0)
        getCandidatos().obterCandidato(pos).addVoto();
}


void Eleicao::listarResultado(){
    getCandidatos().ordenar();
    for(int i=0; i< getCandidatos().obterQtd(); i++)
    {
        Candidato c = getCandidatos().obterCandidato(i);
        cout << (i+1) << " - " << 
                c.getNumero() << "\t" << 
                c.getNome() << "\t" << 
                c.getChapa() << "\t" << 
                c.getVotos() << endl; 
    }
}