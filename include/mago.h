/**
* @file besta.h
* @author Felipe Medeiros
* @version 1.0
*/
#include <string>
#include "../include/criatura.h"
#ifndef MAGO_H
#define MAGO_H

class Mago : public Criatura{
	public:

		//construtor da classe
		Mago();
		Mago(string ,string ,int ,int ,int ,int);
		Mago(const Mago&);
        ~Mago();

		//Imprime na tela o poder da criatura
		void getSpecial();

		//Sobrecarga do operador <<
		friend ostream& operator << (ostream &o, Mago const d);

};
#endif
