/**
* @file besta.h
* @author Felipe Medeiros
* @version 1.0
*/
#include <string>
#include "../include/criatura.h"

#ifndef BESTA_H
#define BESTA_H

class Besta : public Criatura{
	public:

		//construtor da classe
		Besta();
		Besta(string ,string ,int ,int ,int ,int);
		Besta(const Besta&);
        ~Besta();

		//Imprime na tela o poder da criatura
		void getSpecial();

		//Sobrecarga do operador <<
		friend ostream& operator << (ostream &o, Besta const d);

};

#endif
