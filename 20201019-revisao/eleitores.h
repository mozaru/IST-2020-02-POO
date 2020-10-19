#ifndef _ELEITORES_H_
#define _ELEITORES_H_

#include<string>

using namespace std;

class eleitor{
    private:
        string nome;
        int idade;
        bool votou;

    public:
        eleitor();
        void setNome(string valor);
        void setIdade(int valor);
        void setVotou(bool valor);
        string getNome();
        int    getIdade();
        bool   getVotou();
        void mostrarDados();
        void ler();
};


class eleitores
{
    private:
        eleitor V[100];
        int     qtd;
    
    public:
        eleitores();
        void inserir(eleitor e);
        int obterIndice(string nome);
        eleitor getPos(int pos);
        void setPos(int pos, eleitor e);
        int getQtd();
};

#endif