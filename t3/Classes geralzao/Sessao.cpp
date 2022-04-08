#include "Sessao.h"

namespace poo{

    Sessao::Sessao(string nomePeca, DataHorario & dataHora)
    : nomeDaPeca(nomePeca), data_Horario(dataHora){}

    Sessao::~Sessao(){}

    string Sessao::proximoLivre() const{
        string letras = "ABCDEFGHIJKLMNO";
        for (int i = 0; i < 15; i++)
            for (int j = 0; j < 14; j++)
                if (expectador[i][j].getNome() == " ")
                    return letras[i] + to_string(j+1);
        return "cheio";
    }

    bool Sessao::verifica(string poltrona) const{
        int linha = poltrona[0] - 'A';
        int coluna = stoi(poltrona.substr(1)) - 1;
        return expectador[linha][coluna].getNome() != " " ? true : false;
    }

    bool Sessao::ocupa(string poltrona, Pessoa & person){
        if (!verifica(poltrona)){
            int linha = poltrona[0] - 'A';
            int coluna = stoi(poltrona.substr(1)) - 1;
            expectador[linha][coluna] = person;
            return true;
        }
        return false;
    }

    bool Sessao::desocupa(string poltrona){
        if (verifica(poltrona)){
            int linha = poltrona[0] - 'A';
            int coluna = stoi(poltrona.substr(1)) - 1;
            Pessoa sem_expectador(" ", " ");
            expectador[linha][coluna] = sem_expectador;
            return true;
        }
        return false;
    }

    int Sessao::vagas() const{
        int numero_vagas_livres = 0;
        if (!(proximoLivre() == "cheio")){
            for (int i = 0; i < 15; i++)
                for (int j = 0; j < 14; j++)
                    if (expectador[i][j].getNome() == " ")
                        numero_vagas_livres++;
        }
        return numero_vagas_livres;
    }

    ostream & operator<<(ostream & out, const Sessao & session){
        out << "Nome da peça: " << session.nomeDaPeca << endl;
        out << "Data e horário: " << session.data_Horario << endl;
        string letras = "ABCDEFGHIJKLMNO";
        for (int i = 0; i < 15; i++){
                out << "\nPoltronas " << letras[i] << "1-" << letras[i] << "14" << endl << endl;
            for (int j = 0; j < 14; j++){
                string poltrona = letras[i] + to_string(j+1);
                string expect = session.expectador[i][j].getNome();
                expect = expect == " " ? "Vazio!" : expect;
                out << poltrona << "\t" << expect << endl;
            }
            out << endl;
        }

        return out;
    }
}
