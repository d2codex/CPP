#include "contact.hpp"

Contact::Contact() : _firstName(""), _lastName(""), _nickName(""),
				     _phoneNumber(""), _darkestSecret("")
{
    // nothing else needed
}

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

const std::string& Contact::getFirstName() const
{
	return _firstName;
}

const std::string& Contact::getLastName() const
{
	return _lastName;
}

const std::string& Contact::getNickName() const
{
    return _nickName;
}

const std::string& Contact::getPhoneNumber() const
{
    return _phoneNumber;
}

const std::string& Contact::getDarkestSecret() const
{
    return _darkestSecret;
}
