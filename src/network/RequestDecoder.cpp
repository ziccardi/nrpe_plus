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
#include "decoders/v2/V2PacketDecoder.hpp"
#include "decoders/v3/V3PacketDecoder.hpp"
#include "decoders/v4/V4PacketDecoder.hpp"

const Packet* RequestDecoder::decode() const{
    boost::asio::streambuf buf;
    
    int16_t version;

    boost::asio::read(_socket, boost::asio::buffer(&version, sizeof(version)));

    switch (ntohs(version)) {
        case 2: {
            return V2PacketDecoder(_socket).decode();
        }
        case 3: {
            return V3PacketDecoder(_socket).decode();
        }
        case 4: {
            return V4PacketDecoder(_socket).decode();
        }
        default:
            break;
    }
    
    std::cout << "Buffer read" << std::endl;
}
