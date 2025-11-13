// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include "AddressBook.h"

void addContactFromInput(AddressBook& book)
{
    std::string first, last, phone;

    // First name is mandatory
    do 
    {
        std::cout << "Enter first name: ";
        std::getline(std::cin, first);
    } while (first.empty());

    std::cout << "Enter last name (optional): ";
    std::getline(std::cin, last);

    std::cout << "Enter phone number (optional): ";
    std::getline(std::cin, phone);

    std::optional<std::string> lastOpt = last.empty() ? std::nullopt 
                                         : std::optional<std::string>(last);
    std::optional<std::string> phoneOpt = phone.empty() ? std::nullopt 
                                         : std::optional<std::string>(phone);

    book.addContact(std::make_shared<Contact>(first, lastOpt, phoneOpt));
    book.displayAll();
}

void removeContact(AddressBook& book) 
{
    std::string first, last;
    std::cout << "Enter first name of the contact to remove: ";
    std::getline(std::cin, first);

    std::cout << "Enter last name to remove: ";
    std::getline(std::cin, last);

    book.removeContact(first, last);
    book.displayAll();
}

void displayContacts(const std::vector<std::shared_ptr<Contact>>& contacts)
{
    std::cout << "------------------------------------------------\n";
    int width = 15;
    std::cout << std::left << std::setw(width) << "First Name"
        << std::setw(width) << "Last Name"
        << std::setw(width) << "Phone" << "\n";
    std::cout << "------------------------------------------------\n";
    for (const auto& c : contacts) 
    {
        std::cout << std::left << std::setw(15) << c->getFirstName()
            << std::setw(15) << (c->getLastName() ? *c->getLastName() : "(none)")
            << std::setw(15) << (c->getPhoneNumber() ? *c->getPhoneNumber() : "(none)") << "\n";
    }
    std::cout << "------------------------------------------------\n";
}

void searchContact(AddressBook& book) 
{
    std::string name;
    std::cout << "Enter name to search: ";
    std::getline(std::cin, name);
    auto results = book.searchByName(name);
    if (results.empty()) 
    {
        std::cout << "No contacts found matching: " << name << "\n";
    } 
    else 
    {
        displayContacts(results);
    }
}


int main()
{
    AddressBook book;

	//Adding some sample contacts
	book.addContact(std::make_shared<Contact>("Meera", "Kizhoor", "123-456-7890"));
	book.addContact(std::make_shared<Contact>("Chloe", "Hardy", "987-654-3210"));
    book.addContact(std::make_shared<Contact>("Alice", "Zoe", std::nullopt));
    book.addContact(std::make_shared<Contact>("Alice", "Brown", "987-654-3210"));
    book.addContact(std::make_shared<Contact>("Zam", "Ali", std::nullopt));

	std::cout << "Some hardcoded entries for testing....." << std::endl;
    book.displayAll();

    int choice;
    do {
        std::cout <<"\n1. Add Contact\n"
                    "2. Delete Contact\n"
                    "3. Sort by first name\n"
                    "4. Sort by last name\n"
                    "5. Search for contacts with matching name\n"
                    "6. Exit\n";
        std::cin >> choice;
        // clear newline
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        switch (choice) {
        case 1: 
        { 
            addContactFromInput(book);
            break; 
        }
        case 2: 
        { 
            removeContact(book);
            break; 
        }
        case 3: 
        { 
            // Sort by first name
            auto firstSorted = book.getSortedContacts(SortKey::FirstName);
            std::cout << "Sorted by First Name:\n";
			displayContacts(firstSorted);
            break; 
        }
        case 4: 
        {
            // Sort by last name
            auto lastSorted = book.getSortedContacts(SortKey::LastName);
            std::cout << "\nSorted by Last Name:\n";
			displayContacts(lastSorted);
            break; 
        }
        case 5: 
        {
            searchContact(book);
            break;
        }
		case 6:
        {
            std::cout << "Exiting programme...\n";
            return 0;
        }            
        default:
        {
			std::cout << "Invalid choice. Please try again.\n";
            return 0;
        }            
        }
    } while (choice != 6);

    return 0;
}