#include"eleicao.h"

#include <iostream>
#include <iomanip>

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
    cout << setw(4) << "#" << " " << setw(4) << "Num." << " "  << setw(30) << left << "Nome" << " " << setw(20) << "CHAPA" << " " << setw(5) << right << "VOTOS " << endl;
    for(int i=0;i<67;i++)
        cout << '-';
    cout << endl;
    for (int i=0;i<candidatos.obterQtd();i++)
    {
        Candidato c = candidatos.obterCandidato(i);
        cout << setw(4) << (i+1) << " " << 
                setw(4) << c.getNumero() << " " << 
                setw(30) << left << c.getNome() << " " << 
                setw(20) << c.getChapa() << " " << 
                setw(5) << right << c.getVotos() << endl;
    }
    for(int i=0;i<67;i++)
        cout << '-';
    cout << endl;
}