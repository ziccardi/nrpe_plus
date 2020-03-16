//
// Created by Massimiliano Ziccardi on 13/03/2020.
//

#ifndef NRPE_NRPEV4ABSTRACTPACKET_HPP
#define NRPE_NRPEV4ABSTRACTPACKET_HPP

#include <utility>


#include "../Packet.hpp"

class NRPEV4AbstractPacket : public Packet {
public:
    NRPEV4AbstractPacket(int16_t type,
        u_int32_t crc32,
        int16_t resultCode,
        int16_t alignment,
        std::shared_ptr<char> buffer,
        u_int32_t bufferLength,
        std::shared_ptr<char> padding,
        int16_t paddingLength)
        : Packet(4, type, crc32, resultCode, alignment, std::move(buffer), bufferLength, std::move(padding), paddingLength) {}

        ~NRPEV4AbstractPacket() override {}
protected:
    virtual u_int32_t crc32() const override;
};

#endif //NRPE_NRPEV4ABSTRACTPACKET_HPP
