//
//  V3PacketDecoder.cpp
//  NRPE++
//
//  Created by Massimiliano Ziccardi on 12/03/2020.
//  Copyright © 2020 ziccardi. All rights reserved.
//

#include <iostream>
#include "V3PacketDecoder.hpp"
#include "../../protocol/v3/NRPEV3Request.hpp"

Packet* V3PacketDecoder::decode(common_packet *pkt) {
    v3_packet packet;
    memcpy(&packet, pkt, sizeof(common_packet));
    
    // read alignment and buffer_length
    boost::asio::read(_socket, boost::asio::buffer(&packet.alignment, sizeof(packet.alignment)));
    boost::asio::read(_socket, boost::asio::buffer(&packet.buffer_length, sizeof(packet.buffer_length)));
    
    packet.alignment = ntohs(packet.alignment);
    packet.buffer_length = ntohl(packet.buffer_length);
    
    packet.buffer = std::shared_ptr<char>(new char[packet.buffer_length]);

    boost::asio::read(_socket, boost::asio::buffer(packet.buffer.get(), packet.buffer_length));

    packet.padding_length = 1020 - packet.buffer_length;
    packet.padding = std::shared_ptr<char>(new char[packet.padding_length]);

    boost::asio::read(_socket, boost::asio::buffer(packet.padding.get(), packet.padding_length));

    return new NRPEV3Request(packet.crc32_value, packet.alignment, packet.buffer, packet.buffer_length, packet.padding, packet.padding_length);
}
