#include <iostream>
#include <iomanip>

#include "bitboard.h"

Bitboard::Bitboard() { this->bb[UPPER] = 0; this->bb[LOWER] = 0; }
Bitboard::Bitboard(uint64_t l) { this->bb[UPPER] = 0; this->bb[LOWER] = l; }
Bitboard::Bitboard(uint64_t u, uint64_t l) { this->bb[UPPER] = u; this->bb[LOWER] = l; }
uint64_t Bitboard::GetU() const { return this->bb[UPPER]; }
uint64_t Bitboard::GetL() const { return this->bb[LOWER]; }

#ifdef UNIT_TEST_BITBOARD
const int BOARD_WIDTH = 9;
const int UPPER_BIT = 64;
enum { FILE_1, FILE_2, FILE_3, FILE_4, FILE_5, FILE_6, FILE_7, FILE_8, FILE_9, FILE_NB };
enum { RANK_1, RANK_2, RANK_3, RANK_4, RANK_5, RANK_6, RANK_7, RANK_8, RANK_9, RANK_NB };

void Print(Bitboard bb) {
    uint64_t u = bb.GetU(), d = bb.GetL();
    for (int r = RANK_1; r < RANK_NB; r++) {
        for (int f = FILE_9; f >= FILE_1; f--) {
            int shift = f * BOARD_WIDTH + r;
            if (shift < UPPER_BIT) {
                std::cout << ((d & ((uint64_t)1 << shift)) ? "*" : ".");
            }
            else {
                shift -= UPPER_BIT;
                std::cout << ((u & ((uint64_t)1 << shift)) ? "*" : ".");
            }
            std::cout << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

int main(int argc, char **argv) {

    Bitboard bb0 = Bitboard();
    std::cout << "bb0.GetU()=0x" << std::setw(16) << std::setfill('0') << std::hex << bb0.GetU() << std::endl;
    std::cout << "bb0.GetL()=0x" << std::setw(16) << std::setfill('0') << std::hex << bb0.GetL() << std::endl;
    Print(bb0);

    Bitboard bb1 = Bitboard(1);
    std::cout << "bb1.GetU()=0x" << std::setw(16) << std::setfill('0') << std::hex << bb1.GetU() << std::endl;
    std::cout << "bb1.GetL()=0x" << std::setw(16) << std::setfill('0') << std::hex << bb1.GetL() << std::endl;
    Print(bb1);

    Bitboard bb2 = Bitboard(1, 1);
    std::cout << "bb2.GetU()=0x" << std::setw(16) << std::setfill('0') << std::hex << bb2.GetU() << std::endl;
    std::cout << "bb2.GetL()=0x" << std::setw(16) << std::setfill('0') << std::hex << bb2.GetL() << std::endl;
    Print(bb2);

    // 初期配置における自分の駒の位置
    Bitboard bb3 = Bitboard(0x140E0, 0x5028140A05038140);
    std::cout << "bb3.GetU()=0x" << std::setw(16) << std::setfill('0') << std::hex << bb3.GetU() << std::endl;
    std::cout << "bb3.GetL()=0x" << std::setw(16) << std::setfill('0') << std::hex << bb3.GetL() << std::endl;
    Print(bb3);

    // 初期配置における相手の駒の配置
    Bitboard bb4 = Bitboard(0x503, 0x8140A05028140E05);
    std::cout << "bb4.GetU()=0x" << std::setw(16) << std::setfill('0') << std::hex << bb4.GetU() << std::endl;
    std::cout << "bb4.GetL()=0x" << std::setw(16) << std::setfill('0') << std::hex << bb4.GetL() << std::endl;
    Print(bb4);

    // 初期配置における全ての駒の配置
    Bitboard bb5 = Bitboard(0x145E3, 0xD168B45A2D178F45);
    std::cout << "bb5.GetU()=0x" << std::setw(16) << std::setfill('0') << std::hex << bb5.GetU() << std::endl;
    std::cout << "bb5.GetL()=0x" << std::setw(16) << std::setfill('0') << std::hex << bb5.GetL() << std::endl;
    Print(bb5);

    // 初期配置における全ての歩の配置
    Bitboard bb6 = Bitboard(0x4422, 0x1108844221108844);
    std::cout << "bb6.GetU()=0x" << std::setw(16) << std::setfill('0') << std::hex << bb6.GetU() << std::endl;
    std::cout << "bb6.GetL()=0x" << std::setw(16) << std::setfill('0') << std::hex << bb6.GetL() << std::endl;
    Print(bb6);

    // 初期配置における自分の歩の配置
    Bitboard bb7 = Bitboard(0x4020, 0x1008040201008040);
    std::cout << "bb7.GetU()=0x" << std::setw(16) << std::setfill('0') << std::hex << bb7.GetU() << std::endl;
    std::cout << "bb7.GetL()=0x" << std::setw(16) << std::setfill('0') << std::hex << bb7.GetL() << std::endl;
    Print(bb7);

}
#endif // UNIT_TEST_BITBOARD
