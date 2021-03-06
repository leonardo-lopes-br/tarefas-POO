#include "ObraDeArte.h"
#include <iostream>
using namespace std;

namespace catalogo{

    ObraDeArte::ObraDeArte(string titulo, string artista, string material, int anoCriacao){
        setTitulo(titulo);
        setArtista(artista);
        setMaterial(material);
        setAnoCriacao(anoCriacao);
    }

    string ObraDeArte::getTitulo() const { return this->titulo; }
    string ObraDeArte::getArtista() const { return this->artista; }
    string ObraDeArte::getMaterial() const { return this->material; }
    int ObraDeArte::getAnoCriacao() const { return this->anoCriacao; }

    void ObraDeArte::setTitulo(string novoTitulo){ this->titulo = novoTitulo; }
    void ObraDeArte::setArtista(string novoArtista){ this->artista = novoArtista; }
    void ObraDeArte::setMaterial(string novoMaterial){ this->material = novoMaterial; }
    void ObraDeArte::setAnoCriacao(int novoAnoCriacao){ this->anoCriacao = novoAnoCriacao; }

    void ObraDeArte::templateFicha() const{
        string categoria;
        if (getCategoria() == 1) categoria = "Pintura";
        else if (getCategoria() == 2) categoria = "Escultura";
        cout << "Categoria: " << categoria << endl;
        cout << "Titulo: " << getTitulo() << endl;
        cout << "Artista: " << getArtista() << endl;
        cout << "Ano: " << getAnoCriacao() << endl;
    }
}
