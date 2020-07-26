#include "Product.h"

int main() {
    Product products[199];
    int n = 0;

    ifstream in("input.txt");

    if (!in.is_open()) {
        cout << "File does not exist." << endl;
    } else {
        inputProductArray(in, products, n);
        unsigned long total_money = sumPriceOfAllProducts(products, n);
    
        in.close();
        
        ofstream out("output.txt");

        if (!out.is_open()) {
            cout << "Can not create file." << endl;
        } else {
            writeResult(out, total_money);
            out.close();
        }
    }

    return 0;
}