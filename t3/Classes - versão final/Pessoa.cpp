#include "Pessoa.h"

// Definindo o namespace
namespace poo{

    Pessoa::Pessoa(string nome, string cpf)
        : nome(nome), CPF(cpf){}

    // A implementa��o expl�cita do Destrutor n�o � necess�ria neste caso pois a classe n�o utiliza ponteiros
    Pessoa::~Pessoa(){}

    string Pessoa::getNome() const{ return this->nome; }

    string Pessoa::getCPF() const { return this->CPF; }

    ostream& operator<<(ostream& out, const Pessoa & p){
        out << "Nome: " << p.getNome() << endl;
        out << "CPF: " << p.getCPF() << endl;
        return out;
    }

}
