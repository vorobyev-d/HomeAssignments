/*
Vorobyev Dmitriy | st140149@student.spbu.ru
Assignment 3
*/


#ifndef TANK_TRANSFORMER_H
#define TANK_TRANSFORMER_H


#include "Transformer.h"

#include <string>


class TankTransformer : public Transformer
{
public:
    TankTransformer(std::string name, int power, int ammo, int health, bool is_ready_to_fight, std::string engine_type, Operator* transformer_operator, int armour_level, std::string missile_type);


    int get_armour_level();
    void set_armour_level(int armour_level);

    std::string get_missile_type();
    void set_missile_type(std::string missile_type);

    bool is_driving();

private:
    int armour_level_;
    std::string missile_type_;
};

#endif