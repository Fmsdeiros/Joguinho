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
	private:
		int furia;
	public:

		//construtor da classe
		Besta();
		Besta(string ,string ,int ,int ,int ,int);
		Besta(const Besta&);
        ~Besta();

		//Imprime na tela o poder da criatura
		void getSpecial();

		int getFuria();
		void setFuria(int);

		//Sobrecarga do operador <<
		friend ostream& operator << (ostream &o, Besta const d);

};

#endif
