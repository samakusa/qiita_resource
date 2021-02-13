#pragma once

#include <string>

const std::string ENGINE_NAME    = "shogi_neuron";
const std::string ENGINE_AUTHOR  = "samakusa";

class USI {
    public:
        USI();
        void Loop();

    private:
        enum ID { ID_NAME, ID_AUTHOR, ID_NB };
        void SendId(ID id);
        void SendUsiok();
        void SendReadyOk();
        void SendBestmove();
};
