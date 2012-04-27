#include <ostream>

class Integer{
        int value;
  public:

        Integer(int num)
        {
        	value = num;
        }
        
        Integer(const Integer& arg){
                	value = 0;
        }

        Integer operator ()(){
        	Integer res(0);
        	return res;
        }

        Integer operator ()(int val)
        {
        	return val;
        }
        
	friend std::ostream& operator << (std::ostream& out, const Integer& myInt)
	{
		out << myInt.value;
		return out;
	}
	int getValue()
	{
		return value;
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
	
};
