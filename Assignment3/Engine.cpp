/*
Vorobyev Dmitriy | st140149@student.spbu.ru
Assignment 4
*/


#include "Engine.h"

#include <iostream>
#include <string>


Engine::Engine(std::string type) : engine_type_(type) {}

std::string Engine::get_engine_type()
{
    return engine_type_;
}

void Engine::set_engine_type(std::string engine_type)
{
    engine_type_ = engine_type;
}
