
#include "doctest.h"
#include "solver.hpp"
using namespace solver;
using namespace std;


TEST_CASE("test for operator +") {
    RealVariable x;
    CHECK(solve(2+x+10 == 10) == -2);
    CHECK(solve(x+20 == 1) == -19);
    CHECK(solve(7+x == 14) == 7);
    CHECK(solve(9.5 == 2.5+x) == 7);
    CHECK(solve(1+x+2 == 8) == 5);
    CHECK(solve(4+4+x == 21) == 13);
    CHECK(solve(x+1+3.5 == 5.5) == 1);
    CHECK(solve(222+x == 2555) == 2333);
    CHECK(solve(x+1.4 == 2.6) == 1.2);
    CHECK(solve(5.88+x == 11.3) == 5.42);
    CHECK(solve(x+2+3 == 4) == -1);
    CHECK(solve(x+2+3.333 == 4.125) == -1.2081);   
}

TEST_CASE("test for operator -") {
    RealVariable x;
    CHECK(solve(x-20 == 1) == 21);
    CHECK(solve(x-1 == 14) == 15);
    CHECK(solve(4-4-x == 19.11) == -19.11);
    CHECK(solve(x-1-3.5 == -5.5) == -1);
    CHECK(solve(x-1.444 == 2.6) == 4.044);
    CHECK(solve(x+2+3 == -1) == -6);
    CHECK(solve(x-2.21-3.90 == 2) == 8.11);
}

TEST_CASE("test for operator *") {
    RealVariable x;
    CHECK(solve(10*x == 20) == 2);
    CHECK(solve(x*10 == 1.2) == 0.12);
    CHECK(solve(x*1.3 == 4.3) == 3.3076);
    CHECK(solve(2.5*x == 2.5) == 1);
    CHECK(solve(3.45*x == 8) == 2.3188);
    CHECK(solve(8.38*x*3 == 19.11) == 0.7601);
    CHECK(solve(-3*6*x == -5.5) == 0.3055);
    CHECK(solve(-22.678*x == 2.112) == -0.0932);
}

TEST_CASE("test for operator /") {
    RealVariable x;
    CHECK(solve(x/2/6 == 19.11) == 229.32);
    CHECK(solve(x/9.987 == 2.112) == 21.0925);
    CHECK_THROWS(solve(x/0 == 2)); //can't divid by 0
}

TEST_CASE("test for operator ^") {
    RealVariable x;
    CHECK(solve((x^2) == 2) == 1.4142);
    CHECK(solve((x^2) == 1) == 1);
    CHECK(solve((x^2) == 16) == 4);
    CHECK(solve(8 == (x^2)) == 2.8284);
    CHECK(solve(25 == (x^2)) == 5);
    CHECK(solve((x^2) == 0) == 0);
    CHECK_THROWS(solve(-4 == (x^2))); //exception: no real solution
    CHECK_THROWS(solve((x^2)== -16)); //exception: no real solution
    CHECK_THROWS(solve(9 == (x^3))); //not soppurt above X^2
}

TEST_CASE("test for operators + and -") {
    RealVariable x;
    CHECK(solve(x+2-6 == 2) == 6);
    CHECK(solve(10+x-3 == 1) == -6);
    CHECK(solve(8+x == -14) == -22);
    CHECK(solve(x-41-6-9+20 == 8) == 44);
    CHECK(solve(9 == -5.5+x-8) == 22.5);
    CHECK(solve(45 == x-2.112+67.45) == -20.3381);
}


TEST_CASE("test for operators + and *") {
    RealVariable x;
    CHECK(solve(x+2*6 == 2) == -10);
    CHECK(solve(10+x*3 == 1) == -3);
    CHECK(solve(9*5+8*x == 14) == -3.875);
    CHECK(solve(3+2*9.2 == 21.5*x) == 0.9953);
    CHECK(solve(9 == -5.5+x*8) == 1.8125);
    CHECK(solve(45 == x*2.112+67.45) == -10.6298);
}

TEST_CASE("test for operators + and /") {
   RealVariable x;
    CHECK(solve(x/2+6 == 2) == -8);
    CHECK(solve(10+x/3 == 1) == -27);
    //CHECK(solve(x/41+6/9+20 == 8) == -519.3333);
    CHECK(solve(9/3 == 5.5+x/8) == -20);
    CHECK(solve(45 == x/2.112+67.45) == -47.4145);
}

TEST_CASE("test for operators + and ^") {
    RealVariable x;
    CHECK_THROWS(solve((x^2)+6 == 2)); // need to throw
    CHECK_THROWS(solve(10+(x^2) == 1)); // need to throw
    CHECK((solve(9+8+(x^2) == 140) == 11.0905 || solve(9+8+(x^2) == 140) == -11.0905));
    CHECK((solve(3+9.2 == 2.5+(x^2)) == 3.1144 || solve(3+9.2 == 2.5+(x^2)) == -3.1144));
    //CHECK((solve((x^2)+41*x+20 == 8) == -0.2948 || solve((x^2)+41*x+20 == 8) == -40.7051));
    CHECK((solve(25+(x^2) == 39.11) == 3.7563 || solve(25+(x^2) == 39.11) == -3.7563));
    CHECK((solve(9 == 5.5+(x^2)) == 1.8708 || solve(9 == 5.5+(x^2)) == -1.8708));
}

TEST_CASE("test for operators - and *") {
    RealVariable x;
    CHECK(solve(x*2-6 == 2) == 4);
    CHECK(solve(41*x-20 == 8) == 0.6829);
    CHECK(solve(25-x*45 == -19.11) == 0.4246);
    CHECK(solve(9 == -5.5-67.87*x) == -0.1327);
    CHECK(solve(45 == -2.112*x-67.45) == -53.2434);
}

TEST_CASE("test for operators - and /") {
    RealVariable x;
    CHECK(solve(x/2-6 == 2) == 16);
    CHECK(solve(-8-x/3.66 == 14) == -51.2401);
    CHECK(solve(9.2 == 21.5-x/5) == -46.0);
}

TEST_CASE("test for operators - and ^") {
    RealVariable x;
    CHECK((solve((x^2)-6 == 2) == 2.8284 || solve((x^2)-6 == 2) == -2.8284));
    CHECK((solve(9-8+(x^2) == 14) == 3.6055 || solve(9-8+(x^2) == 14) == -3.6055));
    CHECK((solve((x^2)-41 == 8) == 7 || solve((x^2)-41 == 8) == -7));
    CHECK((solve((x^2)-25 == -19.11) == 2.4269 || solve((x^2)-25 == -19.11) == -2.4269));
    CHECK((solve(45 == (x^2)-2.112-67.45) == 10.7033 || solve(45 == (x^2)-2.112-67.45) == -10.7033));
}

TEST_CASE("test for operators * and /") {
    RealVariable x;
    CHECK(solve(x*2/6 == 2) == 6);
    CHECK(solve(9*8*x/2 == 14) == 0.3888);
    CHECK(solve(3/9.2 == 21.5*x) == 0.0151);
    CHECK(solve(x/41*20 == 8*21) == 344.4);
    CHECK(solve(9/0.5 == 5.5*x/2) == 6.5454);
    CHECK(solve(45 == x*2.112/67.45) == 1437.1448);
}

TEST_CASE("test for operators * and ^") {
    RealVariable x;
    CHECK((solve((x^2)*1 == 2) == 1.4142 || solve((x^2)*1 == 2) == -1.4142));
    CHECK((solve(10*(x^2) == 1*10) == 1 || solve(10*(x^2) == 1*10) == -1));
    CHECK((solve(9*8*(x^2) == 14) == 0.4409 || solve(9*8*(x^2) == 14) == -0.4409));
    CHECK((solve(3*9.2 == 21.5*(x^2)) == 1.1330 || solve(3*9.2 == 21.5*(x^2)) == -1.1330));
    CHECK((solve((x^2)*20 == 8*21) == 2.8982 || solve((x^2)*20 == 8*21) == -2.8982));
    CHECK((solve(19.11 == 25*(x^2)) == 0.8742 || solve(19.11 == 25*(x^2)) == -0.8742));
    CHECK((solve(9*2.5 == 5.5*(x^2)*3) == 1.1677 || solve(9*2.5 == 5.5*(x^2)*3) == -1.1677));
    CHECK((solve(45 == (x^2)*2.112*67.45) == 0.5620 || solve(45 == (x^2)*2.112*67.45) == -0.5620));
}

TEST_CASE("test for operators / and ^") {
    RealVariable x;
    CHECK((solve((x^2)/1 == 2) == 1.4142 || solve((x^2)/1 == 2) == -1.4142));
    CHECK((solve((x^2)/20 == 8) == 12.6491 || solve((x^2)/20 == 8) == -12.6491));
    //CHECK(solve(19.11 == 25.0/(x^2.0)) == );
    CHECK_THROWS(solve(-45 == (x^2)/2.112));
}


TEST_CASE("test for all operators ") {
    RealVariable x;
    CHECK((solve((x^2)+7*x-1 == 2) == 0.4051 || solve((x^2)+7*x-1 == 2) == -7.4051));
    CHECK_THROWS((solve(10*(x^2)+x == -10)));
    CHECK((solve(9+8*(x^2)-3.7*x == 14) == 1.0549 || solve(9+8*(x^2)-3.7*x == 14) == -0.5924));
    CHECK((solve(19.11 == 25*(x^2)+3*x+6) == 0.6666 || solve(19.11 == 25*(x^2)+3*x+6) == -0.7866));
    CHECK((solve(9/0.5 == 5.5+(x^2)/3) == 6.1237 || solve(9/0.5 == 5.5+(x^2)/3) == -6.1237));
    CHECK((solve(4389 == (x^2)+2.112+67.45) == 65.7224 || solve(4389 == (x^2)+2.112+67.45) == -65.7224));
    CHECK((solve(2 == (x^2)-209483.112+67.45) == 457.6217 || solve(2 == (x^2)-209483.112+67.45) == -457.6217));
}



//-----------------------complex variable---------------------------

TEST_CASE("test for all operators complex") {
    ComplexVariable x;
    //CHECK(solve(4i+(x^2.0) == 2.0) == 2-4i);
    CHECK(solve(10.0*x-7 == -10) == -0.3);
    //CHECK(solve(x/-1.0+x == 14i) == 0.9949-0.0710);
    //CHECK(solve(3/9.2*x == 21.5/(x^2)) == -2.2);
   // CHECK((solve((x^2)/20+17.77 == 21-6.99) == 23.0034+0i || solve((x^2)/20+17.77 == 21-6.99) == -23.0034+0i));
    CHECK(solve(-19.11 == 25*x+3+6i) == -0.8844-0.24i);
    //CHECK(solve(45 == x+2.112i+67.45/2-4i) == 22.55-182.112i);
    //CHECK((solve((x^2) + 2*x + 4 == 20 + 6*x/2 - x) == 4+0i || solve((x^2) + 2*x + 4 == 20 + 6*x/2 - x) == -4+0i));
}