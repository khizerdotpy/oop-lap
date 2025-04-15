#include <iostream>
#include <string>
#include "book.h"
#include "library.h"
using namespace std;
Library::Library() {}
Library::Library(int s):size(s){
    arr=new Book[size];
}

void Library:: addBook(const Book& b){
    for(int i=0;i<size;i++){
        if (arr[i].getISBN()=="Default"){
            arr[i]=b;
            cout<<"\nBook added\n";
            return;
        }
    }
    cout<<"Unable to add book"<<endl;
}

void Library::removeBook(const string& b){
    for(int i=0;i<size;i++){
        if (arr[i].getISBN()==b){
            arr[i]=Book();
            cout<<"\nBook Removed\n";
            return;
        }
    }
}

void Library::searchBook(const string& isbn){
    for(int i=0;i<size;i++){
        if (arr[i].getISBN()==isbn){
            cout<<"Book Title: "<<arr[i].getTitle()<<endl;
            cout<<"Book Author: "<<arr[i].getAuthor()<<endl;
            cout<<"Book ISBN: "<<arr[i].getISBN()<<endl;
            return;
        } else {
            cout<<"Not found"<<endl;
        }
    }
}
