#include <iostream>
#include <string>
using namespace std;

class Account{

    string accountNumber;
    string accountHolderName;
    double balance;

    public:
    Account(){
        balance=0.0;
    }

    Account( string an="", string ahn="",int bal=0.0):
        accountNumber(an),accountHolderName(ahn),balance(bal) {}

    void deposit(double amt){
        balance+=amt;
        cout<<"amount deposited.\n";
    }

    void withdraw(double amt){
        if (balance==0 || amt>balance){
            cout<<"insufficient funds to withdraw from"<<endl;
        } else {
            balance-=amt;
            cout<<"withdrawal successful."<<endl;
        }
    }

    void displayDetails(){
        cout<<"\nAccount Details\n";

        cout<<"\nAccount ID: \n"<<accountNumber<<"\nName: \n"<<accountHolderName
            <<"\nCurrent Balance: \n"<<balance<<endl;
    }
};

int main(){
    double numd, numw;
    Account acc("345","Tony Stark",5000000.00);

    int choice;
     do {
        cout << "\n=== Bank Menu ===\n";
        cout << "1. Display Account Details\n";
        cout << "2. Deposit money\n";
        cout << "3. Withdraw money\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                acc.displayDetails();
                break;
            case 2:
                cout<<"Enter amount to deposit(in decimal): ";
                cin>>numd;
                acc.deposit(numd);
                break;
            case 3:
                cout<<"Enter amount to withdraw(in decimal): ";
                cin>>numw;
                acc.withdraw(numw);
                break;
            case 4:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice! Please enter a number between 1 and 4.\n";
        }
    } while (choice != 4);

    return 0;
}
