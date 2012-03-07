#pragma once
#ifndef MY_FUNCTION_CPP
#define MY_FUNCTION_CPP
class MyFunction{ 
	
public:
	MyFunction(){
	
	}
	int get(int arg, int num){
		return (37*arg + arg*arg + 7)%num;
	}


};
#endif
