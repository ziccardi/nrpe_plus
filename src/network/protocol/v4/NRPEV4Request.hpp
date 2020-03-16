//
// Created by Massimiliano Ziccardi on 13/03/2020.
//

#ifndef NRPE_NRPEV4REQUEST_HPP
#define NRPE_NRPEV4REQUEST_HPP

#include <utility>


#include "NRPEV4AbstractPacket.hpp"

class NRPEV4Request : public NRPEV4AbstractPacket {
public:
    NRPEV4Request(u_int32_t crc32,
                  int16_t alignment,
                  std::shared_ptr<char> buffer,
                  u_int32_t bufferLength,
                  std::shared_ptr<char> padding,
                  int16_t paddingLength)
            : NRPEV4AbstractPacket(1, crc32, 0, alignment, std::move(buffer), bufferLength, std::move(padding), paddingLength){}
};

#endif //NRPE_NRPEV4REQUEST_HPP
