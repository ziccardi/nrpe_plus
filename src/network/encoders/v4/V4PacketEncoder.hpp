//
// Created by Massimiliano Ziccardi on 13/03/2020.
//

#ifndef NRPE_V4PACKETENCODER_HPP
#define NRPE_V4PACKETENCODER_HPP

#include <boost/asio.hpp>
#include "../../protocol/Packet.hpp"

using boost::asio::ip::tcp;

class V4PacketEncoder {
private:
    tcp::socket& _socket;
public:
    explicit V4PacketEncoder(tcp::socket& socket) : _socket(socket) {}
    void encode(const Packet *pkt) const;
};


#endif //NRPE_V4PACKETENCODER_HPP
