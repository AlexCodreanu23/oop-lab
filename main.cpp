#include <iostream>
#include <cstring>

class Book{
private:
    char* title;
    char* author;
    int code;

public:
     Book(){}

     char *getTitle()const{
        return title;
    }
     char *getAuthor()const{
        return author;
    }
    int getCode() const{
        return code;
    }
    void details()const{
        std::cout<<"The book "<<title<<" was written by "<<author<<" and has the code "<<code<<'\n';
    }
    Book(const char* title_,const char* author_, int code_) {
        size_t len = strlen(title_);
        title= new char[len+1];
        strcpy(title,title_);

        size_t len2=strlen(author_);
        author=new char[len2+1];
        strcpy(author,author_);

        code= code_;
    }
    ~Book(){
        delete[] title;
        delete[] author;
    }

    void setTitle(const char* title_){
        size_t len= strlen(title_);
        title= new char[ len+1];
        strcpy(title, title_);
    }
    void setAuthor(const char* author_){
        size_t len= strlen(author_);
        author= new char[ len+1];
        strcpy(author, author_);
    }

    Book(const Book &bk){
        size_t len= strlen(bk.title);
        title= new char[len+1];
        strcpy(title, bk.title);

        size_t len2=strlen(bk.author);
        author=new char[len2+1];
        strcpy(author, bk.author);

        code=bk.code;
    }
    friend std::ostream& operator<<(std::ostream &os, Book &b) {
        if(!b.title){
            os<<"Cartea nu a fost initializata";
            return os;
        }
        os <<"Titlul cartii: " <<b.title<<std::endl<<"Numele autorului: " << b.author<<std::endl << "Codul cartii: "<<b.code<<std::endl;
        return os;
     }

    friend std::istream& operator>>(std::istream &is, Book &b) {
        char buf[100];
        is >> buf;
        b.setTitle(buf);

        char buf2[100];
        is >> buf2;
        b.setAuthor(buf2);

        is >> b.code;
        return is;
    }


    bool operator==(const Book &rhs) const{
        return strcmp(title,rhs.title)==0 && strcmp(author,rhs.author)==0 && code==rhs.code ;
    }

    bool operator!=(const Book &rhs) const{
         return !(strcmp(title,rhs.title)==0 && strcmp(author,rhs.author)==0 && code==rhs.code);
    }

};
Book b[100000];
int nr1;
void meniu() {
    int choice = 0;
    int nr = -1;
    std::cout << "Meniu" << std::endl;
    std::cout << "1.Adauga carti" << std::endl;
    std::cout << "2.Vizualizeaza carti" << std::endl;
    std::cout << "3.Iesire" << std::endl;
    std::cout << "Alege ce doresti: ";
    std::cin >> choice;
    if (choice == 1)
    {
        std::cout << "Cate carti doresti sa adaugi?";
    std::cin >> nr;
    nr1=nr;
    if (nr > 0) {
        for (int i = 1; i <= nr; i++) {
            std::cout << "Introduceti titlul, autorul si codul cartii " << i << std::endl;
            std::cin >> b[i];
        }
        meniu();
    }
}
    else if (choice == 2) {
        if(nr1>0) {
            for (int i = 1; i <= nr1; i++)
                std::cout << b[i];
            meniu();
        }
        else{
            std::cout<<"Nu exista carti de vizualizat";
        }
    }
    else if(choice==3) {
            std::cout << "La revedere!";
            return;
        }
    else
    {
        std::cout << "Optiune invalida";
        meniu();
    }
}


int main() {
    /*
    b.setTitle("FOTBAL");
    b.setAuthor("Mihai Eminescu");
    b.setCode(2345);
    */
    const Book b1("Pomo","MARIUS CSAMPAR",23456);
    b1.details();
    Book b2=b1;
    b2.details();
    if(b1==b2)
        std::cout<<"da"<<'\n';
    if(b1!=b2)
        std::cout<<"nu"<<'\n';
    Book b3;
    std::cin>>b3;
    std::cout<<b3;

    int n;
    std::cout<<"Introduceti numarul cartilor pe care vreti sa le adaugati: "<<std::endl;
    std::cin>>n;
   /// Book b[n];

    for(int i = 0; i < n; i++) {
        std::cout << "Introduceti titlul, autorul si codul pentru cartea " << i+1 << std::endl;
        std::cin >> b[i];
    }

    if (n!=0) {
        std::cout << "Cartile adaugate sunt:" << std::endl;
        for (int i = 0; i < n; i++) {
            std::cout << b[i] << std::endl;
        }
    }
    else
        std::cout<<"Nu a fost adaugata nicio carte"<<std::endl;

    meniu();
    return 0;
}