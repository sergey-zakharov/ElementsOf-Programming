#ifndef EXECUTER
#define EXECUTER

#include <vector>
#include <iostream>


#include "MyFunction.h"

template <typename NUMERIC>
class PrecycleLengthFinder{
private:
	int _num;		
	MyFunction myFunc; 
	NUMERIC findIncycleElem(NUMERIC arg_first);
	int countLoopElem(NUMERIC second);
	int tailLenCount(NUMERIC first, int looplen);

public:
	PrecycleLengthFinder(int number = 100500){
		_num=number;
	}
	NUMERIC executeFunc(NUMERIC first);
	std::vector<int> run(NUMERIC arg);
	void changeN(int n){
		_num = n;
	}

};

template <typename NUMERIC>
NUMERIC PrecycleLengthFinder<NUMERIC>::executeFunc(NUMERIC first){
	
	return myFunc(first, _num);
	
}

template <typename NUMERIC>
NUMERIC PrecycleLengthFinder<NUMERIC>::findIncycleElem(NUMERIC argFirst)
{
	int numElem = 1;
	bool elementsEqual = true;
	NUMERIC first = argFirst;
	NUMERIC second = argFirst;
	
	while(elementsEqual){
		
		first = executeFunc(first);
		second = executeFunc(executeFunc(second));
		
		if(first==second){
			elementsEqual = false;
		}
	}
	return  second;
}




template <typename NUMERIC>
int PrecycleLengthFinder<NUMERIC>::countLoopElem(NUMERIC incycleElem)
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

	NUMERIC res_second = findIncycleElem(arg);
	
	int cycleLength = countLoopElem(res_second);
	results.push_back(cycleLength);
	
	int tailLen = tailLenCount(arg, cycleLength);
	results.push_back(tailLen);

	return results;
	
}
#endif
