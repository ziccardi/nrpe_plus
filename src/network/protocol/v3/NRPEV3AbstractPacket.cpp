//
// Created by Massimiliano Ziccardi on 13/03/2020.
//

#include <boost/crc.hpp>
#include <arpa/inet.h>
#include "NRPEV3AbstractPacket.hpp"

u_int32_t NRPEV3AbstractPacket::crc32() const {
    boost::crc_32_type crc;

    int16_t version = htons(getVersion());
    int16_t type = htons(getPacketType());
    u_int32_t crc32 = 0;
    int16_t result = 0;
    int16_t alignment = htons(getAlignment());;
    u_int32_t bufLen = htonl(getBufferLength());
    crc.process_bytes(&version, sizeof(version));
    crc.process_bytes(&type, sizeof(type));
    crc.process_bytes(&crc32, sizeof(crc32));
    crc.process_bytes(&result, sizeof(result));
    crc.process_bytes(&alignment, sizeof(alignment));
    crc.process_bytes(&bufLen, sizeof(bufLen));
    crc.process_bytes(getBuffer().get(), getBufferLength());
    crc.process_bytes(getPadding().get(), getPaddingLength());

    return crc.checksum();
}