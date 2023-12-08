 #include "String.h"
#include <cstring>
#include <iostream>

String::String() 
	: data(nullptr)
	, size(0)
{}

String::String(const char* str) {
    if (str) {
        size = strlen(str);
        data = new char[size + 1];
        strcpy(data, str);
    } else {
        data = nullptr;
        size = 0;
    }
}

String::String(const String& other) {
    size = other.size;
    data = new char[size + 1];
    strcpy(data, other.data);
}

String::String(String&& other) {
    size = other.size;
    data = other.data;

    other.size = 0;
    other.data = nullptr;
}

String::~String() {
    delete[] data;
}

const char* String::c_str() const {
    return data;
}

int String::getSize() const {
    return size;
}

void String::append(const char* str) {
    if (str) {
        int len = strlen(str);
        char* temp = new char[size + len + 1];
        strcpy(temp, data);
        strcat(temp, str);

        delete[] data;
        data = temp;
        size += len;
    }
}

// Display the string
void String::display() const {
    std::cout << c_str();
}

// Copy assignment operator
String& String::operator=(const String& other) {
    if (this != &other) {
        delete[] data;
        size = other.size;
        data = new char[size + 1];
        strcpy(data, other.data);
    }
    return *this;
}

// Move assignment operator
String& String::operator=(String&& other) {
    if (this != &other) {
        delete[] data;
        size = other.size;
        data = other.data;

        // Reset the source object
        other.size = 0;
        other.data = nullptr;
    }
    return *this;
}

