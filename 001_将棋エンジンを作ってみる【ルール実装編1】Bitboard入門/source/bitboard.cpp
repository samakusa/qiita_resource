#include <iostream>

#include "bitboard.h"

Bitboard::Bitboard() { this->bb[1] = 0; this->bb[0] = 0; }
Bitboard::Bitboard(uint64_t d) { this->bb[1] = 0; this->bb[0] = d; }
Bitboard::Bitboard(uint64_t u, uint64_t d) { this->bb[1] = u; this->bb[0] = d;}
uint64_t Bitboard::GetU() const { return this->bb[1]; }
uint64_t Bitboard::GetD() const { return this->bb[0]; }

#ifdef UNIT_TEST_BITBOARD
int main(int argc, char **argv) {
    Bitboard bb0 = Bitboard();
    std::cout << "bb0.GetU()=" << bb0.GetU() << ",bb0.GetD()=" << bb0.GetD() << std::endl;

    Bitboard bb1 = Bitboard(1);
    std::cout << "bb1.GetU()=" << bb1.GetU() << ",bb1.GetD()=" << bb1.GetD() << std::endl;

    Bitboard bb2 = Bitboard(1, 1);
    std::cout << "bb2.GetU()=" << bb2.GetU() << ",bb2.GetD()=" << bb2.GetD() << std::endl;

}
#endif // UNIT_TEST_BITBOARD
