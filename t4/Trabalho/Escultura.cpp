#include "Escultura.h"
#include <iostream>
using namespace std;

namespace catalogo{

    Escultura::Escultura(string titulo, string artista, string material, int anoCriacao, double altura)
    : ObraDeArte(titulo, artista, material, anoCriacao){
        setAltura(altura);
    }

    int Escultura::getCategoria() const { return 2; }

    void Escultura::imprimeFicha() const {
        ObraDeArte::templateFicha();
        cout << "Altura: " << getAltura() << endl << endl;
    }

    double Escultura::getAltura() const { return this->altura; }
    void Escultura::setAltura(double novaAltura){ this->altura = novaAltura; }
}
