#include<iostream>
#include<string>

using namespace std;

const float PI=3.141592f;

class FormaGeo
{  
   private:
      static int cont; //static diz que a variavel cont é da classe e nao do objeto
   public:
      FormaGeo()   {  cont++; cout << cont << endl; } 
      virtual void  Ler() = 0;
      virtual float Area() = 0;
      virtual string GetNome() = 0;
};
int FormaGeo::cont = 0;

class Quadrado : public FormaGeo
{
   private:
      float lado;
   public:
      void  Ler();
      float Area();
      string GetNome();
};

class Circulo : public FormaGeo
{
   private:
      float raio;
   public:
      void  Ler();
      float Area();
      string GetNome();
};

class Retangulo : public FormaGeo
{
   private:
      float base,altura;
   public:
      void  Ler();
      float Area();
      string GetNome();
};


class FormasGeo
{
   private:
      FormaGeo* vet[100];
      int      qtd;
      FormaGeo* CriarForma(char Letra);
   public:
      FormasGeo();
      virtual ~FormasGeo();
      void Ler();
      void Listar();
};

string Quadrado::GetNome()
{
    return "Quadrado";
}

void  Quadrado::Ler()
{
    //FormaGeo::Ler();
    cout << "Entre com o tamanho do lado do quadrado:";
    cin >> lado;
}

float Quadrado::Area()
{
    return lado * lado;	
}

string Circulo::GetNome()
{
    return "Circulo";
}

void  Circulo::Ler()
{
    //FormaGeo::Ler();
    cout << "Entre com o tamanho do raio do circulo:";
    cin >> raio;
}

float Circulo::Area()
{
    return raio * raio * PI;	
}


string Retangulo::GetNome()
{
    return "Retangulo";
}

void  Retangulo::Ler()
{
    //FormaGeo::Ler();
    cout << "Entre com o tamanho da base do retangulo:";
    cin >> base;
    cout << "Entre com o tamanho da altura do retangulo:";
    cin >> altura;
}

float Retangulo::Area()
{
    return base * altura;	
}


//method factory - design pattern
FormaGeo* FormasGeo::CriarForma(char Letra)
{
   switch( Letra )
   {
      case 'C': case 'c':  return new Circulo();
      case 'R': case 'r':  return new Retangulo();
      case 'Q': case 'q':  return new Quadrado();
      default           :  return NULL;	 
   }
}

FormasGeo::FormasGeo()
{
   qtd = 0;
}
FormasGeo::~FormasGeo()
{
   for(int i=0;i<qtd;i++)
      delete vet[i];
   qtd = 0;	
}

void FormasGeo::Ler()
{
   char L;
   qtd = 0;   
   do {
     cout << "(Q)uadrado" << endl << "(C)irculo" << endl << "(R)etangulo" << endl << "(E)ncerrar" << endl; 
     cout << "Entre a sua escolha:";
     cin >> L;
     cin.ignore();
     vet[qtd] = CriarForma(L); 
     if (vet[qtd]!=NULL)
     {
       //(*vet[qtd]).Ler();
       vet[qtd]->Ler();
       qtd++;
     }
   } while (L!='E' && L!='e');
}

void FormasGeo::Listar()
{
   for(int i=0;i<qtd;i++)
   { 
      FormaGeo *f = vet[i];
      cout << f->GetNome() << "\t" << f->Area() << endl;
   }
   system("pause");      
}


int main(void)
{
   FormasGeo formas;
 
   formas.Ler();  
   formas.Listar();

   return 0;
}