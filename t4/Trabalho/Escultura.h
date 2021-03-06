#include <string>
#include "ObraDeArte.h"
using std::string;

#ifndef ESCULTURA_H_INCLUDED
#define ESCULTURA_H_INCLUDED

namespace catalogo{
    class Escultura: public ObraDeArte{
        public:
            Escultura(string, string, string, int, double);
            virtual int getCategoria() const;
            virtual void imprimeFicha() const;
            double getAltura() const;
            void setAltura(double);

        private:
            string titulo, artista, material;
            int anoCriacao;
            double altura;
    };
}


#endif // ESCULTURA_H_INCLUDED
