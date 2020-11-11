#ifndef _DISCIPLINAS_H_
#define _DISCIPLINAS_H_

#include<string>

using namespace std;

class Disciplina {
    private:
        int codigo;
        string nome, professor;
        int creditos, semestre,ano;
        float nota1, nota2;
    public:
        float media();
        int getCodigo();
        string getNome();
        int getCreditos();
        int getSemestre();
        int getAno();
        void ler();
};


class Historico {
    private:
        Disciplina vet[100];
        int qtd;
        int obterIndice(int codigo);
    public:
        Historico();
        void inserir(Disciplina d);
        bool existe(int codigo);
        void remover(int codigo);
        void alterar(int codigo, Disciplina d);
        float cr(); 
        void listar();
        void historico();
};

#endif
