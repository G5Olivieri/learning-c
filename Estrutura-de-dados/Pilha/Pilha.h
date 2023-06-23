#ifndef PILHA_H
#define PILHA_H
#include <iostream>
#include "No.h"
using namespace std;

class Pilha
{
    public:
        Pilha();
        Pilha(int);
        virtual ~Pilha();
        bool vazia();
        No *getTopo();
        int getValor();
        void setTopo(No *);
        void push(int valor);
        void pop();
        friend ostream& operator<<(ostream&, Pilha*);
    protected:
    private:
        No *topo;
};

#endif // PILHA_H
