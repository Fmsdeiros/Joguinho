#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "../include/mago.h"
#include "../include/menu.h"
#include "../include/alado.h"
#include "../include/lista.h"
#include "../include/besta.h"
#include "../include/batalha.h"
#include "../include/criatura.h"
#include "../include/primeiroAcesso.h"
#include "../include/gerador13.h"
#include "../include/jokenpo.h"

using namespace std;

void geraCriatura();

int main(){

    string nome,raca;
                    
    int forca,vida,armor,mr;    

    primeiroAcesso();

    bool Fim = false;

    //Carrega a lista pro usuario e pro computador
    Lista<Criatura*> jace;
    jace.carregaLista(1);
    Lista<Criatura*> jogador;
    jogador.carregaLista(2);
    vector<Criatura*> saruman;


    Criatura* mtr;
    Criatura* mtr2;

    int vencedor = 0,
        pass = 0;

    if(jace.listaVazia()){
        while(jace.listaVazia()){
            gerador::gerador13();
            ifstream recebe;
            recebe.open("saruman.txt");
            for(int i = 0; i < 5; i++){                    
                recebe >> raca;
                recebe >> nome;
                recebe >> vida;
                recebe >> forca;
                recebe >> armor;
                recebe >> mr;
                
                Criatura* mtr4 = new Criatura(nome,raca,vida,forca,armor,mr);
                saruman.push_back(mtr4);
            }
            //delete mtr4;
            for(int i = 0; i < 5; i++){
                if(jokenpo::jogada(2) == 1)
                    jace.inserir(saruman[i]);

            }
            saruman.clear();
        }
    }

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
                        }
                        else if(vencedor == 2){
                            jogador.inserir(mtr2);
                        }
                    }
                    else{
                        cout << "\n\n\nFim de jogo!" << endl;
                        if(jogador.listaVazia()){
                            cout << "O seu grimorio está sem criatura!\nEncontre-se com saruman!" << endl;
                        }
                        else{
                            cout << "Seu oponente esta sem criaturas!\nRecomece o jogo para duelar com ele mais uma vez!" << endl;
                        }
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
            

            case 2:
                cls;
                if(!jogador.listaVazia()){
                    cout << "\nVoce nao tem permissao para adentrar no grande salao de saruman." << endl;
                    cout << "Retire-se agora, mortal." << endl;
                    pause;
                }
                else{
                    
                    
                    gerador::gerador13();

                    ifstream recebe;
                    recebe.open("saruman.txt");
                    for(int i = 0; i < 5; i++){                    

                        recebe >> raca;
                        recebe >> nome;
                        recebe >> vida;
                        recebe >> forca;
                        recebe >> armor;
                        recebe >> mr;
                        Criatura* mtr3 = new Criatura(nome,raca,vida,forca,armor,mr);
                        saruman.push_back(mtr3);
                    }

                    cout << "Voce ousou desafiar saruman, agora enfrente de sua terrivel furia!" << endl;
                    cout << "The eagles are coming!" << endl;
                    for(int i = 0; i < 5; i++){
                        if(jokenpo::jogada(1) == 1)
                            jogador.inserir(saruman[i]);

                    }
                    cout << "Saruman comeca a jogar hobbits em você até que voce saia da sala." << endl;
                    saruman.clear();
                }

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
                cout << "  Agradecimentos especiais: Joseh augusto, Luciano Eduardo e Professor Fofinho" << endl;
                cout << "\n\t\t\tNo aguardo da bolsa" << endl;
                pause;
            break;
            case 0:
                Fim = true;
                jogador.attListaTxt(2);
                jace.attListaTxt(1);
                return 0;
            break;
        }
    }
    return 0;
}
