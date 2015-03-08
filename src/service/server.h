
#ifndef WSLIB_SERVICE_SERVER
#define WSLIB_SERVICE_SERVER

#include <cstdlib>
#include <iostream>
#include <boost/bind.hpp>
#include <boost/asio.hpp>
#include "session.h"

using boost::asio::ip::tcp;

namespace wslib {

   namespace service {

      class server {

         private:
            boost::asio::io_service& io_service_;
            tcp::acceptor acceptor_;

         public:
            server( boost::asio::io_service& io_service, short port );
            void handle_accept( session* new_session,
               const boost::system::error_code& error );
      };
   }
}

#endif
