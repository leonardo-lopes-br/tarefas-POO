#ifndef DATAHORARIO_H_INCLUDED
#define DATAHORARIO_H_INCLUDED

// Arquivo de cabeçalho
#include <iostream>
using std::ostream;

// Definindo o namespace
namespace poo{

    class DataHorario {

        public:

            DataHorario(int, int, int, int, int, int);
            ~DataHorario();
            int getDia() const;
            int getMes() const;
            int getAno() const;
            int getHora() const;
            int getMinuto() const;
            int getSegundo() const;
            bool operator<(const DataHorario &) const;
            bool operator==(const DataHorario &) const;
            bool operator<=(const DataHorario &) const;
            bool operator!=(const DataHorario &) const;
            bool operator>(const DataHorario &) const;
            bool operator>=(const DataHorario &) const;
            friend ostream& operator<<(ostream &, const DataHorario &);


        private:

            int dia, mes, ano, hora, minuto, segundo;
    };

}


#endif // DATAHORARIO_H_INCLUDED
