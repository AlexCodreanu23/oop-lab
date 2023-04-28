//#include "NonFiction.h"
//#include <iostream>
//#include <cstring>
//
//
//NonFiction::NonFiction(const char *title_, int code, const char *author_, const char *subject_, int publication_year):Book(title_, code, author_),code(code), publication_year(publication_year) {
//    title = strdup(title_);
//    author = strdup(author_);
//    subject = strdup(subject_);
//}
//
//
//NonFiction::NonFiction(const NonFiction& nf) : Book(nf.title, nf.code, nf.author), publication_year(nf.publication_year), code(nf.code) {
//    title = strdup(nf.title);
//    author = strdup(nf.author);
//    subject = strdup(nf.subject);
//}
//
//int NonFiction::getPublication_year() const {
//    return publication_year;
//}
//
//void NonFiction::setPublication_year(int publication_year) {
//    NonFiction::publication_year = publication_year;
//}
//
//char *NonFiction::getSubject() const {
//    return subject;
//}
//
//void NonFiction::setSubject(const char *subject) {
//    delete[] this->subject;
//    this->subject = strdup(subject);
//}
//
//
//NonFiction::~NonFiction(){
//    delete[]title;
//    delete[]author;
//    delete[]subject;
//}
//
//
//std::istream& operator>>(std::istream &is, NonFiction &nf) {
//    is >> static_cast<Book &>(nf);
//
//    int publication_year;
//    char subject[100];
//    is >> subject >> publication_year;
//    nf.setSubject(subject);
//    nf.setPublication_year(publication_year);
//}
//
//std::ostream &operator<<(std::ostream &os, NonFiction &nf) {
//        os << static_cast<Book &>(nf);
//        os << "The subject is: " << nf.getSubject() << std::endl;
//        os << "The publication year is: " << nf.getPublication_year() << std::endl;
//
//        return os;
//}
//
//
//NonFiction& NonFiction::operator=(const NonFiction& nf) {
//    if (this == &nf) {
//        return *this;
//    }
//
//    Book::operator=(nf);
//    publication_year = nf.publication_year;
//
//    delete[]title;
//    delete[]author;
//    delete[]subject;
//
//    title = strdup(nf.title);
//    author = strdup(nf.author);
//    subject = strdup(nf.subject);
//
//    return *this;
//}
//void NonFiction::details() const {
//    std::cout<<"The book "<<getTitle()<<"was written by "<<getAuthor()<<" and it is a non-fictional book which illustrates the subject: "<<getSubject()<<" and was published in "<<getPublication_year()<<std::endl;
//}
//
