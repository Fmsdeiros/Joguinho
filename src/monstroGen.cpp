#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include "../include/gerador13.h"

/**
*	Funcao responsavel pela geracao de mosntros
*/
void gerador::gerador13(){

	std::string racaText,
		        nome;

	int raca,
		vida,
		forca,
		armor,
		mr;

	int baseVida,
		baseForc,
		baseArmr;

	int tri;
	
	std::ofstream escreve;
	escreve.open("saruman.txt");

	srand(time(NULL));

	for(int variavel = 0; variavel < 5; variavel++){	

		//Define o quao forte a criatura vai ser
		tri = rand()%100 + 1;
		
		if(tri < 40){
			baseVida = rand()%30 + 1;
			baseForc = rand()%7 + 1;
			baseArmr = rand()%3 + 1;
		}
		else if(tri < 70){
			baseVida = rand()%50 + 1;
			baseForc = rand()%15 + 1;
			baseArmr = rand()%5 + 1;
		}
		else{
			baseVida = rand()%100 + 1;
			baseForc = rand()%30 + 1;
			baseArmr = rand()%10 + 1;
		

		//define a raca do monstro
		raca = rand()%3 + 1;


		vida = baseVida + 100;
		forca = baseForc + 10;

		switch(raca){
			case 1:
				racaText = "besta";
				armor = rand()%baseArmr + 1;
				mr = rand()%baseArmr + 5;
				break;

			case 2:
				racaText = "alado";
				armor = rand() % baseArmr + 5;
				mr = rand() % baseArmr + 1;
				break;

			case 3:
				racaText = "mago";
				armor = rand() % baseArmr + 5;
				mr = rand() % baseArmr + 2;
				break;
		}	
		

		int k = rand()% 1000 + 1;
		nome = "criatura_";
		std::string sobrenome = std::to_string(k);
		nome = nome + sobrenome;

		escreve << racaText << std::endl;
		escreve << nome << std::endl;
		escreve << vida << std::endl;
		escreve << forca << std::endl;
		escreve << armor << std::endl;
		escreve << mr << std::endl;
	}
	escreve.close();
}