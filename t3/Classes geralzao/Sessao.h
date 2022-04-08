#ifndef SESSAO_H_INCLUDED
#define SESSAO_H_INCLUDED

#include "DataHorario.h"
#include "Pessoa.h"

namespace poo{

    class Sessao{

        friend ostream& operator<<(ostream &, const Sessao &);

        public:
            Sessao(string, DataHorario &);
            ~Sessao();
            string proximoLivre() const;
            bool verifica(string) const;
            bool ocupa(string, Pessoa &);
            bool desocupa(string);
            int vagas() const;

        private:
            const string nomeDaPeca;
            const DataHorario data_Horario;
            Pessoa expectador[15][14];

    };

}


#endif // SESSAO_H_INCLUDED
