#ifndef BOOK
#define BOOK

#include <iostream>
#include <string>
using namespace std;

class Book{
    private:
    string title,author,ISBN;
    public:
    Book();
    Book(string t, string a, string i);
    string getTitle() const;
    string getAuthor() const;
    string getISBN() const;
};

#endif
