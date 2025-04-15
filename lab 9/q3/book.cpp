#include <iostream>
#include <string>
#include "book.h"
using namespace std;


string Book:: getTitle()const{
    return title;
}
string Book:: getAuthor()const{
    return author;
}
string Book:: getISBN()const {
    return ISBN;
}
Book :: Book():ISBN("default") {}
Book:: Book(string t, string a, string i):title(t),author(a),ISBN(i){}
