//
// Created by Massimiliano Ziccardi on 13/03/2020.
//

#ifndef NRPE_NRPEV3ABSTRACTPACKET_HPP
#define NRPE_NRPEV3ABSTRACTPACKET_HPP

#include <utility>


#include "../Packet.hpp"

class NRPEV3AbstractPacket : public Packet {
public:
    NRPEV3AbstractPacket(int16_t type,
            u_int32_t crc32,
            int16_t resultCode,
            int16_t alignment,
            std::shared_ptr<char> buffer,
            u_int32_t bufferLength,
            std::shared_ptr<char> padding,
            int16_t paddingLength)
        : Packet(3, type, crc32, resultCode, alignment, std::move(buffer), bufferLength, std::move(padding), paddingLength)
    {}
    ~NRPEV3AbstractPacket() override = default;
protected:
    virtual u_int32_t crc32() const override;
};


#endif //NRPE_NRPEV3ABSTRACTPACKET_HPP
