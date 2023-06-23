#include "stack.h"

stack::stack()
{
	this->value = 0;
	this->sizeStack = 0;
	this->next = NULL;
}

stack::stack(stack* s)
{
	s->setNext(NULL);
	setSizeStack(0);
}

void stack::setValue(int n)
{
	this->value = n;
}

int stack::getValue()
{
	return this->value;
}


void stack::setNext(stack* s)
{
	this->next = s;
}

stack* stack::getNext()
{
	return this->next;
}

void stack::setSizeStack(int n)
{
	this->sizeStack = n;
}

int stack::getSizeStack()
{
	return this->sizeStack;
}

bool stack::testEmpty(stack* s)
{
	if(s->getNext() == NULL) return true;
	else return false;
}
stack* stack::pusher()
{
		stack* ptr = new stack();
		if(!ptr){
			std::cout << "Sem espaco na memoria !!";
			return NULL;
		}
		else{
			std::cout << "Digite o valor do elemento: ";
			int n;
			std::cin >> n;
			ptr->setValue(n);
			return ptr;
		}
}

stack* stack::lastElement(stack* s)
{
	if(s->getNext() == NULL) return s;
	else
		return lastElement(s->getNext());
}

stack* stack::antlastElement(stack* s)
{
	stack* antlast, *last;
	antlast = last = s->getNext();
	while(last->getNext())
	{
		antlast = last;
		last = last->getNext();
	}
	return antlast;
}

void stack::push(stack* s)
{
	stack* ptr = pusher();
	ptr->setNext(NULL);
	if(testEmpty(s))
	{
		s->setNext(ptr);
		setSizeStack(getSizeStack()+1);
	}
	else
	{
		stack* temp = lastElement(s);
		temp->setNext(ptr);
		setSizeStack(getSizeStack()+1);
	}
}

void stack::pop(stack* s)
{
	if(testEmpty(s))
	{
		std::cout << "Nao tem elemento para remover\n";
		return;
	}
	else
	{
		stack* last = lastElement(s);
		stack* antlast = antlastElement(s);
		std::cout << "Elemento removido: " << last->getValue() << std::endl;
		delete last;
		antlast->setNext(NULL);
		setSizeStack(getSizeStack()-1);
	}
}

void stack::freeStack(stack* s)
{
	if(testEmpty(s))
	{
		std::cout << "Lista vazia: ";
	}
	else
	{
		stack* current = s->getNext();
		stack* _next;
		while(current)
		{
			_next = current->getNext();
			delete current;
			current = _next;
		} std::cout << "Lista vazia: ";
		stack(s);
	}
}

stack* stack::showStack(stack* s)
{
	if(s->getNext() == NULL) return NULL;
	else
	{
		std::cout << s->getNext()->getValue() << std::endl;
		return showStack(s->getNext());
	}
}

void stack::orderStack(stack* s)
{
	int temp;
	stack* ptr = s->getNext();
	stack* cpr;
	while(ptr)
	{
		cpr = ptr->getNext();
		for(int i = 0; cpr; i++)
		{
			if(ptr->getValue() > cpr->getValue())
			{
				temp = ptr->getValue();
				ptr->setValue(cpr->getValue());
				cpr->setValue(temp);
			}
			cpr = cpr->getNext();
		}
		ptr = ptr->getNext();
	}
}
