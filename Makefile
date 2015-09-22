# schuang; Huang, Samuel
spantree : edge.o main.o region.o sets.o  
	g++ -ansi -Wall -g -o spantree -O3 edge.o main.o region.o sets.o  

edge.o : edge.cpp edge.h 
	g++ -ansi -Wall -g -c -O3 edge.cpp

main.o : main.cpp region.h 
	g++ -ansi -Wall -g -c -O3 main.cpp

region.o : region.cpp region.h 
	g++ -ansi -Wall -g -c -O3 region.cpp

sets.o : sets.cpp sets.h 
	g++ -ansi -Wall -g -c -O3 sets.cpp

clean : 
	rm -f spantree edge.o  main.o  region.o  sets.o   
