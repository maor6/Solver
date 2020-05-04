
#include "solver.hpp"
using namespace std;

namespace solver{
    
    RealVariable RealVariable::operator +(const RealVariable a){   // x^2+x == 3 ___ x+x == 2
        RealVariable temp;
        temp._a = this->_a + a._a;
        temp._b = this->_b + a._b;
        temp._c = this->_c + a._c;
        return temp;
    }

    RealVariable RealVariable::operator -(const RealVariable a){
        RealVariable temp;
        temp._a = this->_a - a._a;
        temp._b = this->_b - a._b;
        temp._c = this->_c - a._c;
        return temp;
    }

    RealVariable RealVariable::operator *(const RealVariable a){ // x*x == 3    
        RealVariable temp;
        if(this->_a == 1 || a._a == 1) { // cant x^2*x...
            throw runtime_error("the power is higher then 2");  
        }
        temp._a = this->_b * a._b;
        temp._b = this->_b * a._c + this->_c * a._b;
        temp._c = this->_c * a._c;
        return temp;
    }

    RealVariable RealVariable::operator ==(const RealVariable a){
        RealVariable temp;
        temp._a = this->_a - a._a;
        temp._b = this->_b - a._b;
        temp._c = this->_c - a._c;
        return temp;
    }

    RealVariable RealVariable::operator+(const double a){ // x+1 == 3... nea = 1 ... x == 3
        this->_c += a;
        return *this;
    }

    RealVariable RealVariable::operator -(const double a){ //x-a    
        this->_c -= a;
        return *this;
    }

    RealVariable RealVariable::operator *(const double a){ // x*2
        this->_a *= a;
        this->_b *= a;
        this->_c *= a;
        return *this;
    }

    RealVariable RealVariable::operator /(const double a){ // x/a
        this->_a /= a;
        this->_b /= a;
        this->_c /= a;
        return *this;
    }

    RealVariable RealVariable::operator ^(const double a){ // x^a == 2  //(2*x+1)(2*X+1)=2X*2X
    RealVariable temp; 
    if (a != 2 || this->_a > 0){
        throw runtime_error("solve 2 degree only");
    }
    else{
        temp._a = this->_b * this->_b;
        temp._b = 2*(this->_b)*this->_c;
        temp._c = this->_c * this->_c;
    }
        return temp;
    }

    RealVariable RealVariable::operator ==(const double a){ // x==a   x ==0
        this->_c -= a;
        return *this;
    }
    
    RealVariable operator +(double a, RealVariable x){ // a+x
        return x + a;
    }

    RealVariable operator -(const double a, RealVariable x){ // a-(x^2+x-3)
        x._a *= -1;
        x._b *= -1;
        x._c = a - x._c;
        return x;
    }

    RealVariable operator *(const double a, RealVariable x){ // a*x
        return x * a;
    }

    RealVariable operator ==(const double a, RealVariable x){
        return x == a;
    }

    //----------------------varible and complex-----------------
    ComplexVariable ComplexVariable::operator +(const std::complex<double> y){ // x+a (a+bi)+(1+3i) == 2
        this->re = this->re + y.real();
        this->im = this->re + y.imag();
        return *this;
        
    }

    ComplexVariable ComplexVariable::operator -(const std::complex<double> y){ //x-a
        this->re = this->re - y.real();
        this->im = this->im - y.imag();
        return *this;
    }

    ComplexVariable ComplexVariable::operator *(const std::complex<double> y){ // x*a
        RealVariable mulReal = this->re * y.real() + this->im * y.imag() * (-1); // (a^2+bi)(2+4i) =
        RealVariable mulIm  = this->re * y.real() + this->im * y.real();  
        return *this;
    }

    ComplexVariable ComplexVariable::operator /(const std::complex<double> y){ // need to delete
        return *this;
    }

    ComplexVariable ComplexVariable::operator ^(const std::complex<double> y){ // need to delete
        ComplexVariable a;
        return a;
    }

    ComplexVariable ComplexVariable::operator == (const std::complex<double> a){ // x==a
        this->re = this->re - a.real();
        this->im = this->im - a.imag();

    }


