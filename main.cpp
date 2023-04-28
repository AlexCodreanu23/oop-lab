#include <iostream>
#include "Book.h"
#include "Fictional.h"
#include "NonFiction.h"
#include <vector>
void meniu (std::vector<Book> &b,int &n) {
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
            std::vector<Book> temp=std::vector<Book>(n+nr);
            for(int i=0;i<n;i++) { temp[i] = b[i];
            }
            for (int i=n; i < n+nr; i++) {
                std::cout << "Introduceti titlul, autorul si codul cartii " << i+1 << std::endl;
                std::cin >> temp[i];
            }
            n+=nr;
            b=temp;
            meniu(b,n);
        }
    }
    else if (choice == 2) {
        if(b.size()>0){
            for(Book book : b){
                std::cout<<book;
            }
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

    NonFiction f7;
    std::cin>>f7;
    std::cout<<f7;
    f7.details();

//    Book *b2 = new NonFiction("The Lord of the Rings", 123, "J.R.R. Tolkien",  "Fantasy",1178);
//
//    NonFiction &nf1 = dynamic_cast<NonFiction&>(*b2);
//    b2->details();
//    delete b2;                     << dynamic_cast >>



//    Book *b9 = new Fictional("The Lord of the Rings", 123, "J.R.R. Tolkien", 1178, "Fantasy");
//    b9->details();
//    delete b9;             <<  funcții virtuale (pure) apelate prin pointeri de clasa bază  >>

    int n;
    std::cout<<"Introduceti numarul de carti pe care vreti sa le adaugati: "<<std::endl;
    std::cin>>n;
    std::vector<Book> b;

    for(int i = 0; i < n; i++) {
        std::cout << "Introduceti titlul, autorul si codul pentru cartea " << i+1 << std::endl;
        Book entry ;
        std::cin >> entry;
        b.push_back(entry);

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


    return 0;
}