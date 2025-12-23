/*
Vorobyev Dmitriy | st140149@student.spbu.ru
Assignment 4
*/

#include <iostream>
#include <string>

#include "Transformer.h"


Transformer::Transformer(std::string name, int power, int ammo, int health,
                         bool is_ready_to_fight, std::string engine_type, Operator* transformer_operator)
    : name_(name), power_(power), ammo_(ammo), health_(health), is_ready_to_fight_(is_ready_to_fight),
      engine_(engine_type), transformer_operator_(transformer_operator) {}

Transformer::Transformer(int power, int ammo, std::string engine_type) 
: power_(power), ammo_(ammo), engine_(engine_type) {}

Transformer::~Transformer() {}

std::string Transformer::get_name()
{
    return name_;
}

void Transformer::set_name(std::string name)
{
    name_ = name;
}

int Transformer::get_power()
{
    return power_;
}

void Transformer::set_power(int power)
{
    power_ = power;
}

int Transformer::get_ammo()
{
    return ammo_;
}

void Transformer::set_ammo(int ammo)
{
    ammo_ = ammo;
}

int Transformer::get_health()
{
    return health_;
}

void Transformer::set_health(int health)
{
    health_ = health;
}

bool Transformer::get_is_ready_to_fight()
{
    return is_ready_to_fight_;
}

void Transformer::set_is_ready_to_fight(bool is_ready_to_fight)
{
    is_ready_to_fight_ = is_ready_to_fight;
}

Engine& Transformer::get_engine()
{
    return engine_;
}

void Transformer::set_engine(std::string engine_type)
{
    engine_.set_engine_type(engine_type);
}

Operator* Transformer::get_operator()
{
    return transformer_operator_;
}

void Transformer::set_operator(Operator* transformer_operator)
{
    transformer_operator_ = transformer_operator;
}

bool Transformer::fire()
{
    return true;
}

bool Transformer::transform()
{
    return true;
}

bool Transformer::reload()
{
    return true;
}

void Transformer::defence_mode()
{
    std::cout << "Transformer::defence_mode" << std::endl;
}

void Transformer::transformer_info()
{
    std::cout << "Transformer::transformer_info" << std::endl;
}


void Transformer::output(std::ostream& os)
{
    os << "Transformer";
}

std::ostream& operator<<(std::ostream& os, Transformer& transformer)
{
    transformer.output(os);
    return os;
}