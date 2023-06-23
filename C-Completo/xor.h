#ifndef XOR_H
#define XOR_H

int xor(int a, int b)
{
	return (a || b) && !(a && b);
}

#endif // XOR_H
