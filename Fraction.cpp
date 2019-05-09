
#include "Fraction.h"

Fraction::~Fraction() {
	m_n = 0; m_d = 1;
}

Fraction & Fraction::operator = (const Fraction & rhs) {
	if (this != &rhs) {
		m_n = rhs.numerator();
		m_d = rhs.denominator();
	}
	return *this;
}

Fraction Fraction::operator + (const Fraction & rhs) const {
	return Fraction((m_n * rhs.m_d) + (m_d * rhs.m_n), m_d * rhs.m_d);
}

Fraction Fraction::operator - (const Fraction & rhs) const {
	return Fraction((m_n * rhs.m_d) - (m_d * rhs.m_n), m_d * rhs.m_d);
}

Fraction Fraction::operator * (const Fraction & rhs) const {
	return Fraction(m_n * rhs.m_n, m_d * rhs.m_d);
}

Fraction Fraction::operator / (const Fraction & rhs) const {
	return Fraction(m_n * rhs.m_d, m_d * rhs.m_n);
}

Fraction & Fraction::operator += (const Fraction & rhs) {
	*this = Fraction((m_n * rhs.m_d) + (m_d * rhs.m_n), m_d * rhs.m_d);
	return *this;
}

Fraction::operator std::string() const {
	if (m_d == 1) return std::to_string(m_n);
	else return std::to_string(m_n) + "/" + std::to_string(m_d);
}

Fraction::operator double() const {
	return double(m_n) / double(m_d);
}

int Fraction::operator < (const Fraction & rhs) const {
	return double(*this) < double(rhs);
}

int Fraction::operator > (const Fraction & rhs) const {
	return double(*this) > double(rhs);
}

int Fraction::operator <= (const Fraction & rhs) const {
	return double(*this) <= double(rhs);
}

int Fraction::operator >= (const Fraction & rhs) const {
	return double(*this) >= double(rhs);
}

int Fraction::operator == (const Fraction & rhs) const {
	return double(*this) == double(rhs);
}
