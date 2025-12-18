/*
Vorobyev Dmitriy | st140149@student.spbu.ru
Assignment 5
*/


#ifndef RATIONAL_H
#define RATIONAL_H


#include <stdexcept>
#include <numeric>


class Rational
{
public:
    Rational();
    Rational(int num);
    Rational(int num, int denom);

    int get_numerator() const;

    int get_denominator() const;

    Rational operator+(const Rational& second_operand) const;
    Rational operator*(const Rational& second_operand) const;
    bool operator==(const Rational& second_operand) const;




private:
    int numerator_;
    int denominator_;

    void normalize();
};

std::ostream& operator<<(std::ostream& os, Rational& rational);




#endif