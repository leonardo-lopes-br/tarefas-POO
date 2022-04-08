#ifndef PROFESSOR_H_INCLUDED
#define PROFESSOR_H_INCLUDED

#include "Pessoa.h"

namespace poo{

    class Professor: public Pessoa {

        public:

            Professor(string, string, string);
            ~Professor();
            string getUniversidade() const;
            friend ostream& operator<<(ostream&, const Professor&);

        private:

            string nome, CPF, universidade;
    };

}

#endif // PROFESSOR_H_INCLUDED
