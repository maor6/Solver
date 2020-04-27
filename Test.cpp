
#include "doctest.h"
#include "solver.hpp"
using namespace solver;
using namespace std;


TEST_CASE("test for operator +") {
    RealVariable x;
    CHECK(solve(2+x+10 == 10) == -2);
    CHECK(solve(x+20 == 1) == -2);
    CHECK(solve(7+x == 14) == -2);
    CHECK(solve(9.5 == 2.5+x) == -2);
    CHECK(solve(1+x+2 == 8) == -2);
    CHECK(solve(4+4+x == 21) == -2);
    CHECK(solve(x+1+3.5 == 5.5) == -2);
    CHECK(solve(222+x == 2555) == -2);
    CHECK(solve(x+1.4 == 2.6) == -2);
    CHECK(solve(5.8+x == 11.3) == -2);
    CHECK(solve(x+2+3 == 4) == -2);
    CHECK(solve(x+2+3.333 == 4.125) == -2);   
}

TEST_CASE("test for operator -") {
    RealVariable x;
    CHECK(solve(2-10-x == 20) == -2);
    CHECK(solve(1-x-20 == 1) == -2);
    CHECK(solve(7-x-1 == 14) == -2);
    CHECK(solve(9.5 == 2.5-x) == -2);
    CHECK(solve(1-x-2.1 == 8) == -2);
    CHECK(solve(4-4-x == 19.11) == -2);
    CHECK(solve(x-1-3.5 == -5.5) == -2);
    CHECK(solve(2212-x == 2.112) == -2);
    CHECK(solve(x-1.444 == 2.6) == -2);
    CHECK(solve(5.8-x == 11.3) == -2);
    CHECK(solve(x+2+3 == -1) == -2);
    CHECK(solve(x-2.21-3.90 == 2) == -2);
}

TEST_CASE("test for operator *") {
    RealVariable x;
    CHECK(solve(10*x == 20) == -2);
    CHECK(solve(x*10 == 1.2) == -2);
    CHECK(solve(x*1.3 == 4.3) == -2);
    CHECK(solve(2.5*x == 2.5) == -2);
    CHECK(solve(3.45*x == 8) == -2);
    CHECK(solve(8.38*x*3 == 19.11) == -2);
    CHECK(solve(3*6*x == -5.5) == -2);
    CHECK(solve(22.678*x == 2.112) == -2);
}

TEST_CASE("test for operator /") {
    RealVariable x;
    CHECK(solve(0/x == 2) == 0);
    CHECK(solve(22.4/x == 1) == -2);
    CHECK(solve(1/4/x == 14) == -2);
    CHECK(solve(x/4.2 == 2.5-x) == -2);
    CHECK(solve(4.387/x == 8) == -2);
    CHECK(solve(x/2/6 == 19.11) == -2);
    CHECK(solve(2.99/x == -5.5) == -2);
    CHECK(solve(x/9.987 == 2.112) == -2);
    CHECK_THROWS(solve(x/0 == 2)); //can't divid by 0
}

TEST_CASE("test for operator ^") {
    RealVariable x;
    CHECK(solve(x^2 == 2) == 0);
    CHECK(solve(x^2 == 1) == -2);
    CHECK(solve(x^2 == 16) == -2);
    CHECK(solve(8 == x^2) == -2);
    CHECK(solve(25 == x^2) == -2);
    CHECK(solve(x^2 == 0) == 0);
    CHECK_THROWS(solve(-4 == x^2)); //exception: no real solution
    CHECK_THROWS(solve(x^2== -16)); //exception: no real solution
    CHECK_THROWS(solve(9 == x^3)); //not soppurt above X^2
}

TEST_CASE("test for operators + and -") {
    RealVariable x;
    CHECK(solve(x+2-6 == 2) == 0);
    CHECK(solve(10+x-3 == 1) == -2);
    CHECK(solve(9-5+8-x == 14) == -2);
    CHECK(solve(3+2-9.2 == 21.5-x) == -2);
    CHECK(solve(x-41-6-9+20 == 8) == -2);
    CHECK(solve(25+3-x+6 == -19.11) == -2);
    CHECK(solve(9 == -5.5+x-8) == -2);
    CHECK(solve(45 == x-2.112+67.45) == -2);
}


TEST_CASE("test for operators + and *") {
    RealVariable x;
    CHECK(solve(x+2*6 == 2) == 0);
    CHECK(solve(10+x*3 == 1) == -2);
    CHECK(solve(9*5+8*x == 14) == -2);
    CHECK(solve(3+2*9.2 == 21.5*x) == -2);
    CHECK(solve(x*6*9+20 == 8) == -2);
    CHECK(solve(25+3*x+6 == 19.11) == -2);
    CHECK(solve(9 == -5.5+x*8) == -2);
    CHECK(solve(45 == x*2.112+67.45) == -2);
}

TEST_CASE("test for operators + and /") {
   RealVariable x;
    CHECK(solve(x+2/6 == 2) == 0);
    CHECK(solve(10+x/3 == 1) == -2);
    CHECK(solve(9-5+8/x == 14) == -2);
    CHECK(solve(3+2-9.2 == 21.5/x) == -2);
    CHECK(solve(x/41+6/9+20 == 8) == -2);
    CHECK(solve(25+3/x+6 == -19.11) == -2);
    CHECK(solve(9/3 == 5.5+x/8) == -2);
    CHECK(solve(45 == x/2.112+67.45) == -2);
}

