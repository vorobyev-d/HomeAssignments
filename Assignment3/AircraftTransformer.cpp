/*
Vorobyev Dmitriy | st140149@student.spbu.ru
Assignment 4
*/


#include "AircraftTransformer.h"


AircraftTransformer::AircraftTransformer(std::string name, int power, int ammo, int health,
        bool is_ready_to_fight, std::string engine_type, Operator* transformer_operator,
        int max_speed, bool has_missiles)
    : Transformer(name, power, ammo, health, is_ready_to_fight, engine_type, transformer_operator),
      max_speed_(max_speed), has_missiles_(has_missiles) {}

AircraftTransformer::AircraftTransformer(int power, int ammo, std::string engine_type, bool has_missiles)
: Transformer(power, ammo, engine_type), has_missiles_(has_missiles) {}


int AircraftTransformer::get_max_speed()
{
    return max_speed_;
}

void AircraftTransformer::set_max_speed(int max_speed)
{
    max_speed_ = max_speed;
}


bool AircraftTransformer::get_has_missiles()
{
    return has_missiles_;
}

void AircraftTransformer::set_has_missiles(bool has_missiles)
{
    has_missiles_ = has_missiles;
}


bool AircraftTransformer::is_flying()
{
    return true;
}


void AircraftTransformer::ultimate_ability()
{
    std::cout << "AircraftTransformer::ultimate_ability" << std::endl;
}

void AircraftTransformer::defence_mode()
{
    std::cout << "AircraftTransformer::defence_mode" << std::endl;
}

void AircraftTransformer::transformer_info()
{
    std::cout << "AircraftTransformer::transformer_info" << std::endl;
}

void AircraftTransformer::output(std::ostream& os)
{
    os << "AircraftTransformer";
}