
#include "solver.hpp"
using namespace std;

namespace solver{
    
    RealVariable& RealVariable::operator +(const RealVariable a){
        RealVariable x;
        return x;
    }

    RealVariable& RealVariable::operator -(const RealVariable a){
        RealVariable x;
        return x;
    }

    RealVariable& RealVariable::operator *(const RealVariable a){
        RealVariable x;
        return x;
    }

    RealVariable& RealVariable::operator /(const RealVariable a){
        RealVariable x;
        return x;
    }

    RealVariable& RealVariable::operator ^(const RealVariable a){
        RealVariable x;
        return x;
    }

    RealVariable& RealVariable::operator ==(const RealVariable a){
        RealVariable x;
        return x;
    }

    RealVariable& RealVariable::operator+(const double a){ // x+a
        RealVariable x;
        return x;
    }

    RealVariable& RealVariable::operator -(const double a){ //x-a
        RealVariable x;
        return x;
    }

    RealVariable& RealVariable::operator *(const double a){ // x*a
        RealVariable x;
        return x;
    }

    RealVariable& RealVariable::operator /(const double a){ // x/a
        RealVariable x;
        return x;
    }

    RealVariable& RealVariable::operator ^(const double a){ // x^a
        RealVariable x;
        return x;
    }

    RealVariable& RealVariable::operator == (const double a){ // x==a
        RealVariable x;
        return x;
    }
    
    RealVariable& operator +(double a, RealVariable x){ // a+x
        RealVariable q;
        return q;
    }

    RealVariable& operator -(double a, RealVariable x){ // a-x
        RealVariable q;
        return q;
    }

    RealVariable& operator *(double a, RealVariable x){ // a*x
        RealVariable q;
        return q;
    }

    RealVariable& operator /(double a, RealVariable x){ // a/x
        RealVariable q;
        return q;
    }

    RealVariable& operator ==(double a, RealVariable x){
        RealVariable q;
        return q;
    }

    //----------------------varible and complex-----------------
    ComplexVariable& ComplexVariable::operator +(const std::complex<double> y){ // x+a
        ComplexVariable a;
        return a;
    }

    ComplexVariable& ComplexVariable::operator -(const std::complex<double> y){ //x-a
        ComplexVariable a;
        return a;
    }

    ComplexVariable& ComplexVariable::operator *(const std::complex<double> y){ // x*a
        ComplexVariable a;
        return a;
    }

    ComplexVariable& ComplexVariable::operator /(const std::complex<double> y){ // x/a
        ComplexVariable a;
        return a;
    }

    ComplexVariable& ComplexVariable::operator ^(const std::complex<double> y){ // x^a
        ComplexVariable a;
        return a;
    }

    ComplexVariable& ComplexVariable::operator == (const std::complex<double> a){ // x==a
        ComplexVariable q;
        return q;
    }


    //----------------------varible and varible-------------------------
    ComplexVariable& ComplexVariable::operator +(const ComplexVariable y){ // x+a
        ComplexVariable a;
        return a;
    }

    ComplexVariable& ComplexVariable::operator -(const ComplexVariable y){ //x-a
        ComplexVariable a;
        return a;
    }

    ComplexVariable& ComplexVariable::operator *(const ComplexVariable y){ // x*a
        ComplexVariable a;
        return a;
    }

    ComplexVariable& ComplexVariable::operator /(const ComplexVariable y){ // x/a
        ComplexVariable a;
        return a;
    }

    ComplexVariable& ComplexVariable::operator ^(const ComplexVariable y){ // x^a
        ComplexVariable a;
        return a;
    }

    ComplexVariable& ComplexVariable::operator == (const ComplexVariable a){ // x==a
        ComplexVariable q;
        return q;
    }

    //---------------------varible and double--------------------------
    ComplexVariable& ComplexVariable::operator +(const double y){
        ComplexVariable a;
        return a;
    }

    ComplexVariable& ComplexVariable::operator -(const double y){
        ComplexVariable a;
        return a;
    }

    ComplexVariable& ComplexVariable::operator *(const double y){
        ComplexVariable a;
        return a;
    }

    ComplexVariable& ComplexVariable::operator /(const double y){
        ComplexVariable a;
        return a;
    }

    ComplexVariable& ComplexVariable::operator ^(const double y){
        ComplexVariable a;
        return a;
    }

    ComplexVariable& ComplexVariable::operator ==(const double y){
        ComplexVariable a;
        return a;
    }
    
    ComplexVariable& operator +(double a, const ComplexVariable y){
        ComplexVariable q;
        return q;
    }
    
    ComplexVariable& operator -(double a, const ComplexVariable y){
        ComplexVariable q;
        return q;
    }

    ComplexVariable& operator *(double a, const ComplexVariable y){
        ComplexVariable q;
        return q;
    }

    ComplexVariable& operator /(double a,const ComplexVariable y){
        ComplexVariable q;
        return q;
    }

    ComplexVariable& operator ==(double a, const ComplexVariable y){
        ComplexVariable q;
        return q;
    }

    ComplexVariable& operator +(const std::complex<double> y ,const ComplexVariable a){
        ComplexVariable q;
        return q;
    }

    ComplexVariable& operator -(const std::complex<double> y ,const ComplexVariable a){
        ComplexVariable q;
        return q;
    }

    ComplexVariable& operator *(const std::complex<double> y ,const ComplexVariable a){
        ComplexVariable q;
        return q;
    }

    ComplexVariable& operator /(const std::complex<double> y ,const ComplexVariable a){
        ComplexVariable q;
        return q;
    }

    ComplexVariable& operator ^(const std::complex<double> y ,const ComplexVariable a){
        ComplexVariable q;
        return q;
    }

    ComplexVariable& operator ==(const std::complex<double> y ,const ComplexVariable a){
        ComplexVariable q;
        return q;
    }

    double solve(RealVariable){
        return 0;
    }
     
    std::complex<double> solve(ComplexVariable){
        std::complex<double> x;
        return x;
    }

}