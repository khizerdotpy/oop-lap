#include <iostream>
#include <string>
using namespace std;

class SmartDevice{
    public:
    SmartDevice() {}
    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
    virtual bool getStatus() = 0;

};

class Lightbulb: public SmartDevice{

    protected:
    bool isOn;
    int brightness;
    public:
    Lightbulb() : isOn(false), brightness(100) {}
    void turnOn() override {
        isOn=true;
    }
    void turnOff() override {
        isOn=false;
    }
    bool getStatus() override {
        return isOn;
    }
};

class Thermostat: public SmartDevice{

    protected:
    bool isOn;
    double temperature;
    public:
    Thermostat() : isOn(false), temperature(22.0) {}
    void turnOn() override {
        isOn=true;
    }
    void turnOff() override {
        isOn=false;
    }
    bool getStatus() override {
        return isOn;
    }
};

int main() {
    Lightbulb l1, l2;
    Thermostat t1, t2;

    l1.turnOn();
    cout << "Lightbulb 1 is on: " << l1.getStatus() << endl;
    t1.turnOn();
    cout << "Thermostat 1 is on: " << t1.getStatus() << endl;
    l2.turnOff();
    cout << "Lightbulb 2 is off: " << l2.getStatus() << endl;
    t2.turnOff();
    cout << "Thermostat 2 is off: " << t2.getStatus() << endl;


    return 0;
}
