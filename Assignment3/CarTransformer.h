/* 
Vorobyev Dmitriy | st140149@student.spbu.ru
Assignment 3
*/


#ifndef CAR_TRANSFORMER_H
#define CAR_TRANSFORMER_H


#include "Transformer.h"

#include <string>


class CarTransformer : public Transformer
{
    public:
        CarTransformer(std::string name, int power, int ammo, int health, bool is_ready_to_fight, std::string engine_type, Operator* transformer_operator, int max_speed, std::string car_type);


        int get_max_speed();
        void set_max_speed(int max_speed);

        std::string get_car_type();
        void set_car_type(std::string car_type);

        bool is_driving();

    private:
        int max_speed_;
        std::string car_type_;
};

#endif