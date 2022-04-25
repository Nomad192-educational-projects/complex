#include <iostream>

using namespace std;

class Complex
{
private:
    double Im;
    double Re;
public:
    Complex() : Im(0.0), Re(0.0) {}
    Complex(double Re, double Im) : Im(Im), Re(Re) {}
    double  getIm() {return Im;}
    double  getRe() {return Re;}
    void    setIm(double Im) {this->Im = Im;}
    void    setRe(double Re) {this->Re = Im;}
    Complex &operator +=(const Complex &second)
    {
        Im += second.Im;
        Re += second.Re;
        return (*this);
    }
    Complex &operator -=(const Complex &second)
    {
        Im -= second.Im;
        Re -= second.Re;
        return (*this);
    }
    Complex &operator *=(const Complex &second)
    {
        double new_im, new_re;
        new_im = ((Re * second.Im) + (Im * second.Re));
        new_re = ((Re * second.Re) - (Im * second.Im));
        Im = new_im;
        Re = new_re;
        return (*this);
    }
    Complex &operator /=(const Complex &second)
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
    Complex operator +(const Complex &second) const
    {
        Complex result(Re, Im);
        result += second;
        return result;
    }
    Complex operator -(const Complex &second) const
    {
        Complex result(Re, Im);
        result -= second;
        return result;
    }
    Complex operator *(const Complex &second) const
    {
        Complex result(Re, Im);
        result *= second;
        return result;
    }
    Complex operator /(const Complex &second) const
    {
        Complex result(Re, Im);
        result /= second;
        return result;
    }
    void print()
    {
        cout << "Complex(" << Re;
        if(Im >= 0.0)
            cout << "+";
        cout << Im << "i)";
    }
};

int main() {
    Complex the_complex_1(-2, 1);
    Complex the_complex_2(1, -1);
    cout << "1 - ";
    the_complex_1.print();
    cout << endl;
    cout << "2 - ";
    the_complex_2.print();
    cout << endl;    
    {
        Complex the_complex_3 = the_complex_1 + the_complex_2;
        cout << "sum - ";
        the_complex_3.print();
        cout << endl;   
    }
    {
        Complex the_complex_3 = the_complex_1 - the_complex_2;
        cout << "sub - ";
        the_complex_3.print();
        cout << endl;   
    }
    {
        Complex the_complex_3 = the_complex_1 * the_complex_2;
        cout << "mul - ";
        the_complex_3.print();
        cout << endl;   
    }
    {
        Complex the_complex_3 = the_complex_1 / the_complex_2;
        cout << "dvn - ";
        the_complex_3.print();
        cout << endl;   
    }
    return 0;
}


//mkdir build & cd build & cmake -G "MinGW Makefiles" .. 
//cmake --build . & complex.exe