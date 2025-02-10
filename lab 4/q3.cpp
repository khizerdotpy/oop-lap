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

    Account( string an="", string ahn="",double bal=0.0):
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

    void checkBalance(){
        cout<<"\nCurrent Funds: "<<balance<<endl;
    }

};

int main(){
    Account acc1("1200","jackson",400000.00);
    Account acc2("6200","jonah",402340.00);

    cout<<"\nBefore deposit: \n";
    acc1.checkBalance();
    acc1.deposit(3000.50);
    cout<<"\nAfter deposit: \n";
    acc1.checkBalance();

    cout<<"\nBefore withdrawal: \n";
    acc2.checkBalance();
    acc2.withdraw(2340.00);
    cout<<"\nAfter withdrawal: \n";
    acc2.checkBalance();

    return 0;

}
