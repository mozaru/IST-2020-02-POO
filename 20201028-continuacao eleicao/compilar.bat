gcc -c eleitores.cpp -o eleitores.o
gcc -c candidatos.cpp -o candidatos.o
gcc -c eleicao.cpp -o eleicao.o
gcc -c principal.cpp -o principal.o
gcc -c arqtextoc.cpp -o arqtextoc.o

gcc eleitores.o candidatos.o eleicao.o principal.o arqtextoc.o -o voto.exe -lstdc++
