
#include "arqtextocpp.h"

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

ArqTextoCPP::ArqTextoCPP(string aNome, Eleicao& aConj) {
    nome = aNome;
    conj = &aConj;
}

char* ArqTextoCPP::lerAte(ifstream &arq, int max, char strDestino[])
{

    arq.get(strDestino, max+1);
    arq.ignore();
    int tam = max;
    while (tam>0 && strDestino[tam-1]==' ')
    {
        strDestino[tam-1]='\0';
        tam--;
    }
    
    return strDestino;
}

void ArqTextoCPP::lerEleitores(string nomeArq)
{
    ifstream arq;
    arq.open(nomeArq.c_str());
    if (arq.is_open()){
        char nome[30], cpf[20], email[50], votou;
        conj->getEleitores().limpar();
        lerAte(arq, 30, nome);
        while ( !arq.eof() )
        {
            Eleitor e;
            e.setNome(nome);
            e.setCPF(lerAte(arq, 20, cpf));
            e.setEmail(lerAte(arq, 50, email));
            arq >> votou;
            arq.ignore();
            e.setVotou(votou=='S');
            conj->getEleitores().inserir(e);
            lerAte(arq, 30, nome);
        }
        arq.close();
    }
}

void ArqTextoCPP::lerCandidatos(string nomeArq)
{
    ifstream arq;
    arq.open(nomeArq.c_str());
    if (arq.is_open()){
        char nome[30], chapa[20];
        int numero, votos;
        conj->getCandidatos().limpar();
        arq >> numero;
        while ( !arq.eof() )
        {
            arq.ignore();
            lerAte(arq, 30, nome);
            lerAte(arq, 20, chapa);
            arq >> votos;
            arq.ignore();
            Candidato c(numero, nome, chapa, votos);
            conj->getCandidatos().inserir(c);
            arq >> numero;
        }
        arq.close();
    }
}
void ArqTextoCPP::gravarEleitores(string nomeArq)
{
    ofstream arq;
    arq.open(nomeArq.c_str(), ofstream::out|ofstream::trunc);
    if (arq.is_open()){
        for (int i=0; i<conj->getEleitores().getQtd(); i++)
        {
            Eleitor e = conj->getEleitores().getPos(i);
            arq << left << setw(30) << e.getNome() << " "
                << setw(20) << e.getCPF() << " "
                << setw(50) << e.getEmail() << " "
                << (e.getVotou()?'S':'N') << endl;
        }    
        arq.close();
    }
}
void ArqTextoCPP::gravarCandidatos(string nomeArq)
{
    ofstream arq;
    arq.open(nomeArq.c_str(), ofstream::out|ofstream::trunc); //w - escrita/criacao
    if (arq.is_open()){
        for (int i=0; i<conj->getCandidatos().obterQtd(); i++)
        {
            Candidato c = conj->getCandidatos().obterCandidato(i);
            arq << setw(4) << c.getNumero() << " " 
                << left << setw(30) << c.getNome() << " "
                << setw(20) << c.getChapa() << " "
                << right << setw(4) << c.getVotos() << endl;
        }    
        arq.close();
    }
}


void ArqTextoCPP::ler()
{
    lerCandidatos(nome+"_candidatos.txt");
    lerEleitores(nome+"_eleitores.txt");
}

void ArqTextoCPP::gravar()
{
    gravarCandidatos(nome+"_candidatos.txt");
    gravarEleitores(nome+"_eleitores.txt");
}