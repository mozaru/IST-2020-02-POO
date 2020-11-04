gcc -c eleitores.cpp -o eleitores.o
gcc -c candidatos.cpp -o candidatos.o
gcc -c eleicao.cpp -o eleicao.o
gcc -c principal.cpp -o principal.o
gcc -c arqtextoc.cpp -o arqtextoc.o
gcc -c arqtextocpp.cpp -o arqtextocpp.o
gcc -c arqbincpp.cpp -o arqbincpp.o

gcc eleitores.o candidatos.o eleicao.o principal.o arqbincpp.o arqtextocpp.o arqtextoc.o -o voto.exe -lstdc++
