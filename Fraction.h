
#ifndef _FRACTION_H_
#define _FRACTION_H_

#include <string>

class Fraction {
	int m_n = 0;
	int m_d = 1;
public:
	Fraction(int numerator = 0, int denominator = 1) : m_n(numerator), m_d(denominator) {};
	Fraction(const Fraction & rhs) : m_n(rhs.m_n), m_d(rhs.m_d) {};    // copy constructor
	~Fraction();
	inline int numerator() const { return m_n; };
	inline int denominator() const { return m_d; };
	Fraction & operator = (const Fraction &);
	Fraction operator + (const Fraction &) const;
	Fraction operator - (const Fraction &) const;
	Fraction operator * (const Fraction &) const;
	Fraction operator / (const Fraction &) const;
	Fraction & operator += (const Fraction &);
	operator std::string() const;
	operator double() const;
	int operator < (const Fraction &) const;
	int operator > (const Fraction &) const;
	int operator <= (const Fraction &) const;
	int operator >= (const Fraction &) const;
	int operator == (const Fraction &) const;
};

#endif // _RATIONAL
