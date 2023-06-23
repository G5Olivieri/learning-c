#ifndef FILA_H_
#define FILA_H_
#include <iostream>

class fila {
	int value;
	int size;
	fila* next;
public:
	fila();
	void setValue(int);
	int getValue();
	void setSize(int);
	int getSize();
	void setNext(fila*);
	fila* getNext();
	bool testEmpty(fila* f);
	fila* lastElement(fila* f);
	fila* pusher();
	void push(fila* f);
	void pop(fila* f);
	void free(fila* f);
	fila* show(fila* f);
	void order(fila* f);
};

#endif /* FILA_H_ */
