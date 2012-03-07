#pragma once

#ifndef VECTOR_H
	#define VECTOR_H
	#include "vector"
	#include "iostream"
#endif
#include "MyFunction.h"

/**
	This class presents simple algo (O(n) on memory) for testing O(1) algorithm

*/

class Tester{
	std::vector<bool> _visited;
	int _arg;
	int _num;
	MyFunction* _myFunc;
	std::vector<int> simple_execute(int arg);
public:
	Tester(int arg, int num, MyFunction* myFunc){
		_arg = arg;
		_num = num;
		_visited.reserve(_num);
		for(int i=0; i < _num; ++i)
		{
			_visited[i] = false;
		}
		/*_myFunc = myFunc;*/
	}
	bool run(std::vector<int> &resVect);



};


bool Tester::run(std::vector<int> &resVect){
	std::vector<int> simp_results;
	simp_results = simple_execute(_arg);
	 	//std::cout << "test results: " << simp_results[0]  <<" and strong: " << resVect[0]<< std::endl;
		//std::cout << "test results: simp:" << simp_results[1] <<" and strong: " << resVect[1] <<  std::endl;

	if(simp_results[0] == resVect[0] && simp_results[1] == resVect[1])
	{
		return true;
	}else 
		return false;
}

std::vector<int> Tester::simple_execute(int arg){
	std::vector<int> simp_res_vect(2);
	int current = arg;
	std::vector<int> stepVect;		//вектор шага
	stepVect.reserve(_num);		//резервируем место в векторе для хранения информации о "посещенных" номерах
	int inc = 0;

	while(!_visited[current]){
		++inc;
		stepVect[current] = inc;	//отмечает, на каком шаге посещена вершина с числом current
		_visited[current] = true;
		current = _myFunc->get(current, _num);
		
		
	}

	
	simp_res_vect[0] = inc - stepVect[current]+1;	//loop length
	simp_res_vect[1] = stepVect[current] - 1;			//tail length
	return simp_res_vect;
}
