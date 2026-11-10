#include "Order.hpp"

#include <map>
#include <list>
#include <unordered_map>
#include <iterator>
#include <cstdint>

struct OrderLocation {
    bool isBuy;
    int price;
    std::list<Order>::iterator it;
};

int main(){
    std::map<int, std::list<Order>, std::greater<int>> bids;
    std::map<int, std::list<Order>, std::less<int>> asks;
    std::unordered_map<uint64_t, OrderLocation> id_lookup;

    auto& bid_level = bids[100];

    bid_level.push_back({1, true, 100, 5});
    id_lookup[1] = {true, 100, std::prev(bid_level.end())};

    bid_level.push_back({2, true, 100, 5});
    id_lookup[2] = {true, 100, std::prev(bid_level.end())};

    auto& ask_level = asks[99];

    ask_level.push_back({3, false, 99, 10});
    id_lookup[3] = {false, 99, std::prev(ask_level.end())};
}