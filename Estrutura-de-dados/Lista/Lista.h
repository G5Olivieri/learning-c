#ifndef LISTA_H
#define LISTA_H
#include <cstddef>

class No
{
public:
    No()
    {
        setAnt(NULL);
        setProx(NULL);
    }
    No(int valor)
    {
        setAnt(NULL);
        setProx(NULL);
        setValor(valor);
    }

    void setValor(int valor)
    {
        this->valor = valor;
    }

    void setProx(No *prox)
    {
        this->prox = prox;
    }

    void setAnt(No *ant)
    {
        this->ant = ant;
    }

    int getValor()
    {
        return this->valor;
    }

    No *getProx()
    {
        return this->prox;
    }

    No *getAnt()
    {
        return this->ant;
    }

private:
    No *ant, *prox;
    int valor;

};

class Lista
{
public:
    Lista()
    {
        setInicio(NULL);
        setFim(NULL);
    }
    Lista(int valor)
    {
        setInicio(NULL);
        setFim(NULL);
        push(valor);
    }
    virtual ~Lista();
    void setInicio(No *inicio)
    {
        this->inicio = inicio;
    }
    void setFim(No *fim)
    {
        this->fim = fim;
    }
    No *getInicio()
    {
        return this->inicio;
    }
    No *getFim()
    {
        return this->fim;
    }
    bool vazia();
    void pushBack(int);
    void pushEnd(int);
    int pop();

private:
    No *inicio;
    No *fim;
};

#endif // LISTA_H
