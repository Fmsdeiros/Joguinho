        /**
    * @file criatura.cpp
    * @author Felipe Medeiros
    * @version 1.0
    */

    #include <iostream>
    #include <string>
    #include "../include/criatura.h"


    using namespace std;


    Criatura::Criatura(){
        prox= NULL;
    }
    Criatura::Criatura(const Criatura& Nova){
        this->nome = Nova.nome;
        this->raca = Nova.raca;
        this->vida = Nova.vida;
        this->forca = Nova.forca;
        this->armor = Nova.armor;
        this->mr = Nova.mr;
        prox = NULL;
    }
    /**
    * Funcao que define o valor da nome da criatura
    *
    * @param nome inteiro com a nome da criatura
    */
    void Criatura::setNome(string nome){this->nome = nome;}

    /**
    * Funcao que define o valor da vida da criatura
    *
    * @param vida inteiro com a vida da criatura
    */
    void Criatura::setVida(int vida){this->vida = vida;}

    /**
    * Funcao que define o valor da forca da criatura
    *
    * @param forca inteiro com a forca da criatura
    */
    void Criatura::setForca(int forca){this->forca = forca;}

    /**
    * Funcao que define o valor da armadura da criatura
    *
    * @param armor inteiro com a armadura da criatura
    */
    void Criatura::setArmor(int armor){this->armor = armor;}
    
    /**
    * Funcao que define o valor da resistencia magica da criatura
    *
    * @param mr inteiro com a resistencia magica da criatura
    */
    void Criatura::setMr(int mr){this->mr = mr;}

    /**
    * Funcao que define a chance de acerto da criatura
    *
    * @param acerto inteiro com a chance de acerto
    */
    void Criatura::setAcerto(int acerto){this->acerto = acerto;}
    
    /**
    * Funcao que define o cooldown da primeira habilidade da criatura
    *
    * @param cooldown inteiro com o tempo de cooldown
    */
    void Criatura::setCooldown(int cooldown){this->cooldown = cooldown;}

    /**
    * Funcao que define o cooldown da segunda habilidade da criatura
    *
    * @param cooldown2 inteiro com o tempo de cooldown
    */
    void Criatura::setCooldown2(int cooldown2){this->cooldown2 = cooldown2;}
    
    /**
    * Funcao que define se a criatura esta ou nao atacando
    *
    * @param atacou bool que informa se a criatura esta ou nao atacando
    */
    void Criatura::setAtacou(bool atacou){this->atacou = atacou;}
    
    /**
    * Funcao que define se a criatura esta ou nao defendendo
    *
    * @param defendeu bool que informa se a criatura esta ou nao atacando
    */
    void Criatura::setDefendeu(bool defendeu){this->defendeu = defendeu;}
    
    /**
    * Funcao que define se a criatura esta usando seu poder
    *
    * @param usouPoder bool que informa se a criatura usou poder
    */
    void Criatura::setUsouPoder(bool usouPoder){this->usouPoder = usouPoder;}
    
    /**
    * Funcao que define se a criatura esta ou nao atacando
    *
    * @param habilidadeAtiva bool que informa se a criatura esta ou nao atacando
    */
    void Criatura::setHabilidadeAtiva(bool habilidadeAtiva){this->habilidadeAtiva = habilidadeAtiva;}

    /**
    * Funcao que define se a criatura esta ou nao atacando
    *
    * @param habilidadePassiva bool que informa se a criatura esta ou nao atacando
    */
    void Criatura::setHabilidadePassiva(bool habilidadePassiva){this->habilidadePassiva = habilidadePassiva;}

    /**
    * Funcao que define a raca da criatura
    *
    * @param raca bool que informa a raca da criatura
    */
    void Criatura::setRaca(string raca){this->raca = raca;}


    void Criatura::getSpecial(){}
    
    /**
    * Funcao retorna o valor
    *
    */
    int Criatura::descobrePoder(){
        if(this->raca == "besta"){
            return 1;
        }
        if(this->raca == "alado"){
            return 2;
        }
        if(this->raca == "mago"){
            return 3;
        }
        return 0;
    }

    /**
    *	Funcao responsavel por retornar a vida da criatura
    *
    */
    string Criatura::getNome(){return this->nome;}

    /**
    *   Funcao responsavel por retornar a vida da criatura
    *
    */
    string Criatura::getRaca(){return this->raca;}
    /**
    *	Funcao responsavel por retornar a vida da criatura
    *
    */
    int Criatura::getVida(){return this->vida;}

    /**
    *	Funcao responsavel por retornar a forca da criatura
    *
    */
    int Criatura::getForca(){return this->forca;}

    /**
    *	Funcao responsavel por retornar a armadura da criatura
    *
    */
    int Criatura::getArmor(){return this->armor;}

    /**
    *	Funcao responsavel por retornar a resistencia magica da criatura
    *
    */
    int Criatura::getMr(){return this->mr;}

    /**
    *   Funcao responsavel por retornar a chance de acerto da criatura
    *
    */
    int Criatura::getAcerto(){return this->acerto;}
    
    /**
    *   Funcao responsavel por retornar o tempo de cooldown da primeira habilidade
    *
    */
    int Criatura::getCooldown(){return this->cooldown;}

        /**
    *   Funcao responsavel por retornar o tempo de cooldown da segunda habilidade
    *
    */
    int Criatura::getCooldown2(){return this->cooldown2;}
    
    /**
    *   Funcao responsavel por retornar se a criatura atacou
    *
    */
    bool Criatura::getAtacou(){return this->atacou;}
    
    /**
    *   Funcao responsavel por retornar se a criatura defendeu
    *
    */
    bool Criatura::getDefendeu(){return this->defendeu;}
    
    /**
    *   Funcao responsavel por retornar se a criatura usou poder
    *
    */
    bool Criatura::getUsouPoder(){return this->usouPoder;}
    
    /**
    *   Funcao responsavel por retornar se a habilidade da criatura esta ativa ou nao
    *
    */
    bool Criatura::getHabilidadeAtiva(){return this->habilidadeAtiva;}

    /**
    *   Funcao responsavel por retornar se a segunda habilidade da criatura esta ativa ou nao
    *
    */
    bool Criatura::getHabilidadePassiva(){return this->habilidadePassiva;}

    /**
    * @param nova objeto da classe Criatura
    *
    */
    void Criatura::operator= (Criatura nova){
        this->nome = nova.nome;
        this->raca = nova.raca;
        this->forca = nova.forca;
        this->armor = nova.armor;
        this->mr = nova.mr;
    }

    /**
    *   Funcao responsavel por setar prox
    *
    *   @param c novo endereco de prox
    */
    void Criatura::setProx(Criatura* c){prox = c;}

    /**
    *   Funcao responsavel por retornar prox
    *
    *   @return endereco de prox
    */
    Criatura* Criatura::obterProx(){return prox;}

