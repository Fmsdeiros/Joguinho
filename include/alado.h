/**
* @file besta.h
* @author Felipe Medeiros
* @version 1.0
*/
#include <string>
#include "../include/criatura.h"

#ifndef ALADO_H
#define ALADO_H

class Alado : public Criatura{
	private:
		int agilidade;
	public:

		//construtor da classe
		Alado();
		Alado(string ,string ,int ,int ,int ,int);
		Alado(const Alado&);
		~Alado();

		int getAgilidade();
		void setAgilidade(int);

		//Imprime na tela o poder da criatura
		void getSpecial();

        //Sobrecarga do operador <<
		friend ostream& operator << (ostream &o, Alado const d);
};

#endif
