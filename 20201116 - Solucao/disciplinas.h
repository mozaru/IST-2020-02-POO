#ifndef _DISCIPLINAS_H_
#define _DISCIPLINAS_H_

#include<string>

using namespace std;

class Disciplina {
    private:
        int codigo;
        string nome, professor;
        int creditos, semestre, ano;
    public:
        Disciplina() { cout << "Criou Disciplina " << endl; }
        virtual ~Disciplina() { cout << "Destruiu Disciplina " << endl; }
        int getCodigo();
        string getNome();
        int getCreditos();
        int getSemestre();
        int getAno();
        virtual void ler();         //metodo virtual para serem refeitos nos descendentes
        virtual float media()=0;    // metodo abstrato - virtual puro
};

class Disciplina1 : public Disciplina
{
    protected:
        float nota1, nota2;
    public:
        Disciplina1() { cout << "Criou Disciplina 1" << endl; }
        virtual ~Disciplina1() { cout << "Destruiu Disciplina 1" << endl; }
        void ler();         
        virtual float media();      //metodo virtual para serem refeitos nos descendentes
};

class Disciplina2 : public Disciplina1
{
    public:
        float media();      //metodo virtual para serem refeitos nos descendentes
        Disciplina2() { cout << "Criou Disciplina 2" << endl; }
        virtual ~Disciplina2() { cout << "Destruiu Disciplina 2" << endl; }

};

class Disciplina3 : public Disciplina
{
    private:
        float nota_ap, nota_doc, nota_exec;
    public:
        Disciplina3() { cout << "Criou Disciplina 3" << endl; }
        virtual ~Disciplina3() { cout << "Destruiu Disciplina 3" << endl; }
        void ler();         
        float media();
};



class Historico {
    private:
        Disciplina* vet[5];
        int qtd;
        int obterIndice(int codigo);
    public:
        Historico();
        ~Historico();
        void inserir(Disciplina *d);
        bool existe(int codigo);
        void remover(int codigo);
        void alterar(int codigo, Disciplina* d);
        float cr(); 
        void listar();
        void historico();
};

#endif
