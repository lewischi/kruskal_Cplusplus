# schuang; Huang, Samuel
spantree : edge.o main.o region.o sets.o  
	g++ -ansi -Wall -g -o spantree -O3 edge.o main.o region.o sets.o  

edge.o : edge.cpp 
	g++ -ansi -Wall -g -c -O3 edge.cpp

main.o : main.cpp 
	g++ -ansi -Wall -g -c -O3 main.cpp

region.o : region.cpp 
	g++ -ansi -Wall -g -c -O3 region.cpp

pts.o : pts.cpp pts.h 
	g++ -ansi -Wall -g -c -O3 pts.cpp

clean : 
	rm -f spantree edge.o  main.o  region.o  pts.o   
