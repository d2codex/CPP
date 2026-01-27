#include <iostream>
#include <string>

int main(void)
{
	std::string name;
	std::cout << "hello\n";
	std::cout << "howdy" << std::endl;
	std::cout << "enter your name ";
	std::getline(std::cin, name);
	std::cout << name << std::endl;

}
