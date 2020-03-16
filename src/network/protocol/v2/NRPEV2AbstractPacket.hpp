//
// Created by Massimiliano Ziccardi on 13/03/2020.
//

#ifndef NRPE_NRPEV2ABSTRACTPACKET_HPP
#define NRPE_NRPEV2ABSTRACTPACKET_HPP

#include <utility>


#include "../Packet.hpp"

#define MAX_PACKETBUFFER_LENGTH 1024

class NRPEV2AbstractPacket : public Packet {
public:
    NRPEV2AbstractPacket(int16_t type, u_int32_t crc32, int16_t resultCode, std::shared_ptr<char> buffer, std::shared_ptr<char> padding)
        : Packet(2, type, crc32, resultCode, 0, std::move(buffer), MAX_PACKETBUFFER_LENGTH, std::move(padding), 2)
    {}
    ~NRPEV2AbstractPacket() override = default;
protected:
    virtual u_int32_t crc32() const override ;
};


#endif //NRPE_NRPEV2ABSTRACTPACKET_HPP
