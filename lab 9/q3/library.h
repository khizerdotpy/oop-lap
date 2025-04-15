#ifndef LIBRARY
#define LIBRARY

#include <iostream>
#include <string>
#include "book.h"
using namespace std;

class Library{
    Book *arr;
    int size;

    public:
    Library();
    Library(int s);

    void addBook(const Book& b);
    void removeBook(const string& b);
    void searchBook(const string& isbn);

};

#endif
