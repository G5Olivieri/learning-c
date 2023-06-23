#include "No.h"
#include <iostream>
using namespace std;

No::No()
{
    setProx(NULL);
}

No::No(No *p)
{
    setProx(p);
}

No::No(int valor)
{
    setProx(NULL);
    setValor(valor);
}

void No::setValor(int valor)
{
    this->valor = valor;
}

int No::getValor()
{
    return this->valor;
}

No *No::getProx()
{
    return this->prox;
}

void No::setProx(No *no)
{
    this->prox = no;
}
