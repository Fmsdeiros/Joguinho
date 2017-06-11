/**
* @file criatura.h
* @author Felipe Medeiros
* @version 1.0
*/

#ifndef CRIATURA_H	//uso do pre-processador
#define CRIATURA_H	//definicao do identificador do cabecalho

#include <string>
#include <iostream>

using namespace std;



/**
*	Classe que contem todas as informações basicas para
*	se criar uma criatura comum.
*/
class Criatura{
	protected:
        string nome,
               raca;

		int mr,
			vida,
			forca,
			armor,
			acerto,
			cooldown,
			cooldown2;
			

		bool atacou,
			 defendeu,
			 usouPoder,
			 habilidadeAtiva,
			 habilidadePassiva;
			 
		Criatura* prox;

	public:
		Criatura();
		Criatura(const Criatura&);
		//Sobrecarga do operador =
        void operator = (Criatura nova);
		
		void verCriatura();
	    //Define o nome da criatura
	    void setNome(string);
	    //Define a raca da criatura
	    void setRaca(string);
		//Define a vida da criatura
		void setVida(int);
		//Define a forca da criatura
		void setForca(int);
		//Define a armadura da criatura
		void setArmor(int);
		//Define a resistencia magica da criatura
		void setMr(int);
		//Define a chance de acerto da criatura
		void setAcerto(int);
		//Define o tempo de cooldown da primeira habilidade
		void setCooldown(int);
		//Define o tempo de cooldown da segunda habilidade
		void setCooldown2(int);
		//Define se a criatura atacou
		void setAtacou(bool);
		//Define se a criatura defendeu
		void setDefendeu(bool);
		//Define se a criatura usou poder
		void setUsouPoder(bool);
		//Define se a habilidade da criatura esta ativa ou nao
		void setHabilidadeAtiva(bool);
		//Define se a segunda habilidade da criatura esta ativa ou nao
		void setHabilidadePassiva(bool);

        //Retorna o nome da criatura
        string getNome();
        //Retorna a raca da criatura
        string getRaca();
		//Retorna o valor da vida da criatura
		int getVida();
		//Retorna o valor da forca da criatura
		int getForca();
		//Retorna o valor da armadura da criatura
		int getArmor();
		//Retorna o valor da resistencia magica da criatura
		int getMr();
		//Retorna a chace de acerto da criatura
		int getAcerto();
		//Retorna o tempo de cooldown da primeira habilidade
		int getCooldown();
		//Retorna o tempo de cooldown da segunda habilidade
		int getCooldown2();
		//Retorna se a criatura atacou
		bool getAtacou();
		//Retorna se a criatura defendeu
		bool getDefendeu();
		//Retorna se a criatura usou poder
		bool getUsouPoder();
		//Retorna se a habilidade da criatura esta ativa ou nao
		bool getHabilidadeAtiva();
		//Retorna se a segunda habilidade da criatura esta ativa ou nao
		bool getHabilidadePassiva();


        virtual void getSpecial();
        int descobrePoder();

        //funcao responsavel por comparar as racas das criaturas
		int comparaRaca(string);
		//funcao responsavel por retornar o dano de um golge
		int Bater(int,string);

		//Funcao responsavel por atualizar o valor de prox
		void setProx(Criatura* l);
		//Funcao responsavel por retornar o valor de prox
		Criatura* obterProx();



};

#endif
