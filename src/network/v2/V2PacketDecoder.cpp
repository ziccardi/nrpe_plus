//
//  V2PacketDecoder.cpp
//  NRPE++
//
//  Created by Massimiliano Ziccardi on 12/03/2020.
//  Copyright © 2020 ziccardi. All rights reserved.
//

#include <iostream>
#include "V2PacketDecoder.hpp"
#include "../protocol/v2/NRPEV2Request.hpp"

Packet* V2PacketDecoder::decode(common_packet *pkt) {
    v2_packet packet;
    packet.buffer = std::shared_ptr<char>(new char[MAX_PACKETBUFFER_LENGTH]);
    memcpy(&packet, pkt, sizeof(common_packet));
    boost::asio::read(_socket, boost::asio::buffer(packet.buffer.get(), MAX_PACKETBUFFER_LENGTH));

    packet.padding = std::shared_ptr<char>(new char[2]);
    boost::asio::read(_socket, boost::asio::buffer(packet.padding.get(), 2));

    return new NRPEV2Request(packet.crc32_value, packet.result_code, packet.buffer, packet.padding);
}
