#pragma once

#include <cstdint>
#include <iostream>

class Tile
{
private:
    int8_t num{};

public:
    Tile(int8_t num) : num{ num } {}

    bool is_empty() const { return num == 0; }
    int8_t get_num() const { return num; }
};

std::ostream& operator<<(std::ostream& out, const Tile& tile);