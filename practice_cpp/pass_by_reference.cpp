#include <iostream>
#include <string>

// Basic ANSI Colors
# define BLK "\033[30m"
# define RED "\033[31m"
# define GRN "\033[32m"
# define YEL "\033[33m"
# define BLU "\033[34m"
# define MAG "\033[35m"
# define CYN "\033[36m"
# define WHT "\033[37m"
# define RESET "\033[0m"

class Contact
{
public:
	// default constructor
	Contact();

	// return by Value
	std::string getByValue() const
	{
		return (_name);
	}

	// return by reference
	const std::string& getByReference() const
	{
		return (_name);
	}


private:
	std::string _name;
};

//======================//

Contact::Contact() : _name("Hugo")
{
}

//======================//
int	main(void)
{
	Contact c;

	// returns a std::string by value = creates a copy
	std::string copy = c.getByValue();
	
	// binds a reference to the original string
	const std::string& reference = c.getByReference();

	std::cout << YEL "=== Proof by memory address ===\n" RESET
			  << "Address inside object  :" << &c.getByReference() << '\n'
			  << "Address of copy (value):" << &copy << '\n'
			  << "Address of reference   :" << &reference << '\n';

	// mutate the copy
	copy[0] = 'X';

	std::cout << YEL "=== Proof by mutation ===\n" RESET
			  << "Original: " << c.getByReference() << '\n'
			  << "Copy    : " << copy << '\n';
}


