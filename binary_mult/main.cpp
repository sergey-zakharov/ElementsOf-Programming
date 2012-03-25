#include <iostream>
#include <fstream> 
#include <vector>
#include "operations.h"
#include "matrix.h"
#include "Integer.h"
#include "Tester.h"


template<typename T, template <class> class BinOp>
T pow (T a, int n, BinOp<T> f){
	return f(a,n);
}



int main(){

	int number;
	
	std::fstream infile ("input", std::fstream::in);
	//std::fstream outfile ("output", std::fstream::out);
	

	int n, m;

	infile >> n >> m;
	std::vector<std::vector<int> > first_matr(n, std::vector<int>(m)); 
	
	for(int row = 0; row < n; ++row){
		for(int col=0; col<m; ++col){
			infile >> first_matr[row][col];

		}
	}
	
	Matrix<> matrix(first_matr);

	Matrix<> multRes = pow(matrix, 5, multOp<Matrix<> >());
	Matrix<> powRes = pow(matrix, 5, powOp<Matrix<> >());
	
	Tester<Matrix<> > tester;
	std::cout << multRes;
	
	std::cout << "Is it right? ";
	if (tester.run("mult", matrix, 5, multRes) == 1){
		std::cout << "yes" << std::endl;
	}
	else std::cout << "no" << std::endl;
	
	std::cout << std::endl;
	
	std::cout << powRes;
	std::cout << "Is it right? ";
	if (tester.run("pow", matrix, 5, powRes) == 1){
		std::cout << "yes" << std::endl;
	}
	else std::cout << "no" << std::endl;
	
}


