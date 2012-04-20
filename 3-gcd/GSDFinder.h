#ifndef GCD_FINDER_H_
#define GCD_FINDER_H_

template <typename T>
class GSDFinder{
	
public:
	
	T find(T first, T second) const;

};

template <typename T>
T GSDFinder<T>::find(T first, T second) const{
	T temp;
	while (second != second(0))		// !=
	{
		temp = first % second; 		// %
		first = second;				// =
		second = temp;
	}
	return first;
}

#endif /* GCD_FINDER_H_ */


