#ifndef PROFESSOR_H_INCLUDED
#define PROFESSOR_H_INCLUDED

#include "Pessoa.h"

// Definindo o namespace
namespace poo{

    // Definindo a herança
    class Professor: public Pessoa {

        friend ostream& operator<<(ostream&, const Professor&);

        public:

            Professor(string, string, string);
            ~Professor();
            string getUniversidade() const;

        private:

            const string nome, CPF;
            string universidade;
    };

}

#endif // PROFESSOR_H_INCLUDED
