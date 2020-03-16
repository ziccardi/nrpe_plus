//
// Created by Massimiliano Ziccardi on 13/03/2020.
//

#ifndef NRPE_V3PACKETENCODER_HPP
#define NRPE_V3PACKETENCODER_HPP

#include <boost/asio.hpp>
#include "../../protocol/Packet.hpp"

using boost::asio::ip::tcp;

class V3PacketEncoder {
private:
    tcp::socket& _socket;
public:
    explicit V3PacketEncoder(tcp::socket& socket) : _socket(socket) {}
    void encode(const Packet *pkt) const;
};


#endif //NRPE_V3PACKETENCODER_HPP
