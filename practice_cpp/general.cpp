#include <iostream>
#include <string>
#include <cstdlib>

#ifdef DEBUG
#define	DBUG(x) x
#else
#define DBUG(x)
#endif


class Contact
{
public:
	// this is a default constructor (has no parameters)
	Contact();
	
	// setter - we pass a const string by reference 
	// 1) we dont modify the string
	// 2) avoids unnecessary copying
	// note:  the function can modify the private member (_firstname)
	// so we cannot put const at the end
	// const inside parentheses means we dont modify the argument first
	void		setContact(const std::string& first);

	

	//const int paren - we pass a promptMsg string to print out
	//we dont modify the string either
	//why dont we put const at the end? are we/ can we modify the
	//private memebers (_firstname)
	//do we modify the input?  
	std::string	promptFirstName(const std::string& promptMsg);
	
	// getters
	// this is a public function that can access the private members
	// the return type is a const string
	// and the function cannot modify the string?
	const std::string&	getFirstName() const;

private:
	std::string	_firstName;
};

//=================================================================//

Contact::Contact()
{
}

void Contact::setContact(const std::string& first)
{
	// copies user input to _firstName
	_firstName = first;
	DBUG(std::cout << "First Name: " << _firstName << '\n');
}

// so this is a public function? it can access the private member
// variables so i can set the first name.
const std::string& Contact::getFirstName() const
{
	return (_firstName);
}

// so the function passes input to cin , which is reads what the user
// typed in, and stores that into the stream
// and then getline reads char by char from the stream until it sees
// a newline and stores the chars into input (local var) and returns input
// but the real question now is do we eventually modify input?
// in setContact, we take the input .. we dont' modify it but we 
// copy it to _firstName, so techinically the return type CAN be
// const std::string?
// but this would mean that th caller cannot modify the returned string
// in practice, its rarely done bc caller usu wants to store or manip
// returned string.
// also returning const for a by-value return is mostly redundant; it 
// prevents moving, which is inefficient in modern c++.
std::string Contact::promptFirstName(const std::string& promptMsg)
{
	std::string	input;

	std::cout << promptMsg;
	if (!std::getline(std::cin, input))
	{
		std::cerr << "getline/cin failed\n";
		//exit(0); not good practice - dont exit mid way
		// return empty string instead, and then check for empty string
		// in main and exit gracefully.
		return (""); // empty indicates failure
	}
	return (input);
}


//==================================================================//
int	main(void)
{
	Contact contact;
	std::string input;

	input = contact.promptFirstName("Enter first name > ");
	if (input.empty())
	{
		return (1);
	}
	contact.setContact(input);
	return (0);
}
