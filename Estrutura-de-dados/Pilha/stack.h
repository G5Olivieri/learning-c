#ifndef STACK_H_
#define STACK_H_
#include <iostream>

class stack {
	int value;
	stack* next;
	int sizeStack;
public:
	stack();
	stack(stack* s);
	void setValue(int n);
	int getValue();
	void setNext(stack* s);
	stack* getNext();
	void setSizeStack(int n);
	int getSizeStack();
	bool testEmpty(stack* s);
	stack* pusher();
	stack* lastElement(stack* s);
	stack* antlastElement(stack* s);
	void push(stack* s);
	void pop(stack* s);
	void freeStack(stack* s);
	stack* showStack(stack* s);
	void orderStack(stack* s);
};

#endif /* STACK_H_ */
