#ifndef POLYNOME_H_
#define POLYNOME_H_

#include <vector>
#include <cstdio>
#include <iostream>
#include <ostream>
#include "Fraction.h"

class Polynome{
private:
	std::vector<Fraction> _coefficients;//коэффициенты хранятся в порядке возрастания степени
	int exp;		//степень многочлена
public:
	void normalize();//нормализация - первый коэффициент(высшего порядка) - единица
public:
	Polynome(){
		std::vector<Fraction> empty;
		empty.clear();
		exp = -1;
		_coefficients = empty;
	}
	Polynome(const std::vector<Fraction> & coef){
		exp = coef.size()-1;
		if(exp >= 0) //со степенью все в порядке
			if(!(coef[exp].getNumerator() == Integer(0) ) ){//многочлен валиден
				_coefficients.resize(exp+1);
				for(int i=0; i<coef.size(); ++i){
					_coefficients[i] = coef[i];
				}


			}
			else std::cerr << "Invalid degree" << std::endl;
		else std::cerr << "Invalid polynome" << std::endl;

			
	}

	bool operator != (const Polynome& second);
	Polynome operator * (const Fraction& multiplier) const;
	Polynome operator * (const Polynome& second) const;
	Polynome operator + (const Polynome& second) const;
	Polynome operator - (const Polynome& second) const;
	Polynome operator / (const Polynome& second);
	Polynome operator % (const Polynome& second);
	
	friend std::ostream& operator << (std::ostream& out, const Polynome& toOut){
		int n = toOut.getExp();

		/*вывод коэфициентов при ненулевых степенях*/
		for(int i=n; i > 0; --i){
			out << toOut.getNthCoef(i) << "(" << "x^" << i << ")" << " + ";
			//out.flush();
		}
		/*если многочлен не отсутствует, то выводим коэффициент при нулевом члене*/
		if(n!=-1){
			out << toOut.getNthCoef(0);
		}
		else{
			out << "0/1";
		}

		return out;
	}
	
	int getExp() const;					//дает степень многочлена
	Fraction getNthCoef(int degree) const;	//выдает коэффициент члена со степенью n

public:
	void setNthCoef(int n, Fraction frac);	//выcтавляет коэффициент члена со степенью n

	void zero();
	void generate();
};

int Polynome::getExp() const {
	return this->exp;
}
/*
Polynome& Polynome::operator = (const Polynome& second ){

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
/**
 * Умножение на дробь
 * */
Polynome Polynome::operator * (const Fraction& multiplier) const{
	Polynome result = *this;
	for(int i=0; i< result.getExp()+1; ++i){
		result.setNthCoef(i, result.getNthCoef(i)*multiplier);
	}
	return result;
}
/**
 * Умножение на многочлен
 * */
Polynome Polynome::operator * (const Polynome& second) const{//TODO
	Polynome result;						//отсутствующий полином (ноль)

	Polynome buffer;						//преобразуется, затем приба
	Fraction multiplier;

	for(int i=second.getExp(); i>=0; --i){	//по всем элементам множителя
		buffer = *this;						 //берем множимое
			//std::cout << i << std::endl;
		int bufExp = buffer.getExp();
			//std::cout << "second: " << second << std::endl;
		multiplier = second.getNthCoef(i);	 //вычленяем множитель
			//std::cout << "multiplier is: " << multiplier << std::endl;

		//Cмещение
		for(int j=bufExp+i; j>=i; --j){
			buffer.setNthCoef(j, buffer.getNthCoef(j-i));//проблема была в неравенстве в setNthCoef
		}
			//std::cout << std::endl;
		buffer=buffer*multiplier;			//домножение на коэффициент

		Fraction zero(0,1);
		for(int j=i-1; j>=0; --j){
			buffer.setNthCoef(j,zero);		//хвост теперь нулевой
		}
			//std::cout << "Buffer contains: "<< buffer << std::endl;

		result=result+buffer;
			std::cout << "Result now contains: "<< result << std::endl;
	}

	return result;
}

Polynome Polynome::operator + (const Polynome& argument) const{
	Polynome result;
	Polynome first = *this;
	Polynome second = argument;
	if(first.getExp() > second.getExp()){
		result=first;
		for(int i=0; i<second.getExp()+1; ++i){
			result.setNthCoef(i, first.getNthCoef(i)+second.getNthCoef(i));
		}
	}
	else {
		result=second;
		for(int i=0; i<first.getExp()+1; ++i){
			result.setNthCoef(i, first.getNthCoef(i)+second.getNthCoef(i));
		}
	}

	return result;
}


Polynome Polynome::operator - (const Polynome& second) const{

	Polynome result;
	Polynome subtrahend;
	if(this->getExp() >= second.getExp()){
		result = *this;
		subtrahend = second;

	}else{
		result = second;
		subtrahend = *this;
		Fraction minusOne(-1, 0);
		subtrahend = second*minusOne;
		result = result*minusOne;
	}

	for(int i=subtrahend.getExp(); i>=0; --i){
		result.setNthCoef(i, result.getNthCoef(i)-subtrahend.getNthCoef(i));
	}

	return result;
}


