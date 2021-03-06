#ifndef ESTUDANTE_H_INCLUDED
#define ESTUDANTE_H_INCLUDED

#include "Pessoa.h"

namespace poo{

    class Estudante: public Pessoa{

        public:

            Estudante(string, string, int, double, double, double, double);
            ~Estudante();

            int getRA() const;
            double media() const;

            bool aprovado() const;
            bool sac() const;
            double notaSAC() const;

            friend ostream& operator<<(ostream&, const Estudante&);


        private:

            string nome, CPF;
            int RA;
            double notaP1, notaP2, notaT1, notaT2;

    };

}


#endif // ESTUDANTE_H_INCLUDED
