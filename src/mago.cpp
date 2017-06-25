#include "../include/mago.h"
#include <iostream>
#include <fstream>

using namespace std;

/**
*   construtor da classe
*/
Mago::Mago(){prox = NULL;}

/**
*   construtor da classe
*/
Mago::Mago(string a,string b,int c,int d,int e,int f){
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
Mago::Mago(const Mago& Nova){
	this->nome = Nova.nome;
    this->raca = Nova.raca;
    this->vida = Nova.vida;
    this->forca = Nova.forca;
    this->armor = Nova.armor;
    this->mr = Nova.mr;
	prox = NULL;
}

/**
*   construtor da classe
*/
Mago::~Mago(){}


int Mago::getPoderMagico(){return this->poderMagico;}
void Mago::setPoderMagico(int poderMagico){this->poderMagico = poderMagico;}

/**
*   imprime os poderes da criatura para o jogador
*/
void Mago::getSpecial(){
    cout << "\nPoder racial: ";

    cout << "\nHabilidade Ativa:" << endl;
    cout << "Raio Domesticado" << endl;
    cout << "Habilidade: Lance um raio no seu inimigo causando 150 porcento do seu poder em dano" << endl;
    cout << "Tempo de recarga: 2 turnos" <<endl;

    cout << "\nBuff Racial:" << endl;
    cout << "Salto evolutivo" << endl;
    cout << "Habilidade: Perca 1/10 da sua vida atual, aumente seu poder de habilidade em 1/4." << endl;
    cout << "Tempo de recarga: 2 turnos" <<endl;
}
/**
*   sobrecarga do operador <<
*/
ostream& operator<< (ostream &o, Mago const d){
	o << "Criatura: " << d.nome << endl << "Raca: "<< d.raca << endl;
	o << "Vida: " << d.vida << endl << "Poder de Habilidade: " << d.forca << endl;
	o << "Armadura: " << d.armor << endl << "Resistencia Magica "<< d.mr << endl;
	return o;
}
