//
// Created by Massimiliano Ziccardi on 13/03/2020.
//

#ifndef NRPE_NRPEV3RESPONSE_HPP
#define NRPE_NRPEV3RESPONSE_HPP

#include "NRPEV3AbstractPacket.hpp"

class NRPEV3Response : public NRPEV3AbstractPacket {
public:
    NRPEV3Response(int16_t resultCode, std::string message)
            : NRPEV3AbstractPacket(2, 0, resultCode, 0, std::shared_ptr<char>(messageToBuffer(message)), message.length(), std::shared_ptr<char>(new char[3]{0,0,0}), 3) {
        updateCRC();
    }

    virtual ~NRPEV3Response() {
    }

private:
    static char* messageToBuffer(std::string msg) {
        char* buf = new char[msg.length()]();
        memcpy(buf, msg.data(), msg.length());
        return buf;
    }
};


#endif //NRPE_NRPEV3RESPONSE_HPP
