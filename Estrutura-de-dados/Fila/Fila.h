#ifndef FILA_H
#define FILA_H
#include <cstddef>
#include <ostream>

#define VAZIA -98143743
class No
{
public:
    No()
    {
        setProx(NULL);
    }

    No(int valor)
    {
        setProx(NULL);
        setValor(valor);
    }

    No(No *prox, int valor)
    {
        setProx(prox);
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

    No *getProx()
    {
        return this->prox;
    }

    int getValor()
    {
        return this->valor;
    }

private:
    No *prox;
    int valor;
};

class Fila
{
public:
    Fila()
    {
        setInicio(NULL);
        setFim(NULL);
        setTamanho(0);
    }
    Fila(int valor)
    {
        setInicio(NULL);
        setFim(NULL);
        push(valor);
        setTamanho(1);
    }

    void setInicio(No *inicio)
    {
        this->inicio = inicio;
    }

    void setFim(No *fim)
    {
        this->fim = fim;
    }

    void setTamanho(int tamanho)
    {
        this->tamanho = tamanho;
    }

    int getTamanho()
    {
        return this->tamanho;
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
    void push(int);
    int pop();
    friend std::ostream& operator<<(std::ostream&, Fila*);
private:
    No *inicio;
    No *fim;
    int tamanho;
};
#endif // FILA_H
