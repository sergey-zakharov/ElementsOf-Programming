
#include <cstdlib>
#ifndef VECTOR
#define VECTOR
	#include <iostream>
	#include <vector>
#endif
//template <class T>
class Matrix{//квадратная матрица
	int _matrSize;
	//int _width;
	//int _height;
public:
	std::vector <std::vector<int> > _matrixContent;
	Matrix(std::vector<std::vector<int> >& content){
		//_width = content[0].length;
		//_heigth = content.length;
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
	Matrix operator()(int param){
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


	Matrix operator * (Matrix b){
		std::vector<std::vector<int> > resMatr(this->_matrixContent.size(), std::vector<int>(b._matrixContent.size() ) );	// column of rows

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
	Matrix operator * (int n){
	std::vector<std::vector<int> > resMatr(this->_matrixContent.size(), std::vector<int>(this->_matrixContent.size() ) );	// column of rows

	//if (this._matrixContent[0].length == .length){
                  for(int i = 0; i<this->_matrixContent.size(); ++i){              // height of A
                       for(int j=0; j<this->_matrixContent[i].size(); ++j)      // width of B
                      {
			resMatr[i][j] = n * this->_matrixContent[i][j];
                      }
                 }
	return resMatr;

	}
	friend std::ostream& operator << (std::ostream& out, const Matrix& matr /*из--за того, что не держится временный объект*/){
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

