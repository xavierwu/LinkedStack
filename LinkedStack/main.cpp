#include "LinkedStack.h"
#include <iostream>

int main ()
{
	LinkedStack<int> ls;
	for (auto i = 0; i < 10; ++i)
		ls.push (i);
	int tmp = 0;
	std::cout << ls.size () << std::endl;
	while (!ls.empty ()) {
		ls.top (tmp);
		std::cout << tmp << std::endl;
		ls.pop ();
	}
	std::cout << ls.size () << std::endl;
	return 0;
}