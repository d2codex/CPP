#include <random>
#include <iostream>

int	coinToss()
{
	static std::mt19937 rng(std::random_device{}());
	return rng() & 1;
}

int main(void)
{
	int countOnes = 0;
	int countZeros = 0;
	int	i = 0;
	int totalCoinTosses = 10000000;

	while(i < totalCoinTosses)
	{
		int result = coinToss();
		if (result == 1)
			countOnes++;
		if (result == 0)
			countZeros++;
		i++;
	}
	std::cout << "Total coin tosses: " << i << std::endl;
	std::cout << "Total Zeros " << countZeros << std::endl;
	std::cout << "Total Ones " << countOnes << std::endl;
}
