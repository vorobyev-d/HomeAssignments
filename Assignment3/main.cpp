/*
Vorobyev Dmitriy | st140149@student.spbu.ru
Assignment 4
*/


#include <gtest/gtest.h>

#include "Transformer.h"
#include "TankTransformer.h"
#include "CarTransformer.h"
#include "AircraftTransformer.h"
#include "Operator.h"
#include "Engine.h"


TEST(EngineTest, GetSetType)
{
    Engine engine("V8");
    EXPECT_EQ(engine.get_engine_type(), "V8");

    engine.set_engine_type("V12");
    EXPECT_EQ(engine.get_engine_type(), "V12");
}


TEST(OperatorTest, GetName)
{
    Operator op("Valera");
    EXPECT_EQ(op.get_name(), "Valera");
}

TEST(TransformerTest, AllBaseGetSet)
{
    Operator op("Stas");
    TankTransformer transformer("Tank", 10, 20, 30, true, "Diesel", &op, 5, "Rocket");

    EXPECT_EQ(transformer.get_name(), "Tank");
    EXPECT_EQ(transformer.get_power(), 10);
    EXPECT_EQ(transformer.get_ammo(), 20);
    EXPECT_EQ(transformer.get_health(), 30);
    EXPECT_TRUE(transformer.get_is_ready_to_fight());
    EXPECT_EQ(transformer.get_operator()->get_name(), "Stas");
    EXPECT_EQ(transformer.get_engine().get_engine_type(), "Diesel");

    transformer.set_name("NewTank");
    transformer.set_power(50);
    transformer.set_ammo(100);
    transformer.set_health(200);
    transformer.set_is_ready_to_fight(false);
    transformer.set_engine("Electric");

    EXPECT_EQ(transformer.get_name(), "NewTank");
    EXPECT_EQ(transformer.get_power(), 50);
    EXPECT_EQ(transformer.get_ammo(), 100);
    EXPECT_EQ(transformer.get_health(), 200);
    EXPECT_FALSE(transformer.get_is_ready_to_fight());
    EXPECT_EQ(transformer.get_engine().get_engine_type(), "Electric");
}

TEST(TransformerTest, ActionMethodsReturnTrue)
{
    Operator op("Anthony Soprano");
    TankTransformer transformer("Tank", 1, 1, 1, true, "X", &op, 1, "M");

    EXPECT_TRUE(transformer.fire());
    EXPECT_TRUE(transformer.transform());
    EXPECT_TRUE(transformer.reload());
}

TEST(TransformerTest, BaseVoidMethodsOutput)
{
    Operator op("Leonid");
    TankTransformer transformer("Tank", 1, 1, 1, true, "X", &op, 1, "M");

    testing::internal::CaptureStdout();
    transformer.defence_mode();
    transformer.transformer_info();
    std::string out = testing::internal::GetCapturedStdout();

    EXPECT_NE(out.find("TankTransformer::defence_mode"), std::string::npos);
    EXPECT_NE(out.find("TankTransformer::transformer_info"), std::string::npos);
}

TEST(TransformerTest, OutputOperator)
{
    Operator op("Bob");
    TankTransformer transformer("Tank", 1, 1, 1, true, "X", &op, 1, "M");

    std::stringstream ss;
    ss << transformer;
    EXPECT_EQ(ss.str(), "TankTransformer");
}

TEST(TankTransformerTest, GetSetTest)
{
    Operator op("Goga");
    TankTransformer tank_transformer("T",1,2,3,true,"X",&op,10,"Big");

    EXPECT_EQ(tank_transformer.get_armour_level(), 10);
    EXPECT_EQ(tank_transformer.get_missile_type(), "Big");

    tank_transformer.set_armour_level(20);
    tank_transformer.set_missile_type("Huge");

    EXPECT_EQ(tank_transformer.get_armour_level(), 20);
    EXPECT_EQ(tank_transformer.get_missile_type(), "Huge");
}

