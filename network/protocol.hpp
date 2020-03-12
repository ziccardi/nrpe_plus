//
//  protocol.hpp
//  NRPE++
//
//  Created by Massimiliano Ziccardi on 12/03/2020.
//  Copyright © 2020 ziccardi. All rights reserved.
//

#ifndef protocol_hpp
#define protocol_hpp

typedef struct packet {
    int16_t        packet_version;
    int16_t        packet_type;
    u_int32_t      crc32_value;
    int16_t        result_code;
} common_packet;

#endif /* protocol_hpp */
