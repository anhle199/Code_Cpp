//
//  main.cpp
//  DataRepresentation
//
//  Created by Le Hoang Anh on 10/24/20.
//

#include <iostream>
#include "NumberConverter.h"

int main() {
    int choice;
    UInt baseN, baseM;
    string value;
    Sign signBit;
    UInt k;
    NumberConverter converter;
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
        cout << "| 4. Print out all decimal values represented by all type of binary. |" << endl;
        cout << "|--------------------------------------------------------------------|" << endl;
        cout << "| 5. Exit.                                                           |" << endl;
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

                converter.setValueBaseN(value, baseN);
                cout << "Base " << baseN << ": " << value << endl;
                cout << "Base " << baseM << ": " << converter.valueBaseN(baseM) << endl;

                break;
            case 2:
                cout << "Enter base n: ";
                cin >> baseN;

                cin.ignore();
                cout << "Enter value of base " << baseN << ": ";
                getline(cin, value);

                converter.setValueBaseN(value, baseN);
                cout << "Base " << baseN << ": " << value << endl;
                cout << "Base 10" << ": " << converter.decimal() << endl;

                break;
            case 3:
                cin.ignore();
                cout << "Enter value of base 10: ";
                getline(cin, value);

                cout << "Enter base n: ";
                cin >> baseN;

                converter.setValueBaseN(value, 10);
                cout << "Base 10" << ": " << value << endl;
                cout << "Base 10" << ": " << converter.valueBaseN(baseN) << endl;

                break;
            case 4:
                cout << "Enter sign bit (0 or 1): ";
                cin >> signBit;

                cin.ignore();
                cout << "Enter the binary value: ";
                getline(cin, value);

                cout << "Enter the k for excess k type (non-negative number): ";
                cin >> k;

                converter.setValueBaseN(signBit + value, 2);
                listOfDecimalValues = converter.decimalRepresentByBinaryAllTypes(k);

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
