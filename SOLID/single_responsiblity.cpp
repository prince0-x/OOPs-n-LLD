#include <bits/stdc++.h>
using namespace std;

class Marker {
public:
    string name;
    string color;
    int year;
    int price;

    Marker(string name, string color, int year, int price) {
      this->name = name;
      this->color = color;
      this->year = year;
      this->price = price;
    }
};

class Invoice {
private:
    Marker marker;
    int quantity;

public:
    Invoice(Marker marker, int quantity) : marker(marker), quantity(quantity) {}

    int calculateTotalPrice() const {  // Marked as const
      return marker.price * quantity;
    }

    // Getters for encapsulation
    Marker getMarker() const { return marker; }
    int getQuantity() const { return quantity; }
};

// Separate class for persistence (DB Operations)
class InvoiceDao {
public:
      static void saveToDb(const Invoice& invoice) {
      cout << "Storing invoice in DB: " 
            << "Marker: " << invoice.getMarker().name 
            << ", Quantity: " << invoice.getQuantity() 
            << ", Total Price: " << invoice.calculateTotalPrice() << endl;
      }
};

// Separate class for printing (Presentation Logic)
class InvoicePrinter {
public:
    static void print(const Invoice& invoice) {
      cout << "Invoice Details: \n"
            << "Marker: " << invoice.getMarker().name << "\n"
            << "Color: " << invoice.getMarker().color << "\n"
            << "Year: " << invoice.getMarker().year << "\n"
            << "Quantity: " << invoice.getQuantity() << "\n"
            << "Total Price: " << invoice.calculateTotalPrice() << "\n";
    }
};

int main() {
    Marker camlinMarker("Camlin", "Blue", 2023, 50);
    Invoice invoice(camlinMarker, 3);

    InvoicePrinter::print(invoice); 
    InvoiceDao::saveToDb(invoice);   

    return 0;
}
