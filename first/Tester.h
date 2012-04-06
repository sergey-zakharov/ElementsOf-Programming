#ifndef TESTER
#define TESTER
#include <vector>
#include <iostream>
#include <map>
#include "MyFunction.h"

/**
	This class presents simple algo (O(n) on memory) for testing O(1) algorithm

*/
template<typename T>
class Tester{
	std::map<T,bool> _visited;
	T _arg;
	//int _num;
	MyFunction _myFunc;
	std::vector<int> simple_execute(T arg);
public:
	Tester(T arg, const MyFunction& myFunc) : _myFunc(myFunc) {
		_arg = arg;
	}
	bool run(std::vector<int> &resVect);



};

template <typename T>
bool Tester<T>::run(std::vector<int> &resVect){
	std::vector<int> simp_results;
	simp_results = simple_execute(_arg);

	if(simp_results[0] == resVect[0] && simp_results[1] == resVect[1])
	{
		return true;
	}else 
		return false;
}

template <typename T>
std::vector<int> Tester<T>::simple_execute(T arg){
	std::vector<int> simp_res_vect(2);
	T current = arg; 
	std::map<T, int> stepVect;		
	int inc = 0;

	while(!_visited[current]){
		++inc;
		stepVect[current] = inc;			//отмечает, на каком шаге посещена вершина с числом current
		_visited[current] = true;
		current = _myFunc(current);
	}
	simp_res_vect[0] = inc - stepVect[current]+1;		//loop length
	simp_res_vect[1] = stepVect[current]-1;			//tail length

	return simp_res_vect;
}
#endif
