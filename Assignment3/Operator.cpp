/*
Vorobyev Dmitriy | st140149@student.spbu.ru
Assignment 4
*/


#include "Operator.h"

#include <iostream>
#include <string>

Operator::Operator(std::string name) : name_(name) {}

std::string Operator::get_name()
{
    return name_;
}

