#include "Pessoa.h"

// Definindo o namespace
namespace poo{

    Pessoa::Pessoa(string nome, string cpf)
        : nome(nome), CPF(cpf){}

    // A implementação explícita do Destrutor não é necessária neste caso pois a classe não utiliza ponteiros
    Pessoa::~Pessoa(){}

    string Pessoa::getNome() const{ return this->nome; }

    string Pessoa::getCPF() const { return this->CPF; }

    ostream& operator<<(ostream& out, const Pessoa & p){
        out << "Nome: " << p.getNome() << endl;
        out << "CPF: " << p.getCPF() << endl;
        return out;
    }

}
