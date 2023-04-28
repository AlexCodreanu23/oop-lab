#ifndef _NonFICTION_H_
#define _NonFICTION_H_
#include <memory>
#include  "book.h"

class NonFiction:public Book {
private:
    int code;
    std::unique_ptr<char[]> title;
    std::unique_ptr<char[]> author;
    std::unique_ptr<char[]> subject;
    int publication_year;
public:

    NonFiction();
    NonFiction(const char *title, int code,const char *author,const char *subject, int publication_year);

    NonFiction(const NonFiction& nf);

    int getPublication_year() const;

    void setPublication_year(int publication_year);

    char *getSubject()const;

    void setSubject(const char *subject);

    ~NonFiction() override;

    friend std::istream& operator>>(std::istream &is, NonFiction &nf);

    friend std::ostream& operator<<(std::ostream& os,NonFiction& nf);

    NonFiction& operator=(const NonFiction& rhs);

    void details() const override;




};

#endif