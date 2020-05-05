
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
        RealVariable temp;
        temp._a = this->_a;
        temp._b = this->_b;
        temp._c = this->_c + a;
        return temp;
    }

    RealVariable RealVariable::operator -(const double a){ //x-a    
        RealVariable temp;
        temp._a = this->_a;
        temp._b = this->_b;
        temp._c = this->_c - a;
        return temp;
    }

    RealVariable RealVariable::operator *(const double a){ // x*2
        RealVariable temp;
        temp._a = this->_a * a;
        temp._b = this->_b * a;
        temp._c = this->_c * a;
        return temp;
    }

    RealVariable RealVariable::operator /(const double a){ // x/a
        if (a == 0){
            throw runtime_error("can't divid by 0");
        }
        RealVariable temp;
        temp._a = this->_a / a;
        temp._b = this->_b / a;
        temp._c = this->_c / a;
        return temp;
    }

    RealVariable RealVariable::operator ^(const double a){ // x^a == 2  //(2*x+1)(2*X+1)=2X*2X
    RealVariable temp;
    if (a == 0){
        temp._b = 0;
        temp._c = 1;    
        return temp;
    }
    if (a == 1){
        return *this;
    }
    if (a != 2 || this->_a > 0){
        throw runtime_error("solve 2 degree only");
    }
    else{
        // temp._a = this->_b * this->_b;    // (2x+1) * (2x+1) =   
        // temp._b = 2*(this->_b)*this->_c;
        // temp._c = this->_c * this->_c;
        return (*this) * (*this);
    }
    }

    RealVariable RealVariable::operator ==(const double a){ // x==a   x ==0
        RealVariable temp;
        temp._a = this->_a;
        temp._b = this->_b;
        temp._c = this->_c - a;
        return temp;
    }
    
    RealVariable operator +(double a, RealVariable x){ // a+x
        return x + a;
    }

    RealVariable operator -(const double a, RealVariable x){ // a-(x^2+x-3)
        RealVariable temp;
        temp._a = x._a * -1;    
        temp._b = x._b * -1;
        temp._c = x._c * -1;
        return temp;
    }

    RealVariable operator *(const double a, RealVariable x){ // a*x
        return x * a;
    }

    RealVariable operator ==(const double a, RealVariable x){
        return x == a;
    }

    //----------------------varible and complex-----------------


    ComplexVariable ComplexVariable::operator +(const std::complex<double> y){ // x+a (a+bi)+(1+3i) == 2
        ComplexVariable temp;
        temp.a = this->a;
        temp.b = this->b;
        temp.c = this->c + y;
        return temp;
    }

    ComplexVariable ComplexVariable::operator -(const std::complex<double> y){ //x-a
        ComplexVariable temp;
        temp.a = this->a;
        temp.b = this->b;
        temp.c = this->c - y;
        return temp;
    }

    ComplexVariable ComplexVariable::operator *(const std::complex<double> y){ // x*a
        ComplexVariable temp;
        temp.a = this->a * y;
        temp.b = this->b * y;
        temp.c = this->c * y;
        return temp;
    }

    ComplexVariable ComplexVariable::operator /(const std::complex<double> y){ // need to delete
        if(y.real() == 0 && y.imag() == 0){
            throw runtime_error("can't divid by 0");
        }
        ComplexVariable temp;
        temp.a = this->a / y;
        temp.b = this->b / y;
        temp.c = this->c / y;
        return temp;
    }

    ComplexVariable ComplexVariable::operator ^(const std::complex<double> y){
        ComplexVariable temp;
        if(y.real() == 0 && y.imag() == 0){
            temp.b = complex(0);
            temp.c = complex(1,0);
        }
        if(y.real() == 1 && y.imag() == 0){
            return *this;
        }
        if(y.real() == 2 && y.imag() == 0 && this->a == complex(0.0)){
            temp.a = this->b * this->b;
            temp.b = 2.0*(this->b)*this->c;
            temp.c = this->c * this->c;
            return temp;
        }
        else{throw runtime_error("solve only 2 degree");}
    }

    ComplexVariable ComplexVariable::operator == (const std::complex<double> a){ // x==a
       return *this - a;
    }


    //----------------------varible and varible-------------------------
    ComplexVariable ComplexVariable::operator +(const ComplexVariable y){ // x+a
        ComplexVariable temp;
        temp.a = this->a + y.a;
        temp.b = this->b + y.b;
        temp.c = this->c + y.c;
        return temp;
    }

    ComplexVariable ComplexVariable::operator -(const ComplexVariable y){ //x-a
        ComplexVariable temp;
        temp.a = this->a - y.a;
        temp.b = this->b - y.b;
        temp.c = this->c - y.c;
        return temp;
    }

    ComplexVariable ComplexVariable::operator *(const ComplexVariable y){ // x*a
        ComplexVariable temp;
        temp.a = this->a * y.a;
        temp.b = this->b * y.b;
        temp.c = this->c * y.c;
        return temp;
    }

    ComplexVariable ComplexVariable::operator /(const ComplexVariable y){ //need to delete
        ComplexVariable t;
        return t;
    }

    ComplexVariable ComplexVariable::operator ^(const ComplexVariable y){ // need to delete
        ComplexVariable a;
        return a;
    }

    ComplexVariable ComplexVariable::operator == (const ComplexVariable a){ // x==a
        return *this - a;
    }

    // //---------------------varible and double--------------------------
    // ComplexVariable ComplexVariable::operator +(const double y){
    //     ComplexVariable temp;
    //     this->c = this->c + y;
    //     return *this;
    // }

    // ComplexVariable ComplexVariable::operator -(const double y){
    //     ComplexVariable temp;
    //     this->c = this->c - y;
    //     return *this;
    // }

    // ComplexVariable ComplexVariable::operator *(const double y){
    //     ComplexVariable temp;
    //     temp->a = temp->a * y;
    //     temp->b = temp->b * y;
    //     temp->c = temp->c * y;
    //     return *temp;
    // }

    // ComplexVariable ComplexVariable::operator /(const double y){
    //     if(y == 0){
    //         throw runtime_error("can't divid by 0");
    //     }
    //     ComplexVariable temp;
    //     temp->a = temp->a / y;
    //     temp->b = temp->b / y;
    //     temp->c = temp->c / y;
    //     return *temp;
    // }

    // ComplexVariable ComplexVariable::operator ^(const double y){
    //     this->re = this->re ^ y;
    //     this->im = this->im ^ y;
    //     return *this;
    // }

    // ComplexVariable ComplexVariable::operator ==(const double y){ // (a+bi)^2 = ?
    //     this->re = this->re == y;
    //     return *this;
    //  }
    
    // ComplexVariable operator +(const double a,ComplexVariable y){
    //     return y + a;
    // }
    
    // ComplexVariable operator -(const double a, ComplexVariable y){ // need to fix
    //     return y - a;
    // }

    // ComplexVariable operator *(const double a, ComplexVariable y){
    //     return y*a;
    // }

    // ComplexVariable operator /(const double a, ComplexVariable y){ // need to delete
    //     ComplexVariable q;
    //     return q;
    // }

    // ComplexVariable operator ==(const double a, ComplexVariable y){
    //     return y == a;
    // }

    ComplexVariable operator +(const std::complex<double> y , ComplexVariable a){
        return a + y;
    }

    ComplexVariable operator -(const std::complex<double> y , ComplexVariable a){
        return (a*(-1) + y);            
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
        if (x._a == 0 && x._b == 0){
            throw runtime_error("there is no solution");
        }
        double ans;
        if(x._a == 0){
            ans =  (x._c*(-1))/x._b;
        }
        else {
            
            ans = ((-1)*(x._b)+sqrt(pow(x._b,2.0)+(-4.0*x._a*x._c))) / (2.0*x._a);
        }
        //  cout << " a is :"<<x._a << endl;
        //  cout << " b is :"<<x._b << endl;
        //  cout << " c is :"<<x._c << endl;
        x._a = 0;
        x._b = 1;
        x._c = 0;
        if (__isnan(ans)){
            throw runtime_error("there is no solution");
        }
        ans = floor(10000*ans)/10000;
        return ans;
    }

    std::complex<double> solve(ComplexVariable y){ //(3a+3bi)+5 = 0
        if (y.a == complex(0.0) && y.b == complex(0.0)){
            throw runtime_error("there is no solution");
        }
        complex<double> ans(0);
        if (y.a == complex(0.0)){
            ans = (y.c*(-1.0))/y.b;
        }
        else{
            ans = ((-1.0)*(y.b)+sqrt(pow(y.b,2.0)+(-4.0*y.a*y.c))) / (2.0*y.a);
        }
        return ans;
    }

}