#include <iostream>
#include <string>
using namespace std;

class Book{

    int id;
    string title;
    string author;
    bool availability;

    public:

    int getID(){
        return id;
    }
    string getTitle(){
        return title;
    }
    string getAuthor(){
        return author;
    }
    bool getAvailability(){
        return availability;
    }

    void setID(int i){
        id=i;
    }
    void setTitle(string t){
        title=t;
    }
    void setAuthor(string auth){
        author=auth;
    }
    void setAvailability(bool av){
        availability=av;
    }    

    void displayDetails(){
        cout<<"Book ID: "<<getID()<<endl;
        cout<<"Book Title: "<<getTitle()<<endl;
        cout<<"Book Author: "<<getAuthor()<<endl;
        (!getAvailability())?(cout<<"Book is not available."<<endl):(cout<<"Book is available."<<endl);
    }


};

class Library{

    Book *books;
    int size;

    public:

    Library(){
        size=20;
    }
    Library(int s){
        size=s;
        books=new Book[size];
    }

    void addBook(Book b1){
        // int bid;
        // string bt;
        // string ba;
        // bool bv;
        // for(int i=0;i<size;++i){
        //     cout<<"\nEnter Book Details:\n";
        //     cout<<"\nEnter Book "<<i+1<<" ID: ";
        //     cin>>bid;
        //     books[i].setID(bid);
        //     cout<<"\nEnter Book "<<i+1<<" Title: ";
        //     getline(cin, bt);
        //     cin.ignore();
        //     books[i].setTitle(bt);
        //     cout<<"\nEnter Book "<<i+1<<" Author: ";
        //     getline(cin, ba);
        //     cin.ignore();
        //     books[i].setAuthor(ba);
        //     cout<<"\nEnter Book "<<i+1<<" Availability(1 for yes, 0 for no): ";
        //     cin>>bv;
        //     books[i].setAvailability(bv);
        // }
        bool exists=false;
        for (int i = 0; i < size; i++) {
        if (books[i].getID() == b1.getID()) {
            exists = true;
            break;
        }
    }
        if (exists) {
        cout << "\nBook ID is not unique. Book not added." << endl;
    } else {
        for (int i = 0; i < size; i++) {
            if (books[i].getID() == 0) {  
                books[i] = b1;
                cout << "\nBook has been added.\n";
                return;
            }
        }
        cout << "\nLibrary is full. Unable to add more books.\n";
    }

    }

    void borrowBook(int id){
        for(int i=0;i<size;++i){
            if(id==books[i].getID()){
                if(books[i].getAvailability()==1){
                    cout<<"Book successfully borrowed."<<endl;
                    books[i].setAvailability(0);
                }
            } else {
                cout<<"Either enter a valid book or the book is not available.\n";
            }
        }
    }

    void returnBook(int id){
        for(int i=0;i<size;++i){
            if(id==books[i].getID()){
                if(books[i].getAvailability()==0){
                    cout<<"Book successfully returned."<<endl;
                    books[i].setAvailability(1);
                }
            } else {
                cout<<"Unable to return book.\n";
            }
        }
    }

    void DisplayAll(){
        for(int i=0;i<size;i++){
            cout<<"\nBook "<<i+1<<" details : "<<endl;
            books[i].displayDetails();
        }
    }

    ~Library(){
        delete[] books;
    }
    
};

// class Book{

//     int id;
//     string title;
//     string author;
//     bool availability;

//     public:

//     int getID(){
//         return id;
//     }
//     string getTitle(){
//         return title;
//     }
//     string getAuthor(){
//         return author;
//     }
//     bool getAvailability(){
//         return availability;
//     }

//     int setID(int i){
//         id=i;
//     }
//     string setTitle(string t){
//         title=t;
//     }
//     string setAuthor(string auth){
//         author=auth;
//     }
//     bool setAvailability(bool av){
//         availability=av;
//     }    

//     void displayDetails(){
//         cout<<"Book ID: "<<getID()<<endl;
//         cout<<"Book Title: "<<getTitle()<<endl;
//         cout<<"Book Author: "<<getAuthor()<<endl;
//         (!getAvailability())?(cout<<"Book is not available."<<endl):(cout<<"Book is available."<<endl);
//     }


// };

int main(){

    int n;
    cout<<"Enter number of books in library: "<<endl;
    cin>>n;
    Library Iqra(n);
    Book b1;

    int bid;
    string bt;
    string ba;
    bool bv;
    int we;
    int ew;

    int choice;
     do {
        cout << "\n=== Library Menu ===\n";
        cout << "1. Add Book\n";
        cout << "2. Borrow Book\n";
        cout << "3. Return Book\n";
        cout << "4. Display Books\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "\nEnter Book ID: ";
                cin >> bid;
                b1.setID(bid);

                cout << "\nEnter Book Title: ";
                cin.ignore();
                getline(cin, bt);
                b1.setTitle(bt);

                cout << "\nEnter Book Author: ";
                getline(cin, ba);
                b1.setAuthor(ba);

                cout << "\nEnter Book Availability(1 for yes, 0 for no): ";
                cin >> bv;
                cin.ignore();
                b1.setAvailability(bv);

                Iqra.addBook(b1);

                break;
            case 2:
                
                cout<<"Enter Book ID of book you want to borrow: ";
                cin>>we;
                Iqra.borrowBook(we);
                break;
            case 3:
            
                cout<<"Enter Book ID of book you want to return: ";
                cin>>ew;
                Iqra.returnBook(ew);
                break;
            case 4:
                cout<<"\nDisplaying all Available Books: \n";
                Iqra.DisplayAll();
                break;
            case 5:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice! Please enter a number between 1 and 5.\n";
        }
    } while (choice != 5);

    return 0;

}
