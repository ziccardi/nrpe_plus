//
// Created by Massimiliano Ziccardi on 13/03/2020.
//

#ifndef NRPE_RESPONSEENCODER_HPP
#define NRPE_RESPONSEENCODER_HPP

#include <boost/asio.hpp>
#include "protocol/Packet.hpp"
using boost::asio::ip::tcp;

class ResponseEncoder {
private:
    tcp::socket& _socket;
public:
    explicit ResponseEncoder(tcp::socket& socket) : _socket(socket) {
    }

    void encode(Packet* pkt);
};

#endif //NRPE_RESPONSEENCODER_HPP
