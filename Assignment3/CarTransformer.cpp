/*
Vorobyev Dmitriy | st140149@student.spbu.ru
Assignment 4
*/


#include "CarTransformer.h"

#include <string>


CarTransformer::CarTransformer(std::string name, int power, int ammo, int health,
                               bool is_ready_to_fight, std::string engine_type, Operator* transformer_operator,
                               int max_speed, std::string car_type)
    : Transformer(name, power, ammo, health, is_ready_to_fight, engine_type, transformer_operator),
      max_speed_(max_speed), car_type_(car_type) {}

CarTransformer::CarTransformer(int power, int ammo, int max_speed, std::string engine_type) 
: Transformer(power, ammo, engine_type), max_speed_(max_speed) {}


int CarTransformer::get_max_speed()
{
    return max_speed_;
}

void CarTransformer::set_max_speed(int max_speed)
{
    max_speed_ = max_speed;
}


std::string CarTransformer::get_car_type()
{
    return car_type_;
}

void CarTransformer::set_car_type(std::string car_type)
{
    car_type_ = car_type;
}


bool CarTransformer::is_driving()
{
    return true;
}

void CarTransformer::ultimate_ability()
{
    std::cout << "CarTransformer::ultimate_ability" << std::endl;
}

void CarTransformer::defence_mode()
{
    std::cout << "CarTransformer::defence_mode" << std::endl;
}

void CarTransformer::transformer_info()
{
    std::cout << "CarTransformer::transformer_info" << std::endl;
}

void CarTransformer::output(std::ostream& os)
{
    os << "CarTransformer";
}