//
//  V3PacketDecoder.cpp
//  NRPE++
//
//  Created by Massimiliano Ziccardi on 12/03/2020.
//  Copyright © 2020 ziccardi. All rights reserved.
//

#include <iostream>
#include "V3PacketDecoder.hpp"

void V3PacketDecoder::decode(common_packet *pkt) {
    v3_packet packet;
    memcpy(&packet, pkt, sizeof(common_packet));
    
    std::cout << "Buffer length: " << packet.buffer_length << std::endl;
    
    // read alignment and buffer_length
    boost::asio::read(_socket, boost::asio::buffer(&packet.alignment, sizeof(packet.alignment)));
    boost::asio::read(_socket, boost::asio::buffer(&packet.buffer_length, sizeof(packet.buffer_length)));
    
    packet.alignment = ntohs(packet.alignment);
    packet.buffer_length = ntohl(packet.buffer_length);
    
    std::unique_ptr<char> buf(new char[packet.buffer_length]);
    
    boost::asio::read(_socket, boost::asio::buffer(buf.get(), packet.buffer_length));
    
    packet.buffer = std::string(buf.get());
    
    std::cout << std::endl;
    
    
    std::cout << "Alignment: " << packet.alignment << std::endl;
    std::cout << "Buffer length: " << packet.buffer_length << std::endl;
    std::cout << "sa: " << sizeof(packet.buffer_length) << std::endl;
    std::cout << "Buffer: " << packet.buffer << std::endl;
}
