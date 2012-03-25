#include "PrecycleLengthFinder.h"
#include "Tester.h"
#include "MyFunction.h"
#include <utility>

template <typename T>
class PrecycleLengthFinderWrapper{
	PrecycleLengthFinder<T> _exec;
	int _num;
	public:
	PrecycleLengthFinderWrapper(int arg, int n){
		_num = n;
		_exec.changeN(n);
	}

	void run(T arg){
	
		T x = arg;
        	Tester<T> myTester(x, _num);

	        std::vector<int> resVect = _exec.run(x);
        	std::cout << "Loop lenght: " << resVect[0] << std::endl;
	        std::cout << "Tail lenght:  " << resVect[1] << std::endl;
        	std::cout << "Is everything right: ";
	        if ( myTester.run(resVect))
        	{
                	std::cout << "yes";     
	        }
        	else 
                	std::cout << "no";
	        std::cout<< std::endl;
	}

};
