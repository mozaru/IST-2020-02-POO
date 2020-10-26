#ifndef _ELEICAO_H_
#define _ELEICAO_H_

#include "candidatos.h"
#include "eleitores.h"

enum EstadoEleicao { Desconhecido, Preparacao, Iniciada, Encerrada };

class Eleicao{
    private: 
        Candidatos c;
        Eleitores  e;
        EstadoEleicao estado;
    public:
        Eleicao();
        EstadoEleicao getEstado();
        void iniciarProcesso();
        void iniciarVotacao();
        void encerrarVotacao();
        Candidatos getCandidatos();
        Eleitores getEleitores();
        void votar(string cpf, int numero);
        void listarResultado();
};

#endif
