//
//  main.cpp
//  DataRepresentation
//
//  Created by Le Hoang Anh on 10/24/20.
//

#include <iostream>
#include <iomanip>
#include "NumberConverter.h"

int main() {
    int choice;
    UInt baseN, baseM;
    string value;
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
                cout << "Base " << setw(2) << left << baseN << ": " << value << endl;
                cout << "Base " << setw(2) << left << baseM << ": " << converter.valueBaseN(baseM) << endl;

                break;
            case 2:
                cout << "Enter base n: ";
                cin >> baseN;

                cin.ignore();
                cout << "Enter value of base " << baseN << ": ";
                getline(cin, value);

                converter.setValueBaseN(value, baseN);
                cout << "Base " << setw(2) << left << baseN << ": " << value << endl;
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
                cout << "Base " << setw(2) << left << baseN << ": " << converter.valueBaseN(baseN) << endl;

                break;
            case 4:
                cin.ignore();
                cout << "Enter a binary value: ";
                getline(cin, value);

                cout << "Enter the k for excess k type (non-negative number): ";
                cin >> k;

                converter.setValueBaseN(value, 2);
                listOfDecimalValues = converter.decimalRepresentByBinaryAllTypes(k);

                cout << setw(17) << left << "Unsigned Integer" << ": " << listOfDecimalValues[NORMAL] << endl;
                cout << "Excess " << setw(10) << left << k << ": " << listOfDecimalValues[OFFSET_BINARY] << endl;
                cout << setw(17) << left << "Sign magnitude" << ": " << listOfDecimalValues[SIGN_MAGNITUDE] << endl;
                cout << setw(17) << left << "One's complement" << ": " << listOfDecimalValues[ONE_COMPLEMENT] << endl;
                cout << setw(17) << left << "Two's complement" << ": " << listOfDecimalValues[TWO_COMPLEMENT] << endl;

                break;
            case 5:
                cout << "You have exited." << endl;
                break;
            default:
                cout << "Invalid choice!." << endl;
                break;
        }

        system("pause");
        system("cls");
    } while (1 <= choice && choice <= 4);
    
    return 0;
}
