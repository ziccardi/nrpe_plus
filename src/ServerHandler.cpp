//
//  ServerHandler.cpp
//  NRPE++
//
//  Created by Massimiliano Ziccardi on 12/03/2020.
//  Copyright © 2020 ziccardi. All rights reserved.
//

#include <iostream>
#include "ServerHandler.hpp"
#include "network/RequestDecoder.hpp"
#include "network/protocol/Packet.hpp"
#include "network/protocol/v2/NRPEV2Response.hpp"
#include "network/protocol/v3/NRPEV3Response.hpp"
#include "network/ResponseEncoder.hpp"

using boost::asio::ip::tcp;

ServiceHandler::pointer ServiceHandler::create(boost::asio::io_context& io_context) {
    return ServiceHandler::pointer(new ServiceHandler(io_context));
}

ServiceHandler::ServiceHandler(boost::asio::io_context& io_context) : _socket(io_context){
}

void ServiceHandler::handle() {
    std::string msg("Hello world");
    RequestDecoder decoder(_socket);
    std::unique_ptr<Packet> pkt(decoder.decode());

    std::cout << pkt->getCommand() << std::endl;
    std::cout << "Valid: " << pkt->validateCRC() << std::endl;
    std::cout << "Writing response" << std::endl;

    // TODO: here we should execute the command and receive the result to return...

    std::unique_ptr<Packet> res;

    switch(pkt->getVersion()) {
        case 2:
            res = std::unique_ptr<Packet>(new NRPEV2Response(0, "Hello World V2"));
            break;
        case 3:
            res = std::unique_ptr<Packet>(new NRPEV3Response(0, "Hello World V3"));
            break;
        default:
            // Unsupported version
            break;
    }


    ResponseEncoder(_socket).encode(res.get());

//    boost::asio::async_write(_socket, boost::asio::buffer(msg),
//                             boost::bind(&ServiceHandler::handle_write, shared_from_this(),
//                                         boost::asio::placeholders::error,
//                                         boost::asio::placeholders::bytes_transferred));
}

void ServiceHandler::handle_write(const boost::system::error_code& /*error*/, size_t /*bytes_transferred*/) {
}
