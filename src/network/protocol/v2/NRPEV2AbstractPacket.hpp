//
// Created by Massimiliano Ziccardi on 13/03/2020.
//

#ifndef NRPE_NRPEV2ABSTRACTPACKET_HPP
#define NRPE_NRPEV2ABSTRACTPACKET_HPP

#include "../Packet.hpp"

#define MAX_PACKETBUFFER_LENGTH 1024

class NRPEV2AbstractPacket : public Packet {
public:
    NRPEV2AbstractPacket(int16_t type, u_int32_t crc32, int16_t resultCode, std::shared_ptr<char> buffer, std::shared_ptr<char> padding)
        : Packet(2, type, crc32, resultCode, 0, buffer, MAX_PACKETBUFFER_LENGTH, padding, 2)
    {}
    virtual ~NRPEV2AbstractPacket() {}
protected:
    virtual u_int32_t crc32() const;
};


#endif //NRPE_NRPEV2ABSTRACTPACKET_HPP
