#ifndef MY_FUNCTION
#define MY_FUNCTION
#include <cstdlib>
#include <utility>
#include <iostream>
class MyFunction{ 
	
public:
	int num_;
	MyFunction(int num) : num_(num) {
	
	}
	int operator()(int arg){
		return (37*arg + arg*arg + 7)%num_;

	}
	std::pair<int, int> operator ()(const std::pair<int,int>& p){
		int first = p.first;
		int second = p.second;

		if( !(abs(first) < 100) )
			first = first%100;
		if( !(abs(second) < 100) )
			second = second%100;
		int tmp = first*100+second;
		return std::pair<int, int>(tmp, num_);	
		
	}
};

#endif
