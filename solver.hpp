#ifndef SOLVER_
#define SOLVER_
#include <iostream>
#include <complex>


namespace solver{

class RealVariable{
    public:
        double _a;
        double _b;
        double _c;

        RealVariable(){  // constructor
            _a = 0;
            _b = 1;
            _c = 0;
        }
    //---------------------- realvariable and double----------------
    RealVariable operator+(const double a); // x+a
    RealVariable operator -(const double a); //x-a
    RealVariable operator *(const double a); // x*a
    RealVariable operator /(const double a); // x/a
    RealVariable operator ^(const double a); // x^a
    RealVariable operator == (const double a); // x==a
    
    //--------------------------realvriable and realvriable------------
    RealVariable operator +(const RealVariable a); 
    RealVariable operator -(const RealVariable a);
    RealVariable operator *(const RealVariable a); 
    RealVariable operator /(const RealVariable a);
    RealVariable operator ==(const RealVariable a);

    //---------------------double and realvariable-----------------
    friend RealVariable operator +(const double a, RealVariable x); // a+x
    friend RealVariable operator -(const double a, RealVariable x); // a-x
    friend RealVariable operator *(const double a, RealVariable x); // a*x
    friend RealVariable operator ==(const double a, RealVariable x); // a==x
};




class ComplexVariable{

    //std::complex<double> mycom;
    public:
        std::complex<double> a;
        std::complex<double> b;
        std::complex<double> c;

        ComplexVariable(): a(0), b(1,0), c(0) {}


        
    // ----------------------varibale and complex-------------------------
    ComplexVariable operator +(const std::complex<double> y); // y+a
    ComplexVariable operator -(const std::complex<double> y); //y-a
    ComplexVariable operator *(const std::complex<double> y); // y*a
    ComplexVariable operator /(const std::complex<double> y);
    ComplexVariable operator ^(const std::complex<double> y);
    ComplexVariable operator ==(const std::complex<double> y); 
    //-----------------------------------------------------------------------

    //------------------------varibale and varible--------------------
    ComplexVariable operator +(const ComplexVariable y); // y+a
    ComplexVariable operator -(const ComplexVariable y); //y-a
    ComplexVariable operator *(const ComplexVariable y); // y*a
    ComplexVariable operator /(const ComplexVariable y);
    ComplexVariable operator ^(const ComplexVariable y);
    ComplexVariable operator ==(const ComplexVariable y);
    //------------------------------------------------------------------------

    //------------------------------varible and double-----------------
    // ComplexVariable operator +(const double y);
    // ComplexVariable operator -(const double y);
    // ComplexVariable operator *(const double y);
    // ComplexVariable operator /(const double y);
    // ComplexVariable operator ^(const double y);
    // ComplexVariable operator ==(const double y);
    //----------------------------------------------------------------------

    //--------------------------------double and varible--------------------------------
    // friend ComplexVariable operator +(double a, const ComplexVariable y); // a+y
    // friend ComplexVariable operator -(double a, const ComplexVariable y); // a-y
    // friend ComplexVariable operator *(double a, const ComplexVariable y); // a*y
    // friend ComplexVariable operator /(double a, const ComplexVariable y); // a/y
    // friend ComplexVariable operator ==(double a, const ComplexVariable y); // a==y
    //-----------------------------------------------------------------------

    // ----------------------complexand varibale-------------------------
    friend ComplexVariable operator +(const std::complex<double> y ,const ComplexVariable a);
    friend ComplexVariable operator -(const std::complex<double> y ,const ComplexVariable a); 
    friend ComplexVariable operator *(const std::complex<double> y ,const ComplexVariable a);
    friend ComplexVariable operator /(const std::complex<double> y ,const ComplexVariable a);
    friend ComplexVariable operator ^(const std::complex<double> y ,const ComplexVariable a);
    friend ComplexVariable operator ==(const std::complex<double> y ,const ComplexVariable a); 

};

    double solve(RealVariable);
    double solveIm(RealVariable x);
    std::complex<double> solve(ComplexVariable);

}
#endif