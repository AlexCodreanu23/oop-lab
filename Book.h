#ifndef _Book_H_
#define _Book_H_
#include <iostream>
#include <cstring>
#include <string>

class Book{
private:
    char* title;
    char* author;
    int code;
public:
    Book();
    Book(const char *title, int code,const char *author);
    Book(const Book &bk);

     int getCode() const;

    void setCode(int code);

    void setTitle(const char *title);

    const char *getAuthor() const;

    const char *getTitle() const;

    void setAuthor(const char *author);

    virtual void details() const;

    virtual ~Book() ;

    bool operator==(const Book& rhs) const;

    bool operator!=(const Book& rhs) const;

    Book& operator=(const Book& rhs) ;

    friend std::istream& operator>>(std::istream &is, Book &b);

    friend std::ostream& operator<<(std::ostream &os, Book &b);

};


#endif