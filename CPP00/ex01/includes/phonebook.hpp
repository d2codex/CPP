#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "contact.hpp"
#include "colors.hpp"
#include <string>

class PhoneBook
{
public:
	//constructor
	PhoneBook();
	void		addContact();
	void		searchContacts() const;
	bool		isEmpty() const;

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

	// constants
	enum
	{
		USER_INDEX_OFFSET = 1,
		MAX_CONTACTS = 8,
		PHONE_LEN = 10,
	};

	//members
	Contact		_contacts[MAX_CONTACTS];
	int			_nextIndex;
	int			_totalContacts;
};

# endif
