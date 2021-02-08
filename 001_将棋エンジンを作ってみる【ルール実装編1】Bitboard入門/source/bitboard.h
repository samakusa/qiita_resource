#pragma once
#include <iostream>

class Bitboard {
    public:
        Bitboard();
        Bitboard(uint64_t l);
        Bitboard(uint64_t u, uint64_t l);
        uint64_t GetU() const;
        uint64_t GetL() const;

    private:
        const int LOWER = 0;
        const int UPPER = 1;
        uint64_t bb[2];
};
