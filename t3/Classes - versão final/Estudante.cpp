#include "Estudante.h"

// Definindo o namespace
namespace poo{

    Estudante::Estudante(string nome, string cpf, int RA, double p1, double p2, double t1, double t2)
    : Pessoa(nome, cpf), RA(RA), notaP1(p1), notaP2(p2), notaT1(t1), notaT2(t2){}

    // A implementa??o expl?cita do Destrutor n?o ? necess?ria neste caso pois a classe n?o utiliza ponteiros
    Estudante::~Estudante(){}

    int Estudante::getRA() const { return this->RA; }

    double Estudante::media() const {
        double MP = (this->notaP1 + this->notaP2) / 2;
        double MT = (this->notaT1 + this->notaT2) / 2;
        double MF = (MP * 8 + MT * 2) / 10;
        return MF;
    }

    bool Estudante::aprovado() const { return media() >= 6; }

    bool Estudante::sac() const { return media() >= 5 && media() < 6; }

    double Estudante::notaSAC() const { return sac() ? 12 - media() : 0; }

    ostream& operator<<(ostream& out, const Estudante & e){
        out << "Nome: " << e.getNome() << endl;
        out << "CPF: " << e.getCPF() << endl;
        out << "Media final: " << e.media() << endl;
        return out;
    }

}
