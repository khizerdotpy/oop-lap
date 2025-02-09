#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class StationaryShop {
private:
    string* item;
    float* price;
    int size;

public:
    StationaryShop(int s) {
        size = s;
        item = new string[size];
        price = new float[size];
    }

    void addItems() {
        cout << "Enter " << size << " items and their prices:\n";
        cin.ignore(); 
        for (int i = 0; i < size; ++i) {
            cout << "Item " << i + 1 << ": ";
            getline(cin, item[i]);
            cout << "Price for " << item[i] << ": $";
            cin >> price[i];
            cin.ignore(); 
        }
    }

    void editPrices() {
        int target;
        float newPrice;

        cout << "Enter the item number (1-" << size << ") to change the price: ";
        cin >> target;

       
        if (target < 1 || target > size) {
            cout << "Invalid item number!\n";
            return;
        }

        cout << "Price before change: $" << price[target - 1] << endl;
        cout << "Enter new price: $";
        cin >> newPrice;

        price[target - 1] = newPrice;
        cout << "Price updated successfully!\n";
    }

    void displayItems() {
        cout << "\nItems in the shop:\n";
        for (int i = 0; i < size; ++i) {
            cout << i + 1 << ". " << item[i] << " - $" << price[i] << endl;
        }
    }

    void generateReceipt() {
        int numPurchases;
        cout << "\nEnter the number of different items the customer is buying: ";
        cin >> numPurchases;

        float total = 0.0;
        cout << "\nGenerating Receipt...\n";
        cout << "------------------------------------\n";
        cout << setw(20) << left << "Item" << setw(10) << "Qty" << setw(10) << "Price" << setw(10) << "Total" << endl;
        cout << "------------------------------------\n";

        for (int i = 0; i < numPurchases; ++i) {
            int itemNum, quantity;
            cout << "Enter item number (1-" << size << "): ";
            cin >> itemNum;

            // Validate input
            if (itemNum < 1 || itemNum > size) {
                cout << "Invalid item number! Try again.\n";
                i--;  // Retry input
                continue;
            }

            cout << "Enter quantity: ";
            cin >> quantity;

            float itemTotal = price[itemNum - 1] * quantity;
            total += itemTotal;

            cout << setw(20) << left << item[itemNum - 1] << setw(10) << quantity
                 << "$" << setw(9) << fixed << setprecision(2) << price[itemNum - 1]
                 << "$" << setw(9) << itemTotal << endl;
        }

        cout << "------------------------------------\n";
        cout << setw(40) << left << "Grand Total: $" << fixed << setprecision(2) << total << endl;
        cout << "------------------------------------\n";
    }

    ~StationaryShop() {
        delete[] item;
        delete[] price;
        cout << "Memory released successfully!\n";
    }
};

int main() {
    int n;
    cout << "Enter the number of items in the shop: ";
    cin >> n;

    StationaryShop shop(n);

    int choice;
    do {
        cout << "\n=== Stationary Shop Menu ===\n";
        cout << "1. Add Items and Prices\n";
        cout << "2. Edit Prices\n";
        cout << "3. View Items and Prices\n";
        cout << "4. Generate Receipt\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                shop.addItems();
                break;
            case 2:
                shop.editPrices();
                break;
            case 3:
                shop.displayItems();
                break;
            case 4:
                shop.generateReceipt();
                break;
            case 5:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice! Please enter a number between 1 and 5.\n";
        }
    } while (choice != 5);
    

    return 0;
}
