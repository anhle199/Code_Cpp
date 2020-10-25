//
//  main.cpp
//  DataRepresentation
//
//  Created by Le Hoang Anh on 10/24/20.
//

#include <iostream>
#include "RepresentInteger.h"

int main() {
    int choice;
    UInt baseN, baseM;
    string value;
    Sign signBit;
    UInt k;
    RepresentInteger rn;
    vector<string> listOfDecimalValues;

    do {
        cout << "|--------------------------------------------------------------------|" << endl;
        cout << "|                        CONVERTER NUMBER                            |" << endl;
        cout << "|--------------------------------------------------------------------|" << endl;
        cout << "| 1. Convert from base n to base m.                                  |" << endl;
        cout << "|--------------------------------------------------------------------|" << endl;
        cout << "| 2. Convert from base n to decimal.                                 |" << endl;
        cout << "|--------------------------------------------------------------------|" << endl;
        cout << "| 3. Convert from base decimal to n.                                 |" << endl;
        cout << "|--------------------------------------------------------------------|" << endl;
        cout << "| 4. Convert from binary to decimal.                                 |" << endl;
        cout << "|--------------------------------------------------------------------|" << endl;
        cout << "| 5. Print out all decimal values represented by all type of binary. |" << endl;
        cout << "|--------------------------------------------------------------------|" << endl;
        cout << "| 6. Exit.                                                           |" << endl;
        cout << "|--------------------------------------------------------------------|" << endl;

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter base n: ";
                cin >> baseN;

                cin.ignore();
                cout << "Enter value of base " << baseN << ": ";
                getline(cin, value);

                cout << "Enter base m: ";
                cin >> baseM;

                rn.setValueBaseN(value, baseN);
                cout << "Base " << baseN << ": " << value << endl;
                cout << "Base " << baseM << ": " << rn.valueBaseN(baseM) << endl;

                break;
            case 2:
                cout << "Enter base n: ";
                cin >> baseN;

                cin.ignore();
                cout << "Enter value of base " << baseN << ": ";
                getline(cin, value);

                rn.setValueBaseN(value, baseN);
                cout << "Base " << baseN << ": " << value << endl;
                cout << "Base 10" << ": " << rn.decimal() << endl;

                break;
            case 3:
                cin.ignore();
                cout << "Enter value of base 10: ";
                getline(cin, value);

                cout << "Enter base n: ";
                cin >> baseN;

                rn.setValueBaseN(value, 10);
                cout << "Base 10" << ": " << value << endl;
                cout << "Base 10" << ": " << rn.valueBaseN(baseN) << endl;

                break;
            case 4:
                cout << "Enter sign bit (0 or 1): ";
                cin >> signBit;

                cin.ignore();
                cout << "Enter the binary value: ";
                getline(cin, value);

                cout << "Enter the k for excess k type (non-negative number): ";
                cin >> k;

                rn.setValueBaseN(signBit + value, 2);
                listOfDecimalValues = rn.decimalRepresentByBinaryAllTypes(k);

                cout << "Normal: " << listOfDecimalValues[NORMAL] << endl;
                cout << "Excess " << k << ": " << listOfDecimalValues[OFFSET_BINARY] << endl;
                cout << "Sign magnitude: " << listOfDecimalValues[SIGN_MAGNITUDE] << endl;
                cout << "One's complement: " << listOfDecimalValues[ONE_COMPLEMENT] << endl;
                cout << "Two's complement: " << listOfDecimalValues[TWO_COMPLEMENT] << endl;

                break;
            case 5:
                cout << "You have exited." << endl;
                break;
            default:
                break;
        }

        system("pause");
        system("cls");
    } while (choice != 5);
    
    return 0;
}
