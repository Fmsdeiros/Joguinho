#include <fstream>

using namespace std;

/**
*   Cria arquivos necessarios para o programa rodar
*/
void primeiroAcesso(){

    ifstream recebe;
    ofstream escreve;

    recebe.open("JaceNum.txt");
    if(!recebe.is_open()){
        recebe.close();
        escreve.open("JaceNum.txt");
        escreve << 0;
        escreve.close();
    }

    recebe.open("JogadorNum.txt");
    if(!recebe.is_open()){
        recebe.close();
        escreve.open("JogadorNum.txt");
        escreve << 0;
        escreve.close();
    }

    recebe.open("CriaturasJace.txt");
    if(!recebe.is_open()){
        recebe.close();
        escreve.open("CriaturasJace.txt");
        escreve << "";
        escreve.close();
    }
    recebe.open("CriaturasJogador.txt");
    if(!recebe.is_open()){
        recebe.close();
        escreve.open("CriaturasJogador.txt");
        escreve << "";
        escreve.close();
    }
}
