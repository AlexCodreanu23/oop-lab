#include "Fictional.h"
#include <iostream>
#include <cstring>


int Fictional::fictional_books_generated = 0;

Fictional::Fictional() : Book("", 0, "") {
    title = nullptr;
    author = nullptr;
    genre = nullptr;
    nrpages = 0;
    code = 0;
}


Fictional::Fictional(const char *title_, int code,const char *author_,int nrpages_,const char *genre_) : Book( title_, code, author_), nrpages(nrpages_), code(code) {
    title = strdup(title_);
    author = strdup(author_);
    genre = strdup (genre_);
    fictional_books_generated++;
}

Fictional::Fictional(const Fictional& f) : Book(f.title, f.code, f.author), nrpages(f.nrpages), code(f.code) {
    title = strdup(f.title);
    author = strdup(f.author);
    genre = strdup(f.genre);
}


int Fictional::getnrpages() const {
    return nrpages;
}

void Fictional::setnrpages(int nrpages){
    Fictional::nrpages = nrpages;
}
void Fictional::setGenre(const char* genre) {
    delete[] this->genre;
    this->genre = strdup(genre);
}

char *Fictional::getGenre() const {
    return genre;
}

int Fictional::getFictionalBooks() {
    return fictional_books_generated;
}

void Fictional::details() const{
    std::cout<<"The Book "<<getTitle()<<" was written by "<<getAuthor()<<" which is a fictional book containing in the "<<getGenre()<<" genre"<<" and having "<<getnrpages()<<" number of pages"<<std::endl;
}


Fictional::~Fictional() {
    delete[]title;
    delete[]author;
    delete[]genre;
}


std::istream& operator>>(std::istream &is, Fictional &f) {
    is >> static_cast<Book&>(f);

    int nrpages;
    char genre[100];
    is >> nrpages >> genre;
    f.setnrpages(nrpages);
    f.setGenre(genre);

    return is;
}


std::ostream& operator<<(std::ostream& os, Fictional& f) {
    os << static_cast<Book&>(f);
    os << "Genre: " << f.getGenre() << std::endl;
    os << "Number of pages: " << f.getnrpages()<<std::endl;

    return os;
}


Fictional& Fictional::operator=(const Fictional& f) {
    if (this == &f) {
        return *this;
    }

    Book::operator=(f);

    nrpages = f.nrpages;

    delete[]title;
    delete[]author;
    delete[]genre;

    title = strdup(f.title);
    author = strdup(f.author);
    genre = strdup(f.genre);

    return *this;
}
