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

        Integer operator ()() const {
        	Integer res(0);
        	return res;
        }

        Integer operator ()(int val) const
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
		return value;
	}
	
	
	Integer operator + (Integer second) const {
		return Integer(this->value + second.getValue());
	}
	
	Integer operator * (Integer second) const {
		return Integer(this->value*second.getValue());
	}

	Integer operator - (Integer second) const {
		return Integer(this->value-second.getValue());
	}

	Integer operator / (Integer second) const {
		return Integer(this->value/second.getValue());
	}
	
	Integer operator + (int second) const {
		return Integer(this->value+second);
	}
	
	
	Integer operator * (int second) const {
		return Integer(this->value*second);
	}

	Integer operator - (int second) const {
		return Integer(this->value-second);
	}

	Integer operator / (int second) const {
		return Integer(this->value/second);
	}
	
};
