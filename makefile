all:
	@echo "make exe - para compilar o código"
	@echo "make bib - para compilar apenas a biblioteca"
	@echo "make do - para compilar ambos"
do:
	@g++ -std=c++11 -c src/monstroGen.cpp
	@mv monstroGen.o build/
	@ar crv lib/libGe13.a build/monstroGen.o
	@g++ -std=c++11 -c src/jokenpo.cpp
	@mv jokenpo.o build/
	@ar crv lib/libJoke.a build/jokenpo.o
	@g++ -std=c++11 -Wall -pedantic src/alado.cpp src/besta.cpp src/criatura.cpp src/mago.cpp src/main.cpp src/menu.cpp src/primeiroAcesso.cpp -o bin/execcutavel lib/libGe13.a lib/libJoke.a
	
exe:
	@g++ -std=c++11 -Wall -pedantic src/alado.cpp src/besta.cpp src/criatura.cpp src/mago.cpp src/main.cpp src/menu.cpp src/primeiroAcesso.cpp -o bin/execcutavel lib/libGe13.a lib/libJoke.a
bib:
	@echo "compilando bibliotecas"
	@g++ -std=c++11 -c src/monstroGen.cpp
	@mv monstroGen.o build/
	@ar crv lib/libGe13.a build/monstroGen.o
	@g++ -std=c++11 -c src/jokenpo.cpp
	@mv jokenpo.o build/
	@ar crv lib/libJoke.a build/jokenpo.o