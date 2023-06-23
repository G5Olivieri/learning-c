#ifndef NO_H
#define NO_H

class No
{
    public:
        No();
        No(int);
        No(No *);
        int getValor();
        void setValor(int);
        void setProx(No *);
        No *getProx();
    protected:
    private:
        No *prox;
        int valor;
};

#endif // NO_H
