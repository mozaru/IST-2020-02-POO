#include <string>
#include <iostream>

#include "eleitores.h"

using namespace std;

int main() {
	eleitores conj;
	int i,p,n;
	eleitor aux;
	string nome,candidato;
	
	cin >> n;
	cin.ignore();
	
	for(i=0; i<n;i++)
	{
	    aux.ler();
	    conj.inserir(aux);
	}
	
	cin >> n;
	cin.ignore();


    for(i=0;i<n;i++)
    {
        getline(cin, nome);
        getline(cin, candidato);
        p = conj.obterIndice(nome);
        if (p==-1)
            cout << "[" << nome << "] nao encontrado!" << endl;
        else if (conj.getPos(p).getVotou())
            cout << "[" << nome << "] ja votou!" << endl;
        else {
            eleitor x = conj.getPos(p);
            x.setVotou(true);
            conj.setPos(p, x);
        }
    }
    

    for(i=0; i<conj.getQtd();i++)
    {
	eleitor x = conj.getPos(i);
	cout << x.getNome() << " " << x.getIdade() << " " << (x.getVotou()?"votou":"nao votou") << endl;
    }
    return 0;
}
