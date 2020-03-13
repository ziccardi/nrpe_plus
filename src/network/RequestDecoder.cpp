//
//  RequestDecoder.cpp
//  NRPE++
//
//  Created by Massimiliano Ziccardi on 12/03/2020.
//  Copyright © 2020 ziccardi. All rights reserved.
//

#include <iostream>
#include <arpa/inet.h>
#include "RequestDecoder.hpp"
#include "protocol.hpp"
#include "v2/V2PacketDecoder.hpp"
#include "v3/V3PacketDecoder.hpp"

Packet* RequestDecoder::decode() {
    boost::asio::streambuf buf;
    
    common_packet packet;
    
    boost::asio::read(_socket, boost::asio::buffer(&packet, sizeof(packet) - 2));
    
    // fix byte order
    packet.packet_version = ntohs(packet.packet_version);
    packet.packet_type = ntohs(packet.packet_type);
    packet.result_code = ntohs(packet.result_code);
    packet.crc32_value = ntohl(packet.crc32_value);
    
    switch (packet.packet_version) {
        case 2: {
            return V2PacketDecoder(_socket).decode(&packet);
        }
        case 4:
        case 3: {
            return V3PacketDecoder(_socket).decode(&packet);
        }
        default:
            break;
    }
    
    std::cout << "Buffer read" << std::endl;
}
