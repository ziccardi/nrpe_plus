//
//  RequestDecoder.hpp
//  NRPE++
//
//  Created by Massimiliano Ziccardi on 12/03/2020.
//  Copyright © 2020 ziccardi. All rights reserved.
//

#ifndef RequestDecoder_hpp
#define RequestDecoder_hpp
#define MAX_PACKETBUFFER_LENGTH 1024

#include <boost/asio.hpp>
using boost::asio::ip::tcp;

class RequestDecoder {
private:
    tcp::socket& _socket;
public:
    explicit RequestDecoder(tcp::socket& socket) : _socket(socket) {
    }
    
    void decode();
};

#endif /* RequestDecoder_hpp */
