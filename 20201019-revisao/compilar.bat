gcc -c eleitores.cpp -o eleitores.o
gcc -c principal.cpp -o principal.o

gcc eleitores.o principal.o -o voto.exe -lstdc++
