//
//  ServerListener.hpp
//  NRPE++
//
//  Created by Massimiliano Ziccardi on 12/03/2020.
//  Copyright © 2020 ziccardi. All rights reserved.
//

#ifndef ServerListener_hpp
#define ServerListener_hpp

#include <ctime>
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/asio.hpp>

#include "ServerHandler.hpp"

using boost::asio::ip::tcp;

class ServerListener {
private:
    boost::asio::io_context& io_context;
    tcp::acceptor acceptor;
    
public:
    ServerListener(boost::asio::io_context& io_context) : io_context(io_context), acceptor(io_context, tcp::endpoint(tcp::v4(), 13)) {
      start_accept();
    }

private:
    void start_accept();
    void handle_accept(ServiceHandler::pointer new_connection, const boost::system::error_code& error);
};


#endif /* ServerListener_hpp */
