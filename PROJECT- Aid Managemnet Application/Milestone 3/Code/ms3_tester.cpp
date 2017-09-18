///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Final Project Milestone 3
//
// NAME - JATIN ARORA (136897162)
// DATE - 7/12/2017
// FILE - ms3_tester.cpp

// Purpose - This file contains definiton of main function which tests our code written in Streamable.h file
/////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "MyFile.h"
using namespace std;
using namespace sict;
int main(){  
  fstream file("ms3.txt", ios::out);
  file << "one" << endl << "two" << endl;
  file.close();
  MyFile F("ms3.txt");
  F.load(file);
  cout << "Linear: " << F << endl;
  cout << "As is: " << endl;
  F.print();
  cout << "Enter the following: " << endl << "three<ENTER>" << endl << "four<ENTER>" << endl << "Ctrl-Z<ENTER>" << endl << endl;
  cin >> F;
  F.store(file, true);
  F.load(file);
  cout << F << endl;
  F.print();
  return 0;
}
