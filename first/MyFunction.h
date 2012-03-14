#ifndef MY_FUNCTION
#define MY_FUNCTION
#include <cstdlib>
#include <utility>
#include <iostream>
class MyFunction{ 
	
public:
	MyFunction(){
	
	}
	int operator()(int arg, int num){
		//std::cout << arg;
		return (37*arg + arg*arg + 7)%num;// функктор для интов. Ожидается для пары, дальше забить.

	}
	std::pair<int, int> operator ()(std::pair<int,int> p, int num){
		if( !(abs(p.first) < 100) )
			p.first = p.first%100;
		if( !(abs(p.second) < 100) )
			p.second = p.second%100;
		int tmp = p.first*100+p.second;//конкатенация
		return std::pair<int, int>(tmp, num);	
		
	}
};
#endif
