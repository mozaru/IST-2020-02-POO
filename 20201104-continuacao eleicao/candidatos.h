#ifndef _CANDIDATOS_H_
#define _CANDIDATOS_H_

#include<string>

using namespace std;

#define _MAX_CANDIDATOS_ 100

class Candidato{
    private:
        string nome;
        int numero;
        string chapa;
        int votos;
    public:
        Candidato();
        Candidato(int aNumero, string aNome, string aChapa,int aVotos);
        string getNome();
        void setNome(string valor);
        string getChapa();
        void setChapa(string valor);
        int getNumero();
        void setNumero(int valor);
        int getVotos();
        void addVoto();
        void ler();
        void mostrar();
};

class Candidatos{
    private:
        Candidato vet[_MAX_CANDIDATOS_]; 
        int       qtd;
    public:
        Candidatos();
        void inserir(Candidato c);
        void remover(string nome);
        void remover(int numero);
        void alterar(string nome, Candidato c);
        void alterar(int numero, Candidato c);
        Candidato& obterCandidato(int pos);
        int obterIndice(string nome);
        int obterIndice(int numero);
        int obterQtd();
        void ordenar();
        void listar();
        void limpar();
};



#endif