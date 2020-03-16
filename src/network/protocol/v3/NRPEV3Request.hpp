//
// Created by Massimiliano Ziccardi on 13/03/2020.
//

#ifndef NRPE_NRPEV3REQUEST_HPP
#define NRPE_NRPEV3REQUEST_HPP

#include <utility>


#include "NRPEV3AbstractPacket.hpp"

class NRPEV3Request : public NRPEV3AbstractPacket {
public:
    NRPEV3Request(u_int32_t crc32,
                  int16_t alignment,
                  std::shared_ptr<char> buffer,
                  u_int32_t bufferLength,
                  std::shared_ptr<char> padding,
                  int16_t paddingLength)
            : NRPEV3AbstractPacket(1, crc32, 0, alignment, std::move(buffer), bufferLength, std::move(padding), paddingLength){}
};

#endif //NRPE_NRPEV3REQUEST_HPP
