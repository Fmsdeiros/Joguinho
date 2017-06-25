Executar usando um linux

Implementção:

Arquivos pertencentes a implementação do programa:

src/main.cpp : Contém o código da função main.
src/alado.cpp : Código responsavel por implementar as funcoes da classe alado
src/besta.cpp : Código responsavel por implementar as funcoes da classe besta
src/mago.cpp : Código responsavel por implementar as funcoes da classe mago
src/lista.cpp : Código responsavel por implementar as funcoes da classe lista
src/criatura.cpp : Código responsavel por implementar as funcoes da classe criatura
src/menu.cpp : Código responsavel por imprimir o menu ao usuario
src/primeiroAcesso: Código responsavel por criar os arquivos necessarios para o programa rodar
src/monstroGen.cpp : Código da função que gera monstros
src/jokenpo.cpp : Código da função responsavel pelo jokenpo

include/gerador13.h: Contémm a assinatura da funcao da biblioteca que gera monstros.
include/gerador13.h: Contémm a assinatura da funcao da biblioteca responsavel pelo jokenpo.
include/menu.h : Contém as assinaturas das funções do arquivo menu.cpp.
include/alado.h : Contém as assinaturas das funções do arquivo alado.cpp.
include/besta.h : Contém as assinaturas das funções do arquivo besta.cpp.
include/mago.h : Contém as assinaturas das funções do arquivo mago.cpp.
include/lista.h : Contém o codigo implementado da lista usada no sistema
include/batalha.h : Contém o codigo implementado das funcoes responsaveis pelas lutas das criaturas
include/criatura.h : Contém as assinaturas das funções do arquivo criatura.cpp.
include/primeiroAcesso.h : Contém as assinaturas das funções do arquivo primeiroAcesso.cpp.

bin/execcutavel : executavel do código.
bin/CriaturasJace.txt : Arquivo que contém todos as criaturas do computador.
bin/CriaturasJogador.txt : Arquivo que contém todos as criaturas do jogador.
bin/JaceNum.txt : Arquivo usado para armazenar a quantidade de criaturas do computador.
bin/JogadorNum.txt : Arquivo usado para armazenar a quantidade de criaturas do jogador.
bin/saruman	: Arquivo que guarda os monstros gerados por saruman.

makefile : Arquivo usado para compilar todo o código.
Doxygen : Arquivo de configuração para gerar a documentação do código com o doxygen.

Como compilar e executar:

Para compilar o código é indicado o compilador g++ pois esse foi o programa utilizado na compilação do codigo. para compilar basta usar o seguinte comando no terminal:

g++ -std=c++11 -Wall -w -pedantic -O0 src/*.cpp -o bin/executavel

Também pode ses utilizar o makefile, basta digitar o seguinte comando:

make 

OBS:
O código faz uso das bibliotecas para poder usar as funcoes: 
	<stdlib.h>:
		rand
		system("cls")
		system("pause")
<time.h>
		time

	As classes filhas de Criatura: alado,besta e mago nao tem variaveis proprias dessas classes. Porem o sistema foi implementado de forma que magos batem usando seu dano magico que é absorvido pela resistencia mágica, alados e bestas atacam com poder fisico que é absorvido pela armadura. Quando um mago ataca uma besta, além do fato de que as bestas tem uma alta resistencia mágica comparada com outras classes, o mago tem tem menos chance de acertar um ataque em uma besta, do que teria se estivesse atacando um alado.

Locais:
	1. O Jokenpo deverá ser uma biblioteca.											-	Pasta Lib
	2. O Gerador deverá ser outra biblioteca.										-	Pasta Lib
	3. O Grimório Mestre de Saruman deverá ser um conteiner STL.					- 	Main.cpp/Linha 36
	4. Os monstros sequem as definições do Laboratório IV.							-	Criatura.cpp/Alado.cpp/Mago.cpp/Besta.cpp
	5. Deveram existir monstros fortes, normais e  fracos nesse	grimório.			-	monstroGem.cpp/Linha 35
	6. A probabilidade de Saruman entregar um monstro fraco e maior que um normal.	-	monstroGem.cpp/Linha 36
	7. Cada vitoria do conjurador, Saruman dará um monstro que deve ser adicionado no Grimório do Conjurador.	-	main.cpp/Linha64/165
	8. Saruman tirará onda com você a cada vitoria dele.							-	jokenpo.cpp/Linha 47
	9. Acabado as cinco partidas, Saruman expulsa o conjurador.						-	main.cpp/Linha 168
	10. Saruman não perde monstros, afinal, ele é O Criador 						-   Código.

Link para repositório do github: https://projetos.imd.ufrn.br/fmsdeiros/Joguinho/tree/master
