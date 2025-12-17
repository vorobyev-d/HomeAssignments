/* 
Vorobyev Dmitriy | st140149@student.spbu.ru
Assignment 3
*/


#include "TankTransformer.h"

#include <string>


TankTransformer::TankTransformer(std::string name, int power, int ammo, int health, 
    bool is_ready_to_fight, std::string engine_type, Operator* transformer_operator, 
    int armour_level, std::string missile_type)
    : Transformer(name, power, ammo, health, is_ready_to_fight, engine_type, transformer_operator),
      armour_level_(armour_level), missile_type_(missile_type) {}


int TankTransformer::get_armour_level()
{
    return armour_level_;
}

void TankTransformer::set_armour_level(int armour_level)
{
    armour_level_ = armour_level; 
}


std::string TankTransformer::get_missile_type()
{
    return missile_type_;
}

void TankTransformer::set_missile_type(std::string missile_type)
{
    missile_type_ = missile_type;
}


bool TankTransformer::is_driving()
{
    return true;
}


