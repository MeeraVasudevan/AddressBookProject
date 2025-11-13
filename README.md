# Overview

This project is a console-based Address Book application written in C++.
It allows users to add, remove, sort, search, and display contacts efficiently.
The design supports large datasets and incorporates case-insensitive search.

# Features

- Add contacts with: First Name (required), Last Name (optional), Phone Number (optional)
- Remove contacts by name
- Sort contacts by first name or last name
- Case-insensitive prefix search (partial matches)
- Formatted display of contacts

# Datastructures

- Uses unordered_multimap for fast lookups (O(1) average), duplicate first names and for efficient storage for large datasets
- Vector for fast sorted output

# Code Structure
AddressBook/
- main.cpp             - Entry point, demo usage
- Contact.h            - Contact class definition
- Contact.cpp          -  Contact class implementation
- AddressBook.h        - AddressBook class definition
- AddressBook.cpp      - AddressBook class implementation
- README.md            - Project documentation

Contact class: stores first name, last name, and phone number

AddressBook class: manages contacts, including add, remove, search, and sorted display

# How to Run

- Clone the Repository from github link https://github.com/MeeraVasudevan/AddressBookProject.git and can be run from Visual Studio directly
- Or can be run from bash using cmake. Added CMakeLists.txt to make it run on Windows, Linux, or macOS.

Steps:
1. git clone https://github.com/MeeraVasudevan/
.git
cd <repo-name>

2.Build using cmake from terminal
mkdir build
cd build
cmake ..
cmake --build .

The executable will be located at:
Linux/macOS: build/bin/AddressBook
Windows: build\bin\AddressBook.exe


# Design Decisions

- Case-insensitive Prefix search : Uses lowercase conversion for search and supports searching by the beginning of the first or last name

- Hybrid data structure: Combines fast hash-based lookup with cached sorted results

- Shared pointers: std::shared_ptr<Contact> allows efficient memory management and avoids copies

# Future Enhancements
- Case-insensitive hashing so contacts are sorted alphabetically irrespective of the cases.

- Validation & Error Handling (e.g. Phone number validation)

- Unit tests

- File persistence (Save to JSON or CSV)

- Add a GUI interface
