#include <iostream>
#include <fstream>
#include "../include/batalha.h"
#include "../include/primeiroAcesso.h"
#include "../include/menu.h"
#include "../include/alado.h"
#include "../include/besta.h"
#include "../include/criatura.h"
#include "../include/lista.h"
#include "../include/mago.h"

using namespace std;

int main()
{
    primeiroAcesso();

    bool Fim = false;

    //Carrega a lista pro usuario e pro computador
    Lista<Criatura*> jace;
    jace.carregaLista(1);
    Lista<Criatura*> jogador;
    jogador.carregaLista(2);

    Criatura* mtr;
    Criatura* mtr2;

    int vencedor = 0,
        pass = 0;

    while(!Fim){
        cls;
        switch(menuPrincipal()){

            case 1:

                while(!Fim){

                    pass = 0;

                    //carrega a criatura
                    if(!jogador.listaVazia()){
                        if(vencedor == 1 || vencedor == 0){
                            mtr = jogador.escolheCriatura();
                            jogador.remover(mtr->getNome());
                            mtr->setProx(NULL);
                        }
                        pass++;
                    }
                    if(!jace.listaVazia()){
                        if(vencedor == 2 || vencedor == 0){
                            mtr2 = jace.escolheCriatura();
                            jace.remover(mtr2->getNome());
                            mtr2->setProx(NULL);
                        }
                        pass++;
                    }
                    if(pass == 2){

                        //Ocorre a luta
                            vencedor = arena(mtr,mtr2);

                        //checa quem venceu
                        if(vencedor == 1){
                            jace.inserir(mtr);
                            jace.exibir();
                        }
                        else if(vencedor == 2){
                            jogador.inserir(mtr2);
                            jogador.exibir();
                        }
                    }
                    else{
                        cout << "\n\n\nFim de jogo!" << endl;
                        pause;
                        Fim = true;
                    }
                }
                if(vencedor == 2){
                    jogador.inserir(mtr);
                }
                else{
                    jace.inserir(mtr2);
                }
                jogador.attListaTxt(2);
                jace.attListaTxt(1);
                break;
            case 9:
                cls;
                cout << "\t\t\t\tCREDITOS:" << endl;
                cout << "\t\t\tDirecao: Felipe Medeiros" << endl;
                cout << "\t\t\tCriacao: Felipe Medeiros" << endl;
                cout << "\t\t\tAnimacao: Felipe Medeiros" << endl;
                cout << "\t\t\tDublagem: Felipe Medeiros" << endl;
                cout << "\t\t     Producao geral: Felipe Medeiros" << endl;
                cout << "\t\t     Direcao de arte: Felipe Medeiros" << endl;
                cout << "\t\t   Audio e iluminacao: Felipe Medeiros" << endl;
                cout << "\t  Refazer a lista no ultimo dia de projeto: Felipe Medeiros" << endl;
                cout << "\t  Agradecimentos especiais: Joseh augusto e Professor Fofinho" << endl;
                cout << "\n\t\t\tNo aguardo da bolsa" << endl;
                pause;
                break;

            case 0:
                Fim = true;
                return 0;
                break;
        }
    }
    return 0;
}
