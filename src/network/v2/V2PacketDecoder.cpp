//
//  V2PacketDecoder.cpp
//  NRPE++
//
//  Created by Massimiliano Ziccardi on 12/03/2020.
//  Copyright © 2020 ziccardi. All rights reserved.
//

#include <iostream>
#include "V2PacketDecoder.hpp"

void V2PacketDecoder::decode(common_packet *pkt) {
    v2_packet packet;
    memcpy(&packet, pkt, sizeof(common_packet));
    boost::asio::read(_socket, boost::asio::buffer(packet.buffer, sizeof(packet.buffer)));
    std::cout << "Buffer: " << packet.buffer << std::endl;
}
