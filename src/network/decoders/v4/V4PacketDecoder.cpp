//
// Created by Massimiliano Ziccardi on 13/03/2020.
//

#include <iostream>
#include "V4PacketDecoder.hpp"
#include "../../protocol/v4/NRPEV4Request.hpp"


void V4PacketDecoder::loadPacketFromNetwork() {
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

const Packet * V4PacketDecoder::buildPacket() const {
    return new NRPEV4Request(
            this->crc32,
            this->alignment,
            this->buffer,
            this->bufferLength,
            this->padding,
            this->paddingLength);
}