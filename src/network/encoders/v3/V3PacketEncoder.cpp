//
// Created by Massimiliano Ziccardi on 13/03/2020.
//

#include "V3PacketEncoder.hpp"

void V3PacketEncoder::encode(const Packet* pkt) const {
    int16_t version = htons(pkt->getVersion());
    int16_t type = htons(pkt->getPacketType());
    u_int32_t crc32 = htonl(pkt->getCrc32());
    int16_t resCode = htons(pkt->getResultCode());
    int16_t alignment = htons(pkt->getAlignment());
    u_int32_t bufferLen = htonl(pkt->getBufferLength());

    boost::asio::write(_socket, boost::asio::buffer(&version, sizeof(version)));
    boost::asio::write(_socket, boost::asio::buffer(&type, sizeof(type)));
    boost::asio::write(_socket, boost::asio::buffer(&crc32, sizeof(crc32)));
    boost::asio::write(_socket, boost::asio::buffer(&resCode, sizeof(resCode)));
    boost::asio::write(_socket, boost::asio::buffer(&alignment, sizeof(alignment)));
    boost::asio::write(_socket, boost::asio::buffer(&bufferLen, sizeof(bufferLen)));
    boost::asio::write(_socket, boost::asio::buffer(pkt->getBuffer().get(), pkt->getBufferLength()));
    boost::asio::write(_socket, boost::asio::buffer(pkt->getPadding().get(), pkt->getPaddingLength()));
}