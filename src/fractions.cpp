#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <sstream>
#include <string>
#include "fractions.h"
using namespace std;

void fraction::reduceFraction() const {
	int lowerNum;
	if(mDenominator == 0) {
		cerr << "Error: Divided By 0\n";
		exit(EXIT_FAILURE);
	} else if(mNumerator == 0)
		mDenominator = 1;
	else {
		if(mDenominator < 0) {
			mNumerator *= -1;
			mDenominator *= -1;
		}
		
		int num1 = abs(mNumerator);
		int num2 = abs(mDenominator);

		while(num2 != 0) {
			int temp = num2;
			num2 = num1 % num2;
			num1 = temp;
		}
		mNumerator /= num1;
		mDenominator /= num1;
	}
}

int fraction::returnNum() {
	reduceFraction();
	return mNumerator;
}

int fraction::returnDenom() {
	reduceFraction();
	return mDenominator;
}

void fraction::setValue(int numerator, int denominator) {
	mNumerator = numerator;
	mDenominator = denominator;
}

fraction::fraction() {
	mNumerator = 0;
	mDenominator = 1;
}

fraction::fraction(int numerator) {
	mNumerator = numerator;
	mDenominator = 1;
}

fraction::fraction(int numerator, int denominator) {
	mNumerator = numerator;
	mDenominator = denominator;
}

void fraction::addValue(int addedNum,int addedDenom) {
	reduceFraction();
	int num1 = mNumerator * addedDenom;
	int num2 = addedNum * mDenominator;
	mNumerator = num1 + num2;
	mDenominator = mDenominator * addedDenom;
}

void fraction::multiplyValue(int multNum, int multDenom) {
	mNumerator *= multNum;
	mDenominator *= multDenom;
	reduceFraction();
}

fraction fraction::operator+(const fraction &b) {
	fraction c = *this;
	b.reduceFraction();
	c.addValue(b.mNumerator, b.mDenominator);
	return c;
}

fraction fraction::operator+(int constant) {
	fraction c = *this;
	c.addValue(constant, 1);
	return c;
}

fraction fraction::operator-(const fraction &b) {
	fraction c = *this;
	b.reduceFraction();
	c.addValue(b.mNumerator * -1,b.mDenominator);
	return c;
}

fraction fraction::operator-(int constant) {
	fraction c = *this;
	c.addValue(constant * - 1, 1);
	return c;
}

void fraction::operator+=(const fraction &b) {
	b.reduceFraction();
	addValue(b.mNumerator, b.mDenominator);
}

void fraction::operator+=(int constant) {
	addValue(constant, 1);
}

void fraction::operator-=(const fraction &b) {
	b.reduceFraction();
	addValue(b.mNumerator * -1, b.mDenominator);
}

void fraction::operator-=(int constant) {
	addValue(constant * -1, 1);
}

fraction fraction::operator*(const fraction &b) {
	fraction c = *this;
	b.reduceFraction();
	c.multiplyValue(b.mNumerator, b.mDenominator);
	return c;
}

fraction fraction::operator*(int constant) {
	fraction c = *this;
	c.multiplyValue(constant, 1);
	return c;
}

fraction fraction::operator/(const fraction &b) {
	fraction c = *this;
	b.reduceFraction();
	c.multiplyValue(b.mDenominator, b.mNumerator);
	return c;
}

fraction fraction::operator/(int constant) {
	fraction c = *this;
	c.multiplyValue(1, constant);
	return c;
}

void fraction::operator*=(const fraction &b) {
	b.reduceFraction();
	multiplyValue(b.mNumerator, b.mDenominator);
}

void fraction::operator*=(int constant) {
	multiplyValue(constant, 1);
}

void fraction::operator/=(const fraction &b) {
	b.reduceFraction();
	multiplyValue(b.mDenominator, b.mNumerator);
}

void fraction::operator/=(int constant) {
	multiplyValue(1, constant);
}

bool fraction::operator==(const fraction &b) {
	reduceFraction();
	b.reduceFraction();
	return ((mNumerator == b.mNumerator) && (mDenominator == b.mDenominator));
}

bool fraction::operator==(int constant) {
	reduceFraction();
	return ((mNumerator == constant) && (mDenominator == 1));
}

bool fraction::operator!=(const fraction &b) {
	reduceFraction();
	fraction c = *this;
	return !(c == b);
}

bool fraction::operator!=(int constant) {
	reduceFraction();
	fraction c = *this;
	return !(c == constant);
}

void fraction::operator=(int constant) {
	mNumerator = constant;
	mDenominator = 1;
}

void fraction::operator=(const fraction &b) {
	mNumerator = b.mNumerator;
	mDenominator = b.mDenominator;
	reduceFraction();
}

istream & operator>>(istream &in, fraction &b) {
	string buffer, s1, s2;
	stringstream ss;

	in >> buffer;
	ss.str(buffer);

	getline(ss, s1, '/');
	if(s1 == buffer) {
		b.mNumerator = atoi(s1.c_str());
		b.mDenominator = 1;
	} else {
		b.mNumerator = atoi(s1.c_str());
		ss >> s2;
		b.mDenominator = atoi(s2.c_str());
	}
	return in;
}

ostream & operator<<(ostream &out, const fraction &b) {
	b.reduceFraction();
	if(b.mDenominator == 1)
		out << b.mNumerator;
	else {
		stringstream ss;
		string buffer;
		ss << b.mNumerator << "/" << b.mDenominator;
		buffer = ss.str();
		out << buffer;
	}
	return out;
}

