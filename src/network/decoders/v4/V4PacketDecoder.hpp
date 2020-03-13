//
// Created by Massimiliano Ziccardi on 13/03/2020.
//

#ifndef NRPE_V4PACKETDECODER_HPP
#define NRPE_V4PACKETDECODER_HPP

#include <cstdint>
#include <boost/asio.hpp>
#include "../../protocol/Packet.hpp"
#include "../AbstractPacketDecoder.hpp"

using boost::asio::ip::tcp;

class V4PacketDecoder : public AbstractPacketDecoder {
public:
    V4PacketDecoder(tcp::socket& socket) : AbstractPacketDecoder(socket) {}
    void loadPacketFromNetwork();
    Packet* buildPacket();
};
#endif //NRPE_V4PACKETDECODER_HPP
