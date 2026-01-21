#include <iostream>
#include <cmath>

int main(void)
{
	int n1;
	int rawIntBits;
	int	rawIntBitsExplicit;
	int rawIntBits256;

	n1 = 5;
	rawIntBits = n1 << 8;
	rawIntBitsExplicit = n1 * (1 << 8);
	rawIntBits256 = n1 * 256;

	std::cout << "Int n1: " << n1 << '\n';
	std::cout << "rawIntBits representation in an int type: " << rawIntBits << '\n';
	std::cout << "rawIntBitsExplicit :" << rawIntBitsExplicit << '\n';
	std::cout << "rawIntBits*256: " << rawIntBits256 << '\n';

	float n2;
	int rawFloatBits;

	n2 = 5.3;
	rawFloatBits = roundf(n2 * (1 << 8));
	//cannot do
	// rawFloatBits = roundf(n2 << 8)
	// bc no way to bitshift floats!

	std::cout << "Float n2 :" << n2 << '\n';
	std::cout << "rawFloatBits :" << rawFloatBits << '\n';
}
