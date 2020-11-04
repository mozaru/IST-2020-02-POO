#ifndef _ELEITORES_H_
#define _ELEITORES_H_

#include<string>

using namespace std;

class Eleitor{
    private:
        string nome,cpf,email;
        bool votou;
    public:
        Eleitor();
        void setNome(string valor);
        void setCPF(string valor);
        void setEmail(string valor);
        void setVotou(bool valor);
        string getNome();
        string getCPF();
        string getEmail();
        bool   getVotou();
        void mostrar();
        void ler();
};


class Eleitores
{
    private:
        Eleitor V[100];
        int     qtd;
    
    public:
        Eleitores();
        void inserir(Eleitor e);
        void remover(string cpf);
        void alterar(string cpf, Eleitor e);
        int obterIndice(string cpf);
        Eleitor& getPos(int pos);
        void setPos(int pos, Eleitor e);
        int getQtd();
        void listar();
        void limpar();
};

#endif