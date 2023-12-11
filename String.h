#ifndef STRING_H
#define STRING_H

#include <string>
#include <cstring>
#include <iostream>


class String {
public:
	String();
	String(const char* str);
	String(const String& other);
	String(String&& other);
	~String();

    String& operator=(const String& other);
    String& operator=(String&& other);

	String& operator+=(const String& s);
	String& operator+=(const char* s);

    String operator+(const String& other) const;
	String operator+(const char* s) const;

	int Size() const;
	const char* c_str() const;
private:
	int size;
	char* data;
};

std::ostream& operator<<(std::ostream& out,const  String& str);
//std::istream& operator>>(std::istream& in,const String& str);
#endif
