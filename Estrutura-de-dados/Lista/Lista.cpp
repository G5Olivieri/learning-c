#include "Lista.h"

bool Lista::vazia()
{
    return getInicio() == NULL;
}

void Lista::pushBack(int valor)
{
    if(vazia())
    {
        setInicio(new No(valor));
        setFim(getInicio());
    }
    else
    {
        No *no = new No(valor);
        no->setAnt(getInicio());
        getInicio()->setProx(no);
        setInicio(no);
    }
}

void Lista::pushEnd(int valor)
{
    if(vazia())
    {
        setInicio(new No(valor));
        setFim(getInicio());
    }
    else
    {
        No *no = new No(valor);
        no->setProx(getFim());
        getFim()->setProx(no);
        setFim(no);
    }
}

Lista::~Lista()
{

}
