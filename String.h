#ifndef STRING_H
#define STRING_H

class String {
public:
	String();
	String(const char* str);
	String(const String& other);
	String(String&& other);
	~String();

    const char* c_str() const;   
    int getSize() const;         
    void append(const char* str);
    void display() const;

    String& operator=(const String& other);
    String& operator=(String&& other);

private:
	char* data;
	int size;
};
#endif	
