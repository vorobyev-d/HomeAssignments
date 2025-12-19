/*
Vorobyev Dmitriy | st140149@student.spbu.ru
Assignment 5
*/


#include <gtest/gtest.h>

#include "Rational.h"
#include "Matrix.h"


TEST(MatrixIntTest, Addition)
{
    Matrix<int> a(2, 3);
    a(0, 0) = 5;
    a(0, 1) = 7;
    a(0, 2) = 11;
    a(1, 0) = 0;
    a(1, 1) = 33;
    a(1, 2) = 21;

    Matrix<int> b(2, 3);
    b(0, 0) = 1;
    b(0, 1) = 12;
    b(0, 2) = 133;
    b(1, 0) = 12;
    b(1, 1) = 9;
    b(1, 2) = 51;

    auto c = a + b;
    EXPECT_EQ(c(0, 1), 19);
}

TEST(MatrixIntTest, Multiplication)
{
    Matrix<int> a(2, 3);
    a(0, 0) = 5;
    a(0, 1) = 7;
    a(0, 2) = 11;
    a(1, 0) = 0;
    a(1, 1) = 33;
    a(1, 2) = 21;

    Matrix<int> b(3, 2);
    b(0, 0) = 1;
    b(0, 1) = 12;
    b(1, 0) = 133;
    b(1, 1) = 12;
    b(2, 0) = 9;
    b(2, 1) = 51;

    auto c = a * b;
    EXPECT_EQ(c(1, 0), 4578);
}

TEST(MatrixIntTest, ScalarMultiplication)
{
    Matrix<int> a(2, 3);
    a(0, 0) = 5;
    a(0, 1) = 7;
    a(0, 2) = 11;
    a(1, 0) = 0;
    a(1, 1) = 33;
    a(1, 2) = 21;

    auto b = a * 17;
    EXPECT_EQ(b(0, 1), 119);
}

TEST(MatrixIntTest, Transposition)
{
    Matrix<int> a(2, 3);
    a(0, 0) = 5;
    a(0, 1) = 7;
    a(0, 2) = 11;
    a(1, 0) = 0;
    a(1, 1) = 33;
    a(1, 2) = 21;

    auto b = a.Transpose();
    EXPECT_EQ(b(0, 1), 0);
}

TEST(MatrixDoubleTest, Addition)
{
    Matrix<double> a(2, 3);
    a(0, 0) = 5.5;
    a(0, 1) = 7.24;
    a(0, 2) = 11.121;
    a(1, 0) = 0.5551;
    a(1, 1) = 33.12;
    a(1, 2) = 21.551;

    Matrix<double> b(2, 3);
    b(0, 0) = 1.0924;
    b(0, 1) = 12.12;
    b(0, 2) = 133.1337;
    b(1, 0) = 12.24;
    b(1, 1) = 9.11;
    b(1, 2) = 51.511;

    auto c = a + b;
    EXPECT_DOUBLE_EQ(c(0, 1), 19.36);
}

TEST(MatrixDoubleTest, Multiplication)
{
    Matrix<double> a(2, 3);
    a(0, 0) = 5.5;
    a(0, 1) = 7.24;
    a(0, 2) = 11.121;
    a(1, 0) = 0.5551;
    a(1, 1) = 33.12;
    a(1, 2) = 21.551;

    Matrix<double> b(3, 2);
    b(0, 0) = 1.0924;
    b(0, 1) = 12.12;
    b(1, 0) = 133.1337;
    b(1, 1) = 12.24;
    b(2, 0) = 9.11;
    b(2, 1) = 51.511;

    auto c = a * b;
    EXPECT_DOUBLE_EQ(c(0, 1), 728.131431);
}

TEST(MatrixDoubleTest, ScalarMultiplication)
{
    Matrix<double> a(2, 3);
    a(0, 0) = 5.5;
    a(0, 1) = 7.24;
    a(0, 2) = 11.121;
    a(1, 0) = 0.5551;
    a(1, 1) = 33.12;
    a(1, 2) = 21.551;

    auto b = a * 14.8;
    EXPECT_DOUBLE_EQ(b(0, 1), 107.152);
}

TEST(MatrixDoubleTest, Transposition)
{
    Matrix<double> a(2, 3);
    a(0, 0) = 5.5;
    a(0, 1) = 7.24;
    a(0, 2) = 11.121;
    a(1, 0) = 0.5551;
    a(1, 1) = 33.12;
    a(1, 2) = 21.551;

    auto b = a.Transpose();
    EXPECT_DOUBLE_EQ(b(0, 1), 0.5551);
}

TEST(MatrixFloatTest, Addition)
{
    Matrix<float> a(2, 3);
    a(0, 0) = 5.5;
    a(0, 1) = 7.24;
    a(0, 2) = 11.121;
    a(1, 0) = 0.5551;
    a(1, 1) = 33.12;
    a(1, 2) = 21.551;

    Matrix<float> b(2, 3);
    b(0, 0) = 1.0924;
    b(0, 1) = 12.12;
    b(0, 2) = 133.1337;
    b(1, 0) = 12.24;
    b(1, 1) = 9.11;
    b(1, 2) = 51.511;

    auto c = a + b;
    EXPECT_FLOAT_EQ(c(0, 1), 19.36);
}

