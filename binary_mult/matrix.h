
#include <cstdlib>
#ifndef VECTOR
#define VECTOR
	#include <iostream>
	#include <vector>
#endif
/**
	Here defined a matrix with a parameter type, which should have *, * with 'int', +, ==, << operators 
*/



template <typename T=int>
class Matrix{//квадратная матрица
	int _matrSize;
public:
	std::vector <std::vector<T> > _matrixContent;
	Matrix(std::vector<std::vector<T> >& content){
		if (content[0].size() != content.size())
		{
			std::cerr << "not square matrix!" << std::endl;
			exit(1);
		}
		
		_matrSize = content.size(); 
		_matrixContent.resize(_matrSize);
		for(int i=0; i < _matrSize; ++i){
			_matrixContent[i].resize(_matrSize);
		}
		_matrixContent = content; // копируем содержимое	

	}
	int getSize();
	Matrix operator()(int param);
	Matrix operator * (Matrix b);
	Matrix operator * (int n);
	Matrix operator + (Matrix summand);
	bool operator == (Matrix secondMatr);	
	
	friend std::ostream& operator << (std::ostream& out, const Matrix<T>& matr /*из--за того, что не держится временный объект*/){
		for(int col=0; col < matr._matrixContent.size(); ++col)
		{
			for(int row=0; row < matr._matrixContent[0].size(); ++row){
				
				out << matr._matrixContent[col][row] << " ";
			}
			out << std::endl;
		}
		return out;
	}
};

template <typename T>
Matrix<T> Matrix<T>::operator()(int param){
	std::vector< std::vector<int> > trivialMatr (_matrSize, std::vector<int>(_matrSize));
	for (int i=0; i < _matrSize; ++i){
		for(int j=0; j< _matrSize; ++j)
		{
			trivialMatr[i][j] = 0;
				
		}
		if (param == 1) trivialMatr[i][i] = 1;
	}
	return trivialMatr;
}

template <typename T>
Matrix<T> Matrix<T>::operator*(Matrix<T> b){
	std::vector<std::vector<T> > resMatr(this->_matrixContent.size(), std::vector<T>(b._matrixContent.size() ) );	// column of rows

	//std::cout << 3 << std::endl;
	if (this->_matrixContent[0].size() == b._matrixContent.size()){
           for(int i = 0; i<this->_matrixContent.size(); ++i){              // height of A

               for(int j=0; j<b._matrixContent[i].size(); ++j)      // width of B
               {
                  for(int k = 0; k < this->_matrixContent[i].size(); ++k)                   // width of A (height of B)
       	          {
                        resMatr[i][j]+=this->_matrixContent[i][k]*b._matrixContent[k][j];
                  }
               }
          }
        } else 	{
			std::cerr << "not acceptable size of matrix";
			exit(1);
		}
	return resMatr;


}

template <typename T>
Matrix<T> Matrix<T>::operator*(int n){
	std::vector<std::vector<T> > resMatr(this->_matrixContent.size(), std::vector<T>(this->_matrixContent.size() ) );	// column of rows

	//if (this._matrixContent[0].length == .length){
                  for(int i = 0; i<this->_matrixContent.size(); ++i){              // height of A
                       for(int j=0; j<this->_matrixContent[i].size(); ++j)      // width of B
                      {
			resMatr[i][j] = n * this->_matrixContent[i][j];
                      }
                 }
	return resMatr;
}

template <typename T>	
Matrix<T> Matrix<T>::operator+(Matrix<T> summand){
	if (this->getSize() != summand.getSize()){
		std::cerr << "not acceptable size of matrix";
		exit(1);
	}
	std::vector<std::vector<int> > resMatr(this->getSize(), std::vector<int>(this->getSize()) );
	
	for(int i = 0; i<this->getSize(); ++i){              // height of A
              	for(int j=0; j<this->getSize(); ++j)      // width of B
              	{
			resMatr[i][j] = this->_matrixContent[i][j] + summand._matrixContent[i][j];
              	}
         }
	return resMatr;
}

	
template <typename T>	
bool Matrix<T>::operator==(Matrix<T> secondMatr){
	bool areEqual = true;
	if(this->getSize() != secondMatr.getSize())
		return false;
	for(int col=0; col < secondMatr._matrixContent.size(); ++col)
	{
		for(int row=0; row < secondMatr._matrixContent[0].size(); ++row){
			if(this->_matrixContent[col][row]!= secondMatr._matrixContent[col][row])
				return false;	
			
		}
	
	}
	return true;
}

template <typename T>
int Matrix<T>::getSize(){
	return _matrSize;
}




