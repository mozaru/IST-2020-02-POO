#include<iostream>
#include<stdlib.h>
#include "disciplinas.h"

using namespace std;

int menu()
{
    int opc;
    do{
        //system("cls");
        cout << "1 - inserir" << endl
             << "2 - remover" << endl
             << "3 - alterar" << endl
             << "4 - historico" << endl
             << "5 - sair" << endl
             << endl << endl << "Entre com uma das opcoes:";
        cin >> opc;
    }while (opc<1 || opc>5);
    cin.ignore();
    //system("cls");
    return opc;
}

Disciplina *criarDisciplina()
{
    int opc;
    do{
        //system("cls");
        cout << "1 - Disciplina do Tipo 1" << endl
             << "2 - Disciplina do Tipo 2" << endl
             << "3 - Disciplina do Tipo 3" << endl
             << "4 - Voltar" << endl
             << endl << endl << "Entre com uma das opcoes:";
        cin >> opc;
    }while (opc<1 || opc>4);
    switch (opc)
    {
        case 1: return new Disciplina1();
        case 2: return new Disciplina2;
        case 3: return new Disciplina3;
        default: return NULL;
    }
}


int main()
{
    Historico   hist;
    Disciplina* disc;
    int         cod;
    bool        fim;
    fim = false;
    while  (!fim)
    {
        switch(menu())
        {
            case 1: //inserir
                disc = criarDisciplina();
                if (disc != NULL)
                {
                    disc->ler();
                    hist.inserir(disc);
                    cout << "Inserido com sucesso!" << endl;
                    system("pause");
                }
                break;
            case 2: //remover
                cout << "entre com o codigo da disciplina a remover:";
                cin >> cod;
                if (hist.existe(cod))
                {
                    hist.remover(cod);
                    cout << "Removido com sucesso!" << endl;
                }
                else
                    cout << "Codigo nao encontrado!" << endl;
                system("pause");
                break;
            case 3: //alterar
                cout << "entre com o codigo da disciplina a alterar:";
                cin >> cod;
                if (hist.existe(cod))
                {
                    disc = criarDisciplina();
                    if (disc!=NULL)
                    {
                        disc->ler();
                        hist.alterar(cod, disc);
                        cout << "Alterado com sucesso!" << endl;
                    }
                }
                else
                    cout << "Codigo nao encontrado!" << endl;
                system("pause");
                break;
            case 4: //historico
                hist.historico();
                system("pause");
                break;
            case 5: //sair
                fim = true;
                break;
        }
    }
    return 0;
}


