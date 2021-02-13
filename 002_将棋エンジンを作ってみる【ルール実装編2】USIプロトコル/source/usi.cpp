#include "usi.h"

#include <iostream>
#include <string>
#include <cassert>

#include "string_ex.h"

USI::USI() {}

void USI::Loop() {
    StringEx cmd;

    while (std::getline(std::cin, cmd)) {
        std::vector<std::string> cmds = cmd.Split();

        if (cmds[0] == "quit") break;

        else if (cmds[0] == "usi") {
            SendId(ID_NAME);
            SendId(ID_AUTHOR);
            SendUsiok();
        }

        else if (cmds[0] == "isready")
            SendReadyOk();

        else if (cmds[0] == "usinewgame")
            continue;

        else if (cmds[0] == "position")
            continue;

        else if (cmds[0] == "go")
            SendBestmove();

        else if (cmds[0] == "gameover")
            continue;

        else std::cout << "invalid comannd: " + cmd << std::endl;
    }
}

void USI::SendId(ID id) {
    if (id == ID_NAME)
        std::cout << "id name " + ENGINE_NAME << std::endl;
    else if (id == ID_AUTHOR)
        std::cout << "id author " + ENGINE_AUTHOR << std::endl;
    else
        assert(false);
}

void USI::SendUsiok() {
    std::cout << "usiok" << std::endl;
}

void USI::SendReadyOk() {
    std::cout << "readyok" << std::endl;
}

void USI::SendBestmove() {
    std::cout << "bestmove resign" << std::endl;
}

#ifdef UNIT_TEST_USI
int main(int argc, char **argv) {
    USI usi = USI();
    usi.Loop();

    return 0;
}
#endif // UNIT_TEST_USI
