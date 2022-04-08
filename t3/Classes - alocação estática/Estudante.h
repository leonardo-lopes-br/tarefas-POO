#ifndef ESTUDANTE_H_INCLUDED
#define ESTUDANTE_H_INCLUDED

// Incluindo a classe que será herdada
#include "Pessoa.h"

// Definindo o namespace
namespace poo{

    // Definindo a herança
    class Estudante: public Pessoa{

        friend ostream& operator<<(ostream&, const Estudante&);

        public:

            Estudante(string, string, int, double, double, double, double);
            ~Estudante();

            int getRA() const;
            double media() const;

            bool aprovado() const;
            bool sac() const;
            double notaSAC() const;

        private:

            string nome, CPF;
            int RA;
            double notaP1, notaP2, notaT1, notaT2;

    };

}


#endif // ESTUDANTE_H_INCLUDED
