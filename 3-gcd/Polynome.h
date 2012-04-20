#ifndef POLYNOME_H_
#define POLYNOME_H_

#include <vector>
#include <cstdio>
#include <ostream>
#include "Fraction.h"

class Polynome{
private:
	std::vector<Fraction> _coefficients;
	int exp;		//степень многочлена
public:
	Polynome(){}
	Polynome(const std::vector<Fraction> & coef){
		exp = coef.size()-1;
		if(exp >= 0) //со степенью все в порядке
			if(!(coef[0].getNumerator() == Integer(0) ) ){//многочлен валиден
				_coefficients.resize(exp+1);
				for(int i=0; i<coef.size(); ++i){
					_coefficients[i] = coef[i];
				}
			//else TODO
			}
		//else	? TODO
			
	}
	//Polynome()
	//TODO конструктор копирования
	//Polynome& operator = (const Polynome& second);
	bool operator != (const Polynome& second);
	
	Polynome operator / (const Polynome& second);
	Polynome operator % (const Polynome& second);
	
	friend std::ostream& operator << (std::ostream& out, const Polynome& toOut){

		int n = toOut.getExp();


		for(int i=n; i > 0; --i){
			out << toOut.getNthCoef(i) << "(" << "x_" << i << ")" << " + ";
			out.flush();
		}

		out << toOut.getNthCoef(0);
		return out;
	}
	
	int getExp() const;	//дает степень многочлена
	Fraction getNthCoef(int n) const;	//выдает коэффициент члена со степенью n
	void normalize();//нормализация - первый коэффициент(высшего порядка) - единица

	void generate();
};

int Polynome::getExp() const {
	return this->exp;
}

/*Polynome& Polynome::operator = (const Polynome& second ){

	std::vector<Fraction> vectForNewPoly(second.getExp()+1);
	
	for(int i=0; i < second.getExp()+1; ++i){
		vectForNewPoly[i] = second.getNthCoef(i);
	}
	
	Polynome newPoly(vectForNewPoly);
	return newPoly;	
}
*/
bool Polynome::operator != (const Polynome& second){
	if (this->getExp() != second.getExp())
		return true;
		
	for(int i=0; i < this->getExp(); ++i){
		if(!(this->_coefficients[i] == second.getNthCoef(i)))
			return true;
	}
	return false;

}

Polynome Polynome::operator / (const Polynome& second){
	Polynome divider = second;

	this->normalize();
	divider.normalize();

	if(this->getExp() > second.getExp() ){
		std::vector<Fraction> coef(this->getExp());
		//TODO: division





		Polynome res(coef);
		return res;
	}

	else{
		if(true){//TODO деление равных по стелени многочленов

		}
		std::vector<Fraction> resVect (1,Fraction(1,1));
		return Polynome(resVect);
	}

}

Polynome Polynome::operator % (const Polynome& second){

	if(this->getExp() > second.getExp() ){
		std::vector<Fraction> coef(this->getExp());
		//TODO: division



		Polynome res(coef);
		return res;
	}
	Polynome res = *this;
	return res;
}

Fraction Polynome::getNthCoef(int n) const{// выдать коэффициент степени n
	return this->_coefficients[getExp()-n];

}

void Polynome::normalize(){
	int newHighest = 0;
	// уберем лишние нули
	Fraction highest = this->_coefficients[0];

	while(highest.getNumerator()==0){
		++newHighest;
		Fraction highest = this->_coefficients[newHighest];
	}
	if (newHighest!=0){
		std::vector<Fraction> tempCoef = _coefficients;
		_coefficients.resize(_coefficients.size()-newHighest);
		for(int i=0; i<_coefficients.size(); ++i){
			_coefficients[i] = tempCoef[newHighest+i];
		}
		highest = _coefficients[0];
	}
	//нормализация к единице

	for(int i=1; i< _coefficients.size(); ++i){
		_coefficients[i]=_coefficients[i]/highest;
	}
}

void Polynome::generate(){
	srand(time(NULL));
	int n = rand()%20+1;
	std::vector<Fraction> coef;
	coef.resize(n);

	Integer num = Integer(rand()%200+1);
	Integer denom = Integer(rand()%200+1);
	//std::cout << n << " " << num << " " << denom << std::endl;

	Fraction ffrac (num, denom);
	coef[0] = ffrac;

	for(size_t i=1; i< coef.size(); ++i)
	{
		num = Integer(rand()%200);
		denom = Integer(rand()%200+1);
		Fraction frac(num, denom);
		coef[i] = frac;

	}
	for(size_t i=0; i< coef.size(); ++i)
		std::cout << coef[i] << " ";
	std::cout << std::endl;
	Polynome res(coef);
	*this=res;
}


//std::ostream& Polynome::operator << (std::ostream& out, const Polynome& toOut)// почему компилятор не дает переопределить оператор именно здесь?
#endif POLYNOME_H_
