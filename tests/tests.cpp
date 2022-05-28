#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include <memory>

#include "../include/player.hpp"
#include "../include/fruit.hpp"
#include "shipMock.hpp"
#include "cargoMock.hpp"

using ::testing::DoAll;
using ::testing::Return;
using ::testing::SaveArg;
using ::testing::StrictMock;
using ::testing::Test;

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

    // TEST_F(ShipTest, ShouldBuyCargo)
    // {

    //     //     ship->addCargo(cargo1, 5);
    // }

    // class CargoTest : public Test
    // {
    //     void SetUp()
    //     {
    //         auto cargo = std::make_shared<CargoMock>();
    //         ship_ = std::make_shared<Ship>(capacity, maxCrew, crew, speed, name, id);
    //     }

    //     CargoMock* getCargo() const { return cargo_.get(); }
    //     Ship* getShip() const { return ship_.get(); }

    // private:
    //     std::shared_ptr<CargoMock> cargo_;
    //     std::shared_ptr<Ship> ship_;
    // };

    // TEST_F(CargoMock, ShouldReturnAmount) {
    //    getShip()->addCargo()

    // }

    constexpr size_t money = 50000;
    class PlayerTest : public Test
    {
    public:
        void SetUp()
        {
            auto ship_ = std::make_shared<ShipMock>();
            player_ = std::make_shared<Player>(ship_, money);
        }
        ShipMock *getShip() { return ship_.get(); }
        Player *getPlayer() const { return player_.get(); }

    private:
        std::shared_ptr<ShipMock> ship_;
        std::shared_ptr<Player> player_;
    };

    TEST_F(PlayerTest, ShuoldBuyItem)
    {
        constexpr const size_t amount = 50;
        std::shared_ptr<Fruit> apple = std::make_shared<Fruit>("apple", 100, 50, 20);
        constexpr size_t expected = money - (20 * 50);

        EXPECT_CALL(*getShip(), load(apple)).WillOnce(Return(nullptr));

        getPlayer()->buy(apple, 20)
        {
            EXPECT_EQ(getPlayer()->getMoney(), expected);
        }
    }

}
int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
