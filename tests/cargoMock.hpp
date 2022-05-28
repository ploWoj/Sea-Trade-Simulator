#pragma once

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "../include/cargo.hpp"

class CargoMock : public Cargo {
    MOCK_METHOD(size_t, getAmount, (), (const));
    MOCK_METHOD(std::string, getName, (), (const));
    MOCK_METHOD(size_t, getBasePrice, (), (const));
};