    //----------------------varible and varible-------------------------
    ComplexVariable ComplexVariable::operator +(const ComplexVariable y){ // x+a
        ComplexVariable t;
        t.re = this->re + y.re;
        t.im = this->im + y.im;
        return t;
    }

    ComplexVariable ComplexVariable::operator -(const ComplexVariable y){ //x-a
        ComplexVariable t;
        t.re = this->re - y.re;
        t.im = this->im - y.im;
        return t;
    }

    ComplexVariable ComplexVariable::operator *(const ComplexVariable y){ // x*a
        ComplexVariable t;
        t.re = this->re * y.re;
        t.im = this->im * y.im;
        return t;
    }

    ComplexVariable ComplexVariable::operator /(const ComplexVariable y){ //need to delete
        ComplexVariable t;
        t.re = this->re + y.re;
        t.im = this->im + y.im;
        return t;
    }

    ComplexVariable ComplexVariable::operator ^(const ComplexVariable y){ // need to delete
        ComplexVariable a;
        return a;
    }

    ComplexVariable ComplexVariable::operator == (const ComplexVariable a){ // x==a
        ComplexVariable t;
        t.re = this->re == a.re;
        t.im = this->im == a.im;
        return t;
    }

    //---------------------varible and double--------------------------
    ComplexVariable ComplexVariable::operator +(const double y){
        this->re = this->re + y;
        return *this;
    }

    ComplexVariable ComplexVariable::operator -(const double y){
        this->re = this->re - y;
        return *this;
    }

    ComplexVariable ComplexVariable::operator *(const double y){
        this->re = this->re * y;
        this->im = this->im * y;
        return *this;
    }

    ComplexVariable ComplexVariable::operator /(const double y){
        this->re = this->re / y;
        this->im = this->im / y;
        return *this;
    }

    ComplexVariable ComplexVariable::operator ^(const double y){
        this->re = this->re ^ y;
        this->im = this->im ^ y;
        return *this;
    }

    ComplexVariable ComplexVariable::operator ==(const double y){
        this->re = this->re == y;
        return *this;
    }
    
    ComplexVariable operator +(const double a,ComplexVariable y){
        return y + a;
    }
    
    ComplexVariable operator -(const double a, ComplexVariable y){ // need to fix
        return y - a;
    }

    ComplexVariable operator *(const double a, ComplexVariable y){
        return y*a;
    }

    ComplexVariable operator /(const double a, ComplexVariable y){ // need to delete
        ComplexVariable q;
        return q;
    }

    ComplexVariable operator ==(const double a, ComplexVariable y){
        return y == a;
    }

    ComplexVariable operator +(const std::complex<double> y , ComplexVariable a){
        return a + y;
    }

    ComplexVariable operator -(const std::complex<double> y , ComplexVariable a){
        return a - y;
    }

    ComplexVariable operator *(const std::complex<double> y , ComplexVariable a){
        return a * y;
    }

    ComplexVariable operator /(const std::complex<double> y ,  ComplexVariable a){ // need to delete
        ComplexVariable x;
        return x;
    }

    ComplexVariable operator ^(const std::complex<double> y , ComplexVariable a){ // need to delete
        ComplexVariable q;
        return q;
    }

    ComplexVariable operator ==(const std::complex<double> y , ComplexVariable a){
        return a == y;
    }

    double solve(RealVariable x){
        double ans;
        if(x._a == 0){
            ans =  (x._c*(-1))/x._b;
        }
        else
        {
            ans = ((-1)*(x._b)+sqrt(pow(x._b,2)-(4*x._a*x._c)))/2*x._a;
        }
        // cout << " a is :"<<x._a << endl;
        // cout << " b is :"<<x._b << endl;
        // cout << " c is :"<<x._c << endl;
        x._a = 0;
        x._b = 1;
        x._c = 0;
        if (__isnan(ans)){
            throw runtime_error("there is no answer");
        }
        ans = floor(10000*ans)/10000;
        return ans;
    }
     
    std::complex<double> solve(ComplexVariable y){
        double a = solve(y.re);
        double b = solve(y.im);
        std::complex<double> ans(a,b);

        y.re._a = 0;
        y.re._b = 1;
        y.re._c = 0;

        y.im._a = 0;
        y.im._b = 1;
        y.im._c = 0;

        return ans;
    }

}