/*
Vorobyev Dmitriy | st140149@student.spbu.ru
Assignment 3
*/


#ifndef AIRCRAFT_TRANSFORMER_H
#define AIRCRAFT_TRANSFORMER_H


#include "Transformer.h"

#include <string>


class AircraftTransformer : public Transformer
{
public:
    AircraftTransformer(std::string name, int power, int ammo, int health, bool is_ready_to_fight, std::string engine_type, Operator* transformer_operator, int max_speed, bool has_missiles);


    int get_max_speed();
    void set_max_speed(int max_speed);

    bool get_has_missiles();
    void set_has_missiles(bool has_missiles);

    bool is_flying();

private:
    int max_speed_;
    bool has_missiles_;
};

#endif