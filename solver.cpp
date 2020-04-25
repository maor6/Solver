
#include "solver.hpp"
using namespace std;

namespace solver{
    
    RealVariable& operator +(const RealVariable a){
        RealVariable x;
        return x;
    }

    RealVariable& operator -(const RealVariable a){
        RealVariable x;
        return x;
    }

    RealVariable& operator *(const RealVariable a){
        RealVariable x;
        return x;
    }

    // RealVariable& operator /(const RealVariable a){
    //     RealVariable x;
    //     return x;
    // }

    // RealVariable& operator ^(const RealVariable a){
    //     RealVariable x;
    //     return x;
    // }

    // RealVariable& operator ==(const RealVariable a){
    //     RealVariable x;
    //     return x;
    // }

    // RealVariable& operator+(const double a){ // x+a
    //     RealVariable x;
    //     return x;
    // }

    // RealVariable& operator -(const double a){ //x-a
    //     RealVariable x;
    //     return x;
    // }

    // RealVariable& operator *(const double a){ // x*a
    //     RealVariable x;
    //     return x;
    // }

    // RealVariable& operator /(const double a){ // x/a
    //     RealVariable x;
    //     return x;
    // }

    // RealVariable& operator ^(const double a){ // x^a
    //     RealVariable x;
    //     return x;
    // }

    // RealVariable& operator == (const double a){ // x==a
    //     RealVariable x;
    //     return x;
    // }
    
    friend RealVariable& operator +(double a, RealVariable x){ // a+x
        RealVariable q;
        return q;
    }

    friend RealVariable& operator -(double a, RealVariable x){ // a-x
        RealVariable q;
        return q;
    }

    friend RealVariable& operator *(double a, RealVariable x){ // a*x
        RealVariable q;
        return q;
    }

    friend RealVariable& operator /(double a, RealVariable x){ // a/x
        RealVariable q;
        return q;
    }

    //----------------------varible and complex-----------------
    ComplexVariable& operator +(const std::complex<double> y){ // x+a
        ComplexVariable a;
        return a;
    }

    ComplexVariable& operator -(const std::complex<double> y){ //x-a
        ComplexVariable a;
        return a;
    }

    ComplexVariable& operator *(const std::complex<double> y){ // x*a
        ComplexVariable a;
        return a;
    }

    // ComplexVariable& operator /(const std::complex<double> y){ // x/a
    //     ComplexVariable a;
    //     return a;
    // }

    // ComplexVariable& operator ^(const std::complex<double> y){ // x^a
    //     ComplexVariable a;
    //     return a;
    // }

    // ComplexVariable& operator == (const std::complex<double> a){ // x==a
    //     ComplexVariable a;
    //     return a;
    // }


    //----------------------varible and varible--------------------------
    ComplexVariable& operator +(const ComplexVariable y){ // x+a
        ComplexVariable a;
        return a;
    }

    ComplexVariable& operator -(const ComplexVariable y){ //x-a
        ComplexVariable a;
        return a;
    }

    ComplexVariable& operator *(const ComplexVariable y){ // x*a
        ComplexVariable a;
        return a;
    }

    // ComplexVariable& operator /(const ComplexVariable y){ // x/a
    //     ComplexVariable a;
    //     return a;
    // }

    // ComplexVariable& operator ^(const ComplexVariable y){ // x^a
    //     ComplexVariable a;
    //     return a;
    // }

    // ComplexVariable& operator == (const ComplexVariable a){ // x==a
    //     ComplexVariable a;
    //     return a;
    // }

    //---------------------varible and double--------------------------
    // ComplexVariable& operator +(const double y){
    //     ComplexVariable a;
    //     return a;
    // }

    // ComplexVariable& operator -(const double y){
    //     ComplexVariable a;
    //     return a;
    // }

    // ComplexVariable& operator *(const double y){
    //     ComplexVariable a;
    //     return a;
    // }

    // ComplexVariable& operator /(const double y){
    //     ComplexVariable a;
    //     return a;
    // }

    // ComplexVariable& operator ^(const double y){
    //     ComplexVariable a;
    //     return a;
    // }

    // ComplexVariable& operator ==(const double y){
    //     ComplexVariable a;
    //     return a;
    // }
    
    friend ComplexVariable& operator +(double a, const ComplexVariable y){
        ComplexVariable q;
        return q;
    }
    
    friend ComplexVariable& operator -(double a, const ComplexVariable y){
        ComplexVariable q;
        return q;
    }

    friend ComplexVariable& operator *(double a, const ComplexVariable y){
        ComplexVariable q;
        return q;
    }

    ComplexVariable::friend ComplexVariable& operator /(double a, const ComplexVariable y){
        ComplexVariable q;
        return q;
    }
}