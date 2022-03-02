#include "gtest/gtest.h"
#include <memory>

#include "../include/fruit.hpp"
#include "../include/time.hpp"
#include "../include/ship.hpp"

namespace shm_test {

constexpr char FRUIT_NAME[] = "Banana";
constexpr size_t fruitAmount = 20;
constexpr size_t basePrice = 10;
constexpr size_t expirationDate = 10;

Fruit fruit(FRUIT_NAME, fruitAmount, basePrice, expirationDate, std::make_shared<Time>());
TEST(FruitTest, ShouldInitFruit){
    EXPECT_EQ(fruit.getName(), FRUIT_NAME);
    EXPECT_EQ(fruit.getAmount(), fruitAmount);
    EXPECT_EQ(fruit.getBasePrice(), basePrice);
}


constexpr size_t SHIP_CAPACITY = 500;
constexpr char SHIP_NAME[] = "Titanic";
constexpr size_t SHIP_MAX_CREW = 20;
constexpr size_t SHIP_SPEED = 666;
constexpr size_t SHIP_ID = 1;
constexpr size_t AVAILABLE_SPACE = 100;
constexpr size_t SHIP_CREW = 5;

Ship ship(SHIP_CAPACITY,  SHIP_MAX_CREW,  SHIP_CREW, SHIP_SPEED, SHIP_NAME,  SHIP_ID, std::make_shared<Time>());
TEST(ShipTest, ShouldInitShip) {
    EXPECT_EQ(ship.getId(), SHIP_ID);
    EXPECT_EQ(ship.getMaxCrew(), SHIP_MAX_CREW);         // next test not recommended here
    EXPECT_EQ(ship.getSpeed(), SHIP_SPEED);
    EXPECT_EQ(ship.getCapacity(), SHIP_CAPACITY);
}

}