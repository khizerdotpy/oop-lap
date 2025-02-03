/*In ocean navigation, locations are measured in degrees and minutes of latitude and longitude. Thus if you’re lying
off the mouth of Papeete Harbor in Tahiti, your location is 149 degrees 34.8 minutes west longitude, and 17
degrees 31.5 minutes south latitude. This is written as 149°34.8’ W, 17°31.5’ S. There are 60 minutes in a degree.
(An older system also divided a minute into 60 seconds, but the modern approach is to use decimal minutes
instead.) Longitude is measured from 0 to 180 degrees, east or west from Greenwich, England, to the international
dateline in the Pacific. Latitude is measured from 0 to 90 degrees, north or south from the equator to the poles.
Create a class angle that includes three member variables: an int for degrees, a float for minutes, and a char for the
direction letter (N, S, E, or W). This class can hold either a latitude variable or a longitude variable. Write one
member function to obtain an angle value (in degrees and minutes) and a direction from the user, and a second to
display the angle value in 179°59.9’ E format. Also write a three-argument constructor.
Write a main() program that displays an angle initialized with the constructor, and then, within a loop, allows the
user to input any angle value, and then displays the value. You can use the hex character constant ‘\xF8’, which
usually prints a degree (°) symbol.

Note:
 fixed: This manipulator is used to display floating-point numbers in fixed-point notation (i.e., a set number
of digits after the decimal point).
 setprecision(n): This manipulator sets the number of digits to be displayed after the decimal point. For
example, setprecision(1) ensures that only one digit will be displayed after the decimal point, as seen in
your angle minutes.*/


#include <iostream>
#include <iomanip>
using namespace std;

class Angle{

    int deg;
    float min;
    char dir;

    public:
    
    void input(){
        cout<<"Enter degrees: ";
        cin>>deg;
        cout<<"Enter minutes (in decimal): ";
        cin>>min;
        cout<<"Enter direction(N/S/E/W): ";
        cin>>dir;
    }

    void display(){
        cout<<deg<<"\xF8 , "<<fixed<<setprecision(1)<<min<<" minutes , "<<dir<<endl;
    }

    //constructor
    Angle(int d,float m, char di){
        deg=d;
        min=m;
        dir=di;
    }

};

int main(){

    Angle lat(120,36.9,'N');
    Angle longi(45,21.2,'S');

    cout<<"Enter latitude as instructed: \n";
    lat.input();

    cout<<"Enter longitude as instructed: \n";
    longi.input();

    cout<<"The latitude is: ";
    lat.display();

    cout<<"The longitude is: ";
    longi.display();

    return 0;
}
