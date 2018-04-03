#include <iostream>
#include <vector>


using namespace std;

struct Vetor{
    int * _data;//bloco de dados
    int _capacidade;//tamanho maximo do vetor
    int _size; //quantos elementos estao inseridos

    Vetor(int capacidade){
        this->_capacidade = capacidade;
        this->_size = 0;
//        this->data = (int*) malloc(capacidade * 4);//retorno lixo
        this->_data = new int[capacidade];//retorno zerado
    }
    void push_back(int value){
        if(this->_size == this->_capacidade)
            return;
            //this->reserve(2 * _capacitade);
        this->_data[this->_size] = value;
        this->_size += 1;
    }
    void pop_back(){
        if(this->_size == 0)
            return;
        this->_data[_size] = 0;
        this->_size -= 1;
    }

    //retornar a refencia à variavel dessa posicao
    int& at(int indice){
        return this->_data[indice];
    }
    int& front(){
        return this->_data[0];
    }
    int& back(){
        return this->_data[this->_size - 1];
    }
    int * begin(){
        return &this->_data[0];
    }
    int * end(){
        return &this->_data[this->_size];
    }
    int size(){
        return this->_size;
    }

    int capacity(){
        return this->_capacidade;

    }

    void reserve(int new_capacity){
        if(this->_capacidade < new_capacity)
            return;
        int *novos_dados = new int[this->_size * 2];
        for(int i = 0; i < this->_size; i++){
            novos_dados[i] = this->_data[i];
        }

        this->_data = novos_dados;
        //salva o bloco antigo em algum lugar
        //pede um novo bloco de dados
    }

};


int main(){

    Vetor teste_vetor(5);

    teste_vetor.push_back(1);
    teste_vetor.push_back(2);
    teste_vetor.push_back(3);
    teste_vetor.push_back(4);

    for(auto i : teste_vetor){
        cout << i << " ";
    }
    cout << endl;

    cout << "O elemento do indice[3] é: " << teste_vetor.at(3);
    cout << endl;
    teste_vetor.at(1) = 8;

    cout << "Capacidade: " << teste_vetor.capacity() << endl;
    cout << "Size: " << teste_vetor.size();
    cout << endl;

    for(auto i : teste_vetor){
        cout << i << " ";
    }

    cout << endl;
    teste_vetor.reserve(30);

    cout << "Capacidade nova: " << teste_vetor.capacity() << endl;

    return 0;
    }


