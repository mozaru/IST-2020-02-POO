all: agenda
 
agenda: principal.o menu.o lista.o contato.o agenda.o
	gcc -o agenda.exe principal.o menu.o lista.o contato.o agenda.o -lstdc++
 
principal.o: principal.cpp 
	gcc -o principal.o principal.cpp -c -W -Wall -ansi -pedantic

menu.o: menu.cpp menu.hpp
	gcc -o menu.o menu.cpp -c -W -Wall -ansi -pedantic

lista.o: lista.cpp lista.hpp
	gcc -o lista.o lista.cpp -c -W -Wall -ansi -pedantic

contato.o: contato.cpp contato.hpp
	gcc -o contato.o contato.cpp -c -W -Wall -ansi -pedantic

agenda.o: agenda.cpp agenda.hpp
	gcc -o agenda.o agenda.cpp -c -W -Wall -ansi -pedantic
 
clean:
	rm -rf *.o *~ agenda