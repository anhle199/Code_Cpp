#include "Product.h"

void inputProduct(ifstream &in, Product &product) {
    getline(in, product.id);
    getline(in, product.name);
    in >> product.stock >> product.price;

    in.ignore(); // clear cache.
}

void inputProductArray(ifstream &in, Product products[], int &n) {
    in >> n;
    in.ignore();

    for (int i = 0; i < n; i++)
        inputProduct(in, products[i]);
}

void writeResult(ofstream &out, const unsigned long &total_money) {
    out << total_money << endl;
}

unsigned long sumPriceOfAllProducts(Product products[], const int &n) {
    unsigned long total_money = 0;

    for (int i = 0; i < n; i++)
        total_money += products[i].stock * products[i].price;

    return total_money;
}