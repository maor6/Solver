#ifndef SOLVER_
#define SOLVER_
#include <iostream>
#include <complex>


namespace solver{

class RealVariable{
    public:
        double an;
        RealVariable(){
            an = 0;
        }

    RealVariable& operator+(const double a); // x+a
    RealVariable& operator -(const double a); //x-a
    RealVariable& operator *(const double a); // x*a
    RealVariable& operator /(const double a); // x/a
    RealVariable& operator ^(const double a); // x^a
    RealVariable& operator == (const double a); // x==a
    
    RealVariable& operator +(const RealVariable a); 
    RealVariable& operator -(const RealVariable a);
    RealVariable& operator *(const RealVariable a); 
    RealVariable& operator /(const RealVariable a);
    RealVariable& operator ^(const RealVariable a); 
    RealVariable& operator ==(const RealVariable a);


    friend RealVariable& operator +(double a, RealVariable x); // a+x
    friend RealVariable& operator -(double a, RealVariable x); // a-x
    friend RealVariable& operator *(double a, RealVariable x); // a*x
    friend RealVariable& operator /(double a, RealVariable x); // a/x
};




class ComplexVariable{

    double re;
    double im;
    //std::complex<double> mycom;
    public:

        ComplexVariable(double r=0, double i=0){
            //this->mycom.operator+;
            this->re = r;
            this->im = i;
        }
    // ----------------------varibale and complex-------------------------
    ComplexVariable& operator +(const std::complex<double> y); // y+a
    ComplexVariable& operator -(const std::complex<double> y); //y-a
    ComplexVariable& operator *(const std::complex<double> y); // y*a
    ComplexVariable& operator /(const std::complex<double> y){
        ComplexVariable a;
        return a;
    } 

    ComplexVariable& operator ^(const std::complex<double> y){
        ComplexVariable a;
        return a;
    } 

    ComplexVariable& operator ==(const std::complex<double> y){
        ComplexVariable a;
        return a;
    } 
    //-----------------------------------------------------------------------

    //------------------------varibale and varible--------------------
    ComplexVariable& operator +(const ComplexVariable y); // y+a
    ComplexVariable& operator -(const ComplexVariable y); //y-a
    ComplexVariable& operator *(const ComplexVariable y); // y*a
    ComplexVariable& operator /(const ComplexVariable y){
        ComplexVariable a;
        return a;
    }

    ComplexVariable& operator ^(const ComplexVariable y){
        ComplexVariable a;
        return a;
    }

    ComplexVariable& operator ==(const ComplexVariable y){
        ComplexVariable a;
        return a;
    }
    //------------------------------------------------------------------------

    //------------------------------varible and double-----------------
    ComplexVariable& operator +(const double y){
        ComplexVariable a;
        return a;
    }

    ComplexVariable& operator -(const double y){
        ComplexVariable a;
        return a;
    }

    ComplexVariable& operator *(const double y){
        ComplexVariable a;
        return a;
    }

    ComplexVariable& operator /(const double y){
        ComplexVariable a;
        return a;
    }

    ComplexVariable& operator ^(const double y){
        ComplexVariable a;
        return a;
    }

    ComplexVariable& operator ==(const double y){
        ComplexVariable a;
        return a;
    }
    //----------------------------------------------------------------------

    //--------------------------------double and varible--------------------------------
    friend ComplexVariable& operator +(double a, const ComplexVariable y); // a+y
    friend ComplexVariable& operator -(double a, const ComplexVariable y); // a-y
    friend ComplexVariable& operator *(double a, const ComplexVariable y); // a*y
    friend ComplexVariable& operator /(double a, const ComplexVariable y); // a/y
    //-----------------------------------------------------------------------

};


    double solve(RealVariable);
    std::complex<double> solve(ComplexVariable);

}
#endif