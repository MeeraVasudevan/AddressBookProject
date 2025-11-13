#pragma once

#include <string>
#include <optional>

class Contact {
private:
    std::string firstName;
    std::optional<std::string> lastName;
    std::optional<std::string> phoneNumber;

public:
    Contact(std::string fName, 
            std::optional<std::string> lName = std::nullopt, 
            std::optional<std::string> phNum = std::nullopt);


    // Getters
    const std::string& getFirstName() const;
    const std::optional<std::string>& getLastName() const;
    const std::optional<std::string>& getPhoneNumber() const;

    std::string getDisplayName() const;
};
