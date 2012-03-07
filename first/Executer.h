#ifndef VECTOR
#define VECTOR
	#include <vector>
	#include <iostream>
#endif

#include "MyFunction.h"

class Executer{
private:
	int _num;		//module
	MyFunction* myFunc; 
public:
	Executer(int number){
		_num=number;
	}
	int executeFunc(int first);
	std::vector<int> run(int arg);

};


int Executer::executeFunc(int first){
	
	return myFunc->get(first, _num);
	
}

std::vector<int> Executer::run(int arg){// дубово
	int first=arg;
	int second=arg;

	std::vector<int> results;

	int loopLen=0;
	int tailLen=0;
	int numElem = 1;

	bool flag = true;

	//поиск элемента из цикла
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
	flag = true;
	
	// подсчет элементов в цикле
	while(flag){
		loopLen++;// зачли элемент, потом идем дальше
		first = executeFunc(first);
		
		if(first==second)
		{	
			flag = false;
		}
	}
	
	
	results.push_back(loopLen);
	//results.push_back(numElem - loopLen); нельзя, так как мы можем пройтись по циклу несколько раз, прежде чем встретимся


	first = arg;// первый указываем на начало
	second = arg;//второй тоже
	
	for(int i=0; i< loopLen; ++i)// переходим до loopLen элемента, чтобы дальше идти параллельно.
	{
		second = executeFunc(second);
	}
	flag = true;
	
	//подсчет длины хвоста
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
	//std::cout << "The lenght of tail is " << tailLen << std::endl;
	results.push_back(tailLen);
	


	return results;
	
}

