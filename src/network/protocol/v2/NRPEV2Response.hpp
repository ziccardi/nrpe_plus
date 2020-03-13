//
// Created by Massimiliano Ziccardi on 13/03/2020.
//

#ifndef NRPE_NRPEV2RESPONSE_HPP
#define NRPE_NRPEV2RESPONSE_HPP

#include "NRPEV2AbstractPacket.hpp"

class NRPEV2Response : public NRPEV2AbstractPacket {
public:
    NRPEV2Response(int16_t resultCode, std::string message)
    : NRPEV2AbstractPacket(2, 0, resultCode, std::shared_ptr<char>(messageToBuffer(message)), std::shared_ptr<char>(new char[2]())) {
        updateCRC();
    }

    virtual ~NRPEV2Response() {
    }

private:
    static char* messageToBuffer(std::string msg) {
        char* buf = new char[MAX_PACKETBUFFER_LENGTH]();
        memcpy(buf, msg.data(), msg.length());
        return buf;
    }
};


#endif //NRPE_NRPEV2RESPONSE_HPP
