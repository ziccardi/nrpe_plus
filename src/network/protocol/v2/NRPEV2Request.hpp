//
// Created by Massimiliano Ziccardi on 13/03/2020.
//

#ifndef NRPE_NRPEV2REQUEST_HPP
#define NRPE_NRPEV2REQUEST_HPP

#include "NRPEV2AbstractPacket.hpp"

class NRPEV2Request : public NRPEV2AbstractPacket {
public:
    NRPEV2Request(u_int32_t crc32, int16_t resultCode, std::shared_ptr<char> buffer, std::shared_ptr<char> padding)
        : NRPEV2AbstractPacket(1, crc32, resultCode, buffer, padding) {}
};


#endif //NRPE_NRPEV2REQUEST_HPP
