#ifndef EXECUTER
#define EXECUTER

#include <vector>
#include <iostream>


#include "MyFunction.h"

template <typename NUMBERIC>
class Executer{
private:
	int _num;		//module
	MyFunction myFunc; 
	std::pair<int, NUMBERIC> elemSearch(NUMBERIC arg_first, NUMBERIC arg_second);
	int countLoopElem(NUMBERIC first, NUMBERIC second);
	int tailLenCount(NUMBERIC first, int looplen);

public:
	Executer(){
		_num = 100500;
	}	
	Executer(int number){
		_num=number;
	}
	NUMBERIC executeFunc(NUMBERIC first);
	std::vector<int> run(NUMBERIC arg);
	void changeN(int n){
		_num = n;
	}

};

template <typename NUMBERIC>
NUMBERIC Executer<NUMBERIC>::executeFunc(NUMBERIC first){
	
	return myFunc(first, _num);
	
}

template <typename NUMBERIC>
std::pair<int, NUMBERIC> Executer<NUMBERIC>::elemSearch(NUMBERIC first, NUMBERIC second)
{
	int numElem = 1;
	bool flag = true;
//	std::cout << "elemsearch" << std::endl;
	while(flag){
	first = executeFunc(first);
	second = executeFunc(executeFunc(second));
	if(first==second)//совпали, нашли элемент в цикле
	{	
		flag = false;
	}
	else 
		++numElem;
	}
	return  std::pair<int, NUMBERIC>(numElem, second);
}

template <typename NUMBERIC>
int Executer<NUMBERIC>::countLoopElem(NUMBERIC first, NUMBERIC second)
{
	bool flag = true;
	int  loopLen = 0;
//	std::cout << "countLoopElem" << std::endl;
	while(flag){
		loopLen++;// зачли элемент, потом идем дальше
		first = executeFunc(first);
	
		if(first==second)
		{	
			flag = false;
		}
	}	
	
	return loopLen;
}

template <typename NUMBERIC>
int Executer<NUMBERIC>::tailLenCount(NUMBERIC first, int loopLen)
{
	int tailLen = 0;
	NUMBERIC second = first;
//	std::cout << "tailLenCount" << std::endl;

	for(int i=0; i< loopLen; ++i)// переходим до loopLen элемента, чтобы дальше идти параллельно.
	{
		second = executeFunc(second);
	}
	bool flag = true;

	//подсчет длины хвоста 		//  TailLenCount
	while(flag){
		if(first==second)// сошлись в цикле
		{	
			flag = false;
		}
		else {
			first = executeFunc(first);
			second = executeFunc(second);
			tailLen++;
		}
	}
	return tailLen;
}


template <typename NUMBERIC>
std::vector<int> Executer<NUMBERIC>::run(NUMBERIC arg){
	//NUMBERIC first=arg;
	//NUMBERIC second=arg;

	std::vector<int> results;

	std::pair<int, NUMBERIC> res_pair = elemSearch(arg, arg);
	int numElem = res_pair.first;
	NUMBERIC res_second = res_pair.second;

	int loopLen = countLoopElem(res_second, res_second);
	results.push_back(loopLen);
	
	int tailLen = tailLenCount(arg, loopLen);
	results.push_back(tailLen);
//		std::cout << "elemsearch" << std::endl;



	return results;
	
}
#endif
