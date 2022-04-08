#ifndef PESSOA_H_INCLUDED
#define PESSOA_H_INCLUDED

#include <iostream>
using namespace std;

namespace poo{

    class Pessoa{

        friend ostream& operator<<(ostream&, const Pessoa&);
        public:

            Pessoa(string = " ", string = " ");
            ~Pessoa();
            string getNome() const;
            string getCPF() const;

        private:

            string nome;
            string CPF;
    };

}


#endif // PESSOA_H_INCLUDED
