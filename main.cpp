#include <iomanip>
#include <iostream>
#include <memory>

#include "include/alcohol.hpp"
#include "include/cargo.hpp"
#include "include/game.hpp"
#include "include/fruit.hpp"
#include "include/island.hpp"
#include "include/item.hpp"
#include "include/map.hpp"
#include "include/player.hpp"
#include "include/ship.hpp"
#include "include/store.hpp"
#include "include/time.hpp"

constexpr size_t start_money = 1'000'000;
constexpr size_t game_days = 100;
constexpr size_t final_goal = 2'000'000;

int main() {

    Game game(start_money, game_days, final_goal);
    game.startGame();

    return 0;
}