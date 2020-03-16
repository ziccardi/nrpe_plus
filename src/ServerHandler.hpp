//
//  ServerHandler.hpp
//  NRPE++
//
//  Created by Massimiliano Ziccardi on 12/03/2020.
//  Copyright © 2020 ziccardi. All rights reserved.
//

#ifndef ServerHandler_hpp
#define ServerHandler_hpp

#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/asio.hpp>

#include <stdio.h>

using boost::asio::ip::tcp;

class ServiceHandler;

class ServiceHandler : public boost::enable_shared_from_this<ServiceHandler> {
private:
    tcp::socket _socket;

public:
    typedef boost::shared_ptr<ServiceHandler> pointer;
    static pointer create(boost::asio::io_context& io_context);
    
    void handle();
    tcp::socket& socket() {
        return _socket;
    }
    
private:
    explicit ServiceHandler(boost::asio::io_context& io_context);
    void handle_write(const boost::system::error_code& /*error*/, size_t /*bytes_transferred*/);
};



#endif /* ServerHandler_hpp */
