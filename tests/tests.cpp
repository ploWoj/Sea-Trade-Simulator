#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include <memory>

#include "../include/fruit.hpp"
#include "../include/ship.hpp"

namespace fruit_test
{

    constexpr char FRUIT_NAME[] = "Banana";
    constexpr size_t fruitAmount = 20;
    constexpr size_t basePrice = 10;
    constexpr size_t expirationDate = 10;

    struct FruitTest : public testing::Test
    {
        Fruit *banana;
        void SetUp() { banana = new Fruit(FRUIT_NAME, fruitAmount, basePrice, expirationDate); }
    };

    TEST_F(FruitTest, ShouldInitFruit)
    {
        EXPECT_EQ(banana->getBasePrice(), 10);
        EXPECT_EQ(banana->getAmount(), 20);
        EXPECT_EQ(banana->getExpirationDate(), 10);
    }

    TEST_F(FruitTest, ShouldLessExpirationDate)
    {
        banana->nextDay();
        EXPECT_EQ(banana->getPurchaseData(), 9);
    }
    constexpr size_t capacity = 5000;
    constexpr size_t maxCrew = 10;
    constexpr size_t crew = 5;
    constexpr size_t speed = 10;
    constexpr char name[] = "Black Widow";
    constexpr size_t id = 1;

    struct ShipTest : public testing::Test
    {
        std::shared_ptr<Fruit> cargo1 = std::make_shared<Fruit>("Banan", 10, 10, 10);
        Ship *ship;
        void SetUp()
        {
            ship = new Ship(capacity, maxCrew, crew, speed, name, id);
            
        };
    };

    TEST_F(ShipTest, ShouldBuyCargo) {
        

    //     ship->addCargo(cargo1, 5);
    }
}
int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
