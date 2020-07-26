#include "ProgramFrame.h"

void ProgramFrame::ErrorMessage(ostream& outDev) {
	outDev << "==> Invalid input!!!" << endl;
}

bool ProgramFrame::AskToContinue(istream& inDev, ostream& outDev) {
	char ch;

	outDev << "Press 'a' or 'A' to continue, other key to stop..." << endl;
	outDev << "Enter your choice: ";
	inDev >> ch;

	return (ch == 'a' || ch == 'A');
}

void ProgramFrame::Run(istream& inDev, ostream& outDev) {
	bool toContinue;

	do {
		StartMessage(outDev);
		Input(inDev);

		if (!ValidData()) {
			ErrorMessage(outDev);
			continue;
		}

		toContinue = AskToContinue(inDev, outDev);
		system("cls");
	} while (toContinue);
}