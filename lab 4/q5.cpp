#include <iostream>
#include <string>
using namespace std;

class Employee{

    int employeeID;
    string name;
    string department;
    double salary;

    public:

    Employee(){
        salary=0.0;
    }

    Employee(int id=0,string n="joan",string dt="mech",double s=400.0):
        employeeID(id),name(n),department(dt),salary(s){}

    void giveBonus(double amt){
        salary+=amt;
        cout<<"\nggs, Bonus added\n";
    }

    bool isManager(){
        if(department=="Management"){
            cout<<"\nyep manager\n";
            return true;
        } else {
            cout<<"\nnot manager\n";
            return false;
        }
    }

    void displayDetail(){
        cout<<"\nEmployee Details\n";

        cout<<"\nEmployee ID: \n"<<employeeID<<"\nName: \n"<<name
            <<"\nDepartment: \n"<<department<<"\nSalary: "<<salary<<endl;
    }
};

int main(){

    Employee e1(2000,"oj simpson","Management",560000);
    Employee e2(5000,"peter parker","teacher",40000);

    cout<<"\nBefore bonus: \n";
    e2.displayDetail();
    e2.giveBonus(500.00);
    cout<<"\nAfter bonus: \n";
    e2.displayDetail();

    e1.isManager();
    e2.isManager();

    return 0;
}
