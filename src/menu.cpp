/**
* @file menu.cpp
* @author Felipe Medeiros
* @version 1.0
*/

#include <iostream>
#include "../include/menu.h"

using namespace std;

/**
*	Funcao responsavel por apresnetar o menu de escolhas ao usuário.
*
*	@return inteiro com valor da
*/
int menuPrincipal(){
	int escolha;

	cout << "Joguinho Hardcore mesmo";
	cout << "\n\n\n";
	cout << "(1) - Iniciar jogo." << endl;
	cout << "(2) - Salao de saruman." << endl;
	cout << "(9) - Creditos." << endl;
	cout << "(0) - Sair do jogo." << endl;
	cout << "Escolha: ";
	cin >> escolha;

	return escolha;
}
