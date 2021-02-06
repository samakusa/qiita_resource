#pragma once
#include <iostream>

class Bitboard {
    public:
        Bitboard();
        Bitboard(uint64_t d);
        Bitboard(uint64_t u, uint64_t d);
        uint64_t GetU() const;
        uint64_t GetD() const;

    private:
        uint64_t bb[2];
};
