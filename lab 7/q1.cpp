#include <iostream>
#include <string>
using namespace std;
#include <math.h>

class Account{
    protected:
    int accNum;
    float balance=0.0;
    string accountHolderName;
    string accountType;

    public:
    Account():accNum(100),balance(0.0),accountHolderName(" "),
        accountType("default"){}

    virtual void deposit(float amount){
        if(amount>=0){
            balance+=amount;
            cout<<"Deposit successfully entered"<<endl;
        }
        cout<<"Unable to deposit amount."<<endl;
    }

    virtual void withdraw(float amount){
        if(amount>=0&&amount<=balance){
            balance-=amount;
            cout<<"Withrawal Successful."<<endl;
        }
        cout<<"Unable to withdraw"<<endl;
    }

    virtual double calculateInterest(double principal, double rate, int time, bool isCompound) {
        double interest = 0;

        if (isCompound) {
            interest = principal * pow(1 + rate / 100, time) - principal;
        } else {
            interest = (principal * rate * time) / 100;
        }

        return interest;
    }

    virtual void printStatement(){
        int choice;
        float numd, numw;
        do{
            cout<<"\nStatement\n";
            cout << "1. Display Account Info\n";
            cout << "2. Deposit money\n";
            cout << "3. Withdraw money\n";
            cout << "4. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch(choice){
                case 1:
                getAccountInfo();
                break;
            case 2:
                cout<<"Enter amount to deposit(in decimal): ";
                cin>>numd;
                deposit(numd);
                break;
            case 3:
                cout<<"Enter amount to withdraw(in decimal): ";
                cin>>numw;
                withdraw(numw);
                break;
            case 4:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice! Please enter a number between 1 and 4.\n";
            }
        } while (choice!=4);
    }

    virtual void getAccountInfo(){
        cout<<"\nAccount Details\n";
        cout<<"Account Number: "<<accNum<<"Account Balance: "<<
            balance<<"Account Holder Name: "<<accountHolderName<<
            "Account Type: "<<accountType;

    }

};

class SavingsAccount : public Account{

    float interestRate; 
    float minimumBalance;

    public:
    SavingsAccount():minimumBalance(10.0),Account(){}

    void deposit(float amount)override{
        if(amount>=0){
            balance+=amount;
            cout<<"Deposit successfully entered in savings account"<<endl;
        }
        cout<<"Unable to deposit amount."<<endl;
    }

    void withdraw(float amount)override{
        if(amount>=0&&amount<=balance&&balance>minimumBalance){
            balance-=amount;
            cout<<"Withrawal Successful from savings account."<<endl;
        }
        cout<<"Unable to withdraw"<<endl;
    }

    double calculateInterest(double principal, double rate, int time, bool isCompound) override {
        

        if (isCompound) {
            interestRate = principal * pow(1 + rate / 100, time) - principal;
        } else {
            interestRate = (principal * rate * time) / 100;
        }

        return interestRate;
    }

    void printStatement()override{

        int choice;
        float numd, numw;
        do{
            cout<<"\nStatement\n";
            cout << "1. Display Account Info\n";
            cout << "2. Deposit money\n";
            cout << "3. Withdraw money\n";
            cout << "4. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch(choice){
                case 1:
                getAccountInfo();
                break;
            case 2:
                cout<<"Enter amount to deposit in savings account(in decimal): ";
                cin>>numd;
                deposit(numd);
                break;
            case 3:
                cout<<"Enter amount to withdraw from savings account(in decimal): ";
                cin>>numw;
                withdraw(numw);
                break;
            case 4:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice! Please enter a number between 1 and 4.\n";
            }
        } while (choice!=4);
    }
};

class CheckingAccount : public Account{
    float fixedinterestRate; 
    float minimumBalance;

    public:
    CheckingAccount():minimumBalance(10.0),Account(){}

    void deposit(float amount)override{
        if(amount>=0){
            balance+=amount;
            cout<<"Deposit successfully entered in checking account"<<endl;
        }
        cout<<"Unable to deposit amount."<<endl;
    }

    void withdraw(float amount)override{
        if(amount>=0&&amount<=balance&&balance>minimumBalance){
            balance-=amount;
            cout<<"Withrawal Successful from checking account."<<endl;
        }
        cout<<"Unable to withdraw"<<endl;
    }

    double calculateInterest(double principal, double rate, int time, bool isCompound) override {
        

        if (isCompound) {
            fixedinterestRate = principal * pow(1 + rate / 100, time) - principal;
        } else {
            fixedinterestRate = (principal * rate * time) / 100;
        }

        return fixedinterestRate;
    }

    void printStatement()override{
        int choice;
        float numd, numw;
        do{
            cout<<"\nStatement\n";
            cout << "1. Display Account Info\n";
            cout << "2. Deposit money\n";
            cout << "3. Withdraw money\n";
            cout << "4. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch(choice){
                case 1:
                getAccountInfo();
                break;
            case 2:
                cout<<"Enter amount to deposit in checking account(in decimal): ";
                cin>>numd;
                deposit(numd);
                break;
            case 3:
                cout<<"Enter amount to withdraw from checking account(in decimal): ";
                cin>>numw;
                withdraw(numw);
                break;
            case 4:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice! Please enter a number between 1 and 4.\n";
            }
        } while (choice!=4);
    }
};

class FixedDepositAccount : public Account{
    int maturityDate;
    float fixedinterestRate;

    public:
    FixedDepositAccount():Account(){}

    void deposit(float amount)override{
        if(amount>=0){
            balance+=amount;
            cout<<"Deposit successfully entered in fixed deposit account"<<endl;
        }
        cout<<"Unable to deposit amount."<<endl;
    }

    double calculateInterest(double principal, double rate, int time, bool isCompound) override {
        

        if (isCompound) {
            fixedinterestRate = principal * pow(1 + rate / 100, time) - principal;
        } else {
            fixedinterestRate = (principal * rate * time) / 100;
        }

        return fixedinterestRate;
    }

    void printStatement()override{
        int choice;
        float numd, numw;
        do{
            cout<<"\nStatement\n";
            cout << "1. Display Account Info\n";
            cout << "2. Deposit money\n";
            cout << "3. Withdraw money\n";
            cout << "4. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch(choice){
                case 1:
                getAccountInfo();
                break;
            case 2:
                cout<<"Enter amount to deposit in fixed deposit account(in decimal): ";
                cin>>numd;
                deposit(numd);
                break;
            case 3:
                cout<<"Enter amount to withdraw from fixed deposit account(in decimal): ";
                cin>>numw;
                withdraw(numw);
                break;
            case 4:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice! Please enter a number between 1 and 4.\n";
            }
        } while (choice!=4);
    }
};

int main(){
    cout<<"Enter account type( s for savings account, c for checking account, f for fixed deposit account): "<<endl;

    char type;
    cin>>type;

    switch(type){
        case 's':
        case 'S':
        Account *acc=new SavingsAccount();
        break;

        case 'C':
        case 'c':
        Account *acc=new CheckingAccount();
        break;

        case 'f':
        case 'F':
        Account *acc=new FixedDepositAccount();
        break;
    }
}
