gcc -c disciplinas.cpp -o disciplinas.obj
gcc -c principal.cpp -o principal.obj


gcc disciplinas.obj principal.obj -o historico.exe -lstdc++

