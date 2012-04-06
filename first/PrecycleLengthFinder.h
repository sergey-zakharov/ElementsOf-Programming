#ifndef EXECUTER
#define EXECUTER

#include <vector>
#include <iostream>


#include "MyFunction.h"

template <typename NUMERIC>
class PrecycleLengthFinder{
private:
	MyFunction myFunc; 
	NUMERIC findIncycleElements(NUMERIC arg_first);
	int countLoopElements(NUMERIC second);
	int tailLenCount(NUMERIC first, int looplen);

public:
	PrecycleLengthFinder(const MyFunction& myFunc_) : myFunc(myFunc_) { }
	NUMERIC executeFunc(NUMERIC first);
	std::vector<int> run(NUMERIC arg);

};

template <typename NUMERIC>
NUMERIC PrecycleLengthFinder<NUMERIC>::executeFunc(NUMERIC object){
	return myFunc(object);
}

template <typename NUMERIC>
NUMERIC PrecycleLengthFinder<NUMERIC>::findIncycleElements(NUMERIC argFirst)
{
	NUMERIC first = argFirst;
	NUMERIC second = argFirst;
	do {
		first = executeFunc(first);
		second = executeFunc(executeFunc(second));
	} while (!(first == second));
	return  second;
}




template <typename NUMERIC>
int PrecycleLengthFinder<NUMERIC>::countLoopElements(NUMERIC incycleElem)
{
	bool elementsEqual = true;
	int  cycleLength = 1;
	NUMERIC second = incycleElem;
	while(elementsEqual){
		incycleElem = executeFunc(incycleElem);
		if(incycleElem==second){
			elementsEqual = false;
		}
		else ++cycleLength;
	}	
	return cycleLength;
}

/**
	Counting elements in precycle.

*/
template <typename NUMERIC>
int PrecycleLengthFinder<NUMERIC>::tailLenCount(NUMERIC first, int cycleLength)
{
	int tailLen = 0;
	NUMERIC second = first;
	bool elementsEqual = true;
	for(int i=0; i< cycleLength; ++i)
	{
		second = executeFunc(second);
	}
	

	while(elementsEqual){
		++tailLen;
		first = executeFunc(first);
		second = executeFunc(second);
		if(first==second){
			elementsEqual = false;
		}
		
	}
	return tailLen;
}


template <typename NUMERIC>
std::vector<int> PrecycleLengthFinder<NUMERIC>::run(NUMERIC arg){

	std::vector<int> results;

	NUMERIC res_second = findIncycleElements(arg);
	
	int cycleLength = countLoopElements(res_second);
	results.push_back(cycleLength);
	
	int tailLen = tailLenCount(arg, cycleLength);
	results.push_back(tailLen);

	return results;
	
}
#endif
