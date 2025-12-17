/*
Vorobyev Dmitriy | st140149@student.spbu.ru
Assignment 3
*/


#ifndef OPERATOR_h
#define OPERATOR_h


#include <string>


class Operator
{
public:
    Operator(std::string type);

    std::string get_name();

private:
    std::string name_;
};


#endif