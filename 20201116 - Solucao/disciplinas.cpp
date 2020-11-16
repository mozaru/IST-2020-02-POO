#include<string>
#include<iostream>
#include<iomanip>

#include"disciplinas.h"

using namespace std;

int Disciplina::getCodigo()
{
    return codigo;
}
string Disciplina::getNome()
{
    return nome;
}
int Disciplina::getCreditos()
{
    return creditos;
}
int Disciplina::getSemestre()
{
    return semestre;
}

int Disciplina::getAno()
{
    return ano;
}

void Disciplina::ler()
{
    cout << "Codigo:";      cin >> codigo;              cin.ignore();
    cout << "Nome:";        getline(cin, nome);
    cout << "Professor:";   getline(cin, professor);
    cout << "Creditos:";    cin >> creditos;
    cout << "Semestre:";    cin >> semestre;
    cout << "Ano:";         cin >> ano;
}

void Disciplina1::ler()
{
    Disciplina::ler();
    cout << "Nota1:";       cin >> nota1;
    cout << "Nota2:";       cin >> nota2;
}

float Disciplina1::media()
{
    return (nota1 + nota2)/2;
}

float Disciplina2::media()
{
    return (nota1 + 2*nota2)/3;
}

void Disciplina3::ler()
{
    Disciplina::ler();
    cout << "Apresentacao:";       cin >> nota_ap;
    cout << "Documentacao:";       cin >> nota_doc;
    cout << "Pratica:";            cin >> nota_exec;
}

float Disciplina3::media()
{
    return (2*nota_ap + 3*nota_doc + 5*nota_exec)/10;
}

int Historico::obterIndice(int codigo)
{
    int i;
    bool achou;
    achou = false;
    i=0;
    while (!achou && i<qtd)
        if (vet[i]->getCodigo() == codigo)
            achou = true;
        else
            i++;
    return achou?i:-1;        
}

Historico::Historico()
{
    qtd = 0;
    cout << "Criou Historico" << endl;
}

Historico::~Historico()
{ 
    for(int i=0;i<qtd;i++)
        delete vet[i];
    cout << "Destruiu Historico" << endl; 
}


void Historico::inserir(Disciplina* d)
{
    vet[qtd]=d;
    qtd++;
}
bool Historico::existe(int codigo)
{
    return obterIndice(codigo)!=-1;
}
void Historico::remover(int codigo)
{
    int pos = obterIndice(codigo);
    if (pos>-1)
    {
        delete vet[pos];
        vet[pos] = vet[qtd-1];
        qtd--;
    }
}
void Historico::alterar(int codigo, Disciplina* d)
{
    int pos = obterIndice(codigo);
    if (pos>-1)
    {
        delete vet[pos];
        vet[pos] = d;
    }
}
float Historico::cr()
{
    float soma=0;
    int i, creditos = 0;
    for (i=0; i<qtd; i++)
    {
        soma += vet[i]->media() * vet[i]->getCreditos();
        creditos += vet[i]->getCreditos();
    }
    return creditos==0?0:soma/creditos;
}
void Historico::listar()
{
    int i;
    cout << setw(10) << left << "codigo" << " " << setw(30) << "nome" << " "  
            << setw(5) << "cred." << " " 
            << setw(4) << "sem." << " "
            << setw(4) << "ano " << " "
            << setw(5) << "media" << endl << right ;
    for (i=0; i<63; i++)
       cout << "-";
    cout << endl;
    for (i=0; i<qtd; i++)
    {
        Disciplina* d = vet[i];
        cout << setw(10) << d->getCodigo() << " " 
                << setw(30) << left << d->getNome() << " " 
                << setw(5) << right << d->getCreditos() << " " 
                << setw(4) << d->getSemestre() << " "
                << setw(4) << d->getAno() << " "
                << setw(5) << fixed << setprecision(2) << d->media() << endl;
    }
    for (i=0; i<63; i++)
       cout << "-";
    cout << endl;
}
void Historico::historico()
{
    listar();
    cout << "Coeficiente de Rendimento (CR): " << fixed << setprecision(2) << setw(5) << cr() << endl;
}
