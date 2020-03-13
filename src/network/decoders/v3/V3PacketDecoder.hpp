//
//  V3PacketDecoder.hpp
//  NRPE++
//
//  Created by Massimiliano Ziccardi on 12/03/2020.
//  Copyright © 2020 ziccardi. All rights reserved.
//

#ifndef V3PacketDecoder_hpp
#define V3PacketDecoder_hpp

#include <cstdint>
#include <boost/asio.hpp>
#include "../../protocol/Packet.hpp"
#include "../AbstractPacketDecoder.hpp"

using boost::asio::ip::tcp;

class V3PacketDecoder : public AbstractPacketDecoder {
public:
    V3PacketDecoder(tcp::socket& socket) : AbstractPacketDecoder(socket) {}
    void loadPacketFromNetwork();
    Packet* buildPacket();
};


#endif /* V3PacketDecoder_hpp */
