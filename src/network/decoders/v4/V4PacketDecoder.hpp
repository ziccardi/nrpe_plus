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
    explicit V4PacketDecoder(tcp::socket& socket) : AbstractPacketDecoder(socket) {}
    void loadPacketFromNetwork() override;
    const Packet* buildPacket() const override;
};
#endif //NRPE_V4PACKETDECODER_HPP
