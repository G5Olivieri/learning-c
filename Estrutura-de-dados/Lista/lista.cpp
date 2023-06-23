#include "lista.h"

lista::lista()
{
	this->value = 0;
	this->pos = 0;
	this->Size = 0;
	this->next = NULL;
	this->ant = NULL;
}

lista::lista(lista* l)
{
	this->value = l->getValue();
	this->pos = l->getPos();
	this->Size = l->getSize();
	this->next = l->getNext();
	this->ant = l->getAnt();
}

void lista::setValue(int value)
{
	this->value = value;
}

void lista::setNext(lista* next)
{
	this->next = next;
}

void lista::setAnt(lista* ant)
{
	this->ant = ant;
}

void lista::setSize(int Size)
{
	this->Size = Size;
}

void lista::setPos(int pos)
{
	this->pos = pos;
}

int lista::getValue()
{
	return this->value;
}

int lista::getSize()
{
	return this->Size;
}

int lista::getPos()
{
	return this->pos;
}

lista* lista::getNext()
{
	return this->next;
}

lista* lista::getAnt()
{
	return this->ant;
}

bool lista::testEmpty(lista* l)
{
	if(!l->getNext()) return true;
	else return false;
}

lista* lista::pusher(std::string s)
{
	int v;
	lista* tempNode = new lista();
	if(!tempNode)
	{
		std::cout << "Sem memoria: ";
		return NULL;
	}
	else
	{
		std::cout << "Digite o valor do " << s << " elemento: ";
		std::cin >> v;
		tempNode->setValue(v);
		return tempNode;
	}
}

lista* lista::pusher(int p)
{
	int v;
	lista* tempNode = new lista();
	if(!tempNode)
	{
		std::cout << "Sem memoria: ";
		return NULL;
	}
	else
	{
		std::cout << "Digite o valor do " << p << " elemento: ";
		std::cin >> v;
		tempNode->setValue(v);
		return tempNode;
	}
}

void lista::atualiza(lista* l)
{
	lista* tempNode = new lista(l);
	for(int i = 0; i <= l->getSize(); i++)
	{
        	tempNode->setPos(i);
		tempNode = tempNode->getNext();
	}
}

lista* lista::lastElement(lista* l)
{
	if(!l->getNext()) return l;
	else return lastElement(l->getNext());
}

void lista::pushFirst(lista* l, lista* newNode)
{
	newNode->setPos(1);
	newNode->setAnt(l);
	newNode->setNext(l->getNext());
	l->setNext(newNode);
	l->setSize(l->getSize()+1);
}

void lista::pushBegin(lista* l)
{
	lista* newNode = pusher("primeiro");
	if(testEmpty(l))
		pushFirst(l, newNode);
	else
	{
		newNode->setAnt(l);
		newNode->setNext(l->getNext());
		l->getNext()->setAnt(newNode);
		l->setNext(newNode);
		l->setSize(l->getSize()+1);
		l->atualiza(l);
	}
}

void lista::pushEnd(lista* l)
{
	lista* newNode = pusher("ultimo");
	if(testEmpty(l))
		pushFirst(l, newNode);
	else
	{
		lista* lastNode = lastElement(l);
		lastNode->setNext(newNode);
		newNode->setAnt(lastNode);
		l->setSize(l->getSize()+1);
		l->atualiza(l);
	}
}

void lista::pushPos(lista* l, int p)
{
	lista* newNode = pusher(p);
	if(testEmpty(l))
	{
		pushFirst(l, newNode);
		std::cout << "lista vazia, elemento colocado na primeira posicao: ";
	}
	else
	{
		lista* atualNode = l->getNext();

		while(atualNode->getPos() != p)
			atualNode = atualNode->getNext();

		newNode->setNext(atualNode);
		newNode->setAnt(atualNode->getAnt());
		atualNode->getAnt()->setNext(newNode);
		atualNode->setAnt(newNode);
		l->setSize(l->getSize()+1);
		l->atualiza(l);
	}
}

void lista::popFirst(lista* l)
{
    delete l->getNext();
    l->setNext(NULL);
    l->setSize(l->getSize()-1);
    l->atualiza(l);
}

void lista::popBegin(lista* l)
{
	lista* atualNode = new lista(l->getNext());
	if(testEmpty(l))
		popFirst(l);
	else
	{
        atualNode = l->getNext();
        atualNode->getNext()->setAnt(l);
        l->setNext(atualNode->getNext());
        l->setSize(l->getSize()-1);
        l->atualiza(l);
        delete atualNode;
	}
}

void lista::popEnd(lista* l)
{
	if(testEmpty(l))
		popFirst(l);
	else
	{
		lista* antLastNode = new lista(lastElement(l));
		antLastNode = antLastNode->getAnt();
		delete antLastNode->getNext();
		antLastNode->setNext(NULL);
		l->setSize(l->getSize()-1);
	}
}

void lista::popPos(lista* l, int p)
{
	lista* atualNode = l->getNext();
	if(testEmpty(l))
		popFirst(l);
	else
	{
		while(atualNode->getPos() != p)
			atualNode = atualNode->getNext();
		atualNode->getAnt()->setNext(atualNode->getNext());
		atualNode->getNext()->setAnt(atualNode->getAnt());
		delete atualNode;
		l->setSize(l->getSize()-1);
		l->atualiza(l);
	}
}

lista* lista::show(lista* l)
{
	if(!l->getNext()) return NULL;
	else
	{
		std::cout << "Element " << l->getNext()->getPos() << " - Value: "
			  << l->getNext()->getValue() << "\n";
		return show(l->getNext());
	}
}

void lista::free(lista* l)
{
	if(testEmpty(l))
	{
		delete l->getNext();
		std::cout << "lista vazia: ";
	}
	else
	{
		lista* tempNode = lastElement(l);
		while(tempNode != l)
		{
			tempNode = tempNode->getAnt();
			delete tempNode->getNext();
		}
		delete l->getNext();
		std::cout << "lista vazia: ";
	}
}
