#ifndef _ELEICAO_H_
#define _ELEICAO_H_

#include "candidatos.h"
#include "eleitores.h"

enum EstadoEleicao { Desconhecido, Preparacao, Iniciada, Encerrada };

class Eleicao{
    private: 
        Candidatos candidatos;
        Eleitores  eleitores;
        EstadoEleicao estado;
    public:
        Eleicao();
        EstadoEleicao getEstado();
        void iniciarProcesso();
        void iniciarVotacao();
        void encerrarVotacao();
        Candidatos& getCandidatos();
        Eleitores& getEleitores();
        void votar(string cpf, int numero);
        void listarResultado();
};

#endif
