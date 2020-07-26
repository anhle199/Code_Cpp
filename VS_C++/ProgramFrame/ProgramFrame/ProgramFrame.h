#ifndef PROGRAM_FRAME_H_
#define PROGRAM_FRAME_H_

#include <iostream>
using namespace std;

class ProgramFrame {
protected:
	virtual void StartMessage(ostream&) = 0;
	virtual void Input(istream&) = 0;
	virtual bool ValidData() = 0;
	virtual void ErrorMessage(ostream&);
	virtual void Processing() {};
	virtual void Output(ostream&) = 0;
	virtual bool AskToContinue(istream&, ostream&);
public:
	void Run(istream&, ostream&);
};

#endif // !PROGRAM_FRAME_H_