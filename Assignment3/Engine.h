/*
Vorobyev Dmitriy | st140149@student.spbu.ru
Assignment 3
*/


#ifndef ENGINE_h
#define ENGINE_h


#include <string>


class Engine
{
public:
    Engine(std::string engine_type);


    std::string get_engine_type();
    void set_engine_type(std::string engine_type);


private:
    std::string engine_type_;
};


#endif