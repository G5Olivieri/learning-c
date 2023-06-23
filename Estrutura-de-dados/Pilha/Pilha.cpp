#include "Pilha.h"
using namespace std;

Pilha::Pilha()
{
    setTopo(NULL);
}

Pilha::Pilha(int valor)
{
    setTopo(new No(valor));
}

int Pilha::getValor()
{
    return this->topo->getValor();
}

No *Pilha::getTopo()
{
    return this->topo;
}

void Pilha::setTopo(No *no)
{
    this->topo = no;
}

bool Pilha::vazia()
{
    return getTopo() == NULL;
}

void Pilha::push(int valor)
{
    if(vazia())
    {
        this->topo = new No(valor);
    }
    else
    {
        No *temp = new No(valor);
        temp->setProx(getTopo());
        topo = temp;
    }
}

void Pilha::pop()
{
    if(vazia())
    {
        return;
    }
    if(!this->topo->getProx())
    {
        delete topo;
        setTopo(NULL);
    }
    else
    {
        No *temp = topo;
        this->setTopo(topo->getProx());
        delete temp;
    }

}

ostream& operator<< (ostream &out, Pilha *p)
{
    No *temp = p->getTopo();
    while(temp)
    {
        out << temp->getValor() << " ";
        temp = temp->getProx();
    }
    return out;
}

Pilha::~Pilha()
{

}