TEST_CASE("test for operators + and ^") {
    RealVariable x;
    CHECK(solve(x^2+6 == 2) == 0);
    CHECK(solve(10+x^2 == 1) == -2);
    CHECK(solve(9+8+x^2 == 14) == -2);
    CHECK(solve(3+9.2 == 21.5+x^2) == -2);
    CHECK(solve(x^2+41+20 == 8) == -2);
    CHECK(solve(25+x^2 == 19.11) == -2);
    CHECK(solve(9 == 5.5+x^2) == -2);
    CHECK(solve(45 == x^2+2.112+67.45) == -2);
}

TEST_CASE("test for operators - and *") {
    RealVariable x;
    CHECK(solve(x*2-6 == 2) == 0);
    CHECK(solve(10-x*2 == 1) == -2);
    CHECK(solve(9-8-x*3.66 == 14*x) == -2);
    CHECK(solve(3-9.2 == 21.5-x*5) == -2);
    CHECK(solve(41*x-20 == 8) == -2);
    CHECK(solve(25-x*45 == -19.11) == -2);
    CHECK(solve(9 == -5.5-67.87*x) == -2);
    CHECK(solve(45 == -2.112*x-67.45) == -2);
}

TEST_CASE("test for operators - and /") {
    RealVariable x;
    CHECK(solve(x/2-6 == 2) == 0);
    CHECK(solve(10-x/2 == 1) == -2);
    CHECK(solve(9-8-x/3.66 == 14) == -2);
    CHECK(solve(3-9.2 == 21.5-x/5) == -2);
    CHECK(solve(41/x-20 == 8) == -2);
    CHECK(solve(25-x/45 == -19.11) == -2);
    CHECK(solve(9 == -5.5-67.87/x) == -2);
    CHECK(solve(-45 == -2.112/x-67.45) == -2);
}

TEST_CASE("test for operators - and ^") {
    RealVariable x;
    CHECK(solve(x^2-6 == 2) == 0);
    CHECK(solve(10-x^2 == 1) == -2);
    CHECK(solve(9-8+x^2 == 14) == -2);
    CHECK(solve(3-9.2 == 21.5-x^2) == -2);
    CHECK(solve(x^2-41-20 == 8) == -2);
    CHECK(solve(25-x^2 == -19.11) == -2);
    CHECK(solve(-9 == -5.5-x^2) == -2);
    CHECK(solve(45 == x^2-2.112-67.45) == -2);
}

TEST_CASE("test for operators * and /") {
    RealVariable x;
    CHECK(solve(x*2/6 == 2) == 0);
    CHECK(solve(10/x == 1*10) == 1);
    CHECK(solve(9*8*x/2 == 14) == -2);
    CHECK(solve(3/9.2 == 21.5*x) == -2);
    CHECK(solve(x/41*20 == 8*21) == -2);
    CHECK(solve(25/x*2 == 19.11) == -2);
    CHECK(solve(9/0.5 == 5.5*x/2) == -2);
    CHECK(solve(45 == x*2.112/67.45) == -2);
}

TEST_CASE("test for operators * and ^") {
    RealVariable x;
    CHECK(solve(x^2*1 == 2) == 0);
    CHECK(solve(10*x^2 == 1*10) == 1);
    CHECK(solve(9*8*x^2 == 14) == -2);
    CHECK(solve(3*9.2 == 21.5*x^2) == -2);
    CHECK(solve(x^2*20 == 8*21) == -2);
    CHECK(solve(19.11 == 25*x^2) == -2);
    CHECK(solve(9*2.5 == 5.5*x^2*3) == -2);
    CHECK(solve(45 == x^2*2.112*67.45) == -2);
}

TEST_CASE("test for operators / and ^") {
    RealVariable x;
    CHECK(solve(x^2/1 == 2) == 0);
    CHECK(solve(10/x^2 == 1/10) == 1);
    CHECK(solve(9/8/x^2 == 14) == -2);
    CHECK(solve(3/9.2 == 21.5/x^2) == -2);
    CHECK(solve(x^2/20 == 8/21) == -2);
    CHECK(solve(19.11 == 25/x^2) == -2);
    CHECK(solve(9/0.5 == 5.5/x^2/3) == -2);
    CHECK(solve(45 == x^2/2.112) == -2);
}


TEST_CASE("test for all operators ") {
    RealVariable x;
    CHECK(solve(x^2+7*x-1 == 2) == 0);
    CHECK(solve(10*x^2+3 == -10) == 1);
    CHECK(solve(9+8*x^2-3.7*x == 14) == -2);
    CHECK(solve(3/9.2*x+43 == 21.5/x^2) == -2);
    CHECK(solve(x^2/20+17.77 == 21-6.99) == -2);
    CHECK(solve(-19.11 == 25*x^2+3*x+6) == -2);
    CHECK(solve(9/0.5 == 5.5+x^2/3) == -2);
    CHECK(solve(45 == x^2+2.112+67.45) == -2);
    CHECK(solve(2 == x^2-2.112+67.45) == -2);

}



//-----------------------complex variable---------------------------

TEST_CASE("test for all operators complex") {
    ComplexVariable x;
    CHECK(solve(4i+x^2 == 2.0) == 2i);
    CHECK(solve(10.0*x-7 == -10) == 1.0);
    CHECK(solve(x/-1.0*x == 14) == -2.0);
    CHECK(solve(3/9.2*x == 21.5/x^2) == -2.2);
    CHECK(solve(x^2/20+17.77 == 21-6.99) == -2i);
    CHECK(solve(-19.11 == 25*x+3+6i) == -2i);
    CHECK(solve(45 == x+2.112i+67.45/2-4i) == -2i);
    CHECK(solve(2.0 == x^2-2.112+67.45) == 3i);
}