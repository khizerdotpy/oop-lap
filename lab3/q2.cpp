/*Imagine a tollbooth at a bridge. Cars passing by the booth are expected to pay a 50 cent toll. Mostly they do, but
sometimes a car goes by without paying. The tollbooth keeps track of the number of cars that have gone by, and of
the total amount of money collected.
Model this tollbooth with a class called tollBooth. The two data items are a type unsigned int to hold the total
number of cars, and a type double to hold the total amount of money collected. A constructor initializes both of

these to 0. A member function called payingCar() increments the car total and adds 0.50 to the cash total. Another
function,
called nopayCar(), increments the car total but adds nothing to the cash total. Finally, a member function called
display() displays the two totals. Make appropriate member functions const.
Include a program to test this class. This program should allow the user to push one key to count a paying car, and
another to count a nonpaying car. Pushing the Esc key should cause the program to print out the total cars and
total cash and then exit.*/

#include <iostream>
#include <conio.h>
using namespace std;

class TollBooth{
    unsigned int tc;
    double tm;
    public:
    TollBooth(){
        tc=0;
        tm=0;
    }
    
    void payingCar(){
        tc++;
        tm+=0.50;
    }

    void nopayCar(){
        tc++;

    }

    void display(){
        cout<<"the total number of cars: "<<tc<<endl;
        cout<<"the total amount of money collected: "<<tm<<endl;
    }

};

int main(){
    TollBooth obj;
    cout<<"Tollbooth system."<<endl<<"enter o to add a paying car. enter p to add a non-paying car. press ESCAPE key to exit."<<endl;
    while(1){
        char ch=_getch();
        switch(ch){
            case 'o':
            case 'O':
                obj.payingCar();
                cout<<"paying car counted"<<endl;
                break;
            case 'p':
            case 'P':
                obj.nopayCar();
                cout<<"non-paying car counted"<<endl;
                break;
            case 27:
                cout<<"Exiting"<<endl;
                obj.display();
                break;
            default:
                cout<<"invalid. press o or p."<<endl;
                break;

        }
    }
    return 0;
}
