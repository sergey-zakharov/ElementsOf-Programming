#include "PrecycleLengthFinder.h"
#include "Tester.h"
#include "MyFunction.h"
#include <utility>

template <typename T>
class PrecycleLengthFinderWrapper{
	PrecycleLengthFinder<T> _exec;
	MyFunction _myFunc;
	
	public:
	PrecycleLengthFinderWrapper(const MyFunction& myFunc) : _exec(myFunc), _myFunc(myFunc){
	}

	void run(T arg){
	
		T x = arg;
        	Tester<T> myTester(x, _myFunc);

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
