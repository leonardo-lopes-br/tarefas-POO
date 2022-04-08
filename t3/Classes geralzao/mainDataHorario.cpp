#include "DataHorario.cpp"
using std::cout;
using namespace poo;
int main(void){

    DataHorario nascimento(3, 8, 200, 7, 9, 3);
    DataHorario casamento(10, 4, 2020, 12, 40, 59);
    cout << nascimento;
    cout << casamento;
    if (nascimento >= casamento)
        printf("Eh maior ou igual!\n");


	return 0;
}
