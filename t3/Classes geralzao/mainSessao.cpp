#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "Sessao.cpp"
#include "Pessoa.cpp"
#include "DataHorario.cpp"

using namespace poo;

int main(void){

    Pessoa p1("Pedro", "123.456.789-01");
    DataHorario dh3(10, 3, 2022, 21, 00, 00);
    Sessao sessao("O Fantasma da �pera", dh3);



    for (int i = 0; i < 28; i++) {
        string s = sessao.proximoLivre();
        sessao.ocupa(s, p1);
    }


    cout << sessao;


	return 0;
}
