//
//  V3PacketDecoder.hpp
//  NRPE++
//
//  Created by Massimiliano Ziccardi on 12/03/2020.
//  Copyright © 2020 ziccardi. All rights reserved.
//

#ifndef V3PacketDecoder_hpp
#define V3PacketDecoder_hpp

#include <stdint.h>
#include <boost/asio.hpp>
#include "../protocol.hpp"

using boost::asio::ip::tcp;

typedef struct _v3_packet{
    int16_t   packet_version;
    int16_t   packet_type;
    u_int32_t crc32_value;
    int16_t   result_code;
    int16_t   alignment;
    int32_t   buffer_length;
    std::string     buffer;
} v3_packet;

class V3PacketDecoder {
private:
    tcp::socket& _socket;
public:
    V3PacketDecoder(tcp::socket& socket) : _socket(socket) {}
    void decode(common_packet *pkt);
};


#endif /* V3PacketDecoder_hpp */
