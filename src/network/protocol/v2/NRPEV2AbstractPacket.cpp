//
// Created by Massimiliano Ziccardi on 13/03/2020.
//

#include <boost/crc.hpp>
#include "NRPEV2AbstractPacket.hpp"
#include <arpa/inet.h>

u_int32_t NRPEV2AbstractPacket::crc32() const {
    boost::crc_32_type crc;

    int16_t version = htons(getVersion());
    int16_t type = htons(getPacketType());
    u_int32_t crc32 = 0;
    int16_t result = htons(getResultCode());
    crc.process_bytes(&version, sizeof(version));
    crc.process_bytes(&type, sizeof(type));
    crc.process_bytes(&crc32, sizeof(crc32));
    crc.process_bytes(&result, sizeof(result));
    crc.process_bytes(getBuffer().get(), MAX_PACKETBUFFER_LENGTH);
    crc.process_bytes(getPadding().get(), 2);

    return crc.checksum();
}
