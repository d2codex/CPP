/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 23:43:26 by diade-so          #+#    #+#             */
/*   Updated: 2026/01/12 14:07:57 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "contact.hpp"
#include "colors.hpp"
#include <string>

/**
 * @class PhoneBook
 * @brief Manages a collection of up to 8 contacts
 *
 * Provides functions to add, search, and display contacts.
 */
class PhoneBook
{
public:
	//constructor
	PhoneBook();

	// main actions
	void		addContact();
	void		searchContacts() const;

	// utility
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
