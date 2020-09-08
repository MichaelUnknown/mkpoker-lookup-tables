// return the 3/5 highest cards, i.e. set bits
//
// the lowest 13 bits represent the cards (2..A) of a given hand

#include <iomanip>
#include <iostream>

auto top_x(int x, int num_linebreak) -> void
{
    std::cout << "#pragma once\n\n#include <cstdint>\n\n// clang format off\nconstexpr uint16_t mkpoker_table_top" << x << "[] = {\n    ";
    for (int cards = 0; cards < int(1) << 13; ++cards)
    {
        int count = 0;
        int ret = cards;

        std::cout << std::setfill(' ') << std::setw(4);

        for (int pos = 12; pos >= 0; --pos)
        {
            // count until we found the x highest cards, then reset the remaining bits
            if (cards & int(1) << pos)
            {
                ++count;
                if (count == x)
                {
                    int unset_bits = 0b0001'1111'1111'1111 >> (13 - pos);
                    ret = cards & ~unset_bits;
                    break;
                }
            }
        }

        std::cout << ret;

        if (cards == (int(1) << 13) - 1)
        {
            std::cout << "\n";
        }
        else if ((cards + 1) % num_linebreak == 0)
        {
            std::cout << ",\n    ";
        }
        else
        {
            std::cout << ", ";
        }
    }
    std::cout << "};\n//clang format on\n";
}


auto main() -> int
{
    constexpr int num_linebreak = 16;

    top_x(3, num_linebreak);
    std::cout << "\n\n";
    top_x(5, num_linebreak);

    return 0;
}