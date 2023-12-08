#include "String.h"
#include <iostream>

int main() {
    // Example usage of the String class
    String str1("Hello");
    String str2("World");

    String str3 = str1; // Copy constructor
    String str4;

    str4 = str2; // Copy assignment operator

    std::cout << "str1: ";
    str1.display();
    std::cout << ", Size: " << str1.getSize() << std::endl;

    std::cout << "str2: ";
    str2.display();
    std::cout << ", Size: " << str2.getSize() << std::endl;

    std::cout << "str3: ";
    str3.display();
    std::cout << ", Size: " << str3.getSize() << std::endl;

    std::cout << "str4: ";
    str4.display();
    std::cout << ", Size: " << str4.getSize() << std::endl;

    // Append and display
    str1.append(" ");
    str1.append("World");
    std::cout << "Appended str1: ";
    str1.display();
    std::cout << ", Size: " << str1.getSize() << std::endl;

    return 0;
}

