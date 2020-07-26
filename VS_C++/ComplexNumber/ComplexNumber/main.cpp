#include "ComplexNumber.h"

int main() {
	ComplexNumber* c1 = new ComplexNumber;
	ComplexNumber* c2 = new ComplexNumber;

	cout << "Enter the real part and the imaginary part: ";
	cin >> *c1;
	cout << "Enter the real part and the imaginary part: ";
	cin >> *c2;

	system("pause");
	system("cls");

	cout << "Complex number 1: " << *c1 << endl;
	cout << "Complex number 2: " << *c2 << endl;

	cout << "Sum two complex numbers: (" << *c1 << ") + (" << *c2 << ") = " << (*c1) + (*c2) << endl;
	cout << "Subtract two complex numbers: (" << *c1 << ") - (" << *c2 << ") = " << (*c1) - (*c2) << endl;
	cout << "Multiply two complex numbers: (" << *c1 << ") * (" << *c2 << ") = " << (*c1) * (*c2) << endl;
	cout << "Divide two complex numbers: (" << *c1 << ") / (" << *c2 << ") = " << (*c1) / (*c2) << endl;
	cout << "Power 9 of (" << *c1 << "): (" << *c1 << ")^9 = " << c1->power(9) << endl;
	cout << "Absolute of (" << *c2 << "): |" << *c2 << "| = " << c2->abs() << endl;

	cout << "Compare two complex numbers: (" << *c1 << ") == (" << *c2 << ") is " << (((*c1) == (*c2)) ? ("true") : ("false")) << endl;
	cout << "Compare two complex numbers: (" << *c1 << ") != (" << *c2 << ") is " << (((*c1) != (*c2)) ? ("true") : ("false")) << endl;

	delete c1;
	delete c2;

	return 0;
}