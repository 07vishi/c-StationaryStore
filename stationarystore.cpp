#include <iostream>
#include <string>
#include <vector>
#include <iomanip> // For std::setprecision

using namespace std;

class StationaryItem {
private:
    
    string name;
    double purchasePrice;
    double sellingPrice;

public:
    StationaryItem(const string& name, double purchasePrice, double sellingPrice)
        : name(name), purchasePrice(purchasePrice), sellingPrice(sellingPrice) {}

    const string& getName() const {
        return name;
    }

    double getPurchasePrice() const {
        return purchasePrice;
    }

    double getSellingPrice() const {
        return sellingPrice;
    }

    double calculateProfit() const {
        return sellingPrice - purchasePrice;
    }
};

class StationaryStore {
private:
    vector<StationaryItem> items;

public:
    void addItem(const StationaryItem& item) {
        items.push_back(item);
    }

    void displayItems() const {
        cout << "Stationary Store Items:" << endl;
        cout << setw(20) << left << "Name" << setw(15) << "Purchase Price" << setw(15) << "Selling Price" << setw(10) << "Profit" << endl;
        cout << setfill('-') << setw(60) << "-" << setfill(' ') << endl;

        for (const auto& item : items) {
            cout << setw(20) << left << item.getName() << setw(15) << fixed << setprecision(2) << item.getPurchasePrice()
                 << setw(15) << fixed << setprecision(2) << item.getSellingPrice() << setw(10) << fixed << setprecision(2) << item.calculateProfit() << endl;
        }
    }

    void purchaseItem(const string& itemName) {
        for (auto& item : items) {
            if (item.getName() == itemName) {
                cout << "Purchased " << item.getName() << " for $" << fixed << setprecision(2) << item.getPurchasePrice() << endl;
                return;
            }
        }
        cout << "Item not found!" << endl;
    }
};

int main() {
    // Creating items
    StationaryItem pen("Pen", 0.5, 1.0);
    StationaryItem pencil("Pencil", 0.3, 0.8);
    StationaryItem notebook("Notebook", 1.5, 3.0);
    StationaryItem eraser("Eraser", 0.2, 0.5);
    StationaryItem ruler("Ruler", 0.4, 0.7);

    // Creating store
    StationaryStore store;

    // Adding items to the store
    store.addItem(pen);
    store.addItem(pencil);
    store.addItem(notebook);
    store.addItem(eraser);
    store.addItem(ruler);

    // Displaying items and their details
    store.displayItems();

    // Example of purchasing an item
    store.purchaseItem("Pencil");

    return 0;
}
