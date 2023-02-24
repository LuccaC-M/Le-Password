#include <iostream>
#include <string.h>
#include <cstdlib>
#include <time.h>
/* Long live the bloat */

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

int main(int argc, char *argv[]) {
    int length;
    std::cout << "length of the password: ";
    std::cin >> length;
    srand(time(0));
    std::cout << CreatePassword(length) << std::endl;
}
