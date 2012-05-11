#ifndef IOSTREAM
#define IOSTREAM
	#include <iostream>
#endif


template <class T/*, class TMultOp*/>
class PowOp{
	  public:
	  T operator ()(T a, int n/*, TMultOp oper*/){
			  if (n == 0)
					  return a(1); //для каждого класса нужно иметь оболочку
			  if (n%2 == 1)
	  {
					  return /*oper(*/(*this)(a, n-1)* a/*)*/;       //для каждого класса нужно иметь перегруженное умножение
			  } else {
		  		  T b = (*this)(a, n/2);
		  		  return b*b;
			  }
	  }
  
  
};


template <class T>
//      requires(T = int, double)
class MultOp{

        public:

        T operator() (T a, int n) const
        {
                return a*n;
        }

};


