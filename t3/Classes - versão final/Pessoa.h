#ifndef PESSOA_H_INCLUDED
#define PESSOA_H_INCLUDED

// Arquivo de cabeçalho
#include <iostream>
using namespace std;

// Definindo o namespace
namespace poo{

    class Pessoa{

        friend ostream& operator<<(ostream&, const Pessoa&);

        public:

            Pessoa(string, string);
            ~Pessoa();
            string getNome() const;
            string getCPF() const;

        private:

            const string nome, CPF;
    };

}


#endif // PESSOA_H_INCLUDED
