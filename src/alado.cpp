#include "../include/alado.h"
#include <fstream>
#include <iostream>

using namespace std;

/**
*   construtor da classe
*/
Alado::Alado(){prox = NULL;}
/**
*   contrutor da classe 
*/
Alado::Alado(string a,string b,int c,int d,int e,int f){
    this->nome = a;
    this->raca = b;
    this->vida = c;
    this->forca = d;
    this->armor = e;
    this->mr = f;
	prox = NULL;
}
/**
*   construtor da classe
*/
Alado::Alado(const Alado& Nova){
	this->nome = Nova.nome;
    this->raca = Nova.raca;
    this->vida = Nova.vida;
    this->forca = Nova.forca;
    this->armor = Nova.armor;
    this->mr = Nova.mr;
	prox = NULL;
}

/**
*   destrutor da classe
*/
Alado::~Alado(){}

/**
*   imprime os poderes da criatura para o jogador
*/
void Alado::getSpecial(){
    cout << "\nPoder racial: ";

    cout << "\nHabilidade Ativa:" << endl;
    cout << "Virando o jogo" << endl;
    cout << "Habilidade: Seu golpe ignora a armadura do inimigo" << endl;
    cout << "Tempo de recarga: 2 turnos" <<endl;

    cout << "\nBuff racial:" << endl;
    cout << "Defesa florescente" << endl;
    cout << "Habilidade: perca 1/10 da sua vida atual, aumente sua armadura em 1/4.";
    cout << "Tempo de recarga: 3 turnos" <<endl;

}
/**
*   sobrecarga do operador <<
*/
ostream& operator<< (ostream &o, Alado const d){
    o << "Criatura: " << d.nome << endl << "Raca: "<< d.raca << endl;
	o << "Vida: " << d.vida << endl << "Poder de Habilidade: " << d.forca << endl;
	o << "Armadura: " << d.armor << endl << "Resistencia Magica "<< d.mr << endl;
	return o;
}
