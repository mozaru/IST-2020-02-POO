#include "candidatos.h"
#include<string>
#include<iostream>
#include<iomanip>
#include<bits/stdc++.h> 

using namespace std;

//------------------ candidato -------------------------------
Candidato::Candidato()                  { votos = 0;        }
string Candidato::getNome()             { return nome;      }
void Candidato::setNome(string valor)   { nome = valor;     }
string Candidato::getChapa()            { return chapa;     }
void Candidato::setChapa(string valor)  { chapa = valor;    }
int Candidato::getNumero()              { return numero;    }
void Candidato::setNumero(int valor)    { numero = valor;   }
int Candidato::getVotos()               { return votos;     }
void Candidato::addVoto()               { votos++;          }

Candidato::Candidato(int aNumero, string aNome, string aChapa,int aVotos)
{
    numero = aNumero;
    nome = aNome;
    chapa = aChapa;
    votos = aVotos;
}

void Candidato::ler(){
    cout <<"Nome:";         getline(cin, nome);
    cout <<"Chapa:";        getline(cin, chapa);
    cout <<"Numero:";       cin >> numero;
}

void Candidato::mostrar(){
    cout <<"Nome:" << nome<< endl;
    cout <<"Chapa:" << chapa << endl;
    cout <<"Numero:" << numero << endl;
}


//------------------ candidatos -------------------------------    
Candidatos::Candidatos() {
    qtd = 0;
}

void Candidatos::inserir(Candidato c) {
    vet[qtd] = c;
    qtd++;
}

void Candidatos::limpar() { 
    qtd = 0;              
}

void Candidatos::remover(string nome){
    int pos = obterIndice(nome);
    if (pos>-1)
    {
        vet[pos] = vet[qtd-1];
        qtd--;
    }
}

void Candidatos::remover(int numero)
{
    int pos = obterIndice(numero);
    if (pos>-1)
    {
      vet[pos] = vet[qtd-1];
      qtd--;
    }
}

void Candidatos::alterar(int numero, Candidato c)
{
    int pos = obterIndice(numero);
    if (pos>-1)
      vet[pos] = c;
}

void Candidatos::alterar(string nome, Candidato c){
    int pos = obterIndice(nome);
    if (pos>-1)
    {
        vet[pos] = c;
    }
}

Candidato& Candidatos::obterCandidato(int pos){
    return vet[pos];
}

int Candidatos::obterQtd(){
    return qtd;
}

int Candidatos::obterIndice(string nome){
    int i = 0;
    bool achou=false;
    while (!achou && i<qtd)
        if (vet[i].getNome()==nome)
            achou = true;
        else
            i++;        
    return achou?i:-1;
}

int Candidatos::obterIndice(int numero){
    int i = 0;
    bool achou=false;
    while (!achou && i<qtd)
        if (vet[i].getNumero()==numero)
            achou = true;
        else
            i++;        
    return achou?i:-1;
}

bool comp(Candidato a, Candidato b){
    return a.getVotos() > b.getVotos();
}

void Candidatos::ordenar()
{
    sort(vet, vet+qtd, comp);
}

void Candidatos::listar()
{
   int i=0;
   cout << setw(4) << "#" << " " << setw(4) << "Num." << " "  << setw(30) << left << "Nome" << " " << setw(20) << "CHAPA" << " " << setw(5) << right << "VOTOS " << endl;
   for(i=0;i<67;i++)
    cout << '-';
   cout << endl;
   for (i=0;i<qtd;i++)
   {
      Candidato c = vet[i];
      cout << setw(4) << i << " " << setw(4) << c.getNumero() << " " << setw(30) << left << c.getNome() << " " << setw(20) << c.getChapa() << " " << setw(5) <<  right << c.getVotos() << endl;
   }
   for(i=0;i<67;i++)
    cout << '-';
   cout << endl;
}
