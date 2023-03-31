#pragma once
#include <cmath>

class Coordinates
{
public:
    constexpr Coordinates(size_t positionX, size_t positionY)
        : positionX_(positionX), positionY_(positionY)
    {
    }

    constexpr void setPositionX(size_t positionX) { positionX_ = positionX; };

    constexpr size_t getPositionX() const { return positionX_; };

    constexpr void setPositionY(size_t positionY) { positionY_ = positionY; };
    constexpr size_t getPositionY() const { return positionY_; };

    constexpr bool operator==(const Coordinates &n_pos) const;

    constexpr size_t distance(const Coordinates &lhs, const Coordinates& rhs);
    

private:
    size_t positionX_;
    size_t positionY_;
};