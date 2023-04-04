#pragma once

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "../include/ship.hpp"

class ShipMock : public Ship
{
public:
    MOCK_METHOD(size_t, getMaxCrew, (), (const));
    MOCK_METHOD(size_t, getCrew, (), (const));
    MOCK_METHOD(std::string, getName, (), (const));
    MOCK_METHOD(size_t, getId, (), (const));
    MOCK_METHOD(void, setName,(const std::string));
    MOCK_METHOD(void, addCargo, (const std::shared_ptr<Cargo>&, size_t));
    MOCK_METHOD(void, unload,(const std::shared_ptr<Cargo> &, size_t ));
    MOCK_METHOD(void, load,(const std::shared_ptr<Cargo> &apple, int));
    
};