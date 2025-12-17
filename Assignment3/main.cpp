/*
Vorobyev Dmitriy | st140149@student.spbu.ru
Assignment 3
*/


#include <gtest/gtest.h>

#include "Transformer.h"
#include "TankTransformer.h"
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


TEST(TransformerTest, ConstructorAndBasicFields)
{
    Operator op("Valera");
    Transformer transformer("MrTransformer", 50, 100, 200, true, "V121", &op);

    EXPECT_EQ(transformer.get_name(), "MrTransformer");
    EXPECT_EQ(transformer.get_power(), 50);
    EXPECT_EQ(transformer.get_ammo(), 100);
    EXPECT_EQ(transformer.get_health(), 200);
    EXPECT_TRUE(transformer.get_is_ready_to_fight());
    EXPECT_EQ((*transformer.get_operator()).get_name(), "Valera");
    EXPECT_EQ(transformer.get_engine().get_engine_type(), "V121");
}

TEST(TransformerTest, CompositionEngine)
{
    Operator op("Valeriy");
    Transformer transformer("MrRobot", 60, 120, 254, true, "Hybrid", &op);

    EXPECT_EQ(transformer.get_engine().get_engine_type(), "Hybrid");

    transformer.set_engine("Hydrogen");
    EXPECT_EQ(transformer.get_engine().get_engine_type(), "Hydrogen");
}

TEST(TransformerTest, MethodsReturnTrue)
{
    Operator op("Anton");
    Transformer transformer("OptimusPride", 66, 123, 111, true, "Atomic", &op);

    EXPECT_TRUE(transformer.fire());
    EXPECT_TRUE(transformer.transform());
    EXPECT_TRUE(transformer.reload());
}


TEST(TankTransformerTest, ConstructorAndSpecificFields)
{
    Operator op("Max");
    TankTransformer tank("MrTank", 88, 99, 111, true, "V12", &op, 5, "Gigamegamissile");

    EXPECT_EQ(tank.get_name(), "MrTank");
    EXPECT_EQ(tank.get_power(), 88);
    EXPECT_EQ(tank.get_ammo(), 99);
    EXPECT_EQ(tank.get_health(), 111);
    EXPECT_TRUE(tank.get_is_ready_to_fight());
    EXPECT_EQ(tank.get_operator()->get_name(), "Max");
    EXPECT_EQ(tank.get_engine().get_engine_type(), "V12");

    EXPECT_EQ(tank.get_armour_level(), 5);
    EXPECT_EQ(tank.get_missile_type(), "Gigamegamissile");
}

TEST(TankTransformerTest, SettersWork)
{
    Operator op("Valentin");
    TankTransformer tank("Tank", 80, 200, 300, true, "V12", &op, 5, "BigMissile");

    tank.set_armour_level(10);
    tank.set_missile_type("VeryBigMissile");

    EXPECT_EQ(tank.get_armour_level(), 10);
    EXPECT_EQ(tank.get_missile_type(), "VeryBigMissile");
}

TEST(TankTransformerTest, IsDriving)
{
    Operator op("Nikolay");
    TankTransformer tank("MrTank", 80, 200, 300, true, "V12", &op, 5, "BigMissile");

    EXPECT_TRUE(tank.is_driving());
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
