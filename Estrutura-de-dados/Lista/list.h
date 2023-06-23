#ifndef LISTA_H
#define LISTA_H
#include <iostream>

class lista
{
    private:
        int value;
        int pos;
        int Size;
        lista* next;
        lista* ant;
	public:
		lista();
		lista(lista* l);
		void setValue(int value);
		void setNext(lista* next);
		void setAnt(lista* ant);
		void setSize(int Size);
		void setPos(int pos);
		int getValue();
		int getSize();
		int getPos();
		lista* getNext();
		lista* getAnt();
		bool testEmpty(lista* l);
		lista* pusher(std::string s);
		lista* pusher(int p);
		void atualiza(lista* l);
		lista* lastElement(lista* l);
		void pushFirst(lista* l, lista* newNode);
		void pushBegin(lista* l);
		void pushEnd(lista* l);
		void pushPos(lista* l, int p);
		void popFirst(lista* l);
		void popBegin(lista* l);
		void popEnd(lista* l);
		void popPos(lista* l, int p);
		lista* show(lista* l);
		void free(lista* l);
};

#endif // LISTA_H
