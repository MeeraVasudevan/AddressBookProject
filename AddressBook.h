#pragma once

#include "Contact.h"
#include <unordered_map>
#include <vector>
#include <string>
#include <memory>
#include <algorithm>
#include <iomanip>

enum class SortKey {
    FirstName,
    LastName
};

class AddressBook {
public:
    // Add a contact (overwrites existing with same first name)
    void addContact(std::shared_ptr<Contact> contact);

    // Remove by first name
    void removeContact(const std::string& firstName);

    // Search (returns nullptr if not found)
    std::vector<std::shared_ptr<Contact>> searchByName(const std::string& searchName) const;

    // Returns sorted view
    const std::vector<std::shared_ptr<Contact>>& getSortedContacts(SortKey key = SortKey::FirstName);

    // Display all contacts
    void displayAll() const;

private:
    std::unordered_multimap<std::string, std::shared_ptr<Contact>> contactsByName;
    std::vector<std::shared_ptr<Contact>> sortedContacts;
	bool sortRequired = true;
	SortKey currentSortKey = SortKey::FirstName;
};


