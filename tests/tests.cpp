#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include <memory>

#include "../include/fruit.hpp"
#include "../include/time.hpp"
#include "../include/ship.hpp"
#include "../include/player.hpp"

namespace shm_test
{

    constexpr char FRUIT_NAME[] = "Banana";
    constexpr size_t fruitAmount = 20;
    constexpr size_t basePrice = 10;
    constexpr size_t expirationDate = 10;

    Fruit fruit(FRUIT_NAME, fruitAmount, basePrice, expirationDate, std::make_shared<Time>());
    TEST(FruitTest, ShouldInitFruit)
    {
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

    Ship ship(SHIP_CAPACITY, SHIP_MAX_CREW, SHIP_CREW, SHIP_SPEED, SHIP_NAME, SHIP_ID, std::make_shared<Time>());
    TEST(ShipTest, ShouldInitShip)
    {
        EXPECT_EQ(ship.getId(), SHIP_ID);
        EXPECT_EQ(ship.getMaxCrew(), SHIP_MAX_CREW); // next test not recommended here
        EXPECT_EQ(ship.getSpeed(), SHIP_SPEED);
        EXPECT_EQ(ship.getCapacity(), SHIP_CAPACITY);
    }

    TEST(ShipTest, shouldChangeName)
    {
        const std::string newName = "Black Widow";
        ship.setName(newName);
        EXPECT_EQ(ship.getName(), newName);
    }

    TEST(ShipTest, shouldLoad)
    {
        const size_t alcocholAmount = 50;
        auto mock = std::make_shared<Fruit>();
    }

    class ShipMock : public Ship
    {
    public:
        ShipMock() = default;
        ~ShipMock() override = default;

        MOCK_CONST_METHOD0(getCapacity, size_t());
        MOCK_CONST_METHOD0(getMaxCrew, size_t());
        MOCK_CONST_METHOD0(getSeed, size_t());
        MOCK_CONST_METHOD0(getCrew, size_t());
        MOCK_CONST_METHOD0(getName, std::string());
        MOCK_CONST_METHOD0(getId, size_t());

        MOCK_METHOD1(setName, void(const std::string &name));
        MOCK_METHOD2(addCargo, void(const std::shared_ptr<Cargo> &cargo, size_t amount));
        MOCK_METHOD2(unload, void(const std::shared_ptr<Cargo> &cargo, size_t amount));
        MOCK_METHOD2(load, void(const std::shared_ptr<Cargo> &cargo, size_t amount));
    };

    TEST(PlayerTest,shouldBuyCargo) {
        auto mock = std::make_shared<ShipMock>();
        auto* mock_ptr = mock.get();
        auto player = std::make_shared<Player>(std::move(mock));
        Fruit fruit("Apple", 20, 12 , 10, std::make_shared<Time>());
        Fruit peach("Peach", 20, 12 , 10, std::make_shared<Time>());

        
        EXPECT_CALL(*mock_ptr, load(std::make_shared<Fruit>(fruit), 5));
        player->buy(std::make_shared<Fruit>(peach), 5);
    }
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}