#include <string>
#include "ObraDeArte.h"
using std::string;

#ifndef PINTURA_H_INCLUDED
#define PINTURA_H_INCLUDED

namespace catalogo{
    class Pintura: public ObraDeArte{

        public:
            Pintura(string, string, string, int, string);
            virtual int getCategoria() const;
            virtual void imprimeFicha() const;
            string getTipo() const;
            void setTipo(string);

        private:
            string titulo, artista, material, tipo;
            int anoCriacao;
    };
}

#endif // PINTURA_H_INCLUDED
