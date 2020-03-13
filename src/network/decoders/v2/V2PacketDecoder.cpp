//
//  V2PacketDecoder.cpp
//  NRPE++
//
//  Created by Massimiliano Ziccardi on 12/03/2020.
//  Copyright © 2020 ziccardi. All rights reserved.
//

#include <iostream>
#include "V2PacketDecoder.hpp"
#include "../../protocol/v2/NRPEV2Request.hpp"

Packet* V2PacketDecoder::decodePacket() {
    this->buffer = std::shared_ptr<char>(new char[MAX_PACKETBUFFER_LENGTH]());
    boost::asio::read(getSocket(), boost::asio::buffer(this->buffer.get(), MAX_PACKETBUFFER_LENGTH));

    this->padding = std::shared_ptr<char>(new char[2]);
    boost::asio::read(getSocket(), boost::asio::buffer(this->padding.get(), 2));

    return new NRPEV2Request(this->crc32, this->resultCode, this->buffer, this->padding);
}
