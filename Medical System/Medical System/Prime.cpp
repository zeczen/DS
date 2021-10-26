#include "Prime.h"

unsigned int Prime::nextPrime(unsigned int n)
{
	while (true)
	{
		if (isPrime(n))
		{
			return n;
		}
		++n;
	}
}

bool Prime::isPrime(unsigned int n)
{
	if (n < 4)
	{
		return false;
	}

	if (n % 2 == 0)
	{
		return false;
	}

	for (int i = 3; i * i < n; i += 2)
	{
		if (n % i == 0)
		{
			return false;
		}
	}

	return true;
}
