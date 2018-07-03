all: mrproper ldiff
ldiff: ldiff.o
	g++ -o ldiff ldiff.o
ldiff.o: ldiff.cpp
	g++ -o ldiff.o -c ldiff.cpp -W -Wall -std=c++17
clean:
	rm -rf *.o
mrproper: clean
	rm -rf teste
