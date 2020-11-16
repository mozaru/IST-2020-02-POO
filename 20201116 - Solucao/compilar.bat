gcc -c disciplinas.cpp -o disciplinas.obj -pedantic -Wall
gcc -c principal.cpp -o principal.obj -pedantic -Wall


gcc disciplinas.obj principal.obj -o historico.exe -lstdc++

