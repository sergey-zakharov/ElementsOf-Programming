#ifndef IOSTREAM
#define IOSTREAM
	#include <iostream>
#endif


template <class T>
  class powOp{
          public:
          T operator ()(T a, int n){
                  if (n == 0)
                          return a(1); // TODO для каждого класса нужно иметь оболочку
                  if (n%2 == 1)
		  {	//std::cout << a << std::endl; 
                          return (*this)(a, n-1) * a;       //для каждого класса нужно иметь перегруженное умножение
                  }else {
			  //std::cout << a << std::endl; 
                          T b = (*this)(a, n/2);// or this->operator()
			  //std::cout << b << std::endl; 
                          return b*b;
  
                  }
          }
  
  
};


template <class T>
//      requires(T = int, double)
class multOp{
       // T _base;

        public:
        multOp(){

        }
        T operator() (T a, int n)
        {
                return a*n;
        }
/*      T getBase(){
                return _base;
        }
*/
};


