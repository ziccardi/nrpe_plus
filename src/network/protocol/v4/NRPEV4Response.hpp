//
// Created by Massimiliano Ziccardi on 13/03/2020.
//

#ifndef NRPE_NRPEV4RESPONSE_HPP
#define NRPE_NRPEV4RESPONSE_HPP

#include "NRPEV4AbstractPacket.hpp"

class NRPEV4Response : public NRPEV4AbstractPacket {
public:
    NRPEV4Response(int16_t resultCode, const std::string& message)
            : NRPEV4AbstractPacket(2, 0, resultCode, 0,
                    std::shared_ptr<char>(messageToBuffer(message)), message.length(),
                    std::shared_ptr<char>(new char[0]), 0) {
        updateCRC();
    }

    virtual ~NRPEV4Response() {
    }

private:
    static char* messageToBuffer(const std::string& msg) {
        char* buf = new char[msg.length() + 1]();
        memcpy(buf, msg.data(), msg.length());
        return buf;
    }
};

#endif //NRPE_NRPEV4RESPONSE_HPP
