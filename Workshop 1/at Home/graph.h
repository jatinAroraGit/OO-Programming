
/* ///////////// Workshop 1 /////////////// AT HOME ////////////
 Name - JATIN ARORA
136897162

Purpose of This Workshop - To make header files and use them in source code files
to get a desired output
Purpose of this file - it has the function prototypes of printGraph,printBar , getSamples and findMax.
/////////////////////////////////////////////// */


#pragma once
#ifndef SICT_GRAPH_H   //Guards to avoid multiple inclusion
#define SICT_GRAPH_H
namespace sict{
#define MAX_NO_OF_SAMPLES 20
	void printGraph(int samples[], int noOfSamples);
	void printBar(int val, int max);
	void getSamples(int samples[], int noOfSamples);
	int findMax(int samples[], int noOfSamples);
}
#endif
