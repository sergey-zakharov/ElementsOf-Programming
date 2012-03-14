#include "Executer.h"
#include "tester.h"
#include "MyFunction.h"
#include <utility>

template <typename T>
class Wrapper{
int _num;
Executer<T> _exec;
public:
	Wrapper(int arg, int n){
		_num = n;
		_exec.changeN(n);
		switch (arg){
			case 0://запуск на парах
			{

			break;
			}
			case 1:{//запуск на интах
				
			break;
			}
		}
		
	}
	void run(T arg){
	
		T x = arg;
//		MyFunction myFunc;              //тут тип должен совпадать с типом, который передается Tester
        	Tester<T> myTester(x, _num);//обобщен.

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
