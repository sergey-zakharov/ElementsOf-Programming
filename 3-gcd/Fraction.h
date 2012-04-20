/*
 * Fraction.h
 *
 *  Created on: Apr 20, 2012
 *      Author: sergeyzakharov
 */


#ifndef GCD_FINDER_H_
#define GCD_FINDER_H_

#include "GSDFinder.h"

#endif /* GCD_FINDER_H_ */

#ifndef FRACTION_H_
#define FRACTION_H_




class Fraction{
private:
	Integer numerator;
	Integer denominator;
	GSDFinder<Integer> gcdFinder;
public:
	Fraction(){}

	Fraction(const Integer& num, const Integer& denom){
		this->numerator = num;
		this->denominator = denom;
	}

	Fraction(const Fraction& frac){
		this->numerator = frac.getNumerator();
		this->denominator = frac.getDenominator();
	}

	Fraction& operator + (const Fraction& argFrac) const;
	Fraction& operator - (const Fraction& argFrac) const;
	Fraction& operator * (const Fraction& argFrac) const;
	Fraction& operator / (const Fraction& argFrac) const;
	friend std::ostream& operator << (std::ostream& out, const Fraction& toOut){
		out << toOut.numerator << "/" << toOut.denominator;
		return out;
	}
	bool operator == (const Fraction& argFrac);
	void normalize();
	Integer getNumerator() const {return this->numerator;}
	Integer getDenominator() const {return this->denominator;}

};



Fraction& Fraction::operator + (const Fraction& argFrac) const{
	Fraction arg = argFrac;
	Fraction thisArg = *this;
	Fraction res;

	Integer gcd = gcdFinder.find(arg.denominator, thisArg.denominator);
	Integer lcm = (arg.denominator * thisArg.denominator)/gcd;


	arg.numerator = arg.numerator * lcm/arg.denominator;	// 1/3 + 1/2 =|lcm = 6|= 2/6 + 3/6
	arg.denominator = lcm;

	thisArg.numerator = thisArg.numerator * lcm/thisArg.denominator;
	thisArg.denominator = lcm;

	res.numerator = thisArg.numerator + arg.numerator;
	res.denominator = lcm;

	res.normalize();

	return res;
}

void Fraction::normalize(){
	Integer gcd = gcdFinder.find(this->denominator, this->numerator);
	if (gcd > 1)
	{
		this->denominator = this->denominator/gcd;
		this->numerator = this->numerator/gcd;
	}
}

Fraction& Fraction::operator - (const Fraction& argFrac) const{
	Fraction arg = argFrac;
	Fraction thisArg = *this;

	Fraction res;


	Integer gcd = gcdFinder.find(arg.denominator, thisArg.denominator);
	Integer lcm = (arg.denominator * thisArg.denominator)/gcd;

	arg.numerator = arg.numerator * lcm/arg.denominator;	// 1/3 + 1/2 =|lcm = 6|= 2/6 + 3/6
	arg.denominator = lcm;

	thisArg.numerator = thisArg.numerator * lcm/thisArg.denominator;
	thisArg.denominator = lcm;

	res.numerator = thisArg.numerator - arg.numerator;
	res.denominator = lcm;

	res.normalize();

	return res;
}

Fraction& Fraction::operator * (const Fraction& argFrac) const{
	Fraction res;
	Fraction thisArg = *this;
	res.numerator = thisArg.numerator*argFrac.numerator;
	res.denominator = thisArg.denominator*argFrac.denominator;

	res.normalize();
	return res;
}

Fraction& Fraction::operator / (const Fraction& argFrac) const{
	Fraction res;
	Fraction thisArg = *this;
	res.denominator = argFrac.numerator;
	res.numerator = argFrac.denominator;
	res = thisArg*res;

	res.normalize();
	return res;
}

bool Fraction::operator == (const Fraction& argFrac){
	if(argFrac.denominator == this->denominator && argFrac.numerator == this->numerator)
		return true;
	return false;
}

#endif /* FRACTION_H_ */
