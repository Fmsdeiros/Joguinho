/**
* @file batalha.h
* @author Felipe Medeiros
* @version 1.0
*/

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "../include/criatura.h"
#include "../include/alado.h"
#include "../include/besta.h"
#include "../include/mago.h"

using namespace std;

#ifdef WIN32
    #define cls system("cls")
    #define pause system("pause")
#else
    #define cls system("/usr/bin/clear")
    #define pause system("read -p \"Pressione enter para sair\" saindo");
#endif

#ifndef BATALHA_H
#define BATALHA_H

template <typename T>
int vantagemRaca(T* primario, T* secundario){
    int r1,r2;
    int gabarito[3][3] = {{0,10,20},{20,0,10},{10,20,0}};

    if(primario->getRaca() == "besta"){
        r1 = 1;
    }
    else if(primario->getRaca() == "alado"){
        r1 = 2;
    }
    else if(primario->getRaca() == "mago"){
        r1 = 3;
    }

    if(secundario->getRaca() == "besta"){
        r2 = 1;
    }
    else if(secundario->getRaca() == "alado"){
        r2 = 2;
    }
    else if(secundario->getRaca() == "mago"){
        r2 = 3;
    }

    r1 = gabarito[r1][r2];
    return r1;
}
template <typename T>
void primeiroTurno(T* primario){
    primario->setCooldown(0);
    primario->setCooldown2(0);
}
template <typename T>
void tempoRecarga(T* primario){
    if(primario->getRaca() == "besta"){
        if(primario->getHabilidadeAtiva() == true){
            primario->setCooldown(3);
        }
        if(primario->getHabilidadePassiva() == true){
            primario->setCooldown2(4);
        }
    }
    else if(primario->getRaca() == "alado"){
        if(primario->getHabilidadeAtiva() == true){
            primario->setCooldown(2);
        }
        if(primario->getHabilidadePassiva() == true){
            primario->setCooldown2(3);
        }
    }
    else{
        if(primario->getHabilidadeAtiva() == true){
            primario->setCooldown(2);
        }
        if(primario->getHabilidadePassiva() == true){
            primario->setCooldown2(3);
        }
    }
    primario->setHabilidadeAtiva(false);
    primario->setHabilidadePassiva(false);
}
template <typename T>
void novoTurno(T* primario){

    primario->setAtacou(false);
    primario->setDefendeu(false);
    primario->setUsouPoder(false);
    primario->setHabilidadeAtiva(false);
    primario->setHabilidadePassiva(false);

    int cd = primario->getCooldown();

    if(cd > 0){
        cd--;
        primario->setCooldown(cd);
    }

    cd = primario->getCooldown2();

    if(cd > 0){
        cd--;
        primario->setCooldown2(cd);
    }
}
template <typename T>
void imprimeCriatura(T* primario){
    cout << "Criatura: " << primario->getNome() << endl << "Raca: "<< primario->getRaca() << endl;
    cout << "Vida: " << primario->getVida() << endl << "Poder de ataque: " << primario->getForca() << endl;
    cout << "Armadura: " << primario->getArmor() << endl << "Resistencia Magica "<< primario->getMr() << endl;
    primario->getSpecial();
}
template <typename T>
void imprimeCriatura(T* primario, T* secundario){
    cout << "Sua criatura:\t\t\tCriatura Inimga:" << endl << endl;
    cout << "Criatura: " << primario->getNome() << "\t\tCriatura:" << secundario->getNome()<< endl;
    cout << "Raca: "<< primario->getRaca() << "\t\t\tRaca: "<< secundario->getRaca() << endl;
    cout << "Vida: " << primario->getVida() << "\t\t\tVida: " << secundario->getVida() << endl;
    cout << "Poder de ataque: " << primario->getForca() << "\t\tPoder de ataque: " << secundario->getForca() << endl;
    cout << "Armadura: " << primario->getArmor() << "\t\t\tArmadura: " << secundario->getArmor() << endl;
    cout << "Resistencia Magica "<< primario->getMr() << "\t\tResistencia Magica "<< secundario->getMr() << endl;
}
template <typename T>
void turnoAtivo(T* primario, T* secundario){

    srand(time(NULL));

    int dano;
    int dado = (rand()%200) + 1;
    int kappa = primario->getAcerto();

    // Checa se o jogador atacou
    if(primario->getAtacou()){
        // Checa se a criatura acertou o golpe
        if( dado > kappa){
            // Checa se a criatura do inimigo defendeu o ataque
            if(secundario->getDefendeu()){

                //Checa se a criatura e um mago
                if(primario->getRaca() == "mago"){
                    dano = primario->getForca() - secundario->getMr();
                }
                //condicao para o caso de a criatura nao ser mago
                else{
                    dano = primario->getForca() - secundario->getArmor();
                }
                secundario->setVida( secundario->getVida() - dano);
            }
            //condicao para o caso de a criatura inimiga nao ter defendido
            else{

                if(primario->getRaca() == "mago"){
                    dano = primario->getForca() - secundario->getMr()/2;
                }

                else{
                    dano = primario->getForca() - secundario->getArmor()/2;
                }
                secundario->setVida( secundario->getVida() - dano);
            }
            cout << primario->getNome() << " causou " << dano << " de dano em seu ataque." << endl;
        }

        //condicao para o caso de a criatura inmiga ter errado o golpe
        else{
            cout << primario->getNome() << " errou o golpe!" << endl;
        }
    }

    // Checa se o jogador defendeu
    else if(primario->getDefendeu()){
        cout << primario->getNome() << " defendeu o ataque" << endl;
    }
    // Checa se o jogador usou seu buff
    else if(primario->getUsouPoder() && primario->getHabilidadePassiva()){

        dano = primario->getVida()/90;
        primario->setVida(primario->getVida() - dano);

        switch(primario->descobrePoder()){
            case 1:
                primario->setMr( primario->getMr() + primario->getMr()/4);
                break;
            case 2:
                primario->setArmor(primario->getArmor() + primario->getArmor()/4);
                break;
            case 3:
                primario->setForca(primario->getForca() + primario->getForca()/4);
                break;
        }

        cout << primario->getNome() << " usou seu buff racial nesse turno!" << endl;

    }

    // Checa se o jogador usou seu poder de raca
    else if(primario->getUsouPoder() && primario->getHabilidadeAtiva()){
        switch(primario->descobrePoder()){
            case 1:
                dano = primario->getForca()/2;
                break;
            case 2:
                dano = primario->getForca();
                secundario->setVida(secundario->getVida() - dano);
                break;
            case 3:
                if(secundario->getDefendeu()){
                    dano = primario->getForca() + primario->getForca()/2 - secundario->getMr();
                }
                else{
                    dano = primario->getForca() + primario->getForca()/2 - secundario->getMr()/2;
                }
                secundario->setVida(secundario->getVida() - dano);
                break;
        }
        cout << primario->getNome() << " causou " << dano << " de dano com seu poder." << endl;
    }
}
template <typename T>
int arena(T* primario, T* secundario){

    cls;
    bool lutando = true,
         valido = true;

    int escolha;

    //imprime a criatura 1
    cout << "Sua criatura:\n" << endl;
    imprimeCriatura(primario);
    cout << endl;
    pause;
    cls;
    //imprime a criatura 2
    cout << "Criatura inimiga:\n" << endl;
    imprimeCriatura(secundario);
    cout << endl;
    pause;

    primario->setAcerto(vantagemRaca(primario, secundario));
    secundario->setAcerto(vantagemRaca(secundario, primario));
    primeiroTurno(primario);
    primeiroTurno(secundario);

    while(lutando){
        srand(time(NULL));

        valido = false;
        novoTurno(primario);
        novoTurno(secundario);


        // While responsavel por garantir que a escolha do usuario e valida
        while(!valido){

            cls;
            imprimeCriatura(primario,secundario);
            cout << "\n\n\n\n";
            cout << "Acao do turno: " << endl;
            cout << "(1) - Golpe normal." << endl;
            cout << "(2) - Defender o proximo ataque." << endl;

            if(primario->getCooldown() > 0){
                cout << "( ) - Habilidade em tempo de recarga." << endl;
            }
            else{
                cout << "(3) - Habilidade especial." << endl;
            }

            if(primario->getCooldown2() > 0){
                cout << "( ) - Habilidade em tempo de recarga." << endl;
            }
            else{
                cout << "(4) - Buff racial." << endl;
            }
            cout << "Escolha: ";
            cin >> escolha;

            switch(escolha){
                case 1:
                    primario->setAtacou(true);
                    valido = true;
                    break;
                case 2:
                    primario->setDefendeu(true);
                    valido = true;
                    break;
                case 3:
                    if(primario->getCooldown() > 0){
                        cout << "Valor invalido!" << endl;
                        pause;
                    }
                    else{
                        primario->setHabilidadeAtiva(true);
                        primario->setUsouPoder(true);
                        valido = true;
                    }
                    break;
                case 4:
                    if(primario->getCooldown2() > 0){
                        cout << "Valor invalido!" << endl;
                        pause;
                    }
                    else{
                        primario->setHabilidadePassiva(true);
                        primario->setUsouPoder(true);
                        valido = true;
                    }
                    break;
                default:
                    cout << "Valor invalido!" << endl;
                    pause;
                    break;
            }
        }

        //Escolha do computador
        escolha = rand() % 100;

        if(secundario->getCooldown() == 0 && secundario->getCooldown2() == 0){
            if(escolha < 30)
                secundario->setAtacou(true);
            else if(escolha < 40){
                secundario->setDefendeu(true);
            }
            else if(escolha < 70){
                secundario->setUsouPoder(true);
                secundario->setHabilidadeAtiva(true);
            }
            else{
                secundario->setUsouPoder(true);
                secundario->setHabilidadePassiva(true);
            }
        }
        else if(secundario->getCooldown() == 0){
            if(escolha < 33){
                //33%
                secundario->setAtacou(true);
            }
            else if(escolha < 53){
                //20%
                secundario->setDefendeu(true);
            }
            else{
                //47%
                secundario->setUsouPoder(true);
                secundario->setHabilidadeAtiva(true);
            }
        }
        else if(secundario->getCooldown2() == 0){
            if(escolha < 33){
                //33%
                secundario->setAtacou(true);
            }
            else if(escolha < 53){
                //20%
                secundario->setDefendeu(true);
            }
            else{
                //47%
                secundario->setUsouPoder(true);
                secundario->setHabilidadePassiva(true);
            }
        }
        else{
            if(escolha > 30){
                //70%
                secundario->setAtacou(true);
            }
            else{
                //30%
                secundario->setDefendeu(true);
            }
        }

        turnoAtivo(primario,secundario);
        turnoAtivo(secundario,primario);
        tempoRecarga(primario);
        tempoRecarga(secundario);
        pause;

        if(primario->getVida() <= 0){
            cout << "Sua criatura morreu!" << endl;
            lutando = false;
            primario->setVida(200);
            secundario->setVida(200);
            return 1;
        }
        if(secundario->getVida() <= 0){
            cout << "A criatura inimiga morreu!" << endl;
            lutando = false;
            primario->setVida(200);
            secundario->setVida(200);
            return 2;
        }
    }
    return 0;
}

#endif
