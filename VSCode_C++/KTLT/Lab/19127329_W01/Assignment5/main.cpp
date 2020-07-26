#include "Date.h"

int main() {
    Date dates[199];
    int n = 0;

    ifstream in("input.txt");
    
    if (!in.is_open()) {
        cout << "File does not exist." << endl;
    } else {
        inputDateArray(in, dates, n);
        sortArrayAscending(dates, n);
        
        in.close();
    
        ofstream out("output.txt");

        if (!out.is_open()) {
            cout << "Can not create file." << endl;
        } else {
            outputDateArray(out, dates, n);
            out.close();
        }
    }

    return 0;
}