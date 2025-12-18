/*
Vorobyev Dmitriy | st140149@student.spbu.ru
Assignment 5
*/


#include <gtest/gtest.h>

#include "Rational.h"
#include "Matrix.h"


TEST(MatrixIntTest, Addition)
{
    Matrix<int> a(2, 2, 1);
    Matrix<int> b(2, 2, 2);
    auto c = a + b;
    EXPECT_EQ(c(0, 0), 3);
}

TEST(MatrixDoubleTest, ScalarMultiplication)
{
    Matrix<double> a(1, 2);
    a(0, 0) = 1.5;
    a(0, 1) = 2.0;
    auto b = a * 2.0;
    EXPECT_DOUBLE_EQ(b(0, 0), 3.0);
    EXPECT_DOUBLE_EQ(b(0, 1), 4.0);
}

TEST(MatrixRationalTest, Multiplication)
{
    Matrix<Rational> a(1, 2);
    Matrix<Rational> b(2, 1);
    a(0, 0) = Rational(1, 2);
    a(0, 1) = Rational(1, 3);
    b(0, 0) = Rational(2);
    b(1, 0) = Rational(3);

    auto c = a * b;
    EXPECT_EQ(c(0, 0), Rational(1 + 1));
}

TEST(RationalTest, Invariant)
{
    Rational r(2, 4);
    EXPECT_EQ(r, Rational(1, 2));
}