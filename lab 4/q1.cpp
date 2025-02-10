#include <iostream>
#include <string>
using namespace std;

class Student{

    int studentID;
    string name;
    int age;
    char grade;

    public:

    Student(){
        grade='N';
    }
    // Student(int id,string n, int a, char grd){
    //     studentID=id;
    //     name=n;
    //     age=a;
    //     grade=grd;
    // }

    Student(int id=000,string n="john", int a=18, char grd='N'):
        studentID(id),name(n),age(a),grade(grd){}

    void promoteStudent(){
        if(grade==65){
            cout<<"we get it they're good, they can't be better(grade cannot go higher than an A)"<<endl;
            return;
        } else if (grade==78){
            cout<<"can't promote a grade if it hasn't been assigned yet"<<endl;
            return;
        } else{
            --grade;
            cout<<"\npromotion successful\n"<<endl;
        }
    }

    bool isEligibleForScholarship(){
        if (grade==65){
            cout<<"yippee. Student is eligible"<<endl;
            return 1;
        } else {
            cout<<"boo hoo. Student is not eligible"<<endl;
            return 0;
        }
    }

    void displayDetails(){
        cout<<"Student Details: \n";
        cout<<"Student ID: "<<studentID<<endl;
        cout<<"Name: "<<name<<endl;
        cout<<"Age: "<<age<<endl;
        cout<<"Grade: "<<grade<<endl;
    }
};

int main(){

    Student s1(100,"jack",19,'B');
    Student s2(200,"elsa",23,'A');
    Student s3(100,"umar",17,'C');

    cout<<"Before promotion: \n"<<endl;
    s1.displayDetails();

    s1.promoteStudent();

    cout<<"After promotion: \n"<<endl;
    s1.displayDetails();

    cout<<endl;

    
    s2.isEligibleForScholarship();

    return 0;
}
