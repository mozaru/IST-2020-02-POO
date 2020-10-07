# Lista por vetor

Lista é um TAD - é uma generalização da pilha e fila
  onde temos as seguintes as seguintes operacoes


* __vazia__ - informa se nao existem elementos na lista
* __cheia__ - informa se a lista esta na sua capacidade maxima
* __obterQtd__ - retorna o numero de elementos na lista
* __obterElemento(pos)__ - retorna o elemento da posicao pos na lista
         normalmente o primeiro esta na posicao pos
* __alterarElemento(pos)__ - permite alterar o valor do elemento na posicao pos da lista
* __inserir__ - inserir um elemento na lista
    * __inserirNoInicio__ -> insere no inicio
    * __inserirNoFinal__ -> insere no final
    * __inserirOrdenado__ -> insere mantendo a ordenação da lista
    * __inserir(pos)__ -> insere na posicao pos
* __remover__ - remover um elemento da lista
    * __removerNoInicio__ -> remove o primeiro
    * __removerNoFinal__  -> remove o ultimo
    * __remover(info)__   -> remove o elemento com a informacao info
    * __remover(pos)__    -> remove o elemento na posicao pos da lista


implementar uma lista de reais em cpp

~~~CPP
#include<iostream>
#include<iomanip>

#define _MAX_  100
typedefe float TInfo;

class Lista
{
   private:
      TInfo v[_MAX_];
      int   qtd;
   public:
      Lista();
      bool vazia();
      bool cheia();
      int  obterQtd();
      TInfo obterElemento(int pos); 
      void alterarElemento(int pos, TInfo info);
      void inserirNoInicio(TInfo info);
      void inserirNoFinal(TInfo info);
      void inserirOrdenado(TInfo info);
      void inserir(int pos, TInfo info);
      void removerNoInicio();
      void removerNoFinal();
      void remover(TInfo info);
      void remover(int pos);
};


~~~



