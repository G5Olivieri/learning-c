#include <iostream>
#include <Fila.h>
using namespace std;

int main()
{
    Fila *fila = new Fila(59);
    fila->push(100);
    fila->push(45);
    fila->push(52);
    fila->push(76);
    fila->push(54);
    fila->push(8);
    fila->push(56);
    fila->push(98);
    fila->push(65);
    fila->push(12);
    fila->push(32);
    fila->push(43);
    fila->push(68);
    fila->push(26);
    fila->push(97);
    cout << "Tamanho " << fila->getTamanho() << endl;
    cout << fila << endl;
    cout << "POP " << fila->pop() << "\n";
    cout << "Tamanho " << fila->getTamanho() << endl;
    cout << fila;
    return 0;
}
