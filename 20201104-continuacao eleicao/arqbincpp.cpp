
#include "arqbincpp.h"

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string.h>

using namespace std;

struct RegCandidato{
    int numero;
    char nome[30];
    char chapa[20];
    int votos;
};

struct RegEleitor{
    char nome[30];
    char cpf[30];
    char email[50];
    int votou;
};

ArqBinCPP::ArqBinCPP(string aNome, Eleicao& aConj) {
    nome = aNome;
    conj = &aConj;
}

string trim(string &strDestino)
{
    int tam = strDestino.length();
    while (tam>0 && strDestino[tam-1]==' ')
    {
        strDestino[tam-1]='\0';
        tam--;
    }
    
    return strDestino;
}

void ArqBinCPP::lerEleitores(string nomeArq)
{
    ifstream arq;
    arq.open(nomeArq.c_str());
    if (arq.is_open()){
        conj->getEleitores().limpar();
        RegEleitor r;
        arq.seekg(0, ios_base::end);    //posicionar no final
        int qtd = arq.tellg() / sizeof(RegEleitor); //calcular a qtd de registros
        arq.seekg(0, ios_base::beg);    //posicionar no inicio
        for(int i=0;i<qtd;i++)
        {
            Eleitor e;
            arq.read( (char *)&r, sizeof(RegEleitor) );
            e.setNome(r.nome);
            e.setCPF(r.cpf);
            e.setEmail(r.email);
            e.setVotou(r.votou);
            conj->getEleitores().inserir(e);
        }
        arq.close();
    }
}

void ArqBinCPP::lerCandidatos(string nomeArq)
{
    ifstream arq;
    arq.open(nomeArq.c_str());
    if (arq.is_open()){
        conj->getCandidatos().limpar();
        RegCandidato r;
        while ( !arq.read( (char *)&r, sizeof(RegCandidato) ).eof() )
        {
            Candidato c(r.numero, r.nome, r.chapa, r.votos);
            conj->getCandidatos().inserir(c);
        }
        arq.close();
    }
}
void ArqBinCPP::gravarEleitores(string nomeArq)
{
    ofstream arq;
    arq.open(nomeArq.c_str(), ofstream::out|ofstream::trunc);
    if (arq.is_open()){
        for (int i=0; i<conj->getEleitores().getQtd(); i++)
        {
            Eleitor e = conj->getEleitores().getPos(i);
            RegEleitor r;
            strcpy(r.nome, e.getNome().c_str());
            strcpy(r.cpf, e.getCPF().c_str());
            strcpy(r.email, e.getEmail().c_str());
            r.votou = e.getVotou();
            arq.write( (char*)&r, sizeof(RegEleitor));
        }    
        arq.close();
    }
}
void ArqBinCPP::gravarCandidatos(string nomeArq)
{
    ofstream arq;
    arq.open(nomeArq.c_str(), ofstream::out|ofstream::trunc); //w - escrita/criacao
    if (arq.is_open()){
        for (int i=0; i<conj->getCandidatos().obterQtd(); i++)
        {
            Candidato c = conj->getCandidatos().obterCandidato(i);
            RegCandidato r;
            strcpy(r.nome, c.getNome().c_str());
            strcpy(r.chapa, c.getChapa().c_str());
            r.numero = c.getNumero();
            r.votos = c.getVotos();
            arq.write( (char*)&r, sizeof(RegCandidato));
        }    
        arq.close();
    }
}


void ArqBinCPP::ler()
{
    lerCandidatos(nome+"_candidatos.bin");
    lerEleitores(nome+"_eleitores.bin");
}

void ArqBinCPP::gravar()
{
    gravarCandidatos(nome+"_candidatos.bin");
    gravarEleitores(nome+"_eleitores.bin");
}