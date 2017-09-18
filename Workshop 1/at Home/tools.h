
/* //////////////// Workshop 1 /////  AT HOME  //////////////
Name - JATIN ARORA
136897162

Purpose of Workshop - To make header files and use them in source code files
to get a desired output
Purpose of This file - it contains function prototypes of menu and getINT
/////////////////////////////////////////////// */



#pragma once
#ifndef SICT_TOOLS_H      //Guards to avoid multiple inclusions
#define SICT_TOOLS_H
namespace sict{
	int menu();
	int getInt(int min, int max);
}
#endif

