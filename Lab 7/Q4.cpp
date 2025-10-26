#include <iostream>
using namespace std;

class Product {
public:
    string name, desc;
    float price;
    bool available;
};

int partition(Product arr[], int low, int high) {
    float pivot = arr[high].price;
    int i = low - 1;
    for (int j = low; j < high; j++)
        if (arr[j].price < pivot) swap(arr[++i], arr[j]);
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(Product arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    Product p[3] = {
        {"Laptop", "Gaming laptop", 150000, true},
        {"Headphones", "Noise cancelling", 15000, true},
        {"Mouse", "Wireless mouse", 5000, false}
    };
    quickSort(p, 0, 2);
    for (int i = 0; i < 3; i++)
        cout << p[i].name << " - " << p[i].price << endl;
}