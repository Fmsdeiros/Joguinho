Implementção:

Arquivos pertenecntes a implementação do programa:

src/main.cpp : Contém o código da função main.
src/alado.cpp : Código responsavel por implementar as funcoes da classe alado
src/besta.cpp : Código responsavel por implementar as funcoes da classe besta
src/mago.cpp : Código responsavel por implementar as funcoes da classe mago
src/lista.cpp : Código responsavel por implementar as funcoes da classe lista
src/criatura.cpp : Código responsavel por implementar as funcoes da classe criatura
src/menu.cpp : Código responsavel por imprimir o menu ao usuario
src/primeiroAcesso: Código responsavel por criar os arquivos necessarios para o programa rodar

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
makefile : Arquivo usado para compilar todo o código.
Doxygen : Arquivo de configuração para gerar a documentação do código com o doxygen.

Como compilar e executar:

Para compilar o código é indicado o compilador g++ pois esse foi o programa utilizado na compilação do codigo. para compilar basta usar o seguinte comando no terminal:

g++ -std=c++11 -Wall -w -pedantic -O0 src/*.cpp -o bin/executavel

Também pode ses utilizar o makefile, basta digitar o seguinte comando:

make 

Link para repositório do github: https://projetos.imd.ufrn.br/fmsdeiros/Joguinho/tree/master