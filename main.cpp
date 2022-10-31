#include <stdio.h>
#include <iostream>
#include <list>

int main()
{
	std::list<int> lst{};

	for (std::list<int>::iterator itr = lst.begin(); itr != lst.end(); ++itr)
	{
		if (*itr == 3)
		{
			itr = lst.insert(itr, 0);
			++itr;
		}
	}

	for (auto itr = lst.begin(); itr != lst.end(); ++itr)
	{
		std::cout << *itr << "\n";
	}

	return 0;
}