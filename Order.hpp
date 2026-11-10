#pragma once

#include <cstdint>

struct Order {
    uint64_t id;
    bool isBuy;
    int price;
    int quantity;
};