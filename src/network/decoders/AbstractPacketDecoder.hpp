//
// Created by Massimiliano Ziccardi on 13/03/2020.
//

#ifndef NRPE_ABSTRACTPACKETDECODER_HPP
#define NRPE_ABSTRACTPACKETDECODER_HPP

#include <cstdint>
#include <boost/asio.hpp>
#include "../protocol/Packet.hpp"
using boost::asio::ip::tcp;

class AbstractPacketDecoder {
private:
    tcp::socket& _socket;
protected:
    int16_t packet_type;
    int16_t resultCode;
    int16_t alignment;
    u_int32_t crc32;
    std::shared_ptr<char>   buffer;
    u_int32_t bufferLength;
    std::shared_ptr<char>   padding;
    u_int32_t paddingLength;
protected:
    tcp::socket& getSocket() { return _socket; }
    virtual void loadPacketFromNetwork() = 0;
    virtual Packet* buildPacket() = 0;
public:
    AbstractPacketDecoder(tcp::socket& socket) : _socket(socket) {}
    Packet* decode();
};


#endif //NRPE_ABSTRACTPACKETDECODER_HPP
