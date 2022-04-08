#ifndef SESSAO_H_INCLUDED
#define SESSAO_H_INCLUDED

// Incluindo as classes que serão usadas
#include "DataHorario.h"
#include "Pessoa.h"

// Definindo o namespace
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
            string nomeDaPeca;
            DataHorario data_Horario;
            Pessoa * expectador[15][14];

    };

}


#endif // SESSAO_H_INCLUDED
