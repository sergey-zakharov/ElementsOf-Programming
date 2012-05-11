#include <iostream>
#include <fstream> 
#include <vector>
#include <cstdio>
#include "operations.h"
#include "matrix.h"
#include "Integer.h"
#include "Tester.h"
/*#include "MatrixMultOp.h"*/


template<class T, template <class> class BinOp>
T pow (T a, int n, BinOp<T> f){
	return f(a,n);
}
/*template<class T, template <class, class TE> class BinOp>
T pow (T a, int n, BinOp<T, TE> f){
	return f(a,n);
}*///хотелось бы за TE сделать MatrixMultOp


int main(int argc, char** argv){

	if(argc != 2){
		std::cerr << "1 argument expected: times to loop tester" << std::endl;
		return 1;
	}
	
	std::fstream infile ("input", std::fstream::in);
	
	srand(time(NULL));
	int n, m;

	infile >> n >> m;
	std::vector<std::vector<int> > first_matr(n, std::vector<int>(m)); 
	
	for(int row = 0; row < n; ++row){
		for(int col=0; col<m; ++col){
			infile >> first_matr[row][col];

		}
	}
	
	Matrix<> matrix(first_matr);

	int timesToLoop = atoi(argv[1]);
	for(int i=0; i<timesToLoop; ++i){

		int multOn = rand()%100;
		int powOn = rand()%10;
	
		Matrix<> multRes = pow(matrix, multOn, MultOp<Matrix<> >());
		Matrix<> powRes = pow(matrix, powOn, PowOp< Matrix<>/*, MatrixMultOp<> */ >());

		Tester<Matrix<> > tester;
		std::cout << multRes;

		std::cout << "Is it right? ";
		if (tester.run("mult", matrix, multOn, multRes) == 1){
			std::cout << "yes" << std::endl;
		}
		else std::cout << "no" << std::endl;

		std::cout << std::endl;

		std::cout << powRes;
		std::cout << "Is it right? ";
		if (tester.run("pow", matrix, powOn, powRes) == 1){
			std::cout << "yes" << std::endl;
		}
		else std::cout << "no" << std::endl;
	}
}


