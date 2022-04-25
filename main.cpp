#include <iostream>
#include "complex.hpp"

using namespace std;

int main() {
    Complex the_complex_1(-2, 1);
    Complex the_complex_2(1, -1);
    the_complex_1.set_Im(9.0);
    the_complex_2.set_Re(-3.0);
    cout << "1 - ";
    the_complex_1.print();
    cout << endl;
    cout << "2 - ";
    the_complex_2.print();
    cout << the_complex_1.get_Re() << " " << the_complex_1.get_Im();
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