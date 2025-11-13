#include "Contact.h"

Contact::Contact(std::string fName,
				std::optional<std::string> lName,
				std::optional<std::string> phNum) :
		firstName(std::move(fName)), lastName(std::move(lName)), phoneNumber(std::move(phNum))
{
}

const std::string& Contact::getFirstName() const
{
	return firstName;
}

const std::optional<std::string>& Contact::getLastName() const
{ 
	return lastName;
}

const std::optional<std::string>& Contact::getPhoneNumber() const
{
	return phoneNumber;
}

std::string Contact::getDisplayName() const
{
	if (lastName)
	{
		return firstName + " " + *lastName;
	}
	return firstName;
}
