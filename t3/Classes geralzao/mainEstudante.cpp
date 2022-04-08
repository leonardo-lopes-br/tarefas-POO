#include "Estudante.cpp"
#include "Pessoa.cpp"
using namespace poo;

int main(void){

    Estudante e1("Leonardo", "48978806880", 761880, 10, 10, 10, 9);
    string nome = e1.getNome();
    string cpf = e1.getCPF();
    int ra = e1.getRA();


    cout << "Printando sem a funcao: \n" << endl;
    cout << "nome: " << nome << endl;
    cout << "cpf: " << cpf << endl;
    cout << "ra: " << ra << endl;

    cout << endl;
    cout << "Imprimindo pelo cout: " << endl << endl;
    cout << e1;
    cout << endl << endl;

    bool aprovado = e1.aprovado();
    bool ficouSac = e1.sac();
    double notaSac = e1.notaSAC();
    printf("Aluno aprovado? --> %d\n", aprovado);
    printf("Aluno ficou de rec? --> %d\n", ficouSac);
    printf("Nota da rec: %.2f\n", notaSac);


	return 0;
}
