#include "Sessao.h"

// Definindo o namespace
namespace poo{

    Sessao::Sessao(string nomePeca, DataHorario & dataHora)
    : nomeDaPeca(nomePeca), data_Horario(dataHora)
    {
        for (int i = 0; i < 15; i++)
            for (int j = 0; j < 14; j++)
                expectador[i][j] = NULL;
    }

    // A implementação explícita do Destrutor não é necessária neste caso pois a classe não utiliza ponteiros
    Sessao::~Sessao(){}

    string Sessao::proximoLivre() const{
        string letras = "ABCDEFGHIJKLMNO";
        for (int i = 0; i < 15; i++)
            for (int j = 0; j < 14; j++)
                if (expectador[i][j] == NULL)
                    return letras[i] + to_string(j+1);
        return "cheio";
    }

    bool Sessao::verifica(string poltrona) const{
        int linha = poltrona[0] - 'A';
        int coluna = stoi(poltrona.substr(1)) - 1;
        return expectador[linha][coluna] != NULL ? true : false;
    }

    bool Sessao::ocupa(string poltrona, Pessoa & person){
        if (!verifica(poltrona)){
            int linha = poltrona[0] - 'A';
            int coluna = stoi(poltrona.substr(1)) - 1;
            expectador[linha][coluna] = new Pessoa(person.getNome(), person.getCPF());
            return true;
        }
        return false;
    }

    bool Sessao::desocupa(string poltrona){
        if (verifica(poltrona)){
            int linha = poltrona[0] - 'A';
            int coluna = stoi(poltrona.substr(1)) - 1;
            expectador[linha][coluna] = NULL;
            return true;
        }
        return false;
    }

    int Sessao::vagas() const{
        int numero_vagas_livres = 0;
        if (!(proximoLivre() == "cheio")){
            for (int i = 0; i < 15; i++)
                for (int j = 0; j < 14; j++)
                    if (expectador[i][j] == NULL)
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
                string expect = session.expectador[i][j] == NULL ? "Vazio!" : session.expectador[i][j]->getNome();
                out << poltrona << "\t" << expect << endl;
            }
            out << endl;
        }

        return out;
    }
}
