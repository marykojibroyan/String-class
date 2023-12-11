#include "String.h"
#include <iostream>

int main() {
    // Create strings
    String str1("Hello");
    String str2(" World");

    // Concatenate strings using operator+
    String result = str1 + str2;

    // Display result
    std::cout << "Result: " << result << " (Size: " << result.Size() << ")\n";

    // Concatenate with a C-style string
    result += "!!!";

    // Display modified result
    std::cout << "Modified Result: " << result << " (Size: " << result.Size() << ")\n";

    return 0;
}

