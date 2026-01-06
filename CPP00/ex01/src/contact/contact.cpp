/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 23:42:01 by diade-so          #+#    #+#             */
/*   Updated: 2026/01/06 23:42:10 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

/**
 * @brief Default constructor for Contact.
 *
 * All std::string members are default-initialized to empty.
 */
Contact::Contact()
{
}

/**
 * @brief Set all fields of a contact at once.
 *
 * @param first First name
 * @param last Last name
 * @param nick Nickname
 * @param phone Phone number
 * @param secret Darkest secret
 */
void Contact::setContact(const std::string& first,
						 const std::string& last,
						 const std::string& nick,
						 const std::string& phone,
						 const std::string& secret)
{
	_firstName     = first;
	_lastName      = last;
	_nickName      = nick;
	_phoneNumber   = phone;
	_darkestSecret = secret;
}

/**
 * @brief Get the first name of the contact.
 * @return const reference to the first name
 */
const std::string& Contact::getFirstName() const
{
	return _firstName;
}

/**
 * @brief Get the last name of the contact.
 * @return const reference to the last name
 */
const std::string& Contact::getLastName() const
{
	return _lastName;
}

/**
 * @brief Get the nickname of the contact.
 * @return const reference to the nickname
 */
const std::string& Contact::getNickName() const
{
    return _nickName;
}

/**
 * @brief Get the phone number of the contact.
 * @return const reference to the phone number
 */
const std::string& Contact::getPhoneNumber() const
{
    return _phoneNumber;
}

/**
 * @brief Get the darkest secret of the contact.
 * @return const reference to the darkest secret
 */
const std::string& Contact::getDarkestSecret() const
{
    return _darkestSecret;
}
