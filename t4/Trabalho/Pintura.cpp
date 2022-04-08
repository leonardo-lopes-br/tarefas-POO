#include "Pintura.h"
#include <iostream>
using namespace std;

namespace catalogo{

    Pintura::Pintura(string titulo, string artista, string material, int anoCriacao, string tipo)
    : ObraDeArte(titulo, artista, material, anoCriacao){
        setTipo(tipo);
    }

    int Pintura::getCategoria() const{ return 1; }

    void Pintura::imprimeFicha() const{
        ObraDeArte::templateFicha();
        cout << "Tipo: " << getTipo() << endl << endl;
    }

    string Pintura::getTipo() const { return this->tipo; }
    void Pintura::setTipo(string novoTipo) { this->tipo = novoTipo; }
}

//int main(void){return 0;}
