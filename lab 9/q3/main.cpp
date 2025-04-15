#include <iostream>
#include <string>
#include "library.h"
using namespace std;

int main(){
Book b1;
Library library(30);
int ch;
cout<<"\nLibrary System\n";

cout<<"1.Add book"<<endl;
cout<<"2.Remove book"<<endl;
cout<<"3.Search book"<<endl;
cin>>ch;
switch(ch){
    case 1:
        {string t,a,i;
        cout<<"enter title: ";
        cin>>t;
        cout<<"enter author: ";
        cin>>a;
        cout<<"enter ISBN: ";
        cin>>i;
        Book b(t,a,i);
        library.addBook(b);
    }
    break;
    case 2:
    {   
        string i;
        cout<<"enter ISBN: ";
        cin>>i;
        library.removeBook(i);
    }
    break;
    case 3:
    {
        string i;
        cout<<"enter ISBN: ";
        cin>>i;
        library.searchBook(i);
    }
    break;
    default:
    cout<<"enter a valid number"<<endl;
}
return 0;
}
