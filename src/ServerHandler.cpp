//
//  ServerHandler.cpp
//  NRPE++
//
//  Created by Massimiliano Ziccardi on 12/03/2020.
//  Copyright © 2020 ziccardi. All rights reserved.
//

#include <iostream>
#include <boost/bind.hpp>
#include "ServerHandler.hpp"
#include "network/RequestDecoder.hpp"
#include "network/protocol/Packet.hpp"


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

    boost::asio::async_write(_socket, boost::asio::buffer(msg),
                             boost::bind(&ServiceHandler::handle_write, shared_from_this(),
                                         boost::asio::placeholders::error,
                                         boost::asio::placeholders::bytes_transferred));
}

void ServiceHandler::handle_write(const boost::system::error_code& /*error*/, size_t /*bytes_transferred*/) {
}