TEST(MatrixFloatTest, Multiplication)
{
    Matrix<float> a(2, 3);
    a(0, 0) = 5.5;
    a(0, 1) = 7.24;
    a(0, 2) = 11.121;
    a(1, 0) = 0.5551;
    a(1, 1) = 33.12;
    a(1, 2) = 21.551;

    Matrix<float> b(3, 2);
    b(0, 0) = 1.0924;
    b(0, 1) = 12.12;
    b(1, 0) = 133.1337;
    b(1, 1) = 12.24;
    b(2, 0) = 9.11;
    b(2, 1) = 51.511;

    auto c = a * b;
    EXPECT_FLOAT_EQ(c(0, 1), 728.131431);
}

TEST(MatrixFloatTest, ScalarMultiplication)
{
    Matrix<float> a(2, 3);
    a(0, 0) = 5.5;
    a(0, 1) = 7.24;
    a(0, 2) = 11.121;
    a(1, 0) = 0.5551;
    a(1, 1) = 33.12;
    a(1, 2) = 21.551;

    auto b = a * 14.8;
    EXPECT_FLOAT_EQ(b(0, 1), 107.152);
}

TEST(MatrixFloatTest, Transposition)
{
    Matrix<float> a(2, 3);
    a(0, 0) = 5.5;
    a(0, 1) = 7.24;
    a(0, 2) = 11.121;
    a(1, 0) = 0.5551;
    a(1, 1) = 33.12;
    a(1, 2) = 21.551;

    auto b = a.Transpose();
    EXPECT_FLOAT_EQ(b(0, 1), 0.5551);
}

TEST(MatrixRationalTest, Addition)
{
    Matrix<Rational> a(2, 3);

    a(0, 0) = Rational(5, 2);
    a(0, 1) = Rational(7, 9);
    a(0, 2) = Rational(15, 232);
    a(1, 0) = Rational(7, 55);
    a(1, 1) = Rational(51, 32);
    a(1, 2) = Rational(9, 9);

    Matrix<Rational> b(2, 3);

    b(0, 0) = Rational(17, 3);
    b(0, 1) = Rational(662, 4);
    b(0, 2) = Rational(123, 22);
    b(1, 0) = Rational(73, 5);
    b(1, 1) = Rational(16, 3);
    b(1, 2) = Rational(3, 69);

    auto c = a + b;
    EXPECT_EQ(c(0, 1), Rational(2993, 18));
}

TEST(MatrixRationalTest, Multiplication)
{
    Matrix<Rational> a(2, 3);

    a(0, 0) = Rational(5, 2);
    a(0, 1) = Rational(7, 9);
    a(0, 2) = Rational(15, 232);
    a(1, 0) = Rational(7, 55);
    a(1, 1) = Rational(51, 32);
    a(1, 2) = Rational(9, 9);

    Matrix<Rational> b(3, 2);

    b(0, 0) = Rational(17, 3);
    b(0, 1) = Rational(662, 4);
    b(1, 0) = Rational(123, 22);
    b(1, 1) = Rational(73, 5);
    b(2, 0) = Rational(16, 3);
    b(2, 1) = Rational(3, 69);

    auto c = a * b;
    EXPECT_EQ(c(0, 1), Rational(102077021, 240120));
}

TEST(MatrixRationalTest, ScalarMultiplication)
{
    Matrix<Rational> a(2, 3);

    a(0, 0) = Rational(5, 2);
    a(0, 1) = Rational(7, 9);
    a(0, 2) = Rational(15, 232);
    a(1, 0) = Rational(7, 55);
    a(1, 1) = Rational(51, 32);
    a(1, 2) = Rational(9, 9);

    auto b = a * Rational(1513, 19);
    EXPECT_EQ(b(0, 1), Rational(10591, 171));
}

TEST(MatrixRationalTest, Transposition)
{
    Matrix<Rational> a(2, 3);

    a(0, 0) = Rational(5, 2);
    a(0, 1) = Rational(7, 9);
    a(0, 2) = Rational(15, 232);
    a(1, 0) = Rational(7, 55);
    a(1, 1) = Rational(51, 32);
    a(1, 2) = Rational(9, 9);

    auto b = a.Transpose();
    EXPECT_EQ(b(0, 1), Rational(7, 55));
}

TEST(MatrixTest, AdditionSizeMissmatchThrow)
{
    EXPECT_THROW(Matrix<int>(2, 3, 1) + Matrix<int>(4, 5, 1), std::invalid_argument);
}

TEST(MatrixTest, MultiplicationSizeMissmatchThrow)
{
    EXPECT_THROW(Matrix<int>(2, 3, 1) * Matrix<int>(4, 5, 1), std::invalid_argument);
}

TEST(RationalTest, Invariant)
{
    Rational r(2, 4);
    EXPECT_EQ(r, Rational(1, 2));
}

TEST(RationalTest, Addition)
{
    Rational r1(3, 5);
    Rational r2(7, 8);
    EXPECT_EQ(r1 + r2, Rational(59, 40));
}

TEST(RationalTest, Multiplication)
{
    Rational r1(3, 5);
    Rational r2(7, 8);
    EXPECT_EQ(r1 * r2, Rational(21, 40));
}

TEST(RationalTest, ZeroDenominatorThrows)
{
    EXPECT_THROW(Rational r(1, 0), std::invalid_argument);
}