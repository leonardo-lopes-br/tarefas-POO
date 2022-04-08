#include "Museu.h"
#include <iostream>
using namespace std;


namespace catalogo{

    Museu::Museu(string nome){
        setNome(nome);
    }

    int Museu::nroObras = 0;
    int Museu::nroPinturas = 0;
    int Museu::nroEsculturas = 0;

    int Museu::qtdeObras(){ return nroObras; }
    int Museu::qtdePinturas(){ return nroPinturas; }
    int Museu::qtdeEsculturas(){ return nroEsculturas; }

    string Museu::getNome() const { return this->nomeDaObra; }

    void Museu::setNome(string novoNome){ this->nomeDaObra = novoNome; }

    bool Museu::adicionaObra(ObraDeArte * novaObra){
        unsigned int i = 0;
        while (i < this->obras.size() && this->obras[i]->getTitulo() != novaObra->getTitulo())
            i++;
        if (i == this->obras.size()){
            this->obras.push_back(novaObra);
            nroObras++;
            if (novaObra->getCategoria() == 1)
                nroPinturas++;
            else if (novaObra->getCategoria() == 2)
                nroEsculturas++;
            return true;
        }
        return false;
    }

    bool Museu::removeObra(string titulo){
        unsigned int i = 0;
        while (i < this->obras.size() && this->obras[i]->getTitulo() != titulo)
            i++;
        if (i != this->obras.size() && this->obras[i]->getTitulo() == titulo){
            if (this->obras[i]->getCategoria() == 1)
                nroPinturas--;
            else if (this->obras[i]->getCategoria() == 2)
                nroEsculturas--;
            this->obras.erase(this->obras.begin() + i);
            nroObras--;
            return true;
        }
        return false;
    }

    ObraDeArte * Museu::obtemObra(string titulo) const {
        unsigned int i = 0;
        while (i < this->obras.size() && this->obras[i]->getTitulo() != titulo)
            i++;
        if (i != this->obras.size()){
            return this->obras[i];
        }
        return NULL;
    }

    void Museu::imprime(int categoria) const {
        bool auxiliarImprimeTodos = categoria == 0;
        for (int i = 0; i < qtdeObras(); i++)
            if (this->obras[i]->getCategoria() == categoria || auxiliarImprimeTodos)
                this->obras[i]->imprimeFicha();
    }
}
