#include <iostream>
#include <string>
using namespace std;

class Vehicle{
    protected:
    string model;
    double rate;

    public:
    Vehicle(string m, double r):model(m),rate(r){}
    virtual void getDailyRate()=0;
    virtual void displayDetails()=0;
};

class Car: public Vehicle{

    public:
    Car(string m, double r):Vehicle(m,r){}
    void getDailyRate() override {
        cout<<"Today's Rate for car: "<<rate<<endl;
    }
    void displayDetails()override{
        cout<<"car model: "<<model<<" , car rate: "<<rate<<endl;
    }
};

class Bike: public Vehicle{

    public:
    Bike(string m, double r):Vehicle(m,r){}
    void getDailyRate() override {
        cout<<"Today's Rate for bike: "<<rate<<endl;
    }
    void displayDetails()override{
        cout<<"bike model: "<<model<<" , bike rate: "<<rate<<endl;
    }
};

int main(){
    Car c1("m59",4500.0);
    Bike b1("m67",3000.0);
    Vehicle* ptr=nullptr;
    char choice;
    cout<<"enter choice(c for car, b for bike): ";
    cin>>choice;
    switch(choice){
        case 'c':
        case 'C':
        {   
            string m;
            double r;
            cout<<"enter model: ";
            cin>>m;
            cout<<"enter rate: ";
            cin>>r;
            ptr= new Car(m,r);
            ptr->getDailyRate();
            ptr->displayDetails();
        }
        break;
        case 'b':
        case 'B':
        {   
            string a;
            double b;
            cout<<"enter model: ";
            cin>>a;
            cout<<"enter rate: ";
            cin>>b;
            ptr= new Bike(a,b);
            ptr->getDailyRate();
            ptr->displayDetails();
        }
        break;
        default:
        cout<<"Enter a valid character"<<endl;
    }
    delete ptr;
    return 0;
}
