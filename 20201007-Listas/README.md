# Lista por vetor

Lista é um TAD - é uma generalização da pilha e fila
  onde temos as seguintes as seguintes operacoes


* __vazia__ - informa se nao existem elementos na lista
* __cheia__ - informa se a lista esta na sua capacidade maxima
* __obterQtd__ - retorna o numero de elementos na lista
* __obterElemento(pos)__ - retorna o elemento da posicao pos na lista
         normalmente o primeiro esta na posicao pos
* __alterarElemento(pos)__ - permite alterar o valor do elemento na posicao pos da lista
* __obterIndice(info)__ - retorna o indice do elemento info na lista
* __existe(info)__ - retorna se a informacao info esta presente na lista
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

using namespace std;

#define _MAX_  100

typedef float TInfo;

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
      int obterIndice(TInfo info);
      bool existe(TInfo info);
      void inserirNoInicio(TInfo info);
      void inserirNoFinal(TInfo info);
      void inserirOrdenado(TInfo info);
      void inserir(int pos, TInfo info);
      void removerNoInicio();
      void removerNoFinal();
      void remover(TInfo info);
      void remover(int pos);
};

Lista::Lista()
{
   qtd=0;
}

bool Lista::vazia()
{
   return qtd==0;
}
bool Lista::cheia()
{
   return qtd == _MAX_;
}
int Lista::obterQtd()
{
   return qtd;
}

TInfo Lista::obterElemento(int pos)
{
   if (pos<0 || pos>=qtd)
   {
      cerr << "indice invalido no obterElemento" << endl;
      exit(0);
   }
   return v[pos];
}

void Lista::alterarElemento(int pos, TInfo info)
{
   if (pos<0 || pos>=qtd)
   {
      cerr << "indice invalido no obterElemento" << endl;
      exit(0);
   }
   v[pos] = info;
}

int Lista::obterIndice(TInfo info)
{
   bool achou=false;
   int i=0;
   while (!achou && i<qtd)
     if (info==v[i])
         achou = true;
     else
         i++;
   return achou?i:-1; 
}

bool Lista::existe(TInfo info)
{
   return obterIndice(info)!=-1;
}

void Lista::inserirNoInicio(TInfo info)
{
   if (cheia())
   {
      cerr << "lista cheia ao tentar inserir no inicio" << endl;
      exit(0);
   }
   else 
   {
      int i;
      for(i=qtd-1;i>=0;i--)
         v[i+1]=v[i];
      v[0] = info;
      qtd++;     
   }     
}

void Lista::inserirNoFinal(TInfo info)
{
   if (cheia())
   {
      cerr << "lista cheia ao tentar inserir no final" << endl;
      exit(0);
   }
   else 
   {
      v[qtd] = info;
      qtd++;     
   }     
}

void Lista::inserirOrdenado(TInfo info)
{
   if (cheia())
   {
      cerr << "lista cheia ao tentar inserir ordenado" << endl;
      exit(0);
   }
   else 
   {
      int i;
      i=qtd-1;
      while (i>=0 && v[i]>info)	
      {
         v[i+1]=v[i];
         i--;
      }
      v[i+1] = info;
      qtd++;     
   }     
}

void Lista::inserir(int pos, TInfo info)
{
   if (cheia())
   {
      cerr << "lista cheia ao tentar inserir" << endl;
      exit(0);
   }
   else 
   {
      int i;
      for(i=qtd-1;i>=pos;i--)
         v[i+1]=v[i];
      v[pos] = info;
      qtd++;     
   }     
}

void Lista::removerNoInicio()
{
   if (vazia())
   {
      cerr << "lista vazia ao tentar remover no inicio" << endl;
      exit(0);
   }
   else
   {
      int i;
      for (i=1;i<qtd;i++)
         v[i-1] = v[i];
      qtd--; 
   }
}

void Lista::removerNoFinal()
{
   if (vazia())
   {
      cerr << "lista vazia ao tentar remover no final" << endl;
      exit(0);
   }
   else
      qtd--; 
}

void Lista::remover(TInfo info)
{
   if (vazia())
   {
      cerr << "lista vazia ao tentar remover a informacao" << endl;
      exit(0);
   }
   else
   {
    	int pos = obterIndice(info);
	if (pos==-1)  
	{
      		cerr << "tentativa de remover uma informacao inexistente" << endl;
      		exit(0);
   	} 
        else
          remover(pos);
   }
}

void Lista::remover(int pos)
{
   if (vazia())
   {
      cerr << "lista vazia ao tentar remover na posicao" << endl;
      exit(0);
   }
   else
   {
      int i;
      for (i=pos+1;i<qtd;i++)
         v[i-1] = v[i];
      qtd--; 
   }
}

int main(void)
{
   Lista l;
   float n;
   cin >> n;
   while (n != 0)    
   {
      l.inserirOrdenado(n);
      cin >> n;
   }
 
   cout << "Quantidade: " << l.obterQtd() << endl;
   for(int i=0; i<l.obterQtd();i++)
     cout << "posicao: " << i << " valor:" << l.obterElemento(i) << endl;
   
   cin >> n;   
   while (n != 0)    
   {
      if (l.existe(n)) {
        cout << "existe e será removido" << endl;
        l.remover(n);
      }
      else
        cout << "NAO ENCONTRADO!" << endl;
      cin >> n;
   }

   cout << "Quantidade: " << l.obterQtd() << endl;
   for(int i=0; i<l.obterQtd();i++)
     cout << "posicao: " << i << " valor:" << l.obterElemento(i) << endl;
   
   return 0;	 
}

~~~


faça uma agenda de contatos com menu e as seguintes operações
1. inserir
2. remover
3. alterar
4. listar todos
5. listar filtrando por parte do nome ou telefone
6. sair

na agenda cada contato tem nome e telefone somente.



