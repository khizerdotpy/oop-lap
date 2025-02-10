#include <iostream>
#include <string>
using namespace std;

class Car{
    int carID;
    string model;
    int year;
    bool isRented;

    public:
    Car(){
        isRented=false;
    }

    Car(int id=0,string mdl="", int yr=0, bool ir=false):
        carID(id),model(mdl),year(yr),isRented(ir){}

    void rentCar(){
        if (isRented==false){
            cout<<"\nCar successfully rented.\n";
            isRented=true;
        } else {
            cout<<"\nCar is already rented.\n";
        }
    }

    void returnCar(){
        if (isRented==true){
            cout<<"\nCar successfully returned.\n";
            isRented=false;
        } else {
            cout<<"\nunable to return car.\n";
        }
    }

    bool isVintage(){
        if(year<2000){
            cout<<"\nyoooo that is vintage.\n";
            return true;
        } else {
            cout<<"\nnot vintage yet, give it a few years\n";
            return false;
        }
    }


};

int main(){

    Car c1(100,"mxy20",2023,1);
    Car c2(400,"m32r",1965,0);

    c1.isVintage();
    c1.rentCar();
    c1.returnCar();

    c2.isVintage();
    c2.rentCar();
    c2.returnCar();
    

    return 0;
}
