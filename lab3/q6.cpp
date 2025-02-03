/*Create a class called Smartphone with the following attributes:
 Company
 Model
 Display Resolution
 RAM
 ROM
 Storage

Create getter and setter methods for your attributes. A smartphone has some specific actions that it can perform.
For example:
1. Make a phone call
2. Send a message
3. Connect to the wifi
4. Browse the internet

Create different smartphone objects. Set their attributes using the setter functions and display their attributes after
using the getter functions to fetch the attributes.*/

#include <iostream>
using namespace std;

class Smartphone {
private:
    string company;
    string model;
    string displayResolution;
    int ram;   
    int rom;   
    int storage; 

public:
    // Constructor
    Smartphone(string c = "", string m = "", string dr = "", int r = 0, int rm = 0, int s = 0) 
        : company(c), model(m), displayResolution(dr), ram(r), rom(rm), storage(s) {}

    void setCompany(string c) { company = c; }
    void setModel(string m) { model = m; }
    void setDisplayResolution(string dr) { displayResolution = dr; }
    void setRAM(int r) { ram = r; }
    void setROM(int rm) { rom = rm; }
    void setStorage(int s) { storage = s; }

    string getCompany() const { return company; }
    string getModel() const { return model; }
    string getDisplayResolution() const { return displayResolution; }
    int getRAM() const { return ram; }
    int getROM() const { return rom; }
    int getStorage() const { return storage; }

    void makeCall(string number) const {
        cout << "Calling " << number << " using " << model << "...\n";
    }

    void sendMessage(string number, string message) const {
        cout << "Sending message to " << number << ": " << message << endl;
    }

    void connectToWiFi(string network) const {
        cout << model << " is connecting to WiFi network: " << network << endl;
    }

    void browseInternet(string website) const {
        cout << model << " is browsing: " << website << endl;
    }

    void displayInfo() const {
        cout << "\nSmartphone Details:\n";
        cout << "Company: " << company << endl;
        cout << "Model: " << model << endl;
        cout << "Display Resolution: " << displayResolution << endl;
        cout << "RAM: " << ram << "GB" << endl;
        cout << "ROM: " << rom << "GB" << endl;
        cout << "Storage: " << storage << "GB" << endl;
    }
};


int main() {

    Smartphone phone1;
    Smartphone phone2("Google", "Pixel 7", "2400x1080", 8, 128, 512);

    phone1.setCompany("OnePlus");
    phone1.setModel("OnePlus 11");
    phone1.setDisplayResolution("3216x1440");
    phone1.setRAM(16);
    phone1.setROM(256);
    phone1.setStorage(512);

    cout << "Phone 1 Details:";
    phone1.displayInfo();
    cout << "\nPhone 2 Details:";
    phone2.displayInfo();

    cout << "\nPerforming Actions:\n";
    phone1.makeCall("+9876543210");
    phone1.sendMessage("+9876543210", "Hey! Are we meeting today?");
    phone1.connectToWiFi("Office_Network");
    phone1.browseInternet("www.github.com");

    return 0;
}

