#include <iostream>
using namespace std;

class Time{
    int hour,minute,sec;

    public:
    //constructor
    Time(int h,int m, int s){
        hour=h;
        minute=m;
        sec=s;
    }
    Time(){
        hour=0;
        minute=0;
        sec=0;
    }

    void display(){
        cout<<hour<<" : "<<minute<<" : "<<sec<<endl;
    }

    Time add(const Time& other){
        int comh,comm,coms;
        comh=hour+other.hour;
        comm=minute+other.minute;
        if (comm >= 60) {
            comm -= 60;
            comh++;
        }
        
        coms=sec+other.sec;
        if (coms >= 60) {
            coms -= 60;
            comm++;
        }
        return Time(comh,comm,coms);
    }


};

int main(){
    Time o1(3,7,12);
    Time o2(7,3,12);
    Time o3=o1.add(o2);
    cout<<"after addition: "<<endl;
    o3.display();
    return 0;
}
