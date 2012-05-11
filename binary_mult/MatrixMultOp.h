#ifndef VECTOR
#define VECTOR
#include <vector>
#endif VECTOR

#ifndef MATRIX
#define MATRIX
#include "matrix.h"
#endif MATRIX



#ifndef MATRIXMULTOP_H_
#define MATRIXMULTOP_H_

template <typename T>
class MatrixMultOp{
	public:
	Matrix<T> operator()(Matrix<T> first, Matrix<T> second) const{
		std::vector<std::vector<T> > resMatr(first._matrixContent.size(), std::vector<T>(second._matrixContent.size() ) );	// column of rows


			if (first._matrixContent[0].size() == second._matrixContent.size()){
		           for(size_t i = 0; i<first._matrixContent.size(); ++i){              // height of A

		               for(size_t j=0; j<second._matrixContent[i].size(); ++j)      // width of B
		               {
		                  for(size_t k = 0; k < first._matrixContent[i].size(); ++k)                   // width of A (height of B)
		       	          {
		                        resMatr[i][j]+=first._matrixContent[i][k]*second._matrixContent[k][j];
		                  }
		               }
		          }
		        } else 	{
					std::cerr << "not acceptable size of matrix";
					exit(1);
				}
			return resMatr;
	}

};


#endif /* MATRIXMULTOP_H_ */
