#include <iostream>
#include <cstring>
#include "Book.h"
#include "NoTitleException.h"
#include "InvalidCodeException.h"



Book::Book(){
}

Book::Book(const char *author_, int code,const char *title_) : code(code) {
    author = strdup(author_);
    title = strdup (title_);

}

Book::Book(const Book &bk) {
    size_t len= strlen(bk.title);
    title= new char[len+1];
    strcpy(title, bk.title);

    size_t len2=strlen(bk.author);
    author=new char[len2+1];
    strcpy(author, bk.author);

    code=bk.code;
}

int Book::getCode() const {
    return code;
}

void Book::setCode(int code) {
        if (code < 0) {
            throw InvalidCodeException();
        }
        Book::code = code;
}

void Book::setTitle(const char *title) {
    try { if(title== nullptr||strlen(title)==0)
        throw NoTitleException();
        else
            Book::title = strdup(title);
    }
    catch (const NoTitleException &e) {
        std::cout << e.what() << '\n';
    }


}
const char *Book::getTitle() const {
    return title;
}

void Book::setAuthor(const char *author) {
    Book::author = strdup(author);
}

const char *Book::getAuthor() const {
    return author;
}

void Book::details() const{
    std::cout<<"Hello world!";
}


bool Book::operator==(const Book &rhs) const {
    return strcmp(title,rhs.title)==0 && strcmp(author,rhs.author)==0 && code==rhs.code ;
}

bool Book::operator!=(const Book &rhs) const {
    return strcmp(title,rhs.title)!=0 || strcmp(author,rhs.author)!=0 || code!=rhs.code ;
}


Book& Book::operator=(const Book &rhs) {
    if (this != &rhs)
    {
        setTitle(rhs.title);
        setAuthor(rhs.author);
        code = rhs.code;
    }
    return *this;
}

std::istream& operator>>(std::istream &is, Book &b) {
    char buf[100];
    is >> buf;
    b.setTitle(buf);

    char buf2[100];
    is >> buf2;
    b.setAuthor(buf2);

    is >> b.code;
    return is;
}


std::ostream& operator<<(std::ostream &os, Book &b) {
    if(!b.title){
        os<<"Cartea nu a fost initializata";
        return os;
    }
    os <<"Titlul cartii: " <<b.title<<std::endl<<"Numele autorului: " << b.author<<std::endl << "Codul cartii: "<<b.code<<std::endl;
    return os;
}

Book::~Book() {
    delete[] title;
    delete[] author;
}