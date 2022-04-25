#ifndef COMPLEX_COMPLEX_HPP
#define COMPLEX_COMPLEX_HPP

#include <iostream>

using namespace std;

class Complex
{
private:
    double Im;
    double Re;
public:
    Complex();
    Complex(double Re, double Im);
    double  get_Im() const;
    double  get_Re() const;
    void    set_Im(double new_Im);
    void    set_Re(double new_Re);
    Complex &operator +=(const Complex &second);
    Complex &operator -=(const Complex &second);
    Complex &operator *=(const Complex &second);
    Complex &operator /=(const Complex &second);
    Complex operator +(const Complex &second) const;
    Complex operator -(const Complex &second) const;
    Complex operator *(const Complex &second) const;
    Complex operator /(const Complex &second) const;
    void print() const;
};

#endif //COMPLEX_COMPLEX_HPP
