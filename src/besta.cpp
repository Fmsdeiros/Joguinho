#include "../include/besta.h"
#include <iostream>
#include <fstream>

using namespace std;

/**
*   construtor da classe
*/
Besta::Besta(){prox = NULL;}
/**
*   construtor da classe
*/
Besta::Besta(string a,string b,int c,int d,int e,int f){
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
Besta::Besta(const Besta& Nova){
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
Besta::~Besta(){}


int Besta::getFuria(){return this->furia;}
void Besta::setFuria(int furia){this->furia = furia;}

/**
*   imprime os poderes da criatura para o jogador
*/
void Besta::getSpecial(){

    cout << "\nPoder racial: ";

    cout << "\nHabilidade Ativa:" << endl;
    cout << "Esmurrador Eletrostatico" << endl;
    cout << "Habilidade: Cause 1/2 do seu poder em dano, nocauteie seu adversario por 1 turno" << endl;
    cout << "Tempo de recarga: 3 turnos" <<endl;

    cout << "\nBuff racial:" << endl;
    cout << "Construido para Arrebentar" << endl;
    cout << "Habilidade: Perca 1/10 da sua vida atual, aumente sua resistencia magica em 1/4." << endl;
    cout << "Tempo de recarga: 4 turnos" <<endl;
}

/**
*   sobrecarga do operador <<
*/
ostream& operator<< (ostream &o, Besta const d){
	o << "Criatura: " << d.nome << endl << "Raca: "<< d.raca << endl;
	o << "Vida: " << d.vida << endl << "Poder de ataque: " << d.forca << endl;
	o << "Armadura: " << d.armor << endl << "Resistencia Magica "<< d.mr << endl;
	return o;
}
