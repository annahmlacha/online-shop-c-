#include <iostream>
#include <vector>
#include <string>
#include <iomanip> // For setting precision for floating point numbers

using namespace std;

// Define a Product class to hold product details
class Product {
public:
    string name;
    float price;
    int stock;

    Product(string n, float p, int s) : name(n), price(p), stock(s) {}

    void displayProduct() const {
        cout << name << " - Price: $" << fixed << setprecision(2) << price 
             << " - Stock: " << stock << endl;
    }
};

// Define a ShoppingCart class to manage added products
class ShoppingCart {
public:
    vector<Product> cart;
    float totalAmount;

    ShoppingCart() : totalAmount(0) {}

    // Function to add product to the cart
    void addProductToCart(const Product& product) {
        cart.push_back(product);
        totalAmount += product.price;
    }

    // Function to display the cart
    void displayCart() const {
        cout << "\nYour Shopping Cart:" << endl;
        for (auto& product : cart) {
            cout << product.name << " - Price: $" << fixed << setprecision(2) << product.price << endl;
        }
        cout << "\nTotal Amount: $" << fixed << setprecision(2) << totalAmount << endl;
    }

    // Function to proceed to checkout
    void checkout() const {
        cout << "\nProceeding to checkout...\n";
        cout << "Total Amount: $" << fixed << setprecision(2) << totalAmount << endl;
        cout << "Thank you for shopping with us!" << endl;
    }
};

int main() {
    // Create a list of products available for sale
    vector<Product> products = {
        Product("Laptop", 999.99, 10),
        Product("Smartphone", 499.99, 20),
        Product("Headphones", 89.99, 50),
        Product("Tablet", 299.99, 15),
        Product("Smart Watch", 149.99, 30)
        Product("Desktop"), 156.17,68)
    };

    // Create a shopping cart
    ShoppingCart cart;
    
    int choice;
    while (true) {
        cout << "\nWelcome to the Online Store!" << endl;
        cout << "Available Products:" << endl;
        
        // Display available products
        for (int i = 0; i < products.size(); i++) {
            cout << i + 1 << ". ";
            products[i].displayProduct();
        }

        cout << "\nEnter the number of the product to add to your cart, or 0 to checkout: ";
        cin >> choice;

        if (choice == 0) {
            // Checkout the cart
            cart.displayCart();
            cart.checkout();
            break;
        } 
        else if (choice > 0 && choice <= products.size()) {
            // Add product to cart
            if (products[choice - 1].stock > 0) {
                cart.addProductToCart(products[choice - 1]);
                products[choice - 1].stock--;
                cout << "Added " << products[choice - 1].name << " to your cart!" << endl;
            } else {
                cout << "Sorry, this product is out of stock." << endl;
            }
        } 
        else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
