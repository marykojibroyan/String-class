#include "String.h"
#include <iostream>

String::String() 
: size(0) 
, data(nullptr)
{}

String::String(const char* str) 
: data(nullptr)
, size(0) {
    if (str) {
        size = std::strlen(str);
        data = new char[size + 1];
        std::strcpy(data, str);
    }
}

String::String(const String& other)
{
        size = other.size;
        data = new char[size + 1];
        std::strcpy(data, other.data);
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


String& String::operator=(const String& other) {
    if (this != &other) {
        delete[] data;

        size = other.size;
        data = new char[size + 1];
        std::strcpy(data, other.data);
    }
    return *this;
}

String& String::operator=(String&& other) {
    if (this != &other) {
        delete[] data;

        size = other.size;
        data = other.data;

        other.size = 0;
        other.data = nullptr;
    }
    return *this;
}



String& String::operator+=(const String& s) {
    size += s.Size();
    char* newData = new char[size + 1];
    std::strcpy(newData, data);
    delete[] data;
    data = newData;
   
    return *this;
}

String& String::operator+=(const char* s) {
    if (s) {
        size += std::strlen(s);
        char* newData = new char[size + 1];
        std::strcpy(newData, data);
        
        delete[] data;
        data = newData;
    }
    return *this;
}



String String::operator+(const String& other) const {
    String result(*this);
    result += other;
    return result;
}

String String::operator+(const char* s2) const {
    String result(*this);
    result += s2;
    return result;
}


int String::Size() const {
    return size;
}


const char* String::c_str() const {
    return data;
}

std::ostream& operator<<(std::ostream& out, const String& str) {
    out << str.c_str();
    return out;
}