TEST(TankTransformerTest, IsDriving)
{
    Operator op("Sanchez");
    TankTransformer tank_transformer("T",1,2,3,true,"X",&op,10,"Big");
    EXPECT_TRUE(tank_transformer.is_driving());
}

TEST(TankTransformerTest, UltimateAbilityOutput)
{
    Operator op("Gleb");
    TankTransformer tank_transformer("T",1,2,3,true,"X",&op,10,"Big");

    testing::internal::CaptureStdout();
    tank_transformer.ultimate_ability();
    std::string out = testing::internal::GetCapturedStdout();
    EXPECT_NE(out.find("TankTransformer::ultimate_ability"), std::string::npos);
}

TEST(CarTransformerTest, AllMethods)
{
    Operator op("Donald");
    CarTransformer car_transformer("Car",1,2,3,true,"Gas",&op,200,"Sport");

    EXPECT_EQ(car_transformer.get_max_speed(), 200);
    EXPECT_EQ(car_transformer.get_car_type(), "Sport");

    car_transformer.set_max_speed(300);
    car_transformer.set_car_type("SUV");

    EXPECT_EQ(car_transformer.get_max_speed(), 300);
    EXPECT_EQ(car_transformer.get_car_type(), "SUV");
    EXPECT_TRUE(car_transformer.is_driving());

    testing::internal::CaptureStdout();
    car_transformer.ultimate_ability();
    car_transformer.defence_mode();
    car_transformer.transformer_info();
    std::string out = testing::internal::GetCapturedStdout();

    EXPECT_NE(out.find("CarTransformer::ultimate_ability"), std::string::npos);
    EXPECT_NE(out.find("CarTransformer::defence_mode"), std::string::npos);
    EXPECT_NE(out.find("CarTransformer::transformer_info"), std::string::npos);
}

TEST(AircraftTransformerTest, AllMethods)
{
    Operator op("A");
    AircraftTransformer aircraft_transformer("Jet",1,2,3,true,"Jet",&op,900,true);

    EXPECT_EQ(aircraft_transformer.get_max_speed(), 900);
    EXPECT_TRUE(aircraft_transformer.get_has_missiles());
    EXPECT_TRUE(aircraft_transformer.is_flying());

    aircraft_transformer.set_max_speed(1200);
    aircraft_transformer.set_has_missiles(false);

    EXPECT_EQ(aircraft_transformer.get_max_speed(), 1200);
    EXPECT_FALSE(aircraft_transformer.get_has_missiles());

    testing::internal::CaptureStdout();
    aircraft_transformer.ultimate_ability();
    aircraft_transformer.defence_mode();
    aircraft_transformer.transformer_info();
    std::string out = testing::internal::GetCapturedStdout();

    EXPECT_NE(out.find("AircraftTransformer::ultimate_ability"), std::string::npos);
    EXPECT_NE(out.find("AircraftTransformer::defence_mode"), std::string::npos);
    EXPECT_NE(out.find("AircraftTransformer::transformer_info"), std::string::npos);
}

TEST(PolymorphismTest, BasePointerCalls)
{
    Operator op("Veniamin");
    Transformer* tank_transformer = new TankTransformer("T",1,1,1,true,"X",&op,5,"M");

    EXPECT_TRUE(tank_transformer->transform());

    testing::internal::CaptureStdout();
    tank_transformer->ultimate_ability();
    std::string out = testing::internal::GetCapturedStdout();

    EXPECT_NE(out.find("TankTransformer"), std::string::npos);

    delete tank_transformer;
}

TEST(PolymorphismTest, VectorOfBasePointers)
{
    Operator op("Someone");
    std::vector<Transformer*> v;

    for (int i = 0; i < 3; ++i)
    {
        v.push_back(new TankTransformer(21, 21, 21, "BigEngine"));
        v.push_back(new CarTransformer(31, 31, 31, "SmthEngine"));
        v.push_back(new AircraftTransformer(33, 12, "reallybigengine", true));
    }

    for (Transformer* t : v)
    {
        EXPECT_TRUE(t->transform());
        t->ultimate_ability();
    }

    for (Transformer* t : v)
        delete t;
}


int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}