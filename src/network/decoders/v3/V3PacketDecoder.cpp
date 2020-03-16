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

void V3PacketDecoder::loadPacketFromNetwork() {
    // read alignment and buffer_length
    boost::asio::read(getSocket(), boost::asio::buffer(&this->alignment, sizeof(this->alignment)));
    boost::asio::read(getSocket(), boost::asio::buffer(&this->bufferLength, sizeof(this->bufferLength)));
    
    this->alignment = ntohs(this->alignment);
    this->bufferLength = ntohl(this->bufferLength);
    
    this->buffer = std::shared_ptr<char>(new char[this->bufferLength]);

    boost::asio::read(getSocket(), boost::asio::buffer(this->buffer.get(), this->bufferLength));

    this->paddingLength = 1020 - this->bufferLength;
    this->padding = std::shared_ptr<char>(new char[this->paddingLength]);

    boost::asio::read(getSocket(), boost::asio::buffer(this->padding.get(), this->paddingLength));
}

const Packet * V3PacketDecoder::buildPacket() const{
    return new NRPEV3Request(
            this->crc32,
            this->alignment,
            this->buffer,
            this->bufferLength,
            this->padding,
            this->paddingLength);
}