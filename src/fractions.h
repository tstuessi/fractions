#include <iostream>
using namespace std;

class fraction {
	mutable int mNumerator; //look into making this a template. would be more useful for scientific stuff.`
	mutable int mDenominator;	
	void reduceFraction() const;
	void multiplyValue(int multNum, int multDenom);
	void addValue(int addedNum, int addedDenom);

public:
	//friends
	friend istream & operator>>(istream &in, fraction &b);
	friend ostream & operator<<(ostream &out, const fraction &b);

	//accessors
	int returnNum();
	int returnDenom();
	void setValue(int numerator, int denominator);
	
	//constructor
	fraction();
	fraction(int numerator);
	fraction(int numerator, int denominator);

	//add function -- overwrite +=, -=
	fraction operator+(const fraction &b);
	fraction operator+(int constant);
	fraction operator-(const fraction &b);
	fraction operator-(int constant);
	void operator+=(const fraction &b);
	void operator+=(int constant);
	void operator-=(const fraction &b);
	void operator-=(int constant);

	//multiply function
	fraction operator*(const fraction &b);
	fraction operator*(int constant);
	fraction operator/(const fraction &b);
	fraction operator/(int constant);
	void operator*=(const fraction &b);
	void operator*=(int constant);
	void operator/=(const fraction &b);
	void operator/=(int constant);

	//equality functions
	bool operator==(const fraction &b);
	bool operator==(int constant);
	bool operator!=(const fraction &b);
	bool operator!=(int constant);

	//equals sign setters
	void operator=(int constant);
	void operator=(const fraction &b);

	//conversion operator
	operator double() const {return (double)mNumerator / (double)mDenominator; }
};

istream & operator>>(istream &in, fraction &b);
ostream & operator<<(ostream &out, const fraction &b);
