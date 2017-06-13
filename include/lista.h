/**
* @file lista.h
* @author Felipe Medeiros
* @version 1.0
*/

#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "../include/criatura.h"
#include "../include/mago.h"
#include "../include/alado.h"
#include "../include/besta.h"

using namespace std;

#ifndef LISTA_H	//uso do pr�-processador
#define LISTA_H	//definicao do identificador do cabe�alho

/**
* Classe responsavel por criar a lista de Ts do sistema
*/
template<class T>
class Lista{
private:
	//primeiro elemento da lista
	T cabeca;
	//ultimo elemento da lista
	T cauda;

	int tamanho;

public:

	/**
	* Construtor da classe no caso de nao haver parametros
	*/
	Lista(){
        cabeca = NULL;
        cauda = NULL;
        tamanho = 0;
	}

    /**
    *  retorna o tamanho da lista
    *
    *  @return int tamanho da lista
    */
	int getTamanho(){

        return this->tamanho;
	}
	void setTamanho(int tamanho){

        this->tamanho = tamanho;
	}
	/**
	* Checa se a lista esta ou nao vazia
    *
    * @return bool onde true a fila esta vazia e false a lista nao esta vazia
	*/
	bool listaVazia(){
        if(this->tamanho == 0){
            return true;
        }
        else{

            return false;
        }
	}
	/**
	* Printa todos os elementos da lista na tela
	*/
	void exibir(){
        cout << "\nImprimindo todos as " << tamanho <<" criaturas..." << endl;
        //aponta para o inicio da lista
        T primario = cabeca;
        int cont = 0;

        if(listaVazia())
            cout << "Nao existem criaturas no grimorio." << endl;
        else{
            while(primario){
                cont++;
                cout << cont << " - " << primario->getNome() << endl;
                primario = primario->obterProx();
            }
        }
	}
	/**
	* Insere um T no inicio da lista
    *
    * @param mtr criatura que vai ser inserida na lista
	*/
	void inserir(T mtr){
        //recebe o objeto que ser� inserido
        if(listaVazia()){
            cabeca = mtr;
            cauda = mtr;
        }
        else{
            mtr->setProx(cabeca);
            cabeca = mtr;
        }
        this->tamanho++;
        //delete mtr;
	}
	/**
	* Busca por um T na lista
    *
    * @param nome string que contem o nome da criatura a ser procurada
    * @return T objeto da classe Criatura 
	*/
	T buscaCriatura(string nome){
        //aponta para o inicio da lista
        T primario = cabeca;
        while(primario){
            if(primario->getNome() == nome)
                return primario;
            primario = primario->obterProx();
        }
        //delete primario;
        return primario;
	}
	/**
	* Remove uma criatura da lista
    *
    * @param nome string que contem o nome da criatura a ser removida
	*/
	void remover(string nome){

        if(!listaVazia()){
            //recebe o objeto que deve ser deletado
            T deleta = buscaCriatura(nome);
            //recebe um objeto vazio
            T vazio = new Criatura();
            //aponta para o inicio da lista
            T primario = cabeca;
            //recebe NULL
            T secundario = NULL;

            if(deleta != vazio){
                while(primario != NULL){
                    if(primario->getNome() == nome)
                        break;

                    secundario = primario;
                    primario = primario->obterProx();
                }
                if(secundario == NULL){
                    cabeca = primario->obterProx();
                }
                else if(primario != NULL){
                    secundario->setProx(primario->obterProx());
                }
            }
           this->tamanho--;
        }
    }

    /**
    * Retorna uma criatura aleatoria da lista
    * 
    * @return um objeto da classe Criatura
    */
    T escolheCriatura(){

        srand(time(NULL));
        int tam = getTamanho();

        int posicao = rand()%tam;

        T primario = cabeca;

        while(posicao > 0){
            primario = primario->obterProx();
            posicao--;
        }

        if(primario->getRaca() == "besta"){
            return (Besta*)primario;
        }
        else if(primario->getRaca() == "alado"){
            return (Alado*)primario;
        }
        else{
            return (Mago*)primario;
        }
        return primario;
    }

    /**
    * Atualiza o arquivo txt que contem as criaturas cadastradas de sua respectiva lista
    *
    * @param j inteiro que informa qual o arquivo deve ser atualizado
    */
    void attListaTxt(int j){
        ofstream escreve;

        //contador
        int k = 0;

        if(j == 1)
            escreve.open("CriaturasJace.txt");
        else
            escreve.open("CriaturasJogador.txt");
        T primario = cabeca;

        if(!listaVazia()){
            while(primario){
                escreve << primario->getRaca() << endl;
                escreve << primario->getNome() << endl;
                escreve << primario->getVida() << endl;
                escreve << primario->getForca() << endl;
                escreve << primario->getArmor() << endl;
                escreve << primario->getMr() << endl;
                primario = primario->obterProx();
                k++;
            }
        }
        escreve.close();
        if(j == 1)
            escreve.open("JaceNum.txt");
        else
            escreve.open("JogadorNum.txt");
        escreve << k;
        escreve.close();
    }
    /*
    * Carrega a lista usando um arquivo de texto
    * 
    * @param k inteiro que infroma qual o arquivo deve ser aberto
    */
    void carregaLista(int k){


        ifstream recebe;

        //variaveis auxiliares
        string raca,nome;
        int vida,forca,armor,mr;


        //recebe a quantidade de Criaturas salvo
        int quant,
        //conta quantos Criaturas foram inseridos
            cont = 0;

        if(k == 1)
            recebe.open("JaceNum.txt");
        else
            recebe.open("JogadorNum.txt");

        if(recebe.is_open()){
            recebe >> quant;
            recebe.close();

            if(k == 1)
                recebe.open("CriaturasJace.txt");
            else
                recebe.open("CriaturasJogador.txt");

            if(recebe.is_open()){
                while(cont < quant){
                    cont++;
                    recebe >> raca;
                    recebe >> nome;
                    recebe >> vida;
                    recebe >> forca;
                    recebe >> armor;
                    recebe >> mr;

                    if(raca == "besta"){
                        Besta *bst = new Besta(nome,raca,vida,forca,armor,mr);
                        inserir(bst);
                        //delete bst;
                    }
                    else if(raca == "alado"){
                        Alado *ald = new Alado(nome,raca,vida,forca,armor,mr);
                        inserir(ald);
                        //delete ald;
                    }
                    else{
                        Mago *mg = new Mago(nome,raca,vida,forca,armor,mr);
                        inserir(mg);
                        //delete mg;
                    }
                }
            }
        }
        recebe.close();
    }

};
#endif
