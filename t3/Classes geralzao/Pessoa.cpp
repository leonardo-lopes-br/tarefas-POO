#include "Pessoa.h"

namespace poo{

    Pessoa::Pessoa(string nome, string cpf)
        : nome(nome), CPF(cpf){}

    Pessoa::~Pessoa(){}

    string Pessoa::getNome() const{ return this->nome; }

    string Pessoa::getCPF() const { return this->CPF; }

    ostream& operator<<(ostream& out, const Pessoa & p){
        out << "Nome: " << p.getNome() << endl;
        out << "CPF: " << p.getCPF() << endl;
        return out;
    }

}
