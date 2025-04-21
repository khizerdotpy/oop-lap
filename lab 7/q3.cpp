#include <iostream>
#include <string>
#include <map>
#include <iomanip>
#include <stdexcept>

using namespace std;

class Currency {
public:
    double amount;
    string currencyCode;
    string currencySymbol;
    double exchangeRate;

public:
    Currency(double amount = 0.0, string code = "", string symbol = "", double rate = 1.0)
        : amount(amount), currencyCode(code), currencySymbol(symbol), exchangeRate(rate) {}

    virtual double convertToBase() {
        return amount * exchangeRate;
    }

    double convertTo(Currency* targetCurrency) {
        double amountInBase = this->convertToBase();
        double targetExchangeRate = targetCurrency->exchangeRate;
        return amountInBase / targetExchangeRate;
    }

    virtual void displayCurrency() {
        cout << "Currency: " << currencyCode << " (" << currencySymbol << ")\n";
        cout << "Amount: " << fixed << setprecision(2) << amount << "\n";
        cout << "Exchange Rate (to Base Currency): " << exchangeRate << "\n";
    }

    virtual ~Currency() {}
};

class Dollar : public Currency {
public:
    Dollar(double amount)
        : Currency(amount, "USD", "$", 1.0) {}

    void displayCurrency() override {
        cout << "Currency: " << currencyCode << " (" << currencySymbol << ")\n";
        cout << "Amount: " << currencySymbol << fixed << setprecision(2) << amount << "\n";
        cout << "Exchange Rate (to Base Currency): " << exchangeRate << "\n";
    }
};

class Euro : public Currency {
public:
    Euro(double amount)
        : Currency(amount, "EUR", "€", 0.85) {}

    void displayCurrency() override {
        cout << "Currency: " << currencyCode << " (" << currencySymbol << ")\n";
        cout << "Amount: " << currencySymbol << fixed << setprecision(2) << amount << "\n";
        cout << "Exchange Rate (to Base Currency): " << exchangeRate << "\n";
    }
};

class Rupee : public Currency {
public:
    Rupee(double amount)
        : Currency(amount, "INR", "₹", 75.0) {}

    void displayCurrency() override {
        cout << "Currency: " << currencyCode << " (" << currencySymbol << ")\n";
        cout << "Amount: " << currencySymbol << fixed << setprecision(2) << amount << "\n";
        cout << "Exchange Rate (to Base Currency): " << exchangeRate << "\n";
    }
};

void displayConversion(Currency* sourceCurrency, Currency* targetCurrency) {
    double convertedAmount = sourceCurrency->convertTo(targetCurrency);
    cout << "\nConverted Amount: " << fixed << setprecision(2) << convertedAmount << " " << targetCurrency->currencySymbol << endl;
}

int main() {
    Dollar usd(250);
    Euro eur(85);
    Rupee inr(5400);

    cout << "Dollar Details:\n";
    usd.displayCurrency();
    cout << "\nEuro Details:\n";
    eur.displayCurrency();
    cout << "\nRupee Details:\n";
    inr.displayCurrency();

    cout << "\nConversion from Dollar to Euro:\n";
    displayConversion(&usd, &eur);

    cout << "\nConversion from Euro to Rupee:\n";
    displayConversion(&eur, &inr);

    cout << "\nConversion from Rupee to Dollar:\n";
    displayConversion(&inr, &usd);

    return 0;
}
