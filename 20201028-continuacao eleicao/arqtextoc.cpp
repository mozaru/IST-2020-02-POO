
#include "arqtextoc.h"

#include <stdio.h>
#include <stdlib.h>

ArqTextoC::ArqTextoC(string aNome, Eleicao& aConj) {
    nome = aNome;
    conj = &aConj;
}

char* ArqTextoC::lerAte(FILE *arq, int max, char strDestino[])
{
    fgets(strDestino,max+1, arq);
    fgetc(arq);
    int tam = max;
    while (tam>0 && strDestino[tam-1]==' ')
    {
        strDestino[tam-1]='\0';
        tam--;
    }
    
    return strDestino;
}

void ArqTextoC::lerEleitores(string nomeArq)
{
    FILE *arq;
    arq = fopen(nomeArq.c_str(), "rt"); //w - escrita/criacao e t - textfile
    if (arq != NULL){
        char nome[30], cpf[20], email[50], votou;
        conj->getEleitores().limpar();
        while ( !feof(arq) )
        {
            Eleitor e;
            e.setNome(lerAte(arq, 30, nome));
            e.setCPF(lerAte(arq, 20, cpf));
            e.setEmail(lerAte(arq, 50, email));
            fscanf(arq, "%c\n",&votou);
            e.setVotou(votou=='S');
            conj->getEleitores().inserir(e);
        }
        fclose(arq);
    }
}

void ArqTextoC::lerCandidatos(string nomeArq)
{
    FILE *arq;
    arq = fopen(nomeArq.c_str(), "rt"); //w - escrita/criacao e t - textfile
    if (arq != NULL){
        char nome[30], chapa[20];
        int numero, votos;
        conj->getCandidatos().limpar();
        while ( !feof(arq) )
        {
            fscanf(arq, "%d", &numero);
            lerAte(arq, 30, nome);
            lerAte(arq, 20, chapa);
            fscanf(arq, "%d\n", &votos);
            Candidato c(numero, nome, chapa, votos);
            conj->getCandidatos().inserir(c);
        }
        fclose(arq);
    }
}
void ArqTextoC::gravarEleitores(string nomeArq)
{
    FILE *arq;
    arq = fopen(nomeArq.c_str(), "wt"); //w - escrita/criacao e t - textfile
    if (arq != NULL){
        for (int i=0; i<conj->getEleitores().getQtd(); i++)
        {
            Eleitor e = conj->getEleitores().getPos(i);
            fprintf(arq, "%-30s %-20s %-50s %c\n", e.getNome().c_str(), e.getCPF().c_str(), e.getEmail().c_str(), e.getVotou()?'S':'N');
        }    
        fclose(arq);
    }
}
void ArqTextoC::gravarCandidatos(string nomeArq)
{
    FILE *arq;
    arq = fopen(nomeArq.c_str(), "wt"); //w - escrita/criacao e t - textfile
    if (arq != NULL){
        for (int i=0; i<conj->getCandidatos().obterQtd(); i++)
        {
            Candidato c = conj->getCandidatos().obterCandidato(i);
            fprintf(arq, "%4d %-30s %-20s %4d\n", c.getNumero(), c.getNome().c_str(), c.getChapa().c_str(), c.getVotos());
        }    
        fclose(arq);
    }
}


void ArqTextoC::ler()
{
    lerCandidatos(nome+"_candidatos.txt");
    lerEleitores(nome+"_eleitores.txt");
}

void ArqTextoC::gravar()
{
    gravarCandidatos(nome+"_candidatos.txt");
    gravarEleitores(nome+"_eleitores.txt");
}