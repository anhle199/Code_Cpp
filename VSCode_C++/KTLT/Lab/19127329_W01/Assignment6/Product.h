#ifndef PRODUCT_H_
#define PRODUCT_H_

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#pragma pack(1)

struct Product {
    string id, name;
    int stock;
    unsigned long price;
};

void inputProduct(ifstream &in, Product &product);
void inputProductArray(ifstream &in, Product products[], int &n);
void writeResult(ofstream &out, const unsigned long &total_money);

// Calculate the total price of all products. 
unsigned long sumPriceOfAllProducts(Product products[], const int &n);

#endif