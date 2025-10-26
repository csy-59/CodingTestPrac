#include <iostream>

bool isPrime[1000001] = { true };
void CheckPrime()
{
	std::fill(isPrime, isPrime + 1000001, true);
	isPrime[0] = isPrime[1] = false;

	for (int i = 2; i * i <= 1000000; ++i)
	{
		if (isPrime[i] == false) 
			continue;

		for (int j = i * i; j <= 1000000; j += i)
			isPrime[j] = false;
	}
}

int main()
{
	std::ios::sync_with_stdio(0); 
	std::cin.tie(0);

	int n;
	CheckPrime();

	do {
		std::cin >> n;
		if (n == 0)
			break;

		bool isFound = false;
		for (int i = 3; i <= n / 2; i += 2)
		{
			if (isPrime[i] == true && isPrime[n - i] == true)
			{
				isFound = true;
				std::cout << n << " = " << i << " + " << n - i << "\n";
				break;
			}
		}

		if (isFound == false)
		{
			std::cout << "Goldbach's conjecture is wrong.\n";
		}

	} while (n != 0);

	return 0;
}