#include "Fraction.h"

int main() {
    Fraction fractions[199];
    int n = 0;

    ifstream in("input.txt");
    
    if (!in.is_open()) {
        cout << "File does not exist." << endl;
    } else {
        inputFractionArray(in, fractions, n);
        Fraction result = findMaxFraction(fractions, n);
        
        in.close();
    
        ofstream out("output.txt");

        if (!out.is_open()) {
            cout << "Can not create file." << endl;
        } else {    
            outputFraction(out, result);
            out.close();
        }
    }

    return 0;
}