#include <ostream>

class Integer{
        int value;
  public:
  		
        Integer(int num=0)
        {
        	value = num;
        }
        
        int operator ()(int val)
        {
        	return val;
        }
        
	friend std::ostream& operator << (std::ostream& out, const Integer& myInt)
	{
		out << myInt.value;
		return out;
	}
	int getValue() const
	{
		return this->value;
	}
	
	Integer operator = (const Integer& second){
		this->value = second.getValue();
		return second;
	}	
		
	Integer operator = (const int& second){
		value = second;
		return second;
	}	

	bool operator > (Integer second){
		return this->value > second.getValue();
	}

	bool operator > (int second){
		return this->value > second;
	}

	bool operator < (Integer second){
		return this->value < second.getValue();
	}

	bool operator < (int second){
		return this->value < second;
	}

	
	Integer operator + (Integer second){
		return Integer(this->value + second.getValue());
	}
	
	Integer operator * (Integer second){
		return Integer(this->value*second.getValue());
	}

	Integer operator - (Integer second){
		return Integer(this->value-second.getValue());
	}

	Integer operator / (Integer second){
		return Integer(this->value/second.getValue());
	}
	
	Integer operator + (int second){
		return Integer(this->value+second);
	}
	
	
	Integer operator * (int second){
		return Integer(this->value*second);
	}

	Integer operator - (int second){
		return Integer(this->value-second);
	}

	Integer operator / (int second){
		return Integer(this->value/second);
	}
	
	
	Integer operator % (Integer second){
		return Integer(this->value % second.getValue());
	}
	
	bool operator != (Integer second){
		return this->value != second.getValue();
	}
	
	bool operator == (Integer second) const {
		return this->value == second.getValue();
	}
	
};
