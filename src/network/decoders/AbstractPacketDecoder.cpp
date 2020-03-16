//
// Created by Massimiliano Ziccardi on 13/03/2020.
//

#include "AbstractPacketDecoder.hpp"

const Packet* AbstractPacketDecoder::decode() {
    boost::asio::read(_socket, boost::asio::buffer(&packet_type, sizeof(packet_type)));
    boost::asio::read(_socket, boost::asio::buffer(&crc32, sizeof(crc32)));
    boost::asio::read(_socket, boost::asio::buffer(&resultCode, sizeof(resultCode)));

    this->packet_type = ntohs(this->packet_type);
    this->crc32 = ntohl(this->crc32);
    this->resultCode = ntohs(this->resultCode);

    this->loadPacketFromNetwork();

    return this->buildPacket();
}