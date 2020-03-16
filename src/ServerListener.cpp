//
//  ServerListener.cpp
//  NRPE++
//
//  Created by Massimiliano Ziccardi on 12/03/2020.
//  Copyright © 2020 ziccardi. All rights reserved.
//

#include "ServerListener.hpp"
#include "ServerHandler.hpp"

void ServerListener::start_accept() {
    ServiceHandler::pointer new_connection = ServiceHandler::create(io_context);
    
    acceptor.async_accept(new_connection->socket(), boost::bind(&ServerListener::handle_accept, this, new_connection, boost::asio::placeholders::error));
}

void ServerListener::handle_accept(const ServiceHandler::pointer& new_connection, const boost::system::error_code& error) {
  if (!error) {
    new_connection->handle();
  }

  start_accept();
}


