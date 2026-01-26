/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 18:20:55 by diade-so          #+#    #+#             */
/*   Updated: 2026/01/12 14:06:55 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

/**
 * @class Contact
 * @brief Stores information for a single contact in the phonebook
 *
 * Contains first name, last name, nickname, phone number, and secret.
 */
class Contact
{	
public:
	// constructor
	Contact();

	// set all fields at once
	void setContact(const std::string& first,
					const std::string& last,
					const std::string& nick,
					const std::string& phone,
					const std::string& secret);
	
	// Getters
    const std::string& getFirstName() const;
    const std::string& getLastName() const;
    const std::string& getNickName() const;
    const std::string& getPhoneNumber() const;
    const std::string& getDarkestSecret() const;

private:
	std::string	_firstName;
	std::string	_lastName;
	std::string	_nickName;
	std::string	_phoneNumber;
	std::string	_darkestSecret;
};

# endif
