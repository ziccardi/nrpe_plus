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
#include "../../protocol/Packet.hpp"
#include "../AbstractPacketDecoder.hpp"

using boost::asio::ip::tcp;

class V2PacketDecoder : public AbstractPacketDecoder {
public:
    V2PacketDecoder(tcp::socket& socket) : AbstractPacketDecoder(socket) {}
    void loadPacketFromNetwork();
    Packet* buildPacket();
};

#endif /* V2PacketDecoder_hpp */
