// find if there is a straight, and if yes, return the rank (i.e. nine-high, queen-high etc.)
//
// the lowest 13 bits represent the ranks (2..A) of a given hand

#include <iomanip>
#include <iostream>

auto main() -> int
{
    constexpr int num_linebreak = 32;

    std::cout << "#pragma once\n\n#include <cstdint>\n\n// clang format off\nconstexpr int8_t mkpoker_straights_table[] = {\n    ";
    for (int cards = 0; cards < int(1) << 13; ++cards)
    {
        int rank = 12;
        int count = 0;

        std::cout << std::setfill(' ') << std::setw(2);

        for (int pos = 12; pos >= 0; --pos)
        {
            // if the bit at position X is set => increase count, if not => reset

            // special case lowest bit: check if there is a straight with a low ace (A2345) or 23456
            if (pos == 0)
            {
                if (cards & int(1) && (count == 4 || (count == 3 && cards & int(1) << 12)))
                {
                    break;
                }

                // else: no flush at all
                rank = 0;
                break;
            }

            if (cards & int(1) << pos)
            {
                ++count;
                if (count == 5)
                {
                    break;
                }
            }
            else
            {
                rank = pos - 1;
                count = 0;
            }
        }

        std::cout << rank;

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

    return 0;
}