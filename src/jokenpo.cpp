#include "../include/jokenpo.h"
#include <iostream>
#include <stdlib.h>

int jokenpo::jogada(int player){

	//tratamentos
	bool ok = false;

	//jogadores
	int p1,p2;
	int vencedor;
	//Gabarito
	int gabarito[3][3] = {{0,-1,1},{1,0,-1},{-1,1,0}};
	if(player == 1){
		while(!ok){
			std::cout << "\nFaca sua jogada:" << std::endl;
			std::cout << "(1) - Pedra." << std::endl;
			std::cout << "(2) - Papel." << std::endl;
			std::cout << "(3) - Tesoura." << std::endl;
			std::cout << "Escolha: ";
			std::cin >> p1;

			if(p1 > 0 && p1 < 4){
				ok = true;
			}
			else{
				std::cout << "Valor invalido! Tente de novo.\n" << std::endl;
			}
		}

		p2 = rand()%3;
		p1--;

		vencedor = gabarito[p1][p2];

		switch(vencedor){
			case 1:
				std::cout << "\n\nVoce venceu!\n\n";
				break;
			case 0:
				std::cout << "\n\nEmpatou!\n\n";
				std::cout << "Assim como legolas e gimli, nosso duelo terminou em empate. Mas eu claramente sou superior a voce." << std::endl;
				break;
			case -1:
				std::cout << "\n\nVoce perdeu!\n\n";
				std::cout << "Eu construi um exercicto de lobos e orcs sozinho, mas para lidar com vc 2 hobbits bastavam." << std::endl;
				vencedor = 0;
				break;
		}
	}
	else{
		p1 = rand()%3 +1;
		p2 = rand()%3 +1;
		vencedor = gabarito[p1][p2];
	}

	return vencedor;
}