Polynome Polynome::operator % (const Polynome& divider){

	if(this->getExp() < divider.getExp() ){
		return *this;
	}
	else{
		std::vector<Fraction> coef(this->getExp());

		Polynome divided = *this;


		int currentDividedDegree = divided.getExp();
		int currentDividerDegree = divider.getExp();
		Fraction curQuotCoef;
		Polynome curQuotCoefPoly;
		int curQuotDegree;

		Polynome quotient;
		Polynome tempPoly;

		while(divided.getExp() >= divider.getExp()){
				std::cout <<  divided.getNthCoef(currentDividedDegree) << std::endl;
				std::cout <<  divider.getNthCoef(currentDividerDegree) << std::endl;
			curQuotDegree = currentDividedDegree-currentDividerDegree;
			curQuotCoef = divided.getNthCoef(currentDividedDegree)/divider.getNthCoef(currentDividerDegree);//	находит результат деления коэф наибольших порядков делимого и делителя
				std::cout << "curQuotCoef = "<<curQuotCoef << std::endl;
				std::cout << "divided degree: " << currentDividedDegree << std::endl;
				std::cout << "divider degree: " << currentDividerDegree << std::endl;

			quotient.setNthCoef(currentDividedDegree-currentDividerDegree, curQuotCoef);// записывает в частное результат деления на нужный порядок
				std::cout << "quotient: " << quotient << std::endl;
			//умножаем делитель на полученный результат и результат записываем в tempPoly
			curQuotCoefPoly.setNthCoef(curQuotDegree, curQuotCoef);//коэффициент с иксом
			std::cout << "divider = "<<divider << std::endl;
			std::cout << "curQuotCoefPoly = " << curQuotCoefPoly << std::endl;

			tempPoly = divider*curQuotCoefPoly;//нужен нормальный оператор умножения
			std::cout << "tempPoly = " << tempPoly << std::endl;
			std::cout << "divided = "<<divided << std::endl;
			//Вычитаем полученный после умножения многочлен из делимого, записываем результат под чертой
			divided = divided-tempPoly;
			std::cout << "divided: " << divided << std::endl;
			tempPoly.zero();//обнуляем
			curQuotCoefPoly.zero();
				std::cout << divided << std::endl;
			divided.normalize();
			std::cout << "divided after norma: " << divided << std::endl;
			currentDividedDegree = divided.getExp();
		}
		return divided;
	}

}

Fraction Polynome::getNthCoef(int degree) const{// выдать коэффициент степени n
	return this->_coefficients[degree];

}
void Polynome::setNthCoef(int insertDegree, Fraction frac){	//выcтавляет коэффициент члена со степенью n, если нет такой степени, тогда происходит перевыделение

	if(insertDegree<_coefficients.size()){
		_coefficients[insertDegree]=frac;
	} else {
		//перевыделение памяти
		//про макс индекс
		int wasInCoefs = _coefficients.size();
		int willBeInCoefs = insertDegree;
		std::vector<Fraction> newCoefs;
		newCoefs.resize(insertDegree+1);

		for(int i=0; i< _coefficients.size(); ++i){
			newCoefs[i] = _coefficients[i];
		}
		newCoefs[newCoefs.size()-1]=frac;

		Fraction zero(0, 1);
		for(int i=wasInCoefs; i<willBeInCoefs; ++i){
			newCoefs[i] = zero;
		}

		exp=newCoefs.size()-1;
		_coefficients=newCoefs;
	}
}

void Polynome::normalize(){
		std::cout << "this in norm: ";
		for(int i=0; i<_coefficients.size(); ++i){
			std::cout << _coefficients[i] << " ";
		}
		std::cout << std::endl;

	int newHighest = _coefficients.size();
	std::cout << newHighest << std::endl;
	// уберем лишние нули
	Fraction highest = this->_coefficients[newHighest-1];
	std::cout << highest << std::endl;

	while(highest.getNumerator()==0 && exp>0){
		--newHighest;
		_coefficients.pop_back();//вынимаем элемент с конца
		highest = (this->_coefficients.back());
		--exp;
	}


	std::cout << "this after norm: ";
		for(int i=0; i<_coefficients.size(); ++i){
			std::cout << _coefficients.size() << " " << this->getExp()+1<< std::endl;
			std::cout << _coefficients[i] << " ";
		}
		std::cout << std::endl;

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
	for(size_t i=0; i< coef.size(); ++i){
		//std::cout << coef[i] << " ";
	}
	//std::cout << std::endl;
	Polynome res(coef);
	*this=res;

}

void Polynome::zero(){
	_coefficients.clear();
}

//std::ostream& Polynome::operator << (std::ostream& out, const Polynome& toOut)// почему компилятор не дает переопределить оператор именно здесь?
#endif POLYNOME_H_
