template <typename T>
class GSDFinder{
	
public:
	
	T find(T first, T second);

};

template <typename T>
T GSDFinder<T>::find(T first, T second){
	T temp;
	while (second != second(0))		// !=
	{
		temp = first % second; 		// %
		first = second;				// =
		second = temp;
	}
	return first;
}


