/*
Vorobyev Dmitriy | st140149@student.spbu.ru
Assignment 5
*/


#include "Rational.h"

#include <iostream>
#include <stdexcept>


Rational::Rational() : numerator_(0), denominator_(1) {}
Rational::Rational(int num) : numerator_(num), denominator_(1) {}
Rational::Rational(int num, int den) : numerator_(num), denominator_(den)
{
    normalize();
}


void Rational::normalize()
{
    if (denominator_ < 0)
    {
        denominator_ = -denominator_;
        numerator_ = -numerator_;
    }
    if (denominator_ == 0)
    {
        throw std::invalid_argument("Err: denominator must be != 0");
    }

    int gcd = std::gcd(numerator_, denominator_);
    numerator_ /= gcd;
    denominator_ /= gcd;
}

int Rational::get_numerator() const
{
    return numerator_;
}

int Rational::get_denominator() const
{
    return denominator_;
}

Rational Rational::operator+(const Rational& second_operand) const
{
    return Rational(numerator_ * second_operand.denominator_ + denominator_ * second_operand.numerator_, denominator_ * second_operand.denominator_);
}

Rational Rational::operator*(const Rational& second_operand) const
{
    return Rational(numerator_ * second_operand.numerator_, denominator_ * second_operand.denominator_);
}

bool Rational::operator==(const Rational& second_operand) const
{
    return (numerator_ == second_operand.numerator_ && denominator_ == second_operand.denominator_);
}

std::ostream& operator<<(std::ostream& os, const Rational& rational)
{
    return os << rational.get_numerator() << "/" << rational.get_denominator();
}


