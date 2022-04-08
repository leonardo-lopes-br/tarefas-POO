#include "DataHorario.h"

// Arquivo de cabeçalho
#include <iomanip>
using std::setfill;
using std::string;
using std::endl;
using std::setw;

// Definindo o namespace
namespace poo{

    DataHorario::DataHorario(int _dia, int _mes, int _ano, int _hora, int _minuto, int _segundo){

        bool segundo_valido = _segundo >= 0 && _segundo <= 59;
        bool minuto_valido = _minuto >= 0 && _minuto <= 59;
        bool hora_valida = _hora >= 0 && _hora <= 23;
        bool ano_valido = _ano > 0;
        bool mes_valido = _mes >= 1 && _mes <= 12;

        bool dataHorario_Valido = segundo_valido && minuto_valido && hora_valida && ano_valido && mes_valido;

        // Se todos forem válidos, pode-se avaliar o dia, que é mais complexo.
        if (dataHorario_Valido){
            bool dia_valido;
            bool bissexto = (_ano % 400 == 0) || (_ano % 4 == 0 && _ano % 100 != 0);
            bool dia_valido_inicial = _dia >= 1;
            if (dia_valido_inicial)
                switch(_mes){
                case 1:
                case 3:
                case 5:
                case 7:
                case 8:
                case 10:
                case 12:
                    dia_valido = _dia <= 31;
                    break;
                case 4:
                case 6:
                case 9:
                case 11:
                    dia_valido = _dia <= 30;
                    break;
                case 2:
                    dia_valido = bissexto ? _dia <= 29 : _dia <= 28;
                    break;
            }
            dataHorario_Valido = dataHorario_Valido && dia_valido;
            // Se todas as informações forem válidas, seta os atributos com os parâmetros
            if (dataHorario_Valido){
                this->dia = _dia;
                this->mes = _mes;
                this->ano = _ano;
                this->hora = _hora;
                this->minuto = _minuto;
                this->segundo = _segundo;
            }
            else{
                // Configurando o padrão para parâmetros errados
                this->dia = this->mes = this->ano = 1;
                this->hora = this->minuto = this->segundo = 0;
            }
        }
        else{
            // Configurando o padrão para parâmetros errados
            this->dia = this->mes = this->ano = 1;
            this->hora = this->minuto = this->segundo = 0;
        }
    }

    // Destrutor não utiliza ponteiros
    DataHorario::~DataHorario(){}

    int DataHorario::getSegundo() const { return this->segundo; }
    int DataHorario::getMinuto() const { return this->minuto; }
    int DataHorario::getHora() const { return this->hora; }
    int DataHorario::getDia() const { return this->dia; }
    int DataHorario::getMes() const { return this->mes; }
    int DataHorario::getAno() const { return this->ano; }

    ostream& operator<<(ostream & out, const DataHorario & dh){
        string meses[12] = {"Janeiro", "Fevereiro", "Março", "Abril", "Maio", "Junho",
                            "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"};

        out << setfill('0') << setw(2) << dh.getDia() << " de " << meses[dh.getMes() - 1];
        out << " de " << setfill('0') << setw(4) << dh.getAno() << " - " << setw(2) << dh.getHora();
        out << " hora(s), " << setfill('0') << setw(2) <<  dh.getMinuto() << " minuto(s) e ";
        out << setfill('0') << setw(2) << dh.getSegundo() << " segundo(s)." << endl;
        return out;
    }

    bool DataHorario::operator<(const DataHorario & dh_direita) const {
        // Obtendo os atributos para as comparações
        int this_atributos[6], dh_direita_atributos[6];
        this_atributos[0] = this->getAno(); dh_direita_atributos[0] = dh_direita.getAno();
        this_atributos[1] = this->getMes(); dh_direita_atributos[1] = dh_direita.getMes();
        this_atributos[2] = this->getDia(); dh_direita_atributos[2] = dh_direita.getDia();
        this_atributos[3] = this->getHora(); dh_direita_atributos[3] = dh_direita.getHora();
        this_atributos[4] = this->getMinuto(); dh_direita_atributos[4] = dh_direita.getMinuto();
        this_atributos[5] = this->getSegundo(); dh_direita_atributos[5] = dh_direita.getSegundo();
        int indice = 0;
        // Comparando os atributos através dos vetores de auxílio
        while (indice < 6){
            if (this_atributos[indice] < dh_direita_atributos[indice])
                return true;
            else if (this_atributos[indice] > dh_direita_atributos[indice])
                return false;
            indice++;
        }
        return false;
    }

    bool DataHorario::operator==(const DataHorario & dh_direita) const{
        // Obtendo as expressões para a análise da igualdade
        bool expressoes[6];
        expressoes[0] = this->getAno() == dh_direita.getAno();
        expressoes[1] = this->getMes() == dh_direita.getMes();
        expressoes[2] = this->getDia() == dh_direita.getDia();
        expressoes[3] = this->getHora() == dh_direita.getHora();
        expressoes[4] = this->getMinuto() == dh_direita.getMinuto();
        expressoes[5] = this->getSegundo() == dh_direita.getSegundo();
        int indice = 0;
        // Avaliando os casos
        while (indice < 6){
            if (!expressoes[indice])
                return false;
            indice++;
        }
        return true;
    }

    bool DataHorario::operator<=(const DataHorario & dh_direita) const{
        return *this < dh_direita || *this == dh_direita;
    }

    bool DataHorario::operator!=(const DataHorario & dh_direita) const{
        return !(*this == dh_direita);
    }

    bool DataHorario::operator>(const DataHorario & dh_direita) const{
        return !(*this <= dh_direita);
    }

    bool DataHorario::operator>=(const DataHorario & dh_direita) const{
        return *this > dh_direita || *this == dh_direita;
    }
}
