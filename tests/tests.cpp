#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include <memory>

#include "../include/fruit.hpp"

namespace shm_test
{

    constexpr char FRUIT_NAME[] = "Banana";
    constexpr size_t fruitAmount = 20;
    constexpr size_t basePrice = 10;
    constexpr size_t expirationDate = 10;

    struct FruitTest : public testing::Test {
        Fruit *fruit;
        void SetUp() { fruit = new Fruit(FRUIT_NAME, fruitAmount, basePrice, expirationDate); };
        void TearDown() { delete fruit;} 

    };

    TEST_F(FruitTest, ShouldInitFruit)
    {
        EXPECT_EQ(fruit->getName(), FRUIT_NAME);
        EXPECT_EQ(fruit->getAmount(), fruitAmount);
        EXPECT_EQ(fruit->getBasePrice(), basePrice);
    }

    TEST_F(FruitTest, changeExpirationDate) {
        constexpr size_t expected = expirationDate - 1;
        fruit--;
        EXPECT_EQ(fruit->getPurchaseData(), expected);
    }
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}