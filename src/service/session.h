#ifndef WSLIB_SERVICE_SESSION
#define WSLIB_SERVICE_SESSION

#include <cstdlib>
#include <iostream>
#include <boost/bind.hpp>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;

namespace wslib {
   namespace service {
      class session {

         private:
            tcp::socket socket_;
            enum { max_length = 1024 };
            char data_[max_length];

         public:
            session( boost::asio::io_service& io_service );
            tcp::socket& socket();
            void start(); 
            void handle_read( 
               const boost::system::error_code& error,
               size_t bytes_transferred );
            void handle_write( const boost::system::error_code& error ); 
      };
   }
}

#endif
