/* 
Vorobyev Dmitriy | st140149@student.spbu.ru
Assignment 2b
*/

#include "rpncalculator.h"
#include <iostream>
#include <string>
#include <sstream>


void calculator()
{
    const int STACK_SIZE = 100;
    double* stack = new double[STACK_SIZE];
    double* i = stack - 1;

    std::cout << "Enter an expression in reversed polish notation(use a space between the elements)" << std::endl;
    std::cout << "!!! Use only 2 operands for 1 operation(e.g. 3 4 + correct; 3 4 5 + incorrect)" << std::endl;   
    std::string expression;
    std::getline(std::cin, expression);

    std::stringstream ss(expression);
    std::string element;

    while(ss >> element)
    {
        if (element == "+" || element == "-" || element == "*" || element == "/")
        {
        // we want to be sure that we have at least 2 numbers in stack
            if (i - stack + 1 < 2)
            {
                std::cerr << "Error, not enough operands" << std::endl;
                delete[] stack;
                return;
            }
            double b = *i;
            i--;
            double a = *i;

            if (element == "+")
            {
                *i = a + b;
            }
            else if (element == "-")
            {
                *i = a - b;
            }
            else if (element == "*")
            {
                *i = a * b;
            }
            else if (element == "/")
            {
                *i = a / b;
            }
        }
        else
        {
            i++;
            *i = std::stod(element);
        }
    }

    // we want to make sure that expression is correct(1 operation for 2 operands)
    if (i - stack != 0)
    {
        std::cerr << "Incorrect expression" << std::endl;
        delete[] stack;
        return;
    }

    std::cout << "Result: " << *i << std::endl;
    delete[] stack;
}