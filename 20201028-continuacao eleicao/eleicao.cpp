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
//todo: as duas linhas abaixo nao funcionam
//      explicar na proxima aula.

Candidatos& Eleicao::getCandidatos()             { return candidatos;    }
Eleitores& Eleicao::getEleitores()               { return eleitores;     }

void Eleicao::votar(string cpf, int numero)
{
    int pos = eleitores.obterIndice(cpf);
    if (pos >= 0 )
        eleitores.getPos(pos).setVotou(true);
    
    pos = candidatos.obterIndice(numero);
    if (pos >= 0)
        candidatos.obterCandidato(pos).addVoto();
}


void Eleicao::listarResultado(){
    candidatos.ordenar();
    for(int i=0; i< candidatos.obterQtd(); i++)
    {
        Candidato c = candidatos.obterCandidato(i);
        cout << (i+1) << " - " << 
                c.getNumero() << "\t" << 
                c.getNome() << "\t" << 
                c.getChapa() << "\t" << 
                c.getVotos() << endl; 
    }
}