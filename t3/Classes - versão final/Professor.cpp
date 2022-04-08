#include "Professor.h"

// Definindo o namespace
namespace poo{

    Professor::Professor(string nome, string cpf, string univ)
    :   Pessoa(nome, cpf), universidade(univ){}

    // A implementação explícita do Destrutor não é necessária neste caso pois a classe não utiliza ponteiros
    Professor::~Professor(){}

    string Professor::getUniversidade() const { return this->universidade; }

    ostream& operator<<(ostream& out, const Professor& prof){
        out << "Nome: " << prof.getNome() << endl;
        out << "CPF: " << prof.getCPF() << endl;
        out << "Universidade: " << prof.getUniversidade() << endl;
        return out;
    }

}
