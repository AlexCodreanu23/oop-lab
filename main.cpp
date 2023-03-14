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
    
    void setCode(int code_) {
        code = code_;
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

    Book& operator=(const Book &rhs) {
        if (this != &rhs)
        {
            setTitle(rhs.title);
            setAuthor(rhs.author);
            code = rhs.code;
        }
        return *this;
    }

};
int nr1;
void meniu (Book *b,int n) {
    int choice = 0;
    std::cout << "Meniu" << std::endl;
    std::cout << "1.Adauga carti" << std::endl;
    std::cout << "2.Vizualizeaza carti" << std::endl;
    std::cout << "3.Iesire" << std::endl;
    std::cout << "Alege ce doresti: ";
    std::cin >> choice;
    if (choice == 1)
    {
        int nr;
        std::cout << "Cate carti doresti sa adaugi?";
        std::cin >> nr;
        if (nr > 0) {
            Book *temp=new Book[n+nr];
            for(int i=0;i<n;i++) { temp[i] = b[i];
            }
            for (int i=n; i < n+nr; i++) {
                std::cout << "Introduceti titlul, autorul si codul cartii " << i+1 << std::endl;
                std::cin >> temp[i];
            }

            b=temp;



            n+=nr;
            delete[] temp;
            meniu(b,n);
        }
    }
    else if (choice == 2) {
        if(n>0) {
            for (int i = 0; i < n; i++)
                std::cout <<b[i];
            meniu(b,n);
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
        std::cout << "Optiune invalida"<<std::endl;
        meniu(b,n);
    }
}


int main() {
    int n;
    std::cout<<"Introduceti numarul de carti pe care vreti sa le adaugati: "<<std::endl;
    std::cin>>n;
    Book *b=new Book[n];

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

    meniu(b,n);

   delete[] b;
    return 0;
}
