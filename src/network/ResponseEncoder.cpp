//
// Created by Massimiliano Ziccardi on 13/03/2020.
//

#include "ResponseEncoder.hpp"
#include "encoders/v2/V2PacketEncoder.hpp"
#include "encoders/v3/V3PacketEncoder.hpp"
#include "encoders/v4/V4PacketEncoder.hpp"

void ResponseEncoder::encode(Packet *pkt) {
    switch (pkt->getVersion()) {
        case 2: {
            V2PacketEncoder(_socket).encode(pkt);
            break;
        }
        case 3: {
            V3PacketEncoder(_socket).encode(pkt);
            break;
        }
        case 4: {
            V4PacketEncoder(_socket).encode(pkt);
            break;
        }
        default:
            break;
    }
}