//
//  V2PacketDecoder.hpp
//  NRPE++
//
//  Created by Massimiliano Ziccardi on 12/03/2020.
//  Copyright © 2020 ziccardi. All rights reserved.
//

#ifndef V2PacketDecoder_hpp
#define V2PacketDecoder_hpp

#define MAX_PACKETBUFFER_LENGTH 1024

#include <cstdint>
#include <boost/asio.hpp>
#include "../protocol.hpp"

using boost::asio::ip::tcp;

typedef struct _v2_packet {
    int16_t      packet_version;
    int16_t      packet_type;
    u_int32_t    crc32_value;
    int16_t      result_code;
    std::shared_ptr<char>   buffer;
    std::shared_ptr<char>   padding;
} v2_packet;

class V2PacketDecoder {
private:
    tcp::socket& _socket;
public:
    V2PacketDecoder(tcp::socket& socket) : _socket(socket) {}
    void decode(common_packet *pkt);
};

#endif /* V2PacketDecoder_hpp */
