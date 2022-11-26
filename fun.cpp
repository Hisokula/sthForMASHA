#include <string>
#include "fun.hpp"
#include <iostream>
namespace vm
{
	void Compliter(std::string* A, std::string* B)
	{
		int Asize = (*A).length();
		int Bsize = (*B).length();
		int Raz = abs(Asize - Bsize);
		if (Asize > Bsize)
		{
			for (int x = 0; x < Raz; x++) { (*B) = "0" + (*B); }
		}
		if (Asize < Bsize)
		{
			for (int x = 0; x < Raz; x++) { (*A) = "0" + (*A); }
		}
	};

	std::string Sum(std::string A, std::string B)
	{
		std::string C;

	}
}