#ifndef _FICTIONAL_H_
#define _FICTIONAL_H_
#include  "book.h"

class Fictional:public Book{
private:
    int code;
    char *title;
    char *author;
    char *genre;
    int nrpages;
    static int fictional_books_generated;
public:

    Fictional();
    Fictional(const char *title, int code,const char *author,int nrpages,const char *genre);

    Fictional(const Fictional& f);


    int getnrpages()const;

    void setnrpages(int nrpages);

    char *getGenre() const;

    void setGenre(const char *genre);

    static int getFictionalBooks();

     void details() const override ;
    ~Fictional() override;

    friend std::istream& operator>>(std::istream &is, Fictional &f);
    friend std::ostream& operator<<(std::ostream& os,Fictional& f);

    Fictional& operator=(const Fictional& rhs);
};



#endif