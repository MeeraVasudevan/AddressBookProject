#include <iostream>
#include "AddressBook.h"

void AddressBook::addContact(std::shared_ptr<Contact> contact)
{
	contactsByName.insert({ contact->getFirstName(), contact });
	sortRequired = true;
}

void AddressBook::removeContact(const std::string& firstName)
{
	if (contactsByName.find(firstName) != contactsByName.end())
	{
		contactsByName.erase(firstName);
		sortRequired = true;
	}
	else
	{
		std::cout << "Contact " << firstName << " not found.\n";
	}
}

inline std::string toLower(const std::string& s) {
	std::string lower = s;
	std::transform(lower.begin(), lower.end(), lower.begin(),
		[](unsigned char c) { return std::tolower(c); });
	return lower;
}

std::vector<std::shared_ptr<Contact>> AddressBook::searchByName(const std::string& searchName) const
{
	std::vector<std::shared_ptr<Contact>> searchResults;
	// case-insensitive search
	const std::string searchLower = toLower(searchName);

	for(auto & [_, contact] : contactsByName)
	{
		std::string firstLower = toLower(contact->getFirstName());
		if (firstLower.rfind(searchLower, 0) == 0) 
		{
			searchResults.push_back(contact);
		}
		else if (contact->getLastName().has_value())
		{
			std::string lastLower = toLower(*contact->getLastName());
			if (lastLower.rfind(searchLower, 0) == 0)
			{
				searchResults.push_back(contact);
			}
		}
	}
	
	return searchResults;
}

const std::vector<std::shared_ptr<Contact>>& AddressBook::getSortedContacts(SortKey key)
{
	// sorting is required only if contacts were modified or if the sort key has changed
	if (!sortRequired && currentSortKey == key)
	{
		return sortedContacts;
	}

	currentSortKey = key;
	sortedContacts.clear();
	sortedContacts.reserve(contactsByName.size());

	//constructing contacts vector from hash map
	for(auto& [_, contact] : contactsByName)
	{
		sortedContacts.push_back(contact);
	}

	std::sort(sortedContacts.begin(), sortedContacts.end(),
		[key](const std::shared_ptr<Contact>& a, const std::shared_ptr<Contact>& b)
		{
			switch (key)
			{
				case SortKey::FirstName:
				{
					if (a->getFirstName() != b->getFirstName())
					{
						return a->getFirstName() < b->getFirstName();
					}
					//if first names are equal, sort by last name
					return a->getLastName().value_or("") < b->getLastName().value_or("");
					}

				case SortKey::LastName:
					if (a->getLastName().value_or("") != b->getLastName().value_or(""))
					{
						return a->getLastName().value_or("") < b->getLastName().value_or("");
					}
					//if last names are equal, sort by first name
					return a->getFirstName() < b->getFirstName();

				default:
					return a->getFirstName() < b->getFirstName();;
			}
		});

	sortRequired = false;

	return sortedContacts;
}

void AddressBook::displayAll() const {
	std::cout << "------------------------------------------------\n";
	int width = 15;
	std::cout << std::left << std::setw(width) << "First Name"
		<< std::setw(width) << "Last Name"
		<< std::setw(width) << "Phone" << "\n";
	std::cout << "------------------------------------------------\n";
	for (const auto&[_, contact] : contactsByName) {
		std::cout << std::left << std::setw(15) << contact->getFirstName()
			<< std::setw(15) << (contact->getLastName() ? *contact->getLastName() : "(none)")
			<< std::setw(15) << (contact->getPhoneNumber() ? *contact->getPhoneNumber() : "(none)") << "\n";
	}
	std::cout << "------------------------------------------------\n";
}
