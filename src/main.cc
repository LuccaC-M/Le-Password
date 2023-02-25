/* Long Live The Bloat*/
#include <iostream>

/* Char & string functionality */
#include <cctype>
#include <ostream>
#include <string>

/* Random number generator */
#include <cstdlib>
#include <ctime>

int GenRandInt(int max, int min) {
    return rand() % (max - min + 1) + min;
}

std::string CreatePassword(int length) {
    std::string password;
    for (int i = 0; i < length; i++) {
        password += (char) (GenRandInt('~','@'));
    }
    return password;
}

bool CheckPassword(std::string password) {
    if (password.length() < 8) {
        return false;
    }

    int len = password.length();

    bool hasUpper = false, hasLower = false, hasSymbol = false, hasNumber = false;

    for (int i = 0; i < len; i++) {
        if (islower(password[i])) {
            hasLower = true;
        }
        else if (isupper(password[i])) {
            hasUpper = true;
        }
        else if (isdigit(password[i])) {
            hasNumber = true;
        } 
        else if (ispunct(password[i])) {
            hasSymbol = true;
        }
        
        if (hasLower && hasUpper && hasSymbol && hasNumber) {
            return true;
        }
    }

    return false;
}

int main(int argc, char *argv[]) {
    short action;

    std::cout << "Choose what do you want to do?\n"
        << "1. Create a password\n"
        << "2. Check password security\n"
        << "> ";
    std::cin >> action;

    if (action == 1) {
        int length;
        std::cout << "length of the password: ";
        std::cin >> length;
        srand(time(0));
        std::cout << CreatePassword(length) << std::endl;
    }
    else if (action == 2) {
        std::string password;
        std::cout << "Enter password: ";
        std::cin >> password;
        bool isStrong = CheckPassword(password);

        if (isStrong) {
            std::cout << "The password is strong" << std::endl;
            return 0;
        } 
        else {
            std::cout << "The password is not strong" << std::endl;
            return 0;
        }
    }
    else {
        std::cout << "Not valid action number" << std::endl;
        return 1;
    }
}
