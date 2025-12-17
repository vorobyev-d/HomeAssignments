/* 
Vorobyev Dmitriy | st140149@student.spbu.ru
Assignment 3
*/


#include "Operator.h"

#include <string>

Operator::Operator(std::string name) : name_(name) {}

std::string Operator::get_name()
{
    return name_;
}