#ifndef Comp_H
#define Comp_H
#include "headers.h"

typedef double pt;

class Comp {
public:
	Comp() {}
	Comp(pt re, pt im): re(re), im(im) {}
	pt re, im;
};

ostream& operator<<(ostream& out, const Comp& v) {
	out << v.re << "+" << v.im << "i";
	return out;
}
istream& operator>>(istream& in, Comp& v) {
	in >> v.re >> v.im;
	return in;
}

pt abs2(const Comp& v) {
	return v.re * v.re + v.im * v.im;
}

Comp operator+(const Comp& a, const Comp& b) {
	return Comp(a.re + b.re, a.im + b.im);
}
Comp operator-(const Comp& a, const Comp& b) {
	return Comp(a.re - b.re, a.im - b.im);
}

Comp operator*(const Comp& a, const Comp& b) {
	return Comp(a.re * b.re - a.im * b.im, a.re * b.im + a.im * b.re);
}
Comp operator/(const Comp& a, const Comp& b) {
	return Comp((a.re * b.re + a.im * b.im) / abs2(b), (a.im * b.re - a.re * b.im) / abs2(b));
}

#endif