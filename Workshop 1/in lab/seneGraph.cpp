

/* //////////// Workshop 1 ////////// IN LAB ///////////////////
 Name - JATIN ARORA
136897162

Purpose Of Workshop - To make header files and use them in source code files
to get a desired output.
Purpose of this file - it contains the main function and the statements which implements the purpose of this workshop.

/////////////////////////////////////////////// */



#include <iostream>
using namespace std;

#include "graph.h"
#include "tools.h"

int main() {
	int noOfSamples = 0;
	int samples[MAX_NO_OF_SAMPLES] = { 0 };
	bool done = false;
	cout << "Welcome to SeneGraph" << endl;
	while (!done) {
		cout << "No Of Samples: " << noOfSamples << endl;
		switch (menu()) {
		case 1:
			cout << "Enter number of samples on hand: ";
			noOfSamples = getInt(1, MAX_NO_OF_SAMPLES);
			break;
		case 2:
			if (noOfSamples == 0) {
				cout << "First enter the number of Samples." << endl;
			}
			else {
				cout << "Please enter the sample values: " << endl;
				getSamples(samples, noOfSamples);
			}
			break;
		case 3:
			if (noOfSamples == 0) {
				cout << "First enter the number of Samples." << endl;
			}
			else if (samples[0] == 0) {
				cout << "Firt enter the samples." << endl;
			}
			else {
				printGraph(samples, noOfSamples);
			}
			break;
		case 0:
			cout << "Thanks for using SeneGraph" << endl;
			done = true;
		}
	}
	return 0;
}
