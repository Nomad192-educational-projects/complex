#include "complex.hpp"

Complex::Complex() : Im(0.0), Re(0.0) {}
Complex::Complex(double Re, double Im) : Im(Im), Re(Re) {}
double  Complex::get_Im() const {return Im;}
double  Complex::get_Re() const {return Re;}
void    Complex::set_Im(const double new_Im) {this->Im = new_Im;}
void    Complex::set_Re(const double new_Re) {this->Re = new_Re;}
Complex & Complex::operator +=(const Complex &second)
{
    Im += second.Im;
    Re += second.Re;
    return (*this);
}
Complex & Complex::operator -=(const Complex &second)
{
    Im -= second.Im;
    Re -= second.Re;
    return (*this);
}
Complex & Complex::operator *=(const Complex &second)
{
    double new_im, new_re;
    new_im = ((Re * second.Im) + (Im * second.Re));
    new_re = ((Re * second.Re) - (Im * second.Im));
    Im = new_im;
    Re = new_re;
    return (*this);
}
Complex & Complex::operator /=(const Complex &second)
{
    double new_im, new_re;
    new_im  = ((second.Re * Im) - (Re * second.Im))
              / ((second.Re*second.Re) + (second.Im*second.Im));

    new_re  = ((Re * second.Re) + (Im * second.Im))
              / ((second.Re*second.Re) + (second.Im*second.Im));
    Im = new_im;
    Re = new_re;
    return (*this);
}
Complex Complex::operator +(const Complex &second) const
{
    Complex result(Re, Im);
    result += second;
    return result;
}
Complex Complex::operator -(const Complex &second) const
{
    Complex result(Re, Im);
    result -= second;
    return result;
}
Complex Complex::operator *(const Complex &second) const
{
    Complex result(Re, Im);
    result *= second;
    return result;
}
Complex Complex::operator /(const Complex &second) const
{
    Complex result(Re, Im);
    result /= second;
    return result;
}
void Complex::print() const
{
    cout << "Complex(" << Re;
    if(Im >= 0.0)
        cout << "+";
    cout << Im << "i)";
}