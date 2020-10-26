#include <string>
#include <iostream>

#include <stdlib.h>
#include <stdio.h>

#include "eleitores.h"
#include "candidatos.h"
#include "eleicao.h"

using namespace std;

void limparTela()
{
    system("cls");
}

void pausar()
{
    cout << "\n\n";
    system("pause");
}

int menu(EstadoEleicao estado){
    int opc,max;
    do{
        limparTela();
        switch(estado)
        {
            case Preparacao:
                printf("1. inserir aluno\n");
                printf("2. remover aluno\n");
                printf("3. alterar aluno\n");
                printf("4. listar alunos\n");
                printf("5. inserir candidato\n");
                printf("6. remover candidato\n");
                printf("7. alterar candidato\n");
                printf("8. listar candidatos\n");
                printf("9. iniciar votacao\n");
                printf("0. sair\n");
                max = 9;
                break;
            case Iniciada:
                printf("1. realizar voto\n");
                printf("2. encerrar votacao\n");
                printf("0. sair\n");
                max = 2;
                break;
            case Encerrada:
                printf("1. listar resultado\n");
                printf("2. iniciar novo processo\n");
                printf("0. sair\n");
                max = 2;
                break;
            default:
                printf("1. iniciar novo processo\n");
                printf("0. sair\n");
                max = 2;
        }
        cout << endl << endl << "Entre com a sua opcao:";
        cin >> opc;
    }while (opc<0 && opc>max);
    if (opc>0)
        opc = estado*10+opc;
    cin.ignore();
    return opc;
}




int main() {
	Eleitor eAux;
    Candidato cAux;
    Eleicao eleicao;    
	string aux;
    int numero, pos;
    char letra;
    bool acabou = false;

    while (!acabou)
    {
        switch( menu (eleicao.getEstado()) )
        {
            case 0:
                acabou = true;
                break;
            case 1: case 32:                //iniciar novo processo
                eleicao.iniciarProcesso();
                break;
            case 31:                        //1. listar resultado
                break;
            case 21:                        //1. realizar voto
                limparTela();
                cout << "Entre com o CPF do eleitor!" << endl;
                cout << "CPF:";
                getline(cin, aux);
                pos = eleicao.getEleitores().obterIndice(aux);
                if (pos == -1)
                    cout << "Eleitor nao cadastrado!" << endl;
                else {
                    eAux = eleicao.getEleitores().getPos(pos);
                    if (eAux.getVotou())
                        cout << "Eleitor ja votou!" << endl;
                    else {
                        do{
                            limparTela();
                            eAux.mostrar();
                            cout << "Entre com o numero do candidato:";    
                            cin >> numero;
                            if (numero <= 0)
                                cout << "Voto em branco";
                            else {
                                pos = eleicao.getCandidatos().obterIndice(numero);
                                if (pos < 0)
                                    cout << "Voto nulo!" << endl;
                                else 
                                    eleicao.getCandidatos().obterCandidato(pos).mostrar();
                            }
                            cout << endl << "CONFIMA? S/N" << endl;
                            do {
                                letra = getchar();
                            } while (letra !='S' && letra!='s' && letra !='N' && letra!='n');
                        } while (letra != 'S' && letra !='s');
                        eleicao.votar(eAux.getCPF(), numero);
                    }
                }
                pausar();
                break;
            case 22:                        //2. encerrar votacao
                eleicao.encerrarVotacao();
                break;
            case 11:                        //1. inserir aluno
                limparTela();
                cout << "Entre com os dados do eleitor" << endl;
                eAux.ler();
                eleicao.getEleitores().inserir(eAux);
                cout << "Inserido com sucesso!";
                pausar();
                break;
            case 12:                        //2. remover aluno
                break;
            case 13:                        //3. alterar aluno
                break;
            case 14:                        //4. listar alunos
                break;
            case 15:                        //5. inserir candidato
                limparTela();
                cout << "Entre com os dados do candidato" << endl;
                cAux.ler();
                eleicao.getCandidatos().inserir(cAux);
                cout << "Inserido com sucesso!";
                pausar();
                break;
            case 16:                        //6. remover candidato
                break;
            case 17:                        //7. alterar candidato
                break;
            case 18:                        //8. listar candidatos
                break;
            case 19:                        //9. iniciar votacao
                eleicao.iniciarVotacao();
                break;
        }
    }
    return 0;
}
