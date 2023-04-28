#include "NonFiction.h"
#include <iostream>
#include <cstring>

NonFiction::NonFiction() : Book("", 0, "") {
    title = nullptr;
    author = nullptr;
    subject = nullptr;
    publication_year = 0;
    code = 0;
}


NonFiction::NonFiction(const char *title_, int code, const char *author_, const char *subject_, int publication_year):Book(title_, code, author_),code(code), publication_year(publication_year) {
    title = std::make_unique<char[]>(std::strlen(title_) + 1);
    std::strcpy(title.get(), title_);

    author = std::make_unique<char[]>(std::strlen(author_) + 1);
    std::strcpy(author.get(), author_);

    subject = std::make_unique<char[]>(std::strlen(subject_) + 1);
    std::strcpy(subject.get(), subject_);
}



NonFiction::NonFiction(const NonFiction& nf) : Book(nf.title.get(), nf.code, nf.author.get()), publication_year(nf.publication_year), code(nf.code) {
    title = std::make_unique<char[]>(std::strlen(nf.title.get()) + 1);
    std::strcpy(title.get(), nf.title.get());

    author = std::make_unique<char[]>(std::strlen(nf.author.get()) + 1);
    std::strcpy(author.get(), nf.author.get());

    subject = std::make_unique<char[]>(std::strlen(nf.subject.get()) + 1);
    std::strcpy(subject.get(), nf.subject.get());
}

int NonFiction::getPublication_year() const {
    return publication_year;
}

void NonFiction::setPublication_year(int publication_year) {
    NonFiction::publication_year = publication_year;
}

char* NonFiction::getSubject() const {
    return subject.get();
}

void NonFiction::setSubject(const char *subject) {
    this->subject = std::make_unique<char[]>(std::strlen(subject) + 1);
    std::strcpy(this->subject.get(), subject);
}


NonFiction::~NonFiction(){

}


std::istream& operator>>(std::istream &is, NonFiction &nf) {
    is >> static_cast<Book &>(nf);

    int publication_year;
    char subject[100];
    is >> subject >> publication_year;
    nf.setSubject(subject);
    nf.setPublication_year(publication_year);
}


std::ostream &operator<<(std::ostream &os, NonFiction &nf) {
    os << static_cast<Book &>(nf);
    os << "The subject is: " << nf.getSubject() << std::endl;
    os << "The publication year is: " << nf.getPublication_year() << std::endl;

    return os;
}


NonFiction& NonFiction::operator=(const NonFiction& nf) {
    if (this == &nf) {
        return *this;
    }

    Book::operator=(nf);
    publication_year = nf.publication_year;

    title.reset(new char[std::strlen(nf.title.get()) + 1]);
    std::strcpy(title.get(), nf.title.get());

    author.reset(new char[std::strlen(nf.author.get()) + 1]);
    std::strcpy(author.get(), nf.author.get());

    subject.reset(new char[std::strlen(nf.subject.get()) + 1]);
    std::strcpy(subject.get(), nf.subject.get());

    return *this;
}
void NonFiction::details() const {
    std::cout<<"The book "<<getTitle()<<" was written by "<<getAuthor()<<" and it is a non-fictional book which illustrates the subject: "<<getSubject()<<" and was published in "<<getPublication_year()<<std::endl;
}

