#include <iostream>
#include <fstream> 
#include <vector>
#include "operations.h"
#include "matrix.h"
#include "Integer.h"

template<typename T, template <class> class BinOp>
T pow (T a, int n, BinOp<T> f){
	return f(a,n);
}



int main(){

	int number;
	
	std::fstream infile ("input", std::fstream::in);
//	std::cin >> number; 
	std::fstream outfile ("output", std::fstream::out);
	

	int n, m;

	infile >> n >> m;
//	std::cout << 1 << std::endl;
	std::vector<std::vector<int> > first_matr(n, std::vector<int>(m)); 
	
	for(int row = 0; row < n; ++row){
		for(int col=0; col<m; ++col){
			infile >> first_matr[row][col];

		}
	}/*
	std::vector<std::vector<int> > second_matr(n, std::vector<int>(m)); 
	
	for(int row = 0; row < n; ++row){
		for(int col=0; col<m; ++col){
			infile >> matr[row][col];

		}
	}
*/

//	std::cout << 2 << std::endl;
	Matrix matrix(first_matr);

	std::cout << pow(matrix, 10, powOp<Matrix>()) << std::endl;	
	//std::cout << pow(Integer(2), 10, powOp<Integer>()) << std::endl;
	//std::cout << matrix*matrix << std::endl;


}


