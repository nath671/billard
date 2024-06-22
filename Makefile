
billard.gif: billard.gnu script_billard.gnu positions.txt
		gnuplot billard.gnu

positions.txt: main.exe
		./main.exe

main.exe: Table.o Trou.o Boule.o classe_Table.h classe_Trou.h classe_Boule.h
		g++ Table.o Trou.o Boule.o main.cpp -o main.exe

Table.o: Table.cpp classe_Table.h
		g++ -c Table.cpp

Trou.o: Trou.cpp classe_Trou.h
		g++ -c Trou.cpp
 
Boule.o: Boule.cpp classe_Table.h classe_Trou.h classe_Boule.h
		g++ -c Boule.cpp

