#include <cstring>
#ifndef IOSTREAM
#define IOSTREAM
	#include <iostream>
#endif
template<typename T>
class Tester{

public: 
bool run(std::string oper, T arg, int intArg, T result);

};

template<typename T>
bool Tester<T>::run(std::string oper, T arg, int intArg, T result){
	if (oper=="pow"){
		//std::cout << "in \'pow\'" << std::endl;
		T multiplier = arg;
		for(int i=0; i<intArg-1; ++i){
		//std::cout << arg << std::endl;
			arg = arg*multiplier;
		}
		T trivial(arg);
		if(!intArg){
			arg=trivial();
		}
		//std::cout << result << std::endl;
		//std::cout << arg << std::endl;
		if(arg == result) 
			return true;
		
	}
	
	if(oper == "mult"){
		//std::cout << "in \'mult\'" << std::endl;
		T summand = arg;
		for(int i=0; i<intArg-1; ++i){
			arg = arg+summand;
		}
		if(!intArg){
			arg = arg(0);
		}
		if(arg == result) 
			return true;
	}
	
	return false;
}
