//
// Created by Massimiliano Ziccardi on 13/03/2020.
//

#include "ResponseEncoder.hpp"
#include "encoders/v2/V2PacketEncoder.hpp"

void ResponseEncoder::encode(Packet *pkt) {
    switch (pkt->getVersion()) {
        case 2: {
            V2PacketEncoder(_socket).encode(pkt);
            break;
        }
        default:
            break;
    }
}