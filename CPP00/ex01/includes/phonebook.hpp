#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "contact.hpp"
#include "colors.hpp"
#include <iostream>
#include <string>

class PhoneBook
{
public:
	//constructor
	PhoneBook();
	void		addContact();
//	void		searchContacts() const; 

private:
	// input helpers
	std::string promptName(const std::string& prompt);
	std::string promptPhoneNumber(const std::string& prompt);
	std::string	promptNonEmpty(const std::string& prompt);

	// confirm helpers
	bool		confirmSave() const;
	bool		confirmReplacement(const Contact& oldContact) const;

	//display helper
	void		printContactSummary(const Contact& contact) const;
	void		printContactTable() const;

	// validationi helper
	int			getValidIndex() const;

	//members
	Contact		_contacts[8];
	int			_nextIndex;
	int			_totalContacts;
};

# endif
