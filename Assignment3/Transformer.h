/*
Vorobyev Dmitriy | st140149@student.spbu.ru
Assignment 3
*/


#ifndef TRANSFORMER_H
#define TRANSFORMER_H


#include <string>

#include "Engine.h"
#include "Operator.h"


class Transformer
{
public:
    Transformer(std::string name, int power, int ammo, int health, bool is_ready_to_fight,
                std::string engine_type, Operator* transformer_operator);

    ~Transformer();


    std::string get_name();
    void set_name(std::string name);

    int get_power();
    void set_power(int power);

    int get_ammo();
    void set_ammo(int ammo);

    int get_health();
    void set_health(int health);

    bool get_is_ready_to_fight();
    void set_is_ready_to_fight(bool is_ready_to_fight);

    Engine get_engine();
    void set_engine(std::string engine_type);

    Operator* get_operator();
    void set_operator(Operator* transformer_operator);

    bool transform();
    bool fire();
    bool reload();

private:
    std::string name_;
    int power_;
    int ammo_;
    int health_;
    bool is_ready_to_fight_;
    Engine engine_;
    Operator* transformer_operator_;

};




#endif