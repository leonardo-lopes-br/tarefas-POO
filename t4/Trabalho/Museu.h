#include <string>
#include <vector>
#include "ObraDeArte.h"
using std::string;
using std::vector;

#ifndef MUSEU_H_INCLUDED
#define MUSEU_H_INCLUDED

namespace catalogo{
    class Museu{
        public:
            Museu(string);
            string getNome() const;
            void setNome(string);
            bool adicionaObra(ObraDeArte *);
            bool removeObra(string);
            ObraDeArte * obtemObra(string) const;
            void imprime(int) const;
            static int qtdeObras();
            static int qtdePinturas();
            static int qtdeEsculturas();

        private:
            string nome;
            vector <ObraDeArte *> obras;
            static int nroObras;
            static int nroPinturas;
            static int nroEsculturas;
    };

}


#endif // MUSEU_H_INCLUDED